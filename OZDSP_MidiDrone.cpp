#include "OZDSP_MidiDrone.h"
#include "IPlug_include_in_plug_src.h"
#include "resource.h"

const int kNumPrograms = 0;

enum EParams
{
	kVolumePid,
	kWaveformPid,
	kNumParams
};

std::vector<ParameterInfo> kParameterList =
{
	ParameterInfo()
		.InitParam("Volume", kVolumePid, KNOB_80_ID, 20, 35)
		.InitLabel()
		.MakeVolumeReductionParam(),
	ParameterInfo()
		.InitParam("Waveform", kWaveformPid, WAVESELECT_ID, 20, 130)
		.MakeWaveformParam()
};

OZDSP_MidiDrone::OZDSP_MidiDrone(IPlugInstanceInfo instanceInfo) :
	CommonPlugBase(instanceInfo, kNumParams, kNumPrograms,
		MakeGraphics(this, GUI_WIDTH, GUI_HEIGHT),
		COMMONPLUG_CTOR_PARAMS),
	mOscillator(this),
	mVolumeProcessor(this),
	mTuningProcessor(this)
{
	SetBackground(BACKGROUND_ID, BACKGROUND_FN);
	RegisterBitmap(KNOB_80_ID, KNOB_80_FN, KNOB_FRAMES);
	RegisterBitmap(WAVESELECT_ID, WAVESELECT_FN, WAVESELECT_FRAMES);
	AddParameters(kParameterList);
	RegisterProcessor(&mOscillator);
	RegisterProcessorParameter(&mOscillator, kWaveformPid, Oscillator::kWaveformParam);
	RegisterProcessor(&mVolumeProcessor);
	RegisterProcessorParameter(&mVolumeProcessor, kVolumePid, VolumeProcessor::kDecibelsParam);
	RegisterProcessor(&mTuningProcessor);
	FinishConstruction();
}

OZDSP_MidiDrone::~OZDSP_MidiDrone()
{
}

void OZDSP_MidiDrone::ProcessMidiMsg(IMidiMsg* pMessage)
{
	mMidiReciver.RecieveMessage(pMessage);
}

void OZDSP_MidiDrone::ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames)
{
	// Mutex is already locked for us.
	const int nChannels = 2;

	for (int i = 0; i < nFrames; i++)
	{
		mMidiReciver.AdvanceSample(&mMidiEventQueue);

		while (!mMidiEventQueue.empty())
		{
			MidiEvent midiEvent = mMidiEventQueue.front();
			mMidiEventQueue.pop();
			HandleMidiEvent(midiEvent);
		}

		double out = mOscillator.GetNextSample();
		out = mVolumeProcessor.GetAdjustedSample(out);

		for (int j = 0; j < nChannels; j++)
		{
			outputs[j][i] = out;
		}
	}

	mMidiReciver.FlushBlock(nFrames);
}

void OZDSP_MidiDrone::HandleMidiEvent(MidiEvent midiEvent)
{
	switch (midiEvent.eventType)
	{
	case MidiEvent::kNoteBegin:
		mOscillator.SetFrequency(mTuningProcessor.GetFrequencyOfNote(midiEvent.noteId));
		break;
	case MidiEvent::kNoteChange:
		mOscillator.SetFrequency(mTuningProcessor.GetFrequencyOfNote(midiEvent.newNoteId));
		break;
	case MidiEvent::kNoteEnd:
		mOscillator.SetFrequency(0.0);
		break;
	}
}
