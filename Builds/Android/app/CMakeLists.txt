# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "juce_jni")

add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")
set_source_files_properties("${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c" PROPERTIES COMPILE_FLAGS "-Wno-sign-conversion -Wno-gnu-statement-expression")

add_definitions("-DJUCE_ANDROID=1" "-DJUCE_ANDROID_API_VERSION=16" "-DJUCE_CONTENT_SHARING=1" "-DANDROID_VERSION_CODE=34" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=8.3.1" "-DJUCE_APP_VERSION_HEX=0x80301")

include_directories( AFTER
    "../../../JuceLibraryCode"
    "D:/Users/eigil/projects/juceProjs/REFguitarFineTune/JUCE/modules"
    "${ANDROID_NDK}/sources/android/cpufeatures"
)

enable_language(ASM)

if(JUCE_BUILD_CONFIGURATION MATCHES "RELEASE")
    add_definitions("-DANDROID_VERSION_CODE=34" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=8.3.1" "-DJUCE_APP_VERSION_HEX=0x80301" "-DNDEBUG=1")
elseif(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    add_definitions("-DANDROID_VERSION_CODE=34" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=8.3.1" "-DJUCE_APP_VERSION_HEX=0x80301" "-DDEBUG=1" "-D_DEBUG=1")
else()
    message( FATAL_ERROR "No matching build-configuration found." )
endif()

add_library( ${BINARY_NAME}

    SHARED

    "../../../iOS_Special/Launch Screen.storyboard"
    "../../../Source/AudioRecorder.cpp"
    "../../../Source/AudioRecorder.h"
    "../../../Source/audioRecorderThread.cpp"
    "../../../Source/audioRecorderThread.h"
    "../../../Source/helpPage.cpp"
    "../../../Source/helpPage.h"
    "../../../Source/AssocVector.h"
    "../../../Source/decimationAndFilterConstants.h"
    "../../../Source/displayControlComponent.cpp"
    "../../../Source/displayControlComponent.h"
    "../../../Source/eksAudioControlComponent.cpp"
    "../../../Source/eksAudioControlComponent.h"
    "../../../Source/eksLookAndFeel.h"
    "../../../Source/eksNotModalProgressWindow.cpp"
    "../../../Source/eksNotModalProgressWindow.h"
    "../../../Source/eksNotModalProgressWindowCallBacks.cpp"
    "../../../Source/eksNotModalProgressWindowCallBacks.h"
    "../../../Source/eksTabbedComponent.cpp"
    "../../../Source/eksTabbedComponent.h"
    "../../../Source/eksThreadWithProgressWindow.cpp"
    "../../../Source/eksThreadWithProgressWindow.h"
    "../../../Source/Factory.h"
    "../../../Source/gfft.h"
    "../../../Source/guitarFineTuneFirstClass.cpp"
    "../../../Source/guitarFineTuneFirstClass.h"
    "../../../Source/guitarFineTuneGlobalEnums.h"
    "../../../Source/guitarStringSoundsControl.cpp"
    "../../../Source/guitarStringSoundsControl.h"
    "../../../Source/LokiTypeInfo.h"
    "../../../Source/Main.cpp"
    "../../../Source/NullType.h"
    "../../../Source/post_decimation_NOTCH_filters_Coeffs.h"
    "../../../Source/pre_decimation_FIR_filter_Coeffs.h"
    "../../../Source/SimpleLevelMeter.cpp"
    "../../../Source/SimpleLevelMeter.h"
    "../../../Source/tuneComponent.cpp"
    "../../../Source/tuneComponent.h"
    "../../../Source/Typelist.h"
    "../../../Source/TypeManip.h"
    "../../../Source/xmlGuitarFineTuneConfig.cpp"
    "../../../Source/xmlGuitarFineTuneConfig.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_ADSR.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Decibels.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_GenericInterpolator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Reverb.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPacket.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPackets.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPConversion.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPConverters.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPDispatcher.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPFactory.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPIterator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToBytestreamTranslator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPProtocols.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPReceiver.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPSysEx7.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPSysEx7.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPUtils.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPUtils.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPView.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPView.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Definitions.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Oboe.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Utilities.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Version.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioClock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/OboeDebug.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Utilities.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Version.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/CMakeLists.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/readme.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/all.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/assert.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/callback.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/compat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/export.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/format.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/crctable.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/README.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/README.md"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AU_Shared.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Array.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayBase.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_OwnedArray.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SparseSet.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_File.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_File.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Random.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Range.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_AllocationHooks.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_AllocationHooks.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_ConsoleApplication.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Result.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/java/README.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_IPAddress.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_wasm_SystemStats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_Socket.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_URL.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_CompilerWarnings.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Base64.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_String.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_String.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Process.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_WaitableEvent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_Time.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTestCategories.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_Message.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngdebug.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Displays.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_linux_Windowing.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_HWNDComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_HWNDComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../../JuceLibraryCode/AppConfig.h"
    "../../../JuceLibraryCode/BinaryData.cpp"
    "../../../JuceLibraryCode/BinaryData.h"
    "../../../JuceLibraryCode/include_juce_audio_basics.cpp"
    "../../../JuceLibraryCode/include_juce_audio_devices.cpp"
    "../../../JuceLibraryCode/include_juce_audio_formats.cpp"
    "../../../JuceLibraryCode/include_juce_audio_processors.cpp"
    "../../../JuceLibraryCode/include_juce_audio_utils.cpp"
    "../../../JuceLibraryCode/include_juce_core.cpp"
    "../../../JuceLibraryCode/include_juce_data_structures.cpp"
    "../../../JuceLibraryCode/include_juce_events.cpp"
    "../../../JuceLibraryCode/include_juce_graphics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_basics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_extra.cpp"
    "../../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties("../../../iOS_Special/Launch Screen.storyboard" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/AudioRecorder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/audioRecorderThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/helpPage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/AssocVector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/decimationAndFilterConstants.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/displayControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksAudioControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksLookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksNotModalProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksNotModalProgressWindowCallBacks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksTabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/eksThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Factory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/gfft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/guitarFineTuneFirstClass.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/guitarFineTuneGlobalEnums.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/guitarStringSoundsControl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/LokiTypeInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/NullType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/post_decimation_NOTCH_filters_Coeffs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/pre_decimation_FIR_filter_Coeffs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/SimpleLevelMeter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/tuneComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Typelist.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/TypeManip.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/xmlGuitarFineTuneConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/audio_play_head/juce_AudioPlayHead.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioChannelSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioDataConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioProcessLoadMeasurer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_AudioSampleBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/buffers/juce_FloatVectorOperations.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiKeyboardState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiMessageSequence.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/midi/juce_MidiRPN.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEInstrument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEMessages.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPENote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPESynthesiserVoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/mpe/juce_MPEZoneLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/native/juce_mac_CoreAudioLayouts.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_AudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_BufferingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ChannelRemappingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_IIRFilterAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MemoryAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_MixerAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_PositionableAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ResamplingAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ReverbAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/sources/juce_ToneGeneratorAudioSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/synthesisers/juce_Synthesiser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_ADSR.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Decibels.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_GenericInterpolator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_IIRFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Interpolators.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_LagrangeInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_Reverb.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_SmoothedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/utilities/juce_WindowedSincInterpolator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_basics/juce_audio_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioDeviceManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODevice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/audio_io/juce_SystemAudioVolume.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPacket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPackets.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPBytestreamInputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPConversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPConverters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPDispatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToBytestreamTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToMidi2DefaultTranslator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPMidi1ToMidi2DefaultTranslator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPProtocols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPReceiver.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPSysEx7.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPSysEx7.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPU32InputHandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPUtils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPUtils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/ump/juce_UMPView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiDevices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/midi_io/juce_MidiMessageCollector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/AudioStreamCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Definitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/LatencyTuner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Oboe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/ResultWithValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/StabilizedCallback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Utilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/include/oboe/Version.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AAudioLoader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/aaudio/AudioStreamAAudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioClock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioSourceCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/AudioStreamBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/DataConversionFlowGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FilterAudioStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockAdapter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/FixedBlockWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/LatencyTuner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/MonotonicCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/OboeDebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/QuirksManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceFloatCaller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/SourceI16Caller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/StabilizedCallback.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Trace.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Utilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/common/Version.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoController.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/fifo/FifoControllerIndirect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/HyperbolicCosineWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/IntegerRatio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/KaiserWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/LinearResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/MultiChannelResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerMono.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/PolyphaseResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/resampler/SincResamplerStereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ChannelCountConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ClipToRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/FlowGraphNode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/ManyToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MonoToMultiConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/MultiToMonoConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/RampLinear.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SampleRateConverter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SinkI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/flowgraph/SourceI24.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioInputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioOutputStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamBuffered.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/AudioStreamOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/EngineOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OpenSLESUtilities.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/src/opensles/OutputMixerOpenSLES.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/CMakeLists.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/oboe/readme.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_HighPerformanceAudioHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_Oboe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_android_OpenSL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_ios_Audio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_ALSA.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_Bela.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_linux_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_mac_CoreAudio.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_mac_CoreMidi.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_MidiDataConcatenator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_ASIO.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_DirectSound.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_Midi.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/native/juce_win32_WASAPI.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioSourcePlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/sources/juce_AudioTransportSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_devices/juce_audio_devices.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitmath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitreader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/bitwriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/cpu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/crc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/fixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/float.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/md5.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/stream_encoder_framing.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/private/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/include/protected/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitmath.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitreader.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/bitwriter.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/cpu.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/crc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/fixed.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/float.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/format.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/lpc_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/md5.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/memory.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_decoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/stream_encoder_framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/libFLAC/window_flac.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/alloc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/assert.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/callback.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/compat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/endswap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/export.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/Flac Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/format.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/metadata.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/ordinals.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/stream_decoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/stream_encoder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/flac/win_utf8_io.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/coupled/res_books_stereo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/floor/floor_books.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/books/uncoupled/res_books_uncoupled.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/floor_all.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/psych_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/residue_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_22.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44p51.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_44u.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/modes/setup_X.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/analysis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/backends.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/bitrate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/block.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codebook.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/codec_internal.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/envelope.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/floor1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/highlevel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/info.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lookup_data.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lpc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/lsp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mapping0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/masking.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/mdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/misc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/os.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/psy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/registry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/res0.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/scales.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/sharedbook.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/smallft.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/synthesis.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisenc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/vorbisfile.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/lib/window.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/libvorbis-1.3.7/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/bitwise.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/codec.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/config_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/crctable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/framing.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/Ogg Vorbis Licence.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/ogg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/os_types.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisenc.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/oggvorbis/vorbisfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_AiffAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_CoreAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_FlacAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_LAMEEncoderAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_MP3AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_OggVorbisAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WavAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/codecs/juce_WindowsMediaAudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatReaderSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioFormatWriter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_AudioSubsectionReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_BufferingAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/format/juce_MemoryMappedAudioFormatReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/sampler/juce_Sampler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_formats/juce_audio_formats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format/juce_AudioPluginFormatManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/baseiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/classfactoryhelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fbuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fobject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstreamer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/fstring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/source/updatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/include/flock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/thread/source/flock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/base/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/conststringtable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/coreiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/falignpush.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fplatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fstrdefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ftypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/funknown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/futils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/fvariant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ibstream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/icloneable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipersistent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ipluginbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/istringresult.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/iupdatehandler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/smartpointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/typesizecheck.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/base/ustring.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/gui/iplugviewcontentscalesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstattributes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstaudioprocessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstautomationstate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstchannelcontextinfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstcontextmenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstevents.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsthostapplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstinterappaudio.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidicontrollers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstmidilearn.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstnoteexpression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstparameterchanges.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstphysicalui.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstpluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstplugview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprefetchablesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstprocesscontext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstrepresentation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivsttestplugprovider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/ivstunits.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstpshpack4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vstspeaker.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/vst/vsttypes.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/pluginterfaces/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/memorystream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/common/pluginview.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/hostclasses.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/hosting/pluginterfacesupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstbus.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstcomponentbase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vsteditcontroller.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstinitiids.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstparameters.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/source/vst/vstpresetfile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/public.sdk/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/LICENSE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/VST3_SDK/README.md" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AU_Shared.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_AudioUnitPluginFormat.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LADSPAPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_LegacyAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3Common.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3Headers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VST3PluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTCommon.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTMidiEventList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/format_types/juce_VSTPluginFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioPluginInstance.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorGraph.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_AudioProcessorParameterGroup.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_GenericAudioProcessorEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/processors/juce_PluginDescription.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_KnownPluginList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginDirectoryScanner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/scanning/juce_PluginListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterBool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterChoice.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterFloat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioParameterInt.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorParameterWithID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_AudioProcessorValueTreeState.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_ParameterAttachments.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_PluginHostType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/utilities/juce_RangedAudioParameter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_processors/juce_audio_processors.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDBurner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/audio_cd/juce_AudioCDReader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioDeviceSelectorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnail.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioThumbnailCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_AudioVisualiserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_BluetoothMidiDevicePairingDialogue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/gui/juce_MidiKeyboardComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_android_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_ios_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_linux_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_linux_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDBurner.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_AudioCDReader.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_mac_BluetoothMidiDevicePairingDialogue.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win_BluetoothMidiDevicePairingDialogue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDBurner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/native/juce_win32_AudioCDReader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_AudioProcessorPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/players/juce_SoundPlayer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_audio_utils/juce_audio_utils.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ArrayBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_OwnedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_RangedDirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_AllocationHooks.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_AllocationHooks.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_ConsoleApplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/java/README.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_wasm_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_CompilerWarnings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_WaitableEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/unit_tests/juce_UnitTestCategories.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngdebug.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/desktop/juce_Displays.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_X11_Symbols.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_linux_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_ScopedThreadDPIAwarenessSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_HWNDComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_HWNDComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../REFguitarFineTune/JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/BinaryData.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

target_compile_options( ${BINARY_NAME} PRIVATE "-fsigned-char" )

if( JUCE_BUILD_CONFIGURATION MATCHES "RELEASE" )
    target_compile_options( ${BINARY_NAME} PRIVATE)
endif()

if( JUCE_BUILD_CONFIGURATION MATCHES "DEBUG" )
    target_compile_options( ${BINARY_NAME} PRIVATE)
endif()

find_library(log "log")
find_library(android "android")
find_library(glesv2 "GLESv2")
find_library(egl "EGL")

target_link_libraries( ${BINARY_NAME}

    ${log}
    ${android}
    ${glesv2}
    ${egl}
    "cpufeatures"
)
