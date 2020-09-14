/*
  ==============================================================================


 eksAudioInputAccessPermissions.cpp

    14. sept. 2020
        created  /eks

  ==============================================================================
*/

#include "audio_io/juce_AudioDeviceManager.cpp"
#include "audio_io/juce_AudioIODevice.cpp"
#include "audio_io/juce_AudioIODeviceType.cpp"
#include "midi_io/juce_MidiMessageCollector.cpp"
#include "midi_io/juce_MidiDevices.cpp"
#include "sources/juce_AudioSourcePlayer.cpp"
#include "sources/juce_AudioTransportSource.cpp"
#include "native/juce_MidiDataConcatenator.h"

#include "eksCheckAudioInputAccessPermissions.cpp"
