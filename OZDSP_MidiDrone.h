#ifndef __OZDSP_MIDIDRONE__
#define __OZDSP_MIDIDRONE__

#include "IPlug_include_in_plug_hdr.h"

#include "../OZDSP_Common/CommonPlugBase.h"
#include "../OZDSP_Common/midi/MidiStackReciever.h"
#include "../OZDSP_Common/midi/TuningProcessor.h"
#include "../OZDSP_Common/parameter/ParameterInfo.h"
#include "../OZDSP_Common/processing/Oscillator.h"
#include "../OZDSP_Common/processing/VolumeProcessor.h"

class OZDSP_MidiDrone : public CommonPlugBase
{
public:
	OZDSP_MidiDrone(IPlugInstanceInfo instanceInfo);
	~OZDSP_MidiDrone();

	void ProcessMidiMsg(IMidiMsg* pMessage) override;
	void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames) override;

private:
	Oscillator mOscillator;
	VolumeProcessor mVolumeProcessor;

	MidiStackReciever mMidiReciver;
	TuningProcessor mTuningProcessor;

	std::queue<NoteStatusEvent> mMidiEventQueue;

	void HandleMidiEvent(NoteStatusEvent midiEvent);
};

#endif
