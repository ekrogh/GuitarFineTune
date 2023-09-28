/*
	AudioRecorder.cpp
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

//#if ((defined (_WIN32) || defined (_WIN64)) && _DEBUG)
//#include "vld.h"
//#endif //  (JUCE_WINDOWS && _DEBUG)

#include "AudioRecorder.h"

//==============================================================================
/** A simple class that acts as an AudioIODeviceCallback and writes the
	incoming audio data to a WAV file.
*/
AudioRecorder::AudioRecorder()
{
	backgroundThread.startThread();
}

AudioRecorder::~AudioRecorder()
{
	backgroundThread.stopThread(-1);
	stop();
	free(bufferForDataWGainApplied);
}

//==============================================================================
void AudioRecorder::startRecording(const File& file)
{
	stop();

	if (sampleRate > 0)
	{
		// Create an OutputStream to write to our destination file...
		file.deleteFile();
		std::unique_ptr<FileOutputStream> fileStream(file.createOutputStream());

		if (fileStream.get() != nullptr)
		{
			// Now create a WAV writer object that writes to our output stream...
			WavAudioFormat wavFormat;
			auto* writer = wavFormat.createWriterFor(fileStream.get(), sampleRate, 1, 16, {}, 0);

			if (writer != nullptr)
			{
				fileStream.release(); // (passes responsibility for deleting the stream to the writer object that is now using it)

				// Now we'll create one of these helper objects which will act as a FIFO buffer, and will
				// write the data to disk on our background thread.
				threadedWriter.reset(new AudioFormatWriter::ThreadedWriter(writer, backgroundThread, 32768));

				// And now, swap over our active writer pointer so that the audio callback will start using it..
				const ScopedLock sl(writerLock);
				activeWriter = threadedWriter.get();
			}
		}
	}
}

void AudioRecorder::stop()
{
	// First, clear this pointer to stop the audio callback from using our writer object..
	{
		const ScopedLock sl(writerLock);
		activeWriter = nullptr;
	}

	// Now we can delete the writer object. It's done in this order because the deletion could
	// take a little time while remaining data gets flushed to disk, so it's best to avoid blocking
	// the audio callback while this happens.
	threadedWriter.reset();
}

bool AudioRecorder::isRecording() const
{
	return activeWriter != nullptr;
}

void AudioRecorder::filteredAudioSourceAboutToStart(double theSampleRate, int bufferSize)
{
	sampleRate = theSampleRate;
	if (bufferSize != numSamplesPerBufferInUse)
	{
		free(bufferForDataWGainApplied);
		bufferForDataWGainApplied = (float*)std::calloc(bufferSize, sizeof(float));
		numSamplesPerBufferInUse = bufferSize;
	}
}

void AudioRecorder::audioDeviceAboutToStart(AudioIODevice* device)
{
	sampleRate = device->getCurrentSampleRate();
	auto CurrentBufferSizeSamples = device->getCurrentBufferSizeSamples();
	if (CurrentBufferSizeSamples != numSamplesPerBufferInUse)
	{
		free(bufferForDataWGainApplied);
		bufferForDataWGainApplied = (float*)std::calloc(CurrentBufferSizeSamples, sizeof(float));
		numSamplesPerBufferInUse = CurrentBufferSizeSamples;
	}
}

void AudioRecorder::audioDeviceStopped()
{
	sampleRate = 0;
}

inline float AudioRecorder::findMaxLevel(const float* inputData, int numSamples)
{
	return abs(*std::max_element(inputData, inputData + numSamples, [](float a, float b) { return (std::abs(a) < std::abs(b)); }));
}


inline void AudioRecorder::applyGain(const float* inputData, float* outputData, int numSamples)
{
	if (autoGain)
	{
		gainToUse = 1.0f / findMaxLevel(inputData, numSamples);
	}

#if (JUCE_WINDOWS && _DEBUG)
	std::transform
	(
		stdext::make_unchecked_array_iterator(inputData)
		, stdext::make_unchecked_array_iterator(inputData + numSamples)
		, stdext::make_unchecked_array_iterator(outputData)
		, [&](float inputDataElement) { return inputDataElement * gainToUse; }
	);
#else // (JUCE_WINDOWS && _DEBUG)
	std::transform
	(
		inputData, inputData + numSamples, outputData, [&](float inputDataElement) { return inputDataElement * gainToUse; }
	);
#endif // (JUCE_WINDOWS && _DEBUG)
}


