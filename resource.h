#define PLUG_MFR "ZachOhara"
#define PLUG_NAME "OZDSP_MidiDrone"

#define PLUG_CLASS_NAME OZDSP_MidiDrone

#define BUNDLE_MFR "ZachOhara"
#define BUNDLE_NAME "OZDSP_MidiDrone"

#define PLUG_ENTRY OZDSP_MidiDrone_Entry
#define PLUG_FACTORY OZDSP_MidiDrone_Factory
#define PLUG_VIEW_ENTRY OZDSP_MidiDrone_ViewEntry

#define PLUG_ENTRY_STR "OZDSP_MidiDrone_Entry"
#define PLUG_VIEW_ENTRY_STR "OZDSP_MidiDrone_ViewEntry"

#define VIEW_CLASS OZDSP_MidiDrone_View
#define VIEW_CLASS_STR "OZDSP_MidiDrone_View"

// Format        0xMAJR.MN.BG - in HEX! so version 10.1.5 would be 0x000A0105
#define PLUG_VER 0x00010000
#define VST3_VER_STR "1.0.0"

#define PLUG_COPYRIGHT  "Copyright 2019 Zach Ohara"

// http://service.steinberg.de/databases/plugin.nsf/plugIn?openForm
// 4 chars, single quotes. At least one capital letter
#define PLUG_UNIQUE_ID 'Ipef'
// make sure this is not the same as BUNDLE_MFR
#define PLUG_MFR_ID 'Acme'

// ProTools stuff

#if (defined(AAX_API) || defined(RTAS_API)) && !defined(_PIDS_)
  #define _PIDS_
  const int PLUG_TYPE_IDS[2] = {'EFN1', 'EFN2'};
  const int PLUG_TYPE_IDS_AS[2] = {'EFA1', 'EFA2'}; // AudioSuite
#endif

// TODO
#define PLUG_MFR_PT "ZachOhara\nZachOhara\nAcme"
#define PLUG_NAME_PT "OZDSP_MidiDrone\nIPEF"
#define PLUG_TYPE_PT "Effect"
#define PLUG_DOES_AUDIOSUITE 1

/* PLUG_TYPE_PT can be "None", "EQ", "Dynamics", "PitchShift", "Reverb", "Delay", "Modulation", 
"Harmonic" "NoiseReduction" "Dither" "SoundField" "Effect" 
instrument determined by PLUG _IS _INST
*/

#define PLUG_CHANNEL_IO "1-1 2-2"

#define PLUG_LATENCY 0
#define PLUG_IS_INST 1

// if this is 0 RTAS can't get tempo info
#define PLUG_DOES_MIDI 1

#define PLUG_DOES_STATE_CHUNKS 0

// Unique IDs for each image resource.
#define BACKGROUND_ID 101
#define KNOB_80_ID 201
#define WAVESELECT_ID 301

// Image resource locations for this plug.
#define BACKGROUND_FN "resources/img/MidiDrone.png"
#define KNOB_80_FN "resources/img/knob_white80.png"
#define WAVESELECT_FN "resources/img/waveforms.png"

// Number of frames in the bitmaps
#define KNOB_FRAMES 128
#define WAVESELECT_FRAMES 4

// GUI default dimensions
#define GUI_WIDTH 120
#define GUI_HEIGHT 230

// on MSVC, you must define SA_API in the resource editor preprocessor macros as well as the c++ ones
#if defined(SA_API)
#include "app_wrapper/app_resource.h"
#endif

// vst3 stuff
#define MFR_URL "www.zachohara.com"
#define MFR_EMAIL "zjohara@gmail.com"
#define EFFECT_TYPE_VST3 "Instrument|Synth"

/* "Fx|Analyzer"", "Fx|Delay", "Fx|Distortion", "Fx|Dynamics", "Fx|EQ", "Fx|Filter",
"Fx", "Fx|Instrument", "Fx|InstrumentExternal", "Fx|Spatial", "Fx|Generator",
"Fx|Mastering", "Fx|Modulation", "Fx|PitchShift", "Fx|Restoration", "Fx|Reverb",
"Fx|Surround", "Fx|Tools", "Instrument", "Instrument|Drum", "Instrument|Sampler",
"Instrument|Synth", "Instrument|Synth|Sampler", "Instrument|External", "Spatial",
"Spatial|Fx", "OnlyRT", "OnlyOfflineProcess", "Mono", "Stereo",
"Surround"
*/
