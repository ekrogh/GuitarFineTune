/*
	AudioRecorder.h
	Eigil Krogh Sorensen	18. mar. 2018
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

 name:             AudioRecorder
 version:          1.0.0
 vendor:           juce
 website:          http://juce.com
 description:      Records audio to a file.

 dependencies:     juce_audio_basics, juce_audio_devices, juce_audio_formats,
				   juce_audio_processors, juce_audio_utils, juce_core,
				   juce_data_structures, juce_events, juce_graphics,
				   juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2017, linux_make, androidstudio, xcode_iphone

 type:             Component
 mainClass:        AudioRecorderControl

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/
#pragma once

#include <memory>
#include <ctime>
#include <chrono>
#include <complex>
#include <deque>
#include <list>
#include <vector>
#include <iostream>   // std::cout
#include <string>
#include <numeric>
#include <random>
#include <exception>      // std::exception
#include <iterator>
#include <cmath>

#include "JuceHeader.h"
#include "SimpleLevelMeter.h"

using namespace std;
using namespace std::chrono;

//==============================================================================
/** A simple class that acts as an AudioIODeviceCallback and writes the
	incoming audio data to a WAV file.
*/
class AudioRecorder : public AudioIODeviceCallback
{
public:
	AudioRecorder();

	~AudioRecorder();

	void startRecording(const File& file);
	
	void stop();
	
	bool isRecording() const;
	
	void filteredAudioSourceAboutToStart(double theSampleRate, int bufferSize);
	
	void audioDeviceAboutToStart(AudioIODevice* device) override;
	
	void audioDeviceStopped() override;

	inline float findMaxLevel(const float* inputData, int numSamples);

	inline void applyGain(const float* inputData, float* outputData, int numSamples);

	void audioDeviceIOCallback(const float** inputChannelData, int numInputChannels,
		float** outputChannelData, int numOutputChannels,
		int numSamples) override;
	
	void recordFilteredAudio(float* inputData);
	
	void setRecordingGain(float thegainToUse);
	float getCurrentRecordingGain();
	void setAutoGainOn(bool setAutoGainOn);

	void setPtrRecordingLevelMeter(std::weak_ptr<SimpleLevelMeter> thePtrRecordingLevelMeter) { pRecordingLevelMeter = thePtrRecordingLevelMeter; }

	void setCalcCurrentMaxLevel(bool shouldBeCalculated);

	float getCurrentMaxLevel();

private:
	TimeSliceThread backgroundThread{ "Audio Recorder Thread" }; // the thread that will write our audio data to disk
	std::shared_ptr<AudioFormatWriter::ThreadedWriter> threadedWriter; // the FIFO used to buffer the incoming data
	double sampleRate = 0.0;

	CriticalSection writerLock;
	AudioFormatWriter::ThreadedWriter* volatile activeWriter = nullptr;

	bool calculateCurrentMaxLevel = false;
	float CurrentMaxLevel = std::numeric_limits<float>::min();

	float gainToUse = 0.0f;
	bool autoGain = true;

	float* bufferForDataWGainApplied = { 0 };
	int numSamplesPerBufferInUse = std::numeric_limits<int>::min();

	std::weak_ptr<SimpleLevelMeter> pRecordingLevelMeter;
};



//==============================================================================
class AudioRecorderControl : public Component
{
public:
	AudioRecorderControl();

	~AudioRecorderControl();
	

	void StopAudioDeviceIOCallback();
		
	void setSourceRaw();

	void setSourceFiltered();

	void filteredAudioSourceAboutToStart(double theSampleRate, int bufferSize);

	void startAudioRecorderRecording();

	void stopAudioRecorderRecording();
	
	void recordFilteredAudio(float* inputChannelData);
	
	void setCalcCurrentMaxLevel(bool shouldBeCalculated);

	float getCurrentMaxLevel();

	void setRecordingGain(float thegainToUse);
	float getCurrentRecordingGain();
	void setAutoGainOn(bool setAutoGainOn);

	void setPtrRecordingLevelMeter(std::weak_ptr<SimpleLevelMeter> thePtrRecordingLevelMeter) { spRecorder->setPtrRecordingLevelMeter(thePtrRecordingLevelMeter); }

private:

	void startRecording();

	void stopRecording();


	std::shared_ptr<AudioRecorder> spRecorder = std::make_shared<AudioRecorder>();

	File lastRecording;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioRecorderControl)
};