void AudioRecorder::audioDeviceIOCallbackWithContext(const float* const* inputChannelData, int numInputChannels,
	float* const* outputChannelData, int numOutputChannels,
	int numSamples, const AudioIODeviceCallbackContext& context)
{
	ignoreUnused(context);

	auto RecordingLevelMeterIsShowing = (pRecordingLevelMeter.lock()) && (pRecordingLevelMeter.lock()->isShowing());

	if (isRecording() || RecordingLevelMeterIsShowing)
	{
		applyGain(*inputChannelData, bufferForDataWGainApplied, numSamples);

		// record
		if (isRecording())
		{
			const ScopedLock sl(writerLock);

			if (activeWriter != nullptr && numInputChannels > 0)
			{
				activeWriter->write(&bufferForDataWGainApplied, numSamples);
			}
		}

		// Update level meter and/or gain
		if (RecordingLevelMeterIsShowing)
		{
			pRecordingLevelMeter.lock()->updateLevelMeter(findMaxLevel(bufferForDataWGainApplied, numSamples));
		}
	}

	// We need to clear the output buffers, in case they're full of junk..
	for (int i = 0; i < numOutputChannels; ++i)
		if (outputChannelData[i] != nullptr)
			FloatVectorOperations::clear(outputChannelData[i], numSamples);

}

void AudioRecorder::recordFilteredAudio(float* inputData)
{
	auto RecordingLevelMeterIsShowing = pRecordingLevelMeter.lock()->isShowing();

	if (isRecording() || RecordingLevelMeterIsShowing)
	{
		// Apply gain
		applyGain(inputData, bufferForDataWGainApplied, numSamplesPerBufferInUse);

		// record
		if (isRecording())
		{
			const ScopedLock sl(writerLock);

			if (activeWriter != nullptr)
			{
				activeWriter->write(&bufferForDataWGainApplied, numSamplesPerBufferInUse);
			}
		}

		// Update level meter and/or gain
		if (RecordingLevelMeterIsShowing)
		{
			pRecordingLevelMeter.lock()->updateLevelMeter(findMaxLevel(bufferForDataWGainApplied, numSamplesPerBufferInUse));
		}
	}
}

void AudioRecorder::setRecordingGain(float thegainToUse)
{
	if (thegainToUse == 0.0f)
	{
		gainToUse = 0.0f;
		autoGain = true;
	}
	else
	{
		gainToUse = thegainToUse;
		autoGain = false;
	}
}

float AudioRecorder::getCurrentRecordingGain()
{
	return gainToUse;
}

void AudioRecorder::setAutoGainOn(bool setAutoGainOn)
{
	autoGain = setAutoGainOn;
}

void AudioRecorder::setCalcCurrentMaxLevel(bool shouldBeCalculated)
{
	calculateCurrentMaxLevel = shouldBeCalculated;
}

float AudioRecorder::getCurrentMaxLevel()
{
	return CurrentMaxLevel;
}

//==============================================================================
extern std::shared_ptr<AudioDeviceManager> sharedAudioDeviceManager;

AudioRecorderControl::AudioRecorderControl()
{
}

AudioRecorderControl::~AudioRecorderControl()
{
	sharedAudioDeviceManager->removeAudioCallback(spRecorder.get());
	if (spRecorder->isRecording())
	{
		stopRecording();
	}

	if (spRecorder)
	{
		spRecorder = nullptr;
		spRecorder.reset();
	}

	if (myChooser)
	{
		myChooser = nullptr;
		myChooser.reset();
	}

}

void AudioRecorderControl::setSourceRaw()
{
	sharedAudioDeviceManager->addAudioCallback(spRecorder.get());
}


void AudioRecorderControl::setSourceFiltered()
{
	sharedAudioDeviceManager->removeAudioCallback(spRecorder.get());
}

void AudioRecorderControl::StopAudioDeviceIOCallback()
{
	sharedAudioDeviceManager->removeAudioCallback(spRecorder.get());
}

void AudioRecorderControl::filteredAudioSourceAboutToStart(double theSampleRate, int bufferSize)
{
	spRecorder->filteredAudioSourceAboutToStart(theSampleRate, bufferSize);
}

void AudioRecorderControl::startAudioRecorderRecording()
{
	if (!spRecorder->isRecording())
	{
		startRecording();
	}
}

void AudioRecorderControl::stopAudioRecorderRecording()
{
	if (spRecorder->isRecording())
	{
		stopRecording();
	}
}

void AudioRecorderControl::recordFilteredAudio(float* inputChannelData)
{
	spRecorder->recordFilteredAudio(inputChannelData);
}

void AudioRecorderControl::setRecordingGain(float thegainToUse)
{
	spRecorder->setRecordingGain(thegainToUse);
}

float AudioRecorderControl::getCurrentRecordingGain()
{
	return spRecorder->getCurrentRecordingGain();
}

void AudioRecorderControl::setAutoGainOn(bool setAutoGainOn)
{
	spRecorder->setAutoGainOn(setAutoGainOn);
}

