/*
	audioRecorderThread.h
		Eigil Krogh Sorensen	21. mar. 2018

  ==============================================================================

   This file is part of the JUCE examples.
   Copyright (c) 2017 - ROLI Ltd.

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             audioRecorderThread
 version:          1.0.0
 vendor:           juce
 website:          http://juce.com
 description:      Thread that handles recording of filtered audio

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2017, linux_make, androidstudio, xcode_iphone

 mainClass:        audioRecorderThread

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once
#include "JuceHeader.h"

class AudioRecorderControl;


//==============================================================================
class audioRecorderThread    : public Thread
{
public:
	audioRecorderThread(std::shared_ptr<AudioRecorderControl> spTheAudioRecorderControllerInUse);

	~audioRecorderThread();
    
	void run() override;
    
	void recordingFilteredAudioBuffer(float* theAudioBuffer);
	
	void signalweAudioReadyForRecording();
	
private:
	float* bufferToRecord;
	bool bufferReady = false;
	std::shared_ptr<AudioRecorderControl> spTheAudioRecorderController;
	WaitableEvent weAudioReadyForRecording;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (audioRecorderThread)
};