void AudioRecorderControl::startRecording()
{
	if
		(
			!(
				RuntimePermissions::isGranted(RuntimePermissions::writeExternalStorage)
				&&
				RuntimePermissions::isGranted(RuntimePermissions::readExternalStorage)
				)
			)
	{
		SafePointer<AudioRecorderControl> safeThis(this);

		if (!RuntimePermissions::isGranted(RuntimePermissions::writeExternalStorage))
		{

			RuntimePermissions::request(RuntimePermissions::writeExternalStorage,
				[safeThis](bool granted) mutable
				{
					if (granted)
						safeThis->startRecording();
				});
			return;
		}
		if (!RuntimePermissions::isGranted(RuntimePermissions::readExternalStorage))
		{

			RuntimePermissions::request(RuntimePermissions::readExternalStorage,
				[safeThis](bool granted) mutable
				{
					if (granted)
						safeThis->startRecording();
				});
			return;
		}
	}

	auto parentDir = File::getSpecialLocation(File::tempDirectory);

	lastRecording = parentDir.getChildFile("guitarFineTune_Audio_Recording.wav");
	if (lastRecording.existsAsFile())
	{
		lastRecording.deleteFile();
	}

	spRecorder->startRecording(lastRecording);
}


void AudioRecorderControl::stopRecording()
{
	spRecorder->stop();

#if (JUCE_IOS)
	SafePointer<AudioRecorderControl> safeThis(this);
	File fileToShare = lastRecording;

	ContentSharer::shareFilesScoped(Array<URL>({ URL(fileToShare) }),
		[safeThis, fileToShare](bool success, const String& error)
		{
			if (fileToShare.existsAsFile())
				fileToShare.deleteFile();

			if (!success && error.isNotEmpty())
			{
				NativeMessageBox::showMessageBoxAsync(AlertWindow::WarningIcon,
					"Sharing Error",
					error);
			}
		});
#else

	File fileToSave = lastRecording;
	lastRecording = File(); // "Close" fille
	auto theRecordedFile = fileToSave.getFullPathName();

	juce::File initialFilAndDirectory;



#if (JUCE_ANDROID)
	myChooser =
		std::make_unique <FileChooser>
		(
			"Save Audio File as..."
			,
			fileToSave
			,
			"*.wav"
		);

	myChooser->launchAsync
	(
		FileBrowserComponent::saveMode
		|
		FileBrowserComponent::canSelectFiles
		|
		FileBrowserComponent::warnAboutOverwriting
		,
		[fileToSave](const FileChooser& chooser)
		{
			auto result = chooser.getURLResult();
			auto name = result.isEmpty() ? String()
				: (result.isLocalFile() ? result.getLocalFile().getFullPathName()
					: result.toString(true));

			// Android and iOS file choosers will create placeholder files for chosen
			// paths, so we may as well write into those files.
			if (!result.isEmpty())
			{
				std::unique_ptr<InputStream>  wi(fileToSave.createInputStream());
				std::unique_ptr<OutputStream> wo(result.createOutputStream());

				if (wi.get() != nullptr && wo.get() != nullptr)
				{
					auto numWritten = wo->writeFromInputStream(*wi, -1);
					jassertquiet(numWritten > 0);
					wo->flush();
				}
			}

//			AlertWindow::showAsync(MessageBoxOptions()
//				.withIconType(MessageBoxIconType::InfoIcon)
//				.withTitle("File Chooser...")
//				.withMessage("You picked: " + name)
//				.withButton("OK"),
//				nullptr);
		}
	);
#else
#if (JUCE_LINUX)

	juce::String snapHome(std::getenv("SNAP_REAL_HOME"));
	snapHome += '/';

	if (snapHome != "")
	{
		initialFilAndDirectory =
			juce::File(snapHome).getChildFile(fileToSave.getFileName());
	}
	else
	{
		initialFilAndDirectory =
			File::getSpecialLocation
			(
				File::userMusicDirectory
			).getChildFile
			(
				fileToSave.getFileName()
			);
	}
#else
	initialFilAndDirectory =
		File::getSpecialLocation
		(
			File::userMusicDirectory
		).getChildFile
		(
			fileToSave.getFileName()
		);
#endif // #if (JUCE_LINUX)

	myChooser =
	std::make_unique <FileChooser>
	(
		"Save Audio File as..."
		,
		initialFilAndDirectory
		,
		"*.wav"
	);

	myChooser->launchAsync
	(
		FileBrowserComponent::saveMode
		|
		FileBrowserComponent::canSelectFiles
		|
		FileBrowserComponent::warnAboutOverwriting
		,
		[fileToSave](const FileChooser& chooser)
		{
			auto rslt = chooser.getResult();
			if (rslt == File{})
				return;

			File soundFile(rslt);

			fileToSave.moveFileTo(soundFile);
		}
	);
#endif // #if (JUCE_ANDROID)
#endif // #if (JUCE_IOS)
}


void AudioRecorderControl::setCalcCurrentMaxLevel(bool shouldBeCalculated)
{
	spRecorder->setCalcCurrentMaxLevel(shouldBeCalculated);
}

float AudioRecorderControl::getCurrentMaxLevel()
{
	return spRecorder->getCurrentMaxLevel();
}
