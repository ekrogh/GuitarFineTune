/*
  ==============================================================================

  08. nov. 2016
	Eigil Krogh Sorensen

  ==============================================================================
*/
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES // For use in math.h
#endif // !_USE_MATH_DEFINES

#define SHOWGOERTZELVALUES false

//#if ((defined (_WIN32) || defined (_WIN64)) && _DEBUG)
//#include "vld.h"
//#endif //  (JUCE_WINDOWS && _DEBUG)

#include "../JuceLibraryCode/JuceHeader.h"


#include "xmlGuitarFineTuneConfig.h"
#include "displayControlComponent.h"
#include "eksThreadWithProgressWindow.h"
#include "eksNotModalProgressWindow.h"
#include "AudioRecorder.h"
#include "audioRecorderThread.h"
#include "tuneComponent.h"


extern std::shared_ptr<AudioDeviceManager> sharedAudioDeviceManager;
extern bool errorInGetSharedAudioDeviceManager;


tuneComponent::tuneComponent
(
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig
#if ( JUCE_IOS )
	, Component::SafePointer<guitarFineTuneFirstClass> pGuitarFineTuneFirstClass
#endif // #if ( JUCE_IOS )
)
	: Thread( "Tune_Spectrogram_Drawings" )
    , AudioAppComponent( *sharedAudioDeviceManager )
    #if ( JUCE_IOS )
        , ptrGuitarFineTuneFirstClass( pGuitarFineTuneFirstClass )
    #endif // #if ( JUCE_IOS )
	, pXmlGuitarFineTuneConfig( pXmlGFTConfig )
{
	if ( errorInGetSharedAudioDeviceManager )
	{
		return;
	}
	setOpaque( true );


#if (JUCE_IOS || JUCE_ANDROID)
	{
		Rectangle<int> r = Desktop::getInstance( ).getDisplays( ).getPrimaryDisplay()->userArea;
		double sizeScale;
		sizeScale = (double)( r.getWidth( ) ) / (double)widthOfTuneWindow;
		setSize( (int)( widthOfTuneWindow * sizeScale ), (int)( hightOfTuneWindow * sizeScale ) );
	}
#else
	{
		setSize( widthOfTuneWindow, hightOfTuneWindow );
	}
#endif

	//EKSFONTHER
#if (JUCE_IOS || JUCE_ANDROID)
	defaultFontOfSpectrImGraphcs = spectrImGraphcs.getCurrentFont( );
	hightOfDefaultFontOfSpectrImGraphcs = defaultFontOfSpectrImGraphcs.getHeight( );
	spectrImGraphcs.setFont( hightOfDefaultFontOfSpectrImGraphcs * 2 );
#endif // (JUCE_IOS || JUCE_ANDROID)
	defaultFontOfSpectrImGraphcs = spectrImGraphcs.getCurrentFont( );
	hightOfDefaultFontOfSpectrImGraphcs = defaultFontOfSpectrImGraphcs.getHeight( );
	strHalfStringNamesWidth = (int)( defaultFontOfSpectrImGraphcs.getStringWidthFloat( "D3" ) / 2 );

	spAudioRecorderController = std::make_shared<AudioRecorderControl>( );

	makeHannWinCoefficients();

}


void tuneComponent::modalStateFinished( int /*result*/ )
{
//    sharedAudioDeviceManager->closeAudioDevice();
//    JUCEApplication::getInstance( )->systemRequestedQuit( );
}


bool tuneComponent::openAudioDeviceThatWillOpenWithLegalSampleRate( )
{
	using namespace decimationAndFilterConstants;

	String possibleErrorOfSetAudioDeviceSetup = String( );
	String errorInitDevMgr = String( );

	juce::AudioDeviceManager::AudioDeviceSetup currentAudioConfig;

	bool foundUseableAudioDevice = false;
	// Default system audio device couldn't be initialized. Try with the others
	const OwnedArray<juce::AudioIODeviceType>& availableDeviceTypes = sharedAudioDeviceManager->getAvailableDeviceTypes( );

	// Try every combination of device type, output and input
	for ( auto availableDeviceType : availableDeviceTypes )
	{
		StringArray outputNamesOfDeviceType( availableDeviceType->getDeviceNames( false ) );
		StringArray inputNamesOfDeviceType( availableDeviceType->getDeviceNames( true ) );

		// For all output/input combination
		for ( auto outputName : outputNamesOfDeviceType )
		{
			for ( auto inputName : inputNamesOfDeviceType )
			{
				sharedAudioDeviceManager->setCurrentAudioDeviceType( availableDeviceType->getTypeName( ), true );
				// Get current audio config for modification
				sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );
				currentAudioConfig.outputDeviceName = outputName;
				currentAudioConfig.inputDeviceName = inputName;
				currentAudioConfig.sampleRate = 44100;
				// Try the combinations
				if ( ( possibleErrorOfSetAudioDeviceSetup = sharedAudioDeviceManager->setAudioDeviceSetup( currentAudioConfig, true ) ).isEmpty( ) )
				{
					if (
						(
							std::find
							(
								legalSampleFrequencies.begin( )
								, legalSampleFrequencies.end( )
								, sharedAudioDeviceManager->getCurrentAudioDevice( )->getCurrentSampleRate( )
							) != legalSampleFrequencies.end( )
							)
						)
					{
						std::unique_ptr<XmlElement> audioState( sharedAudioDeviceManager->createStateXml( ) );
						setAudioChannels( numInputChannels, numOutputChannels, audioState.get( ) );
						//setAudioChannels( numInputChannels, numOutputChannels );

						if ( sharedAudioDeviceManager->getAudioDeviceSetup( ).inputDeviceName == "" )
						{
							foundUseableAudioDevice = true;
							break; // Break for loop
						}
						//errorInitDevMgr = setAudioChannels(2, 2, audioState.get());
						//if (errorInitDevMgr.isEmpty())
						//{
						//	foundUseableAudioDevice = true;
						//	break; // Break for loop
						//}
					}
				}
			}
			if ( foundUseableAudioDevice )
			{
				break;
			}
		}
		if ( foundUseableAudioDevice )
		{
			break;
		}
	}

	if ( !foundUseableAudioDevice )
	{
	#if JUCE_MODAL_LOOPS_PERMITTED
		juce::AlertWindow::showMessageBox
		(
			juce::AlertWindow::WarningIcon
			, "Found no usable audio device!"
			, "Try to connect another\naudio device"
			, "Quit"
			, nullptr
		);
	#else
		juce::AlertWindow::showMessageBoxAsync
		(
			juce::AlertWindow::WarningIcon
			, "Found no usable audio device!"
			, "Try to connect another\naudio device"
			, "Quit"
			, nullptr
		);
	#endif
		return false;
	}

	return true;
}


bool tuneComponent::audioSysInit( )
{
	if ( ( sharedAudioDeviceManager->initialise( numInputChannels, numOutputChannels, nullptr, true, {}, nullptr ) ).isNotEmpty( ) )
	{
		if ( !openAudioDeviceThatWillOpenWithLegalSampleRate( ) )
		{
            sharedAudioDeviceManager->closeAudioDevice();
			JUCEApplication::getInstance( )->systemRequestedQuit( );
			return false;
		}
	}

    // Save current audio config
	audioDeviceTypeAtStartUp = sharedAudioDeviceManager->getCurrentAudioDeviceType( );

	setAudioChannels( numInputChannels, numOutputChannels );

	sharedAudioDeviceManager->getAudioDeviceSetup( audioConfigAtStartUp );
	if ( audioConfigAtStartUp.inputDeviceName == "" )
	{
		if ( !openAudioDeviceThatWillOpenWithLegalSampleRate( ) )
		{
            sharedAudioDeviceManager->closeAudioDevice();
			JUCEApplication::getInstance( )->systemRequestedQuit( );
			return false;
		}
	}

	currentaudioDeviceTypeInUse = ( sharedAudioDeviceManager->getCurrentAudioDeviceType( ) ).toStdString( );

	// Get current audio config for modification
	juce::AudioDeviceManager::AudioDeviceSetup currentAudioConfig = sharedAudioDeviceManager->getAudioDeviceSetup( );

	//#if !(JUCE_IOS || JUCE_ANDROID)
	// Get buffer sizes
	juce::Array<int> availableBufferSizes( sharedAudioDeviceManager->getCurrentAudioDevice( )->getAvailableBufferSizes( ) );
	availableBufferSizes.sort( );
	// Get sample rates
	juce::Array<double> availableSampleRates( sharedAudioDeviceManager->getCurrentAudioDevice( )->getAvailableSampleRates( ) );
	availableSampleRates.sort( );
	//#endif // !(JUCE_IOS || JUCE_ANDROID)
#if JUCE_WINDOWS
	{
		//const StringArray devs(type.getDeviceNames(isInputs));
		// Get input channel names
		StringArray availableInputChannelNames( sharedAudioDeviceManager->getCurrentDeviceTypeObject( )->getDeviceNames( true ) );
		// Get output channel names
		StringArray availableOutputChannelNames( sharedAudioDeviceManager->getCurrentDeviceTypeObject( )->getDeviceNames( false ) );

		// Set i/o devices to None
		currentAudioConfig.inputDeviceName = "";
		currentAudioConfig.outputDeviceName = "";

		// Make the changes
		String possibleError = sharedAudioDeviceManager->setAudioDeviceSetup( currentAudioConfig, true );
		if ( possibleError.isNotEmpty( ) )
		//{
		//	//int lastIndxOfSound = possibleError.lastIndexOfIgnoreCase("Sound");
		//	//if (lastIndxOfSound > 0)
		//	//{
		//	//	possibleError = possibleError.replaceSection(possibleError.indexOfChar(lastIndxOfSound, ' '), 1, "\n");
		//	//}
		//	AlertWindow::showOkCancelBox
		//	(
		//		AlertWindow::WarningIcon
		//		, TRANS("Error when trying to\nconfigure audio!")
		//		, possibleError + "\nHave you enabled access to the Microphone in Privacy Settings?"
		//		, ""
		//		, ""
		//		, nullptr
		//		, nullptr
		//	);
		//}
		// Reconfigure to preferred
			sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );

			// Select buffer size
		currentAudioConfig.bufferSize = availableBufferSizes.getLast( );
		if ( currentAudioConfig.bufferSize > preferreAudioBufferSize )
		{
			if ( availableBufferSizes.indexOf( preferreAudioBufferSize ) >= 0 )
			{
				currentAudioConfig.bufferSize = preferreAudioBufferSize;
			}
		}

		// Select lowest sample rate
		availableSampleRates.sort( );
		currentAudioConfig.sampleRate = availableSampleRates.getFirst( );
		if ( currentAudioConfig.sampleRate < 44100 )
		{
			currentAudioConfig.sampleRate = 44100;
		}

		// Select Input Channel
		if ( availableInputChannelNames.indexOf( "Primary Sound Capture Driver" ) >= 0 )
		{
			currentAudioConfig.inputDeviceName = "Primary Sound Capture Driver";
		}

		// Select Output Channel
		if ( availableOutputChannelNames.indexOf( "Primary Sound Driver" ) >= 0 )
		{
			currentAudioConfig.outputDeviceName = "Primary Sound Driver";
		}

		// Make the changes
		possibleError = sharedAudioDeviceManager->setAudioDeviceSetup( currentAudioConfig, true );
		if ( possibleError.isNotEmpty( ) )
		{
			//int lastIndxOfSound = possibleError.lastIndexOfIgnoreCase("Sound");
			//if (lastIndxOfSound > 0)
			//{
			//	possibleError = possibleError.replaceSection(possibleError.indexOfChar(lastIndxOfSound, ' '), 1, "\n");
			//}
			AlertWindow::showOkCancelBox
			(
				AlertWindow::WarningIcon
				, TRANS( "Error when trying to\nconfigure audio!" )
				, possibleError + "\nHave you enabled access to the Microphone in Privacy Settings?"
				, ""
				, ""
				, nullptr
				, nullptr
			);
		}
		// Get the actual config.
		sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );
	}
#else
	{
	#if !JUCE_ANDROID
		// Select buffer size
		currentAudioConfig.bufferSize = availableBufferSizes.getLast( );
		if ( currentAudioConfig.bufferSize > preferreAudioBufferSize )
		{
			if ( availableBufferSizes.indexOf( preferreAudioBufferSize ) >= 0 )
			{
				currentAudioConfig.bufferSize = preferreAudioBufferSize;
			}
		}
	#endif // !JUCE_ANDROID

	#if !(JUCE_IOS || JUCE_ANDROID)
		// Select lowest sample rate
		availableSampleRates.sort( );
		currentAudioConfig.sampleRate = availableSampleRates.getFirst( );
		if ( currentAudioConfig.sampleRate < 44100 )
		{
			currentAudioConfig.sampleRate = 44100;
		}
	#endif // !(JUCE_IOS || JUCE_ANDROID)
		// Make the changes
		String possibleError = sharedAudioDeviceManager->setAudioDeviceSetup( currentAudioConfig, true );
		if ( possibleError.isNotEmpty( ) )
		{
			//int lastIndxOfSound = possibleError.lastIndexOfIgnoreCase("Sound");
			//if (lastIndxOfSound > 0)
			//{
			//	possibleError = possibleError.replaceSection(possibleError.indexOfChar(lastIndxOfSound, ' '), 1, "\n");
			//}
			AlertWindow::showOkCancelBox
			(
				AlertWindow::WarningIcon
				, TRANS( "Error when trying to\nconfigure audio!" )
				, possibleError
				, ""
				, ""
				, nullptr
				, nullptr
			);
		}
		// Get the actual config.
		sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );
	}
#endif // JUCE_WINDOWS

	currentBufferSizeInUse = currentAudioConfig.bufferSize;
	currentSampleRateInUse = currentAudioConfig.sampleRate;

#ifdef THIS_IS_IOS
	//sharedAudioDeviceManager->getCurrentAudioDevice()->setAirPlayBlueToothOn(airPlayAllowed, false);
	//sharedAudioDeviceManager->getCurrentAudioDevice()->setAirPlayBlueToothOn(airPlayAllowed, blueToothAllowed);
#endif // THIS_IS_IOS

	// ChangeListner = this
	sharedAudioDeviceManager->addChangeListener( this );
	startThread( 1 ); // priority 1


	return true;
}


void tuneComponent::saveThresholdForShowingResultsToXml( )
{
	unsigned int idxOfGuitarString = 0;
	for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
	{
		getXmlTagDISPLAYCONTROL( )->setAttribute
		(
			String( guitarStringNames[ idxOfGuitarString++ ] + "threshold" )
			, (double)goertzelStatistics.thresholdForShowingResultMagnitudeSquared
		);
	}
	// Write to xml file
	pXmlGuitarFineTuneConfig->writeConfigToXmlFile( );
}

tuneComponent::~tuneComponent( )
{
	weSpectrumDataReady.signal( );
	stopThread( -10 );
	shutdownAudio( );
	sharedAudioDeviceManager->closeAudioDevice( );
	 // Make thread shut down
	//stopThread( 6000 );

	if ( spTheAudioRecorderThread )
	{
		spTheAudioRecorderThread.reset( );
	}
	if ( spAudioRecorderController )
	{
		spAudioRecorderController.reset( );
	}

	if ( recorderSourceFilteredAudioOn )
	{
		spTheAudioRecorderThread.reset( );
		spTheAudioRecorderThread = nullptr;
		recorderSourceFilteredAudioOn = false;
	}
	std::free( audioRecordBuffer1 );
	audioRecordBuffer1 = nullptr;
	std::free( audioRecordBuffer2 );
	audioRecordBuffer2 = nullptr;

	// Finelize geortzel
	if ( adaptiveBackgroundSoundReductionIsOn )
	{
		saveThresholdForShowingResultsToXml( );
	}
	dqGoertzelBins1.clear( );
	dqGoertzelBins2.clear( );
	dqGoertzelResultStatistics.clear( );
	guitarStringsTonesXCoordsAndNames.clear( );

	if ( showFFTToggleButtonOn ) // FFT on ?
	{
		// Free resources
		delete gfft;
		gfft = nullptr;
	}
	std::free( fftDataBuffer1 );
	fftDataBuffer1 = nullptr;
	std::free( fftDataBuffer2 );
	fftDataBuffer2 = nullptr;
	

}


void tuneComponent::guitarStringsTonesXCoordsAndNamesCalc( )
{
	if ( guitarStringsTonesXCoordsAndNames.empty( ) )
	{
		GUITARSTRINGTONEXCOORDANDNAME sXN;
		for ( unsigned int guitarIndex = 0; guitarIndex < 6; guitarIndex++ )
		{
			sXN.stringXCoord = (float)( freqToXCoordFactor * ( (float)guitar[ guitarIndex ] - (float)lowestFreqToDisplayDataForHz ) );
			sXN.stringName = guitarStringNames[ guitarIndex ];
			guitarStringsTonesXCoordsAndNames.push_back( sXN );
		}
	}
	else
	{
		unsigned guitarIndex = 0;
		for ( auto& xCoordAndName : guitarStringsTonesXCoordsAndNames )
		{
			xCoordAndName.stringXCoord = (float)( freqToXCoordFactor * ( (float)guitar[ guitarIndex ] - (float)lowestFreqToDisplayDataForHz ) );
			xCoordAndName.stringName = guitarStringNames[ guitarIndex++ ];
		}
	}
}

bool tuneComponent::readFilterConstants( unsigned int FS )
{
	using namespace decimationAndFilterConstants;

	switch ( FS )
	{
		case 8000:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS8000;
				decimatedSampleRate = (double)decimatedFsAtFS8000;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS8000;
				break;
			}
		case 16000:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS16000;
				decimatedSampleRate = (double)decimatedFsAtFS16000;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS16000;
				break;
			}
		case 44100:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS44100;
				decimatedSampleRate = (double)decimatedFsAtFS44100;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS44100;
				break;
			}
		case 48000:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS48000;
				decimatedSampleRate = (double)decimatedFsAtFS48000;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS48000;
				break;
			}
		case 88200:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS88200;
				decimatedSampleRate = (double)decimatedFsAtFS88200;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS88200;
				break;
			}
		case 96000:
			{
				sampleSpace = sampleSpaceAtDecimatedFsAtFS96000;
				decimatedSampleRate = (double)decimatedFsAtFS96000;
				noCoeffsForPreDecimationFIRFilter = noCoeffsForPreDecimationFIRFilterAtFS96000;
				break;
			}
		default:
			{
				return false;
			}
	}

	if ( noSecondsSoundPerCalcComboBoxReady )
	{
		pDisplayControlComponent.lock( )->updateNoSecondsSoundPerCalcComboBox( (double)1.0f / decimatedSampleRate );
	}

	return true;
}



bool tuneComponent::readFIRFilterCoeffs( unsigned int FS )
{
	using namespace preDecimationFIRFilterCoeffs;

	switch ( FS )
	{
		case 8000:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS8000.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS8000.cend( );
				break;
			}
		case 16000:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS16000.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS16000.cend( );
				break;
			}
		case 44100:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS44100.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS44100.cend( );
				break;
			}
		case 48000:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS48000.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS48000.cend( );
				break;
			}
		case 88200:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS88200.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS88200.cend( );
				break;
			}
		case 96000:
			{
				bFIRCoeffsInvertedBegin = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS96000.cbegin( );
				bFIRCoeffsInvertedEnd = bFIRCoeffsInvertedForPreDecimationFIRFilterAtFS96000.cend( );
				break;
			}
		default:
			{
				return false;
			}
	}

	if ( inBufferFIR.size( ) != noCoeffsForPreDecimationFIRFilter )
	{
		inBufferFIR.clear( ); // clear inputbuffer to pre decmation FIR filter
		// Size inBufferFIR to FIR filter coeffs.
		inBufferFIR.resize( noCoeffsForPreDecimationFIRFilter, 0 );
		preDecimationFilterIndxToSampleInInBuffer = 0;
	}

	return true;
}

bool tuneComponent::readNotchFilterCoeffsAndConstants( unsigned int FS )
{
	using namespace decimationAndFilterConstants;
	using namespace postDecimationNOTCHFiltersCoeffs;

	if ( use60HzFilter )
	{
		// Use 60 Hz filter
		switch ( FS )
		{
			case 8000:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS8000;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS8000;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs8000.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs8000.cbegin( );
					break;
				}
			case 16000:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS16000;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS16000;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs16000.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs16000.cbegin( );
					break;
				}
			case 44100:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS44100;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS44100;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs44100.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs44100.cbegin( );
					break;
				}
			case 48000:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS48000;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS48000;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs48000.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs48000.cbegin( );
					break;
				}
			case 88200:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS88200;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS88200;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs88200.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs88200.cbegin( );
					break;
				}
			case 96000:
				{
					cNotchNoOfCoeffs = c60HzNotchNoOfCoeffsAtDecimatedFsAtFS96000;
					dNotchNoOfCoeffs = d60HzNotchNoOfCoeffsAtDecimatedFsAtFS96000;
					cNotchCoeffsBegin = c60HzNotchCoeffsAtDecimatedFsAtFs96000.cbegin( );
					dNotchCoeffsBegin = d60HzNotchCoeffsAtDecimatedFsAtFs96000.cbegin( );
					break;
				}
			default:
				{
					return false;
				}
		}
	}
	else
	{
		//Use 50Hz filter
		switch ( FS )
		{
			case 8000:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS8000;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS8000;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs8000.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs8000.cbegin( );
					break;
				}
			case 16000:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS16000;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS16000;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs16000.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs16000.cbegin( );
					break;
				}
			case 44100:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS44100;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS44100;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs44100.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs44100.cbegin( );
					break;
				}
			case 48000:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS48000;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS48000;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs48000.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs48000.cbegin( );
					break;
				}
			case 88200:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS88200;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS88200;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs88200.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs88200.cbegin( );
					break;
				}
			case 96000:
				{
					cNotchNoOfCoeffs = c50HzNotchNoOfCoeffsAtDecimatedFsAtFS96000;
					dNotchNoOfCoeffs = d50HzNotchNoOfCoeffsAtDecimatedFsAtFS96000;
					cNotchCoeffsBegin = c50HzNotchCoeffsAtDecimatedFsAtFs96000.cbegin( );
					dNotchCoeffsBegin = d50HzNotchCoeffsAtDecimatedFsAtFs96000.cbegin( );
					break;
				}
			default:
				{
					return false;
				}
		}
	}

	// Resize post decimation NOTCH filters input and output deque
	if ( postDecimationFilterXValues.size( ) != dNotchNoOfCoeffs )
	{
		postDecimationFilterXValues.clear( );
		postDecimationFilterXValues.resize( dNotchNoOfCoeffs, 0 );
	}
	if ( postDecimationFilterYValues.size( ) != cNotchNoOfCoeffs )
	{
		postDecimationFilterYValues.clear( );
		postDecimationFilterYValues.resize( cNotchNoOfCoeffs, 0 );
	}

	return true;
}


bool tuneComponent::setPreAndPostFiltersAndConstantsBasedOnSampleRate( double newSampleRate )
{
	if ( !readFilterConstants( (unsigned int)newSampleRate ) )
	{
		return false;
	}
	if ( !readFIRFilterCoeffs( (unsigned int)newSampleRate ) )
	{
		return false;
	}
	if ( !readNotchFilterCoeffsAndConstants( (unsigned int)newSampleRate ) )
	{
		return false;
	}

	if ( highestFreqToDisplayDataForHz > ( decimatedSampleRate / 2 ) )
	{
		highestFreqToDisplayDataForHz = ( juce::uint16 )( decimatedSampleRate / 2 );
	}

	freqToXCoordFactor = (long double)widthOfTuneWindow / (long double)( (long double)highestFreqToDisplayDataForHz - (long double)lowestFreqToDisplayDataForHz );

	goertzelInit( );
	guitarStringsTonesXCoordsAndNamesCalc( );

	fDelta = (long double)decimatedSampleRate / (long double)fftSize;
	timeSecundsPerFullAudioRecordBuffer = (float)( 1.0f / fDelta );
	timeSecundsPerFullAudioRecordBufferReady = true;

	goForInitAdaptiveNoSecondsComboBox = timeSecundsPerFullAudioRecordBufferReady && bDisplayControlComponentReady; // set flag for ok ForInitAdaptiveNoSecondsComboBox

	if ( bDisplayControlComponentReady )
	{
		pDisplayControlComponent.lock( )->setLabelHighstFreqText( decimatedSampleRate, E2 - goertzelFreqsAroundGuitarStringFreqs, E4 + goertzelFreqsAroundGuitarStringFreqs );
		pDisplayControlComponent.lock( )->showLowestAndHighestFreqToDisplayDataForHz( decimatedSampleRate, E2 - goertzelFreqsAroundGuitarStringFreqs, E4 + goertzelFreqsAroundGuitarStringFreqs );
	}
	if ( adaptiveNoSecondsComboBoxReady )
	{
		pDisplayControlComponent.lock( )->updateAdaptiveNoSecondsComboBox( timeSecundsPerFullAudioRecordBuffer );
	}
	noOfFullAudioRecordBuffersDuringTimeToFadeAwaySecunds = std::trunc( (float)timeToFadeAwaySecunds / timeSecundsPerFullAudioRecordBuffer );

	generateNoiseIndxToSampleInInBuffer = 0;

	generateImpulseIndxToSampleInInBuffer = 0;


	firstFftDataToDisplay = (int)round( (long double)lowestFreqToDisplayDataForHz / fDelta );
	lastFftDataToDisplay = (int)round( (long double)highestFreqToDisplayDataForHz / fDelta );
	resToDisply = (float)( (long double)widthOfTuneWindow * (long double)spaceBtwFftDataToDisplay / (long double)( (long double)lastFftDataToDisplay - (long double)firstFftDataToDisplay ) );

	noOfInputValues = 0;
	nextSpectrumDataBlockReady = false;


	return true;
}

void tuneComponent::guitarStringSoundsCleanUp
(
	double sampleRate
)
{
	static double sampleRateLastTime = -1.0f;

	if ( sampleRateLastTime != sampleRate )
	{
		doPlayGuitarStringSounds = false;
		guitarStringSoundsOnLastTime = { false, false, false, false, false, false };
		ptrsToGuitarStringsSinePhases.clear( );
		if ( ptrGuitarStringSoundsControl != nullptr )
		{
			ptrGuitarStringSoundsControl->disableAllStringTonesAndMutes( );
		}
		outputMuteToggleButtonOn = false;
		stringsMuteToggleButtonOn = false;

		sampleRateLastTime = sampleRate;
	}
}

void tuneComponent::prepareToPlay( int samplesPerBlockExpected, double newSampleRate )
{
	// do guitar strings sounds stuff
	guitarStringSoundsCleanUp( newSampleRate );
	calcHalfSinePeriodValues( samplesPerBlockExpected );
	calcNewGuitarStringsSinePhasesFromSampleRate( newSampleRate );

	if ( currentSampleRateInUse != newSampleRate )
	{
		using namespace decimationAndFilterConstants;

		if (
			(
				std::find
				(
					legalSampleFrequencies.begin( )
					, legalSampleFrequencies.end( )
					, newSampleRate
				) == legalSampleFrequencies.end( )
				)
			)
		{
			AlertWindow::showOkCancelBox
			(
				juce::AlertWindow::AlertIconType::WarningIcon
				, "Illegal sample rate"
				, "Illegal sample rate: " + String( (int)( newSampleRate ) )
				, ""
				, ""
				, nullptr
				, nullptr
			);
			return;
		}
		else
		{

			if ( !setPreAndPostFiltersAndConstantsBasedOnSampleRate( newSampleRate ) )
			{
				AlertWindow::showOkCancelBox
				(
					juce::AlertWindow::AlertIconType::WarningIcon
					, "Illegal sample rate"
					, "Illegal sample rate"
					, ""
					, ""
					, nullptr
					, nullptr
				);
				return;
			}
		}
	}
}


void tuneComponent::changeListenerCallback( ChangeBroadcaster* )
{
	AudioDeviceManager::AudioDeviceSetup currentAudioConfig;
	sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );

	if ( ( currentSampleRateInUse != currentAudioConfig.sampleRate )
		 || ( currentBufferSizeInUse != currentAudioConfig.bufferSize )
		 || ( currentaudioDeviceTypeInUse != sharedAudioDeviceManager->getCurrentAudioDeviceType( ) )
		 )
	{
		if ( auto curAudioDevice = sharedAudioDeviceManager->getCurrentAudioDevice( ) )
		{
			currentaudioDeviceTypeInUse = ( sharedAudioDeviceManager->getCurrentAudioDeviceType( ) ).toStdString( );
			currentBufferSizeInUse = currentAudioConfig.bufferSize;
			currentSampleRateInUse = currentAudioConfig.sampleRate;
			if ( currentSampleRateInUse < 44100 )
			{
				// Try to set samplerate to at least 44100
				// Get sample rates
				juce::Array<double> availableSampleRates( curAudioDevice->getAvailableSampleRates( ) );
				availableSampleRates.sort( );
				auto it = std::find_if( std::begin( availableSampleRates ), std::end( availableSampleRates ), [ ]( double SF )
										{
											return SF >= 44100;
										} );
				if ( it != std::end( availableSampleRates ) )
				{
					currentAudioConfig.sampleRate = *it;
					sharedAudioDeviceManager->setAudioDeviceSetup( currentAudioConfig, true );
					sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );
					currentaudioDeviceTypeInUse = ( sharedAudioDeviceManager->getCurrentAudioDeviceType( ) ).toStdString( );
					currentBufferSizeInUse = currentAudioConfig.bufferSize;
					currentSampleRateInUse = currentAudioConfig.sampleRate;
				}
			}

			// do guitar strins sounds stuff
			guitarStringSoundsCleanUp( currentSampleRateInUse );
			calcHalfSinePeriodValues( currentBufferSizeInUse );
			calcNewGuitarStringsSinePhasesFromSampleRate( currentSampleRateInUse );

			if ( !setPreAndPostFiltersAndConstantsBasedOnSampleRate( currentAudioConfig.sampleRate ) )
			{
				AlertWindow::showOkCancelBox
				(
					juce::AlertWindow::AlertIconType::WarningIcon
					, "Illegal sample rate"
					, "Illegal sample rate"
					, ""
					, ""
					, nullptr
					, nullptr
				);
				return;
			}
		}
	}
}

void tuneComponent::calcNewGuitarStringsSinePhasesFromSampleRate( double sampleRate )
{
	static double sampleRateLastTime = -1.0f;

	if ( sampleRateLastTime != sampleRate )
	{
		guitarStringsSinePhases.clear( );
		ptrsToGuitarStringsSinePhases.clear( );

		GUITARSTRINGSPHASES locGuitarStringsSinePhases;

		for ( unsigned int guitarTone : guitar )
		{
			locGuitarStringsSinePhases.guitarStringFreq = (float)guitarTone;
			locGuitarStringsSinePhases.phaseDeltaPerSample = (float)( float_2PI * (float)guitarTone / sampleRate );
			locGuitarStringsSinePhases.currentPhase = -( locGuitarStringsSinePhases.phaseDeltaPerSample ); // So this sin starts w. phase = 0;

			guitarStringsSinePhases.push_back( locGuitarStringsSinePhases );
		}

		sampleRateLastTime = sampleRate;
	}
}

void tuneComponent::getLowestAndHighestFreqToDisplayDataForHz( int& lowestFreq, int& highestFreq )
{
	lowestFreq = lowestFreqToDisplayDataForHz;
	highestFreq = highestFreqToDisplayDataForHz;
}

bool tuneComponent::setLowestAndHighestFreqToDisplayDataForHz( int lowestFreq, int highestFreq )
{
	if ( ( highestFreq < lowestFreq )
		 || ( highestFreq < 1 ) || ( highestFreq > ( (int)( decimatedSampleRate / 2 ) ) )
		 || ( lowestFreq < 1 ) || ( lowestFreq > ( (int)( decimatedSampleRate / 2 ) ) ) )
	{
		return false;
	}

	lowestFreqToDisplayDataForHz = lowestFreq;
	highestFreqToDisplayDataForHz = highestFreq;

	firstFftDataToDisplay = (int)round( (long double)lowestFreqToDisplayDataForHz / fDelta );
	lastFftDataToDisplay = (int)round( (long double)highestFreqToDisplayDataForHz / fDelta );
	resToDisply = (float)( (long double)widthOfTuneWindow * (long double)spaceBtwFftDataToDisplay / (long double)( lastFftDataToDisplay - firstFftDataToDisplay ) );

	freqToXCoordFactor = (long double)widthOfTuneWindow / (long double)( (long double)highestFreqToDisplayDataForHz - (long double)lowestFreqToDisplayDataForHz );

	goertzelInit( );
	guitarStringsTonesXCoordsAndNamesCalc( );

	nextSpectrumDataBlockReady = false;

	return true;
}

double tuneComponent::getCurrentDecimatedSampleRate( )
{
	return decimatedSampleRate;
}

void tuneComponent::getCurrentDecimatedSampleRateAndLowestAndHighestGoertzelFreq( double& curSampleRate, uint16& lowestGoertzelFreq, uint16& highestGoertzelFreq )
{
	curSampleRate = decimatedSampleRate;
	lowestGoertzelFreq = E2 - goertzelFreqsAroundGuitarStringFreqs;
	highestGoertzelFreq = E4 + goertzelFreqsAroundGuitarStringFreqs;
}

void tuneComponent::setDisplayControlComponentReadyFlag( bool isReady )
{
	bDisplayControlComponentReady = isReady;
	goForInitAdaptiveNoSecondsComboBox = timeSecundsPerFullAudioRecordBufferReady && bDisplayControlComponentReady; // set flag for ok ForInitAdaptiveNoSecondsComboBox
}

void tuneComponent::releaseResources( )
{
	// (nothing to do here)
}


void tuneComponent::filterAndPushNextSampleIntoFifo( float sample )
{
	// if the inBuffer contains enough data, set a flag to say
	// that the next line should now be rendered..
	if ( noOfInputValues >= fftSize )
	{
		// Switch buffers
		if ( bSwitchBufferTo2 )
		{
			if ( showFFTToggleButtonOn )
			{
				inBuffer = inBuffer2;
				fftData = fftData2;
			}
			if ( recorderSourceFilteredAudioOn )
			{
				audioRecordBufferOut = audioRecordBuffer1;
				audioRecordBufferIn = audioRecordBuffer2;
			}
			pDqGoertzelBinsIn = &dqGoertzelBins2;
			pDqGoertzelBinsOut = &dqGoertzelBins1;
			bSwitchBufferTo2 = false;
		}
		else
		{
			if ( showFFTToggleButtonOn )
			{
				inBuffer = inBuffer1;
				fftData = fftData1;
			}
			if ( recorderSourceFilteredAudioOn )
			{
				audioRecordBufferOut = audioRecordBuffer2;
				audioRecordBufferIn = audioRecordBuffer1;
			}
			pDqGoertzelBinsIn = &dqGoertzelBins1;
			pDqGoertzelBinsOut = &dqGoertzelBins2;
			bSwitchBufferTo2 = true;
		}


		nextSpectrumDataBlockReady = true;

		weSpectrumDataReady.signal( );

		if ( recorderSourceFilteredAudioOn )
		{
			spTheAudioRecorderThread->recordingFilteredAudioBuffer( audioRecordBufferOut );
		}

		noOfInputValues = 0;

		firstSampleIn = true;

		goertzelReset( );
	}


	static double yNew;

	if ( usePowerGridFrequencyFilter )
	{
		postDecimationFilterXValues.pop_back( );
		postDecimationFilterXValues.push_front( (double)sample );

		yNew = inner_product( postDecimationFilterXValues.begin( ), postDecimationFilterXValues.end( ), dNotchCoeffsBegin, (double)0.0 )
			- inner_product( postDecimationFilterYValues.begin( ), postDecimationFilterYValues.end( ), cNotchCoeffsBegin, (double)0.0 );

		postDecimationFilterYValues.pop_back( );
		postDecimationFilterYValues.push_front( yNew );
	}
	else
	{
		yNew = (double)sample;
	}

	if (recorderSourceFilteredAudioOn)
	{
		audioRecordBufferIn[noOfInputValues] = (float)yNew;
	}

	if (!showFiltersToggleButtonOn)
	{
		// Hann window
		yNew *= hannWinCoefficients[noOfInputValues];
	}

	if ( showFFTToggleButtonOn )
	{
		inBuffer[ noOfInputValues++ ] = yNew;
	}
	else
	{
		noOfInputValues++;
	}

	static long double Q0;

	//HEREKS
	for ( auto& goertzelBinToCalc : *pDqGoertzelBinsIn )
	{
		Q0 = goertzelBinToCalc.coeff * goertzelBinToCalc.Q1 - goertzelBinToCalc.Q2 + yNew;
		goertzelBinToCalc.Q2 = goertzelBinToCalc.Q1;
		goertzelBinToCalc.Q1 = Q0;
	}

}

void tuneComponent::getNextAudioBlock( const AudioSourceChannelInfo& bufferToFill )
{
	if ( generateNoiseToggleButtonOn )
	{
		static std::random_device rd;   // non-deterministic generator
		static std::mt19937 gen( rd( ) );  // to seed mersenne twister.
		static std::uniform_real_distribution<> dist( -1, 1 );

		bufferToFill.clearActiveBufferRegion( );

		for ( int chan = 0; chan < bufferToFill.buffer->getNumChannels( ); ++chan )
		{

			float* const channelData = bufferToFill.buffer->getWritePointer( chan, bufferToFill.startSample );

			while ( generateNoiseIndxToSampleInInBuffer < bufferToFill.numSamples )
			{
				channelData[ generateNoiseIndxToSampleInInBuffer ] = (float)( dist( gen ) ); // Random
				filterAndPushNextSampleIntoFifo( channelData[ generateNoiseIndxToSampleInInBuffer ] );
				generateNoiseIndxToSampleInInBuffer += sampleSpace;
			}
			generateNoiseIndxToSampleInInBuffer -= bufferToFill.numSamples; // make ready for next buffertofill 
		}
	}
	else
	{
		if ( showFiltersToggleButtonOn )
		{
			if ( bufferToFill.buffer->getNumChannels( ) != 0 )
			{
				bufferToFill.clearActiveBufferRegion( );
				float* channelData = bufferToFill.buffer->getWritePointer( 0, bufferToFill.startSample );

				if ( firstSampleIn )
				{
					channelData[ generateImpulseIndxToSampleInInBuffer ] = 1;
					firstSampleIn = false;
				}
			}
		}
	}


	if ( bufferToFill.buffer->getNumChannels( ) != 0 )
	{
		const float* channelData = bufferToFill.buffer->getReadPointer( 0, bufferToFill.startSample );

		static double FIRFilteredInputSample;
		if ( preDecimationFilterIndxToSampleInInBuffer > 0 )
		{
			// Insert first of raw input samples in buffer into inBufferFIR
			inBufferFIR.insert( inBufferFIR.end( )
								, channelData
								, channelData + preDecimationFilterIndxToSampleInInBuffer
			);
			// Filter w. FIR filter
			FIRFilteredInputSample = std::inner_product( bFIRCoeffsInvertedBegin
														 , bFIRCoeffsInvertedEnd
														 , inBufferFIR.begin( )
														 , (double)0.0
			);
			filterAndPushNextSampleIntoFifo( (float)FIRFilteredInputSample );
		}
		for ( ; preDecimationFilterIndxToSampleInInBuffer <= bufferToFill.numSamples - sampleSpace; preDecimationFilterIndxToSampleInInBuffer += sampleSpace )
		{
			// erase the first sampleSpace elements (oldest samples)
			inBufferFIR.erase( inBufferFIR.begin( ), inBufferFIR.begin( ) + sampleSpace );
			// Insert sampleSpace raw inputs into inBufferFIR
			inBufferFIR.insert( inBufferFIR.end( )
								, channelData + preDecimationFilterIndxToSampleInInBuffer
								, channelData + preDecimationFilterIndxToSampleInInBuffer + sampleSpace
			);
			// Filter w. FIR filter
			FIRFilteredInputSample = std::inner_product( bFIRCoeffsInvertedBegin
														 , bFIRCoeffsInvertedEnd
														 , inBufferFIR.begin( )
														 , (double)0.0
			);
			filterAndPushNextSampleIntoFifo( (float)FIRFilteredInputSample );
		}
		// erase the first sampleSpace elements (oldest samples)
		inBufferFIR.erase( inBufferFIR.begin( ), inBufferFIR.begin( ) + sampleSpace );
		// Insert rest of raw input samples in buffer into inBufferFIR
		// (rest of raw samples will be inserted when getNextAudioBlock is called again)
		inBufferFIR.insert( inBufferFIR.end( )
							, channelData + preDecimationFilterIndxToSampleInInBuffer
							, channelData + bufferToFill.numSamples
		);
		preDecimationFilterIndxToSampleInInBuffer += sampleSpace - bufferToFill.numSamples; // make ready for next buffer full
	}

	if ( !playGuitarStringSoundsRamp )
	{
		if ( outputMuteToggleButtonOn )
		{
			bufferToFill.clearActiveBufferRegion( );
		}
		else
		{
			if ( bufferToFill.buffer->getNumChannels( ) > 0 )
			{
				if ( inputMuteToggleButtonOn )
				{
					bufferToFill.clearActiveBufferRegion( );
				}
				else
				{
					bufferToFill.buffer->applyGain( 0, bufferToFill.startSample, bufferToFill.numSamples, inputGain );
				}


				if ( doPlayGuitarStringSounds && !stringsMuteToggleButtonOn )
				{
					float currentPhase;
					float phaseDeltaPerSample;

					float* channelData = bufferToFill.buffer->getWritePointer( 0, bufferToFill.startSample );
				#if (JUCE_WINDOWS && _DEBUG)
					auto outBffrStart = stdext::make_unchecked_array_iterator( channelData );
					auto outBffrEnd = stdext::make_unchecked_array_iterator( channelData + bufferToFill.numSamples );
				#else // (JUCE_WINDOWS && _DEBUG)
					auto outBffrStart = channelData;
					auto outBffrEnd = channelData + bufferToFill.numSamples;
				#endif // (JUCE_WINDOWS && _DEBUG)

				#define f2PI (6.28318530717958647692)
					double gainToUse = stringGainToUse;


					for ( auto gStringPhase : ptrsToGuitarStringsSinePhases )
					{
						phaseDeltaPerSample = ( *gStringPhase ).phaseDeltaPerSample;
						currentPhase = ( *gStringPhase ).currentPhase;
						std::transform
						(
							outBffrStart, outBffrEnd, outBffrStart,
							[ &currentPhase, phaseDeltaPerSample, &gainToUse ]
						( float guitarStringSoundsIn )
							{
								currentPhase = std::fmod( currentPhase + phaseDeltaPerSample, (float)f2PI );
								return guitarStringSoundsIn + (float)( gainToUse * std::sin( currentPhase ) );
							}
						);
						( *gStringPhase ).currentPhase = currentPhase;
					}
				}
				if ( bufferToFill.buffer->getNumChannels( ) > 1 )
				{
					bufferToFill.buffer->copyFrom( 1, bufferToFill.startSample, *bufferToFill.buffer, 0, bufferToFill.startSample, bufferToFill.numSamples );
				}
			}
		}
	}
	else
	{

		if ( bufferToFill.buffer->getNumChannels( ) > 0 )
		{
			if ( inputMuteToggleButtonOn )
			{
				bufferToFill.clearActiveBufferRegion( );
			}
			else
			{
				bufferToFill.buffer->applyGain( 0, bufferToFill.startSample, bufferToFill.numSamples, inputGain );
			}

			{ // Begin scope of guitarStringSoundsLockMutex
				const ScopedLock sl( guitarStringSoundsLockMutex );

			#if (JUCE_WINDOWS && _DEBUG)
				std::transform( guitarStringSoundsRamp.begin( ), guitarStringSoundsRamp.end( ), stdext::make_unchecked_array_iterator( bufferToFill.buffer->getReadPointer( 0, bufferToFill.startSample ) ), stdext::make_unchecked_array_iterator( bufferToFill.buffer->getWritePointer( 0, bufferToFill.startSample ) ), std::plus<float>( ) );
			#else // (JUCE_WINDOWS && _DEBUG)
				std::transform( guitarStringSoundsRamp.begin( ), guitarStringSoundsRamp.end( ), bufferToFill.buffer->getReadPointer( 0, bufferToFill.startSample ), bufferToFill.buffer->getWritePointer( 0, bufferToFill.startSample ), std::plus<float>( ) );
			#endif // (JUCE_WINDOWS && _DEBUG)

				if ( bufferToFill.buffer->getNumChannels( ) > 1 )
				{
					bufferToFill.buffer->copyFrom( 1, bufferToFill.startSample, *bufferToFill.buffer, 0, bufferToFill.startSample, bufferToFill.numSamples );
				}
			} // end scope of guitarStringSoundsLockMutex

		}
		playGuitarStringSoundsRamp = false;
	}

}



//=======================================================================
void tuneComponent::paint( Graphics& g )
{
	g.fillAll( Colours::black );

	g.setOpacity( 1.0f );
	g.drawImageWithin( spectrogramImage, 0, 0, getWidth( ), getHeight( ), RectanglePlacement::stretchToFit );
}

void tuneComponent::parentSizeChanged( )
{
	resized( );
}

void tuneComponent::resized( )
{
#if ( JUCE_ANDROID )
	{
		Rectangle<int> r = Desktop::getInstance( ).getDisplays( ).getPrimaryDisplay()->userArea;
		double sizeScale = (double)( r.getWidth( ) ) / (double)widthOfTuneWindow;
		setSize( (int)( widthOfTuneWindow * sizeScale ), (int)( hightOfTuneWindow * sizeScale ) );
	}
#elif ( JUCE_IOS )
	{
		Rectangle<int> r = Desktop::getInstance( ).getDisplays( ).getPrimaryDisplay()->userArea;
		double sizeScale;
		if ( r.getHeight( ) >= r.getWidth( ) ) // Portrait
		{
			sizeScale = (double)( r.getWidth( ) ) / (double)widthOfTuneWindow;
		}
		else
		{
			if ( ptrGuitarFineTuneFirstClass->thisiPhoneiPadNeedsSafeArea( ) )
			{
				sizeScale = (double)( r.getWidth( ) ) / (double)( (double)widthOfTuneWindow + ( (double)2 * (double)iOSSafeMargin ) );
			}
			else
			{
				sizeScale = (double)( r.getWidth( ) ) / (double)widthOfTuneWindow;
			}
		}
		setSize( (int)( widthOfTuneWindow * sizeScale ), (int)( hightOfTuneWindow * sizeScale ) );
	}
#else // macos or win
	{
		setSize( widthOfTuneWindow, hightOfTuneWindow );
	}
#endif

}

#if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)
    void tuneComponent::timerCallback()
    {
#if (JUCE_MAC || JUCE_LINUX)
        if (SystemStats::getOperatingSystemType() >= SystemStats::MacOSX_10_14 )
        {
#endif
            AudioIODevice* CurrentAudioDevice = sharedAudioDeviceManager->getCurrentAudioDevice( );
            if ( CurrentAudioDevice != nullptr )
            {
                switch (CurrentAudioDevice->checkAudioInputAccessPermissions( ))
                {
                    case eksAVAuthorizationStatusDenied:
                    {
                        stopTimer();
#if JUCE_MODAL_LOOPS_PERMITTED
                        juce::AlertWindow::showMessageBox
                        (
                            juce::AlertWindow::WarningIcon
                            , "Access to audio input device\nNOT granted!"
#if (JUCE_IOS)
                            , "You might try to\nEnbale guitarFineTune in\nSettings -> Privacy -> Microphone\nOr UNinstall\nand REinstall guitarFineTune"
#else // JUCE_MAC || JUCE_LINUX
                            , "You might try to\nEnbale guitarFineTune in\nSystem Preferences -> Security & Privacy -> Privacy -> Microphone\nOr UNinstall\nand REinstall guitarFineTune"
#endif
                            , "Quit"
                         );
                        sharedAudioDeviceManager->closeAudioDevice();
                        JUCEApplication::getInstance( )->systemRequestedQuit( );
#else //#if JUCE_MODAL_LOOPS_PERMITTED
                        juce::AlertWindow::showMessageBoxAsync
                        (
                            juce::AlertWindow::WarningIcon
                            , "Access to audio input device\nNOT granted!"
#if (JUCE_IOS)
                            , "You might try to\nEnbale guitarFineTune in\nSettings -> Privacy -> Microphone\nOr UNinstall\nand REinstall guitarFineTune"
#else // JUCE_MAC || JUCE_LINUX
                            , "You might try to\nEnbale guitarFineTune in\nSystem Preferences -> Security & Privacy -> Privacy -> Microphone\nOr UNinstall\nand REinstall guitarFineTune"
#endif
                         );
#endif //#if JUCE_MODAL_LOOPS_PERMITTED
                         break;
                    }
                    case eksAVAuthorizationStatusRestricted:
                    case eksAVAuthorizationStatusAuthorized:
                    {
                        stopTimer();
                        break;
                    }
                    case eksAVAuthorizationStatusNotDetermined:
                    {
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
#if (JUCE_MAC || JUCE_LINUX)
        }
#endif
    }
#endif // #if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)


void tuneComponent::run( )
{
	bool adaptiveNoSecondsComboBoxInited = false;

#if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)
#if (JUCE_MAC || JUCE_LINUX)
        if (SystemStats::getOperatingSystemType() >= SystemStats::MacOSX_10_14 )
        {
#endif
            AudioIODevice* CurrentAudioDevice = sharedAudioDeviceManager->getCurrentAudioDevice( );
            if ( CurrentAudioDevice != nullptr )
            {
                switch (CurrentAudioDevice->checkAudioInputAccessPermissions( ))
                {
                    case eksAVAuthorizationStatusDenied:
                    {
                        startTimer(1000);
                        break;
                    }
                    case eksAVAuthorizationStatusRestricted:
                    case eksAVAuthorizationStatusAuthorized:
                    {
                        break;
                    }
                    case eksAVAuthorizationStatusNotDetermined:
                    {
                        startTimer(1000);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
#if (JUCE_MAC || JUCE_LINUX)
        }
#endif
#endif // #if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)

	while ( !threadShouldExit( ) && !adaptiveNoSecondsComboBoxInited )
	{
		if ( !adaptiveNoSecondsComboBoxInited && goForInitAdaptiveNoSecondsComboBox )
		{
			MessageManagerLock mml;
			pDisplayControlComponent.lock( )->initAdaptiveNoSecondsComboBox( timeSecundsPerFullAudioRecordBuffer );
			adaptiveNoSecondsComboBoxInited = true;
		}

		weSpectrumDataReady.wait( -1 ); // Wait for event to be signaled.
		if ( nextSpectrumDataBlockReady )
		{
			drawSpectrogram( );
			nextSpectrumDataBlockReady = false;
			triggerAsyncUpdate( );
		}
	}

	while ( !threadShouldExit( ) )
	{
		weSpectrumDataReady.wait( -1 ); // Wait for event to be signaled.
		if ( nextSpectrumDataBlockReady )
		{
			drawSpectrogram( );
			nextSpectrumDataBlockReady = false;
			triggerAsyncUpdate( );
		}
	}

}


void tuneComponent::handleAsyncUpdate( ) // Called from AsyncUpdater
{
	repaint( );
}



void tuneComponent::gfftPerformFrequencyOnlyForwardTransform( double* d )
{
	// compute FFT
	gfft->fft( d );

	std::complex<double>* pComplex = ( std::complex<double>* )d;

	for ( int i = 0; i < fftSize; i++ )
	{
		d[ i ] = std::abs( pComplex[ i ] );
	}

}

inline std::string tuneComponent::eksLongDoubleToString( long double valueToConvert )
{
	char stringOfRoundedSecondsPerBufferBuffer[ 20 ] = { 0 };
	std::sprintf( stringOfRoundedSecondsPerBufferBuffer, "%.Le", valueToConvert );
	return stringOfRoundedSecondsPerBufferBuffer;
}
//inline std::string tuneComponent::eksLongDoubleToString(long double valueToConvert, int noOfDecimals)
//{
//	char stringOfRoundedSecondsPerBufferBuffer[20] = { 0 };
//	long double roundedSecondsPerBuffer = std::round(valueToConvert * std::pow(10, noOfDecimals)) / std::pow(10, noOfDecimals);
//	std::sprintf(stringOfRoundedSecondsPerBufferBuffer, "%.*Lf", noOfDecimals, roundedSecondsPerBuffer);
//	return stringOfRoundedSecondsPerBufferBuffer;
//}

void tuneComponent::drawSpectrogram( )
{
	MessageManagerLock mml( Thread::getCurrentThread( ) );
	if ( !mml.lockWasGained( ) )
		return; // another thread is trying to kill us!

	const ScopedLock sl( drawSpectrogramLockMutex );

#ifdef EVAL_TIME_BETW_CALLS
	static steady_clock::time_point end;
	static steady_clock::time_point start = std::chrono::steady_clock::now( );
	static std::deque<double> allElapsed_seconds( 10, 0.0f );

	end = std::chrono::steady_clock::now( );
	std::chrono::duration<double> elapsed_seconds = end - start;
	start = std::chrono::steady_clock::now( );

	allElapsed_seconds.push_front( elapsed_seconds.count( ) );
	allElapsed_seconds.pop_back( );
	double avgTime = 0.0f;
	for ( double elapsed : allElapsed_seconds )
	{
		avgTime += elapsed;
	}
	avgTime /= 10;
	string strAvgTime = std::to_string( avgTime ) + " " + std::to_string( timeSecundsPerFullAudioRecordBuffer );
#endif // EVAL_TIME_BETW_CALLS

	const int imageHeight = spectrogramImage.getHeight( );
	const int imageWidth = spectrogramImage.getWidth( );

	long double buttomLine = imageHeight - 4;
	//double txtYPos = buttomLine;
	//double txtYPos = buttomLine - defaultFontOfSpectrImGraphcs.getHeight();

	// then FFT data..
	if ( showFFTToggleButtonOn )
	{
		gfftPerformFrequencyOnlyForwardTransform( fftData );
		Thread::sleep( 1 );
	}

	goertzelCalcResults( );
	Thread::sleep( 1 );

	double* pTheMaxElement;
	//static std::deque<float> vMaxLevels(vMaxLevelsSize, FLT_MAX);
	float maxLevel = 0.;
	static std::deque<int> vIdxOMaxs( vIdxOMaxsSize, 0 );
	static std::deque<float> vScaleFactrs( vScaleFactrsSize, 0.0f );
	float scaleFactr = 1.0;

	if ( showFFTToggleButtonOn )
	{
		// find the range of values produced, so we can scale our rendering to
		// show up the detail clearly
		pTheMaxElement = std::max_element( fftData + firstFftDataToDisplay, fftData + lastFftDataToDisplay - 1 );

		maxLevel = (float)( *pTheMaxElement );

		vIdxOMaxs.pop_back( );
		vIdxOMaxs.push_front( (int)( pTheMaxElement - fftData ) );

		vScaleFactrs.pop_back( );
		if ( maxLevel != 0. )
		{
			vScaleFactrs.push_front( (float)( buttomLine / maxLevel ) );
		}
		else
		{
			vScaleFactrs.push_front( (float)buttomLine );
		}
		scaleFactr = std::accumulate( vScaleFactrs.begin( ), vScaleFactrs.end( ), (float)0. ) / vScaleFactrs.size( );
	}


	spectrogramImage.clear( spectrogramImage.getBounds( ), Colours::white );


	// Mark guitar strings frequencies
	spectrImGraphcs.setColour( Colours::green );
	float rectY = hightOfDefaultFontOfSpectrImGraphcs + 3.0f;
	float rectHight = (float)( buttomLine - ( rectY * 2.0f ) );
	float arrowsYStart = rectY;
	float arrowsYEnd = arrowsYStart + rectHight / 2;
	int textBaseLine = (int)( std::ceil( hightOfDefaultFontOfSpectrImGraphcs ) );

	for ( auto& xCoordAndName : guitarStringsTonesXCoordsAndNames )
	{
		spectrImGraphcs.drawArrow( Line<float>( xCoordAndName.stringXCoord, arrowsYStart, xCoordAndName.stringXCoord, arrowsYEnd ), 4.0f, 28.0f, 24.0f );
		spectrImGraphcs.drawSingleLineText( xCoordAndName.stringName, (int)( xCoordAndName.stringXCoord - strHalfStringNamesWidth ), textBaseLine );
	}

	Thread::sleep( 1 );

	static long double absFreqsOutOfTune;
	juce::String strOutOfTuneValue;
	int txtStartX;
	arrowsYStart = rectY + rectHight;
	int idxGuitarStringsTonesXCoordsAndNames = 0;
	// Fading arrows
	typedef struct
	{
		Colour clour;
		float colourAlpha;
		float colourAlphaDecr;
		Line<float> line;
		bool fadedAway;
	} ARROWPARAMS;
	static vector<ARROWPARAMS> fadingArrows( 6 );
	if ( showIndicatorsToggleButtonOn && !showFiltersToggleButtonOn && !generateNoiseToggleButtonOn )
	{
		for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
		{
			if ( goertzelStatistics.showThisOne )
			{
				goertzelStatistics.thisOneShownLastTime = true;

				absFreqsOutOfTune = abs( goertzelStatistics.meanFreqsOutOfTune );
				spectrImGraphcs.setColour
				(
					Colour( (uint8)( absFreqsOutOfTune * redFactorForGuitarStringsOutOfTone )
							, (uint8)( 0x80 - ( absFreqsOutOfTune * greenFactorForGuitarStringsOutOfTone ) )
							, (uint8)0 )
				);
				spectrImGraphcs.drawArrow
				(
					Line<float>
					(
						guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord
						, arrowsYStart
						, (float)goertzelStatistics.meanOutOfTuneXCoordinat
						, arrowsYEnd
						)
					, 4.0
					, 28.0
					, 24.0
				);
				if ( showStringsOffTuneValues )
				{
					if ( goertzelStatistics.meanFreqsOutOfTune > 0 )
					{
						strOutOfTuneValue = "+" + juce::String( (double)goertzelStatistics.meanFreqsOutOfTune, 1 );
					}
					else
					{
						strOutOfTuneValue = juce::String( (double)goertzelStatistics.meanFreqsOutOfTune, 1 );
					}
					if ( ( txtStartX = (int)( guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord - defaultFontOfSpectrImGraphcs.getStringWidthFloat( strOutOfTuneValue ) / 2.0f ) ) < 0.0f )
					{
						txtStartX = 0;
					}
					spectrImGraphcs.drawSingleLineText
					(
						strOutOfTuneValue + " Hz"
						, txtStartX
						, (int)buttomLine
					);
				}
				else
				{
					if ( ( txtStartX = (int)( guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord - defaultFontOfSpectrImGraphcs.getStringWidthFloat( goertzelStatistics.stringName ) / 2.0f ) ) < 0.0f )
					{
						txtStartX = 0;
					}
					spectrImGraphcs.drawSingleLineText
					(
						goertzelStatistics.stringName
						, txtStartX
						, (int)buttomLine
					);
				}
			}
			else
			{
				ARROWPARAMS& rTheArrowParms = fadingArrows[ idxGuitarStringsTonesXCoordsAndNames ];

				if ( goertzelStatistics.thisOneShownLastTime )
				{
					absFreqsOutOfTune = abs( goertzelStatistics.meanFreqsOutOfTune );
					rTheArrowParms.clour = Colour
					(
						(uint8)( absFreqsOutOfTune * redFactorForGuitarStringsOutOfTone )
						, (uint8)( 0x80 - ( absFreqsOutOfTune * greenFactorForGuitarStringsOutOfTone ) )
						, (uint8)0
					);
					rTheArrowParms.colourAlpha =
						rTheArrowParms.clour.getFloatAlpha( );
					rTheArrowParms.colourAlphaDecr = rTheArrowParms.colourAlpha / noOfFullAudioRecordBuffersDuringTimeToFadeAwaySecunds;
					rTheArrowParms.line = Line<float>
						(
							guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord
							, arrowsYStart
							, (float)goertzelStatistics.meanOutOfTuneXCoordinat
							, arrowsYEnd
							);

					rTheArrowParms.fadedAway = false;

					goertzelStatistics.thisOneShownLastTime = false;
				}

				if ( !rTheArrowParms.fadedAway )
				{
					if ( ( rTheArrowParms.colourAlpha -= rTheArrowParms.colourAlphaDecr ) < 0 )
					{
						rTheArrowParms.colourAlpha = 0.0f;
						rTheArrowParms.fadedAway = true;
					}
					spectrImGraphcs.setColour
					(
						rTheArrowParms.clour.withAlpha( rTheArrowParms.colourAlpha )
					);
					spectrImGraphcs.drawArrow
					(
						rTheArrowParms.line
						, 4.0f
						, 28.0f
						, 24.0f
					);
					if ( showStringsOffTuneValues )
					{
						if ( goertzelStatistics.meanFreqsOutOfTune > 0 )
						{
							strOutOfTuneValue = "+" + juce::String( (double)goertzelStatistics.meanFreqsOutOfTune, 1 );
						}
						else
						{
							strOutOfTuneValue = juce::String( (double)goertzelStatistics.meanFreqsOutOfTune, 1 );
						}
						if ( ( txtStartX = (int)( guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord - defaultFontOfSpectrImGraphcs.getStringWidthFloat( strOutOfTuneValue ) / 2.0f ) ) < 0.0f )
						{
							txtStartX = 0;
						}
						spectrImGraphcs.drawSingleLineText
						(
							strOutOfTuneValue + " Hz"
							, txtStartX
							, (int)buttomLine
						);
					}
					else
					{
						if ( ( txtStartX = (int)( guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord - defaultFontOfSpectrImGraphcs.getStringWidthFloat( goertzelStatistics.stringName ) / 2.0f ) ) < 0.0f )
						{
							txtStartX = 0;
						}
						spectrImGraphcs.drawSingleLineText
						(
							goertzelStatistics.stringName
							, txtStartX
							, (int)buttomLine
						);
					}
				}
			}

			idxGuitarStringsTonesXCoordsAndNames++;
		}
	#ifdef EVAL_TIME_BETW_CALLS
		const int imageWidth = spectrogramImage.getWidth( );
		spectrImGraphcs.setColour( Colours::black );
		spectrImGraphcs.drawSingleLineText
		(
			strAvgTime
			, imageWidth - 200
			, (int)buttomLine - 20
		);
	#endif // EVAL_TIME_BETW_CALLS
	}
	Thread::sleep( 1 );

	if ( showFFTToggleButtonOn )
	{
		spectrImGraphcs.setColour( Colours::black );

		float newEndX = 0, oldEndX = 0;
		float oldEndY = (float)buttomLine, newEndY = 0.;
		for ( int fftDataIdx = firstFftDataToDisplay; fftDataIdx < lastFftDataToDisplay; fftDataIdx += spaceBtwFftDataToDisplay )
		{
			newEndY = (float)( buttomLine - ( fftData[ fftDataIdx ] * scaleFactr ) );
			spectrImGraphcs.drawLine( oldEndX, oldEndY, newEndX, newEndY, 1. );
			oldEndX = newEndX;
			newEndX += resToDisply;
			oldEndY = newEndY;
			Thread::sleep( 1 );
		}

		// Show 50, 100, 150, 60, 120 and 180 Hz indicators
	#if (JUCE_IOS || JUCE_ANDROID)
		Font currentFont = spectrImGraphcs.getCurrentFont( );
		auto newFontHeight = currentFont.getHeightInPoints( ) / 2;
		spectrImGraphcs.setFont( newFontHeight );
	#endif
		spectrImGraphcs.setColour( Colours::orange );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 50 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 50 ), (int)( freqToXCoordFactor * ( 50 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 100 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 100 ), (int)( freqToXCoordFactor * ( 100 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 150 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 150 ), (int)( freqToXCoordFactor * ( 150 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 60 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 60 ), (int)( freqToXCoordFactor * ( 60 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 120 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 120 ), (int)( freqToXCoordFactor * ( 120 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
		spectrImGraphcs.fillRect( (float)( freqToXCoordFactor * ( 180 - lowestFreqToDisplayDataForHz ) ), 0., 1., (float)( buttomLine - 6 ) );
		spectrImGraphcs.drawSingleLineText( std::to_string( 180 ) + " Hz", (int)( freqToXCoordFactor * ( 180 - lowestFreqToDisplayDataForHz ) + 1 ), (int)( buttomLine - 30 ) );
	#if (JUCE_IOS || JUCE_ANDROID)
		spectrImGraphcs.setFont( currentFont ); //Restore font
	#endif

		if ( showFFTMaxIndictrToggleButtonOn )
		{
			int idxOMax = std::accumulate( vIdxOMaxs.begin( ), vIdxOMaxs.end( ), (int)0 ) / (int)( vIdxOMaxs.size( ) );
			long double maxValFreq = (long double)idxOMax * fDelta;
			spectrImGraphcs.setColour( Colours::red );
			spectrImGraphcs.fillRect( (float)( ( idxOMax - firstFftDataToDisplay ) * resToDisply ), 0., 2., (float)buttomLine );
			spectrImGraphcs.drawSingleLineText( String( maxLevel ) + ", " + String( (long)maxValFreq ) + ", " + String( idxOMax ), (int)( ( ( idxOMax - firstFftDataToDisplay ) * resToDisply ) + 4 ), (int)buttomLine );
		}

		Thread::sleep( 1 );
	}

	if ( showThreshold || showSpectrumToggleButtonOn )
	{
		static auto spectrumScaleFactr = std::numeric_limits<long double>::max( );
		static auto spectrumMaxValue = std::numeric_limits<long double>::min( );
		static auto thresholdMaxValue = std::numeric_limits<long double>::min( );
		static auto thresholdScaleFctr = std::numeric_limits<long double>::max( );

		auto savedFont = spectrImGraphcs.getCurrentFont( );
	#if (JUCE_IOS || JUCE_ANDROID)
		spectrImGraphcs.setFont( savedFont.getHeightInPoints( ) / 2.25f );
	#else
		spectrImGraphcs.setFont( savedFont.getHeightInPoints( ) / 1.1f );
	#endif // (JUCE_IOS || JUCE_ANDROID)

		auto curFont = spectrImGraphcs.getCurrentFont( );

		// Find scale factor
		if ( showSpectrumToggleButtonOn )
		{
			for ( auto& binToGetResult : *pDqGoertzelBinsOut )
			{
				if ( ( buttomLine - ( binToGetResult.resultMagnitudeSquared * spectrumScaleFactr ) ) < 0.0L )
				{
					spectrumScaleFactr = buttomLine / binToGetResult.resultMagnitudeSquared;
					spectrumMaxValue = binToGetResult.resultMagnitudeSquared;
				}
			}
		}
		if ( showThreshold )
		{
			for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
			{
				if ( ( buttomLine - ( goertzelStatistics.thresholdForShowingResultMagnitudeSquared * thresholdScaleFctr ) ) < 0.0L )
				{
					thresholdScaleFctr = buttomLine / goertzelStatistics.thresholdForShowingResultMagnitudeSquared;
					thresholdMaxValue = goertzelStatistics.thresholdForShowingResultMagnitudeSquared;
				}
			}
		}
		if ( showThreshold && showSpectrumToggleButtonOn )
		{
			// Make common scale factor
			if ( spectrumScaleFactr > thresholdScaleFctr )
			{
				spectrumScaleFactr = thresholdScaleFctr;
				spectrumMaxValue = thresholdMaxValue;
			}
			else
			{
				thresholdScaleFctr = spectrumScaleFactr;
				thresholdMaxValue = spectrumMaxValue;
			}
		}

		Thread::sleep( 1 );

		if ( showSpectrumToggleButtonOn )
		{
			auto spectrumTapY = 0.0f;
			auto spectrumTapHeight = 0.0L;

			auto theText = eksLongDoubleToString( (double)spectrumMaxValue );
			//auto theText = eksLongDoubleToString((double)spectrumMaxValue, 2);

			spectrImGraphcs.setColour( Colours::violet );

			spectrImGraphcs.drawSingleLineText( theText, imageWidth - curFont.getStringWidth( theText ), (int)curFont.getHeight( ) );

			for ( auto& binToGetResult : *pDqGoertzelBinsOut )
			{
				spectrumTapHeight = binToGetResult.resultMagnitudeSquared * spectrumScaleFactr;
				if ( ( spectrumTapY = (float)( buttomLine - spectrumTapHeight ) ) < 0.0f )
				{
					spectrumTapY = 0.0f;
				}
				spectrImGraphcs.fillRect( binToGetResult.xCoordinat, spectrumTapY, 2.0f, (float)spectrumTapHeight );
			}
			Thread::sleep( 1 );
		}
		else
		{
			spectrumScaleFactr = std::numeric_limits<long double>::max( );
		}

		if ( showThreshold )
		{
			spectrImGraphcs.setColour( Colours::blue );

			auto theText = eksLongDoubleToString( (double)thresholdMaxValue );
			//auto theText = eksLongDoubleToString((double)thresholdMaxValue, 2);

			spectrImGraphcs.drawSingleLineText( theText, 0, (int)curFont.getHeight( ) );

			idxGuitarStringsTonesXCoordsAndNames = 0;
			int y_coord = 0;
			for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
			{
				if ( ( y_coord = roundToInt( buttomLine - ( goertzelStatistics.thresholdForShowingResultMagnitudeSquared * thresholdScaleFctr ) ) ) < 0 )
				{
					y_coord = 0;
				}
				float x_left = guitarStringsTonesXCoordsAndNames[ idxGuitarStringsTonesXCoordsAndNames ].stringXCoord - 10;
				float x_right = x_left + 20;
				spectrImGraphcs.drawHorizontalLine( y_coord, x_left, x_right );
				idxGuitarStringsTonesXCoordsAndNames++;
			}
			Thread::sleep( 1 );
		}
		else
		{
			thresholdScaleFctr = std::numeric_limits<long double>::max( );
		}

		static steady_clock::time_point clockStart = std::chrono::steady_clock::now( );

		if ( ( std::chrono::steady_clock::now( ) - clockStart ) >= std::chrono::duration<double>( 15.0 ) )
		{
			clockStart = std::chrono::steady_clock::now( );
			spectrumScaleFactr = std::numeric_limits<long double>::max( );
			spectrumMaxValue = std::numeric_limits<long double>::min( );
			thresholdMaxValue = std::numeric_limits<long double>::min( );
			thresholdScaleFctr = std::numeric_limits<long double>::max( );
		}

		spectrImGraphcs.setFont( savedFont );
	}

}

void tuneComponent::initObjects( std::weak_ptr<displayControlComponent> pObj1 )
{
	pDisplayControlComponent = pObj1;

}

void tuneComponent::initPGuitarStringSoundsControl( Component::SafePointer<guitarStringSoundsControl> pGuitarStringSoundsControl )
{
	ptrGuitarStringSoundsControl = pGuitarStringSoundsControl;
}

//AudioDeviceManager& tuneComponent::getTheAudioDeviceManager( )
//{
//	return *sharedAudioDeviceManager;
//}

void tuneComponent::goertzelInit( )
{
	using namespace decimationAndFilterConstants;


	long double omega, cosine;

	if ( ( !dqGoertzelBins1.empty( ) ) && ( !dqGoertzelBins2.empty( ) ) ) // First time ?
	{ // Not first time
		for ( auto& localGoertzelBin : dqGoertzelBins1 )
		{
			localGoertzelBin.xCoordinat = (float)( freqToXCoordFactor * ( localGoertzelBin.targetFreq - lowestFreqToDisplayDataForHz ) );
			localGoertzelBin.Q1 = 0.0L;
			localGoertzelBin.Q2 = 0.0L;
			localGoertzelBin.resultMagnitudeSquared = 0.0L;
			if ( !almost_equal( localGoertzelBin.targetFreq, goertzelFrequencyToAvoid, 1 ) )
			{
				omega = ( 2.0L * (long double)M_PI * localGoertzelBin.targetFreq ) / (long double)decimatedSampleRate;
				cosine = cos( omega );
				localGoertzelBin.coeff = 2.0L * cosine;
			}
			else
			{
				localGoertzelBin.coeff = 0.0L;
			}
		}
		for ( auto& localGoertzelBin : dqGoertzelBins2 )
		{
			localGoertzelBin.xCoordinat = (float)( freqToXCoordFactor * ( localGoertzelBin.targetFreq - lowestFreqToDisplayDataForHz ) );
			localGoertzelBin.Q1 = 0.0L;
			localGoertzelBin.Q2 = 0.0L;
			localGoertzelBin.resultMagnitudeSquared = 0.0L;
			if ( !almost_equal( localGoertzelBin.targetFreq, goertzelFrequencyToAvoid, 1 ) )
			{
				omega = ( 2.0L * (long double)M_PI * localGoertzelBin.targetFreq ) / (long double)decimatedSampleRate;
				cosine = cos( omega );
				localGoertzelBin.coeff = 2.0L * cosine;
			}
			else
			{
				localGoertzelBin.coeff = 0.0L;
			}
		}
	}
	else
	{ // First time
	  // local Goertzel bin
		GOERTZELBIN localGoertzelBin;
		unsigned int guitarString = 0;

		for ( int guitarStringNo = 0; guitarStringNo < 6; guitarStringNo++ )
		{
			guitarString = guitar[ guitarStringNo ];

			for ( long double targetFreq : goertzelTargetFrequencies[ guitarStringNo ] )
			{
				localGoertzelBin.guitarStringFreq = guitarString;
				localGoertzelBin.targetFreq = targetFreq;
				localGoertzelBin.xCoordinat = (float)( freqToXCoordFactor * ( targetFreq - lowestFreqToDisplayDataForHz ) );
				localGoertzelBin.Q1 = 0.0L;
				localGoertzelBin.Q2 = 0.0L;
				localGoertzelBin.resultMagnitudeSquared = 0.0L;
				if ( !almost_equal( targetFreq, goertzelFrequencyToAvoid, 1 ) )
				{
					omega = ( 2.0L * (long double)M_PI * targetFreq ) / (long double)decimatedSampleRate;
					cosine = cos( omega );
					localGoertzelBin.coeff = 2.0L * cosine;
				}
				else
				{
					localGoertzelBin.coeff = 0.0L;
				}
				dqGoertzelBins1.push_back( localGoertzelBin );
				dqGoertzelBins2.push_back( localGoertzelBin );
			}
		}
	}

	noValuesInAdaptiveThresholdCalcs = goertzelNoFrequenciesPerString * noOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs;
	noValuesInAdaptiveThresholdCalcsDbl = (long double)noValuesInAdaptiveThresholdCalcs;
	noValuesInAdaptiveThresholdCalcsDblMinus1 = noValuesInAdaptiveThresholdCalcsDbl - 1.0L;

	goertzelStatisticsInit( );
}

void tuneComponent::goertzelReset( )
{
	for ( auto& binToReset : *pDqGoertzelBinsIn )
	{
		binToReset.Q1 = 0.0L;
		binToReset.Q2 = 0.0L;
		binToReset.resultMagnitudeSquared = 0.0L;
	}
}

void tuneComponent::goertzelStatisticsInit( )
{
	const ScopedLock sl( drawSpectrogramLockMutex );

	dqGoertzelResultStatistics.clear( );

	GOERTZELRESULTSTATISTICS localGoertzelMaxValueBin;
	localGoertzelMaxValueBin.goertzelBin.coeff = 0.0L;
	localGoertzelMaxValueBin.goertzelBin.Q1 = 0.0L;
	localGoertzelMaxValueBin.goertzelBin.Q2 = 0.0L;
	localGoertzelMaxValueBin.goertzelBin.resultMagnitudeSquared = 0.0L;
	localGoertzelMaxValueBin.goertzelBin.targetFreq = 0.0L;
	localGoertzelMaxValueBin.goertzelBin.xCoordinat = 0.0f;
	for ( unsigned int i = 1; i <= iNoValsInAvgFreqsOutOfTuneCalc; i++ )
	{
		localGoertzelMaxValueBin.freqsOutOfTune.push_back( 0.0L );
	}
	double globalThreshold = getXmlTagDISPLAYCONTROL( )->getDoubleAttribute( "globalThresholdForShowing" );
	bool useGlobalThreshold = ( globalThreshold >= 0.0 );
	if ( useGlobalThreshold )
	{
		localGoertzelMaxValueBin.thresholdForShowingResultMagnitudeSquared = (long double)globalThreshold;
	}

	localGoertzelMaxValueBin.showThisOne = false;
	localGoertzelMaxValueBin.meanFreqsOutOfTune = 0.0L;
	localGoertzelMaxValueBin.meanOutOfTuneXCoordinat = 0.0;
	if ( adaptiveBackgroundSoundReductionIsOn )
	{
		localGoertzelMaxValueBin.oldMagnitudeSquareddResults.assign( noValuesInAdaptiveThresholdCalcs, 0.0 );
	}
	else
	{
		localGoertzelMaxValueBin.oldMagnitudeSquareddResults.clear( );
	}
	for ( unsigned int idxOfGuitarString = 0; idxOfGuitarString < 6; idxOfGuitarString++ )
	{
		localGoertzelMaxValueBin.goertzelBin.guitarStringFreq = guitar[ idxOfGuitarString ];
		localGoertzelMaxValueBin.stringName = guitarStringNames[ idxOfGuitarString ];
		if ( !useGlobalThreshold )
		{
			localGoertzelMaxValueBin.thresholdForShowingResultMagnitudeSquared =
				getXmlTagDISPLAYCONTROL( )->getDoubleAttribute( String( guitarStringNames[ idxOfGuitarString ] + "threshold" ) );
		}
		dqGoertzelResultStatistics.push_back( localGoertzelMaxValueBin );
	}
}

void tuneComponent::goertzelCalcResults( )
{
	using namespace decimationAndFilterConstants;

	max_goertzelValue = -DBL_MAX;

	GOERTZELRESULTSTATISTICS& E2_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( E2idx ); // E2idx = 0
	GOERTZELRESULTSTATISTICS& A2_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( A2idx ); // A2idx = 1
	GOERTZELRESULTSTATISTICS& D3_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( D3idx ); // D3idx = 2
	GOERTZELRESULTSTATISTICS& G3_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( G3idx ); // G3idx = 3
	GOERTZELRESULTSTATISTICS& B3_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( B3idx ); // B3idx = 4
	GOERTZELRESULTSTATISTICS& E4_GoertzelStatisticsBin = dqGoertzelResultStatistics.at( E4idx ); // E4idx = 5
	E2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;
	A2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;
	D3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;
	G3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;
	B3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;
	E4_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared = -DBL_MAX;


	if ( adaptiveBackgroundSoundReductionIsOn )
	{
		// Remove oldMagnitudeSquareddResults not to be used any longer
		for ( auto& GoertzelResultStatistics : dqGoertzelResultStatistics )
		{
			GoertzelResultStatistics.oldMagnitudeSquareddResults.erase
			(
				GoertzelResultStatistics.oldMagnitudeSquareddResults.begin( )
				, GoertzelResultStatistics.oldMagnitudeSquareddResults.begin( ) + goertzelNoFrequenciesPerString
			);
		}
		for ( auto& binToCalc : *pDqGoertzelBinsOut )
		{
			//   result = Q1 * Q1 + Q2 * Q2 - Q1 * Q2 * coeff;
			binToCalc.resultMagnitudeSquared = std::pow( binToCalc.Q1, 2 ) + std::pow( binToCalc.Q2, 2 ) - ( binToCalc.Q1 * binToCalc.Q2 * binToCalc.coeff );

			if ( max_goertzelValue < binToCalc.resultMagnitudeSquared )
			{
				max_goertzelValue = binToCalc.resultMagnitudeSquared;
			}

			// Find max around guitar string freqs.
			switch ( binToCalc.guitarStringFreq )
			{
				case E2:
					{
						E2_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( E2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							E2_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case A2:
					{
						A2_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( A2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							A2_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case D3:
					{
						D3_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( D3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							D3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case G3:
					{
						G3_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( G3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							G3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case B3:
					{
						B3_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( B3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							B3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case E4:
					{
						E4_GoertzelStatisticsBin.oldMagnitudeSquareddResults.push_back( (double)( binToCalc.resultMagnitudeSquared ) ); // Save for adaptive calcs
						if ( E4_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							E4_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
			}
		}

		long double meanValue, accum;
		for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
		{
			// Calculate threshold for string
			meanValue = 0.0L;
			for ( double oldMagnitudeSquareddResult : goertzelStatistics.oldMagnitudeSquareddResults )
			{
				meanValue += oldMagnitudeSquareddResult;
			}
			meanValue /= noValuesInAdaptiveThresholdCalcsDbl;

			accum = 0.0f;
			for ( double oldMagnitudeSquareddResult : goertzelStatistics.oldMagnitudeSquareddResults )
			{
				accum += std::pow( ( oldMagnitudeSquareddResult - meanValue ), 2 );
			}

			goertzelStatistics.thresholdForShowingResultMagnitudeSquared = meanValue + std::sqrt( accum / noValuesInAdaptiveThresholdCalcsDblMinus1 );

			if ( goertzelStatistics.goertzelBin.resultMagnitudeSquared >= goertzelStatistics.thresholdForShowingResultMagnitudeSquared ) // Only take into account if threshold high enough
			{
				goertzelStatistics.showThisOne = true;
				if ( goertzelStatistics.freqsOutOfTune.size( ) == iNoValsInAvgFreqsOutOfTuneCalc )
				{
					goertzelStatistics.freqsOutOfTune.pop_back( );
				}
				goertzelStatistics.freqsOutOfTune.push_front
				(
					goertzelStatistics.goertzelBin.targetFreq - (long double)goertzelStatistics.goertzelBin.guitarStringFreq
				);
				goertzelStatistics.meanFreqsOutOfTune = std::accumulate
				(
					goertzelStatistics.freqsOutOfTune.begin( )
					, goertzelStatistics.freqsOutOfTune.end( ), 0.0L
				) / (long double)goertzelStatistics.freqsOutOfTune.size( );
				goertzelStatistics.meanOutOfTuneXCoordinat = (float)( freqToXCoordFactor * ( goertzelStatistics.meanFreqsOutOfTune + goertzelStatistics.goertzelBin.guitarStringFreq - lowestFreqToDisplayDataForHz ) );
			}
			else // Pop old value out
			{
				goertzelStatistics.showThisOne = false;
				if ( goertzelStatistics.freqsOutOfTune.size( ) != 0 )
				{
					goertzelStatistics.freqsOutOfTune.pop_back( );
				}
			}
		}
	}
	else
	{
		for ( auto& binToCalc : *pDqGoertzelBinsOut )
		{
			//   result = Q1 * Q1 + Q2 * Q2 - Q1 * Q2 * coeff;
			binToCalc.resultMagnitudeSquared = std::pow( binToCalc.Q1, 2 ) + std::pow( binToCalc.Q2, 2 ) - ( binToCalc.Q1 * binToCalc.Q2 * binToCalc.coeff );

			if ( max_goertzelValue < binToCalc.resultMagnitudeSquared )
			{
				max_goertzelValue = binToCalc.resultMagnitudeSquared;
			}

			// Find max around guitar string freqs.
			switch ( binToCalc.guitarStringFreq )
			{
				case E2:
					{
						if ( E2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							E2_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case A2:
					{
						if ( A2_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							A2_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case D3:
					{
						if ( D3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							D3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case G3:
					{
						if ( G3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							G3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case B3:
					{
						if ( B3_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							B3_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
				case E4:
					{
						if ( E4_GoertzelStatisticsBin.goertzelBin.resultMagnitudeSquared < binToCalc.resultMagnitudeSquared )
						{
							E4_GoertzelStatisticsBin.goertzelBin = binToCalc;
						}
						break;
					}
			}
		}

		for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
		{
			if ( goertzelStatistics.goertzelBin.resultMagnitudeSquared >= goertzelStatistics.thresholdForShowingResultMagnitudeSquared ) // Only take into account if threshold high enough
			{
				goertzelStatistics.showThisOne = true;
				if ( goertzelStatistics.freqsOutOfTune.size( ) == iNoValsInAvgFreqsOutOfTuneCalc )
				{
					goertzelStatistics.freqsOutOfTune.pop_back( );
				}
				goertzelStatistics.freqsOutOfTune.push_front
				(
					(float)goertzelStatistics.goertzelBin.targetFreq - (float)goertzelStatistics.goertzelBin.guitarStringFreq
				);
				goertzelStatistics.meanFreqsOutOfTune = std::accumulate
				(
					goertzelStatistics.freqsOutOfTune.begin( )
					, goertzelStatistics.freqsOutOfTune.end( )
					, 0.0L
				) / (float)goertzelStatistics.freqsOutOfTune.size( );
				goertzelStatistics.meanOutOfTuneXCoordinat =
					(float)( freqToXCoordFactor * ( goertzelStatistics.meanFreqsOutOfTune
													+ goertzelStatistics.goertzelBin.guitarStringFreq
													- lowestFreqToDisplayDataForHz ) );
			}
			else // Pop old value out
			{
				goertzelStatistics.showThisOne = false;
				if ( goertzelStatistics.freqsOutOfTune.size( ) != 0 )
				{
					goertzelStatistics.freqsOutOfTune.pop_back( );
				}
			}
		}
	}


	if ( thresholdAutoCalibrationInProgress )
	{
		static unsigned int noSamplesNowInMeasuredNoiseCalcs = 0;

		spEksNotModalProgressWindow->setProgress( noSamplesNowInMeasuredNoiseCalcs / (double)noSamplesWantedInMeasuredNoiseCalcs );

		unsigned int idxOfGuitarString = 0;
		for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
		{
			measuredNoise[ idxOfGuitarString++ ].push_back( goertzelStatistics.goertzelBin.resultMagnitudeSquared );
		}
		if ( ++noSamplesNowInMeasuredNoiseCalcs >= noSamplesWantedInMeasuredNoiseCalcs )
		{
			// Got the # samples wanted. Calculate Mean a Standard Deviation
			long double sum, meanValue, accum, threshold;
			idxOfGuitarString = 0;
			for ( auto& measuredNoiseForGuitarString : measuredNoise )
			{
				sum = std::accumulate( measuredNoiseForGuitarString.begin( ), measuredNoiseForGuitarString.end( ), 0.0L );
				meanValue = sum / (long double)noSamplesWantedInMeasuredNoiseCalcs;

				accum = 0.0L;
				std::for_each
				(
					measuredNoiseForGuitarString.begin( ), measuredNoiseForGuitarString.end( ),
					[ & ]( const long double noise )
					{
						accum += std::pow( ( noise - meanValue ), 2 );
						//accum += (noise - m) * (noise - m);
					}
				);

				threshold = meanValue + std::sqrt( accum / noSamplesWantedInMeasuredNoiseCalcsMinus1 );
				dqGoertzelResultStatistics[ idxOfGuitarString ].thresholdForShowingResultMagnitudeSquared = threshold;

				getXmlTagDISPLAYCONTROL( )->setAttribute( String( guitarStringNames[ idxOfGuitarString ] + "threshold" ), (double)threshold );
				idxOfGuitarString++;
			}
			getXmlTagDISPLAYCONTROL( )->setAttribute( "globalThresholdForShowing", Auto_globalThresholdForShowing );
			// Write to xml file
			pXmlGuitarFineTuneConfig->writeConfigToXmlFile( );

			measuredNoise.clear( ); // Unused hereafter

			// Close progress bar
			spEksNotModalProgressWindow->stopAll( );

			thresholdAutoCalibrationInProgress = false; // Stop measuring
			noSamplesNowInMeasuredNoiseCalcs = 0;

			if ( adaptiveBackgroundSoundReductionIsOn )
			{
				pDisplayControlComponent.lock( )->setToAdapThresholdTextEditor( ); // Show "Adap" in thresholdTextEditor
			}
			pDisplayControlComponent.lock( )->enableAdaptiveToggleButton( );
		}
	}
}


void tuneComponent::calcHalfSinePeriodValues
(
	unsigned int bffrLgth
)
{
	/*
	 Make ½ sin period ramp = (sin(((3/4)*(2*pi))...(pi/2)...) + 1)/2
	 Full currentBufferSizeInUse in
	 fullBffrLgthHalfSinePeriodValues
	 and ½ * currentBufferSizeInUse in
	 halfBffrLgthHalfSinePeriodValues
	*/

	static unsigned int bffrLgthLastTime = 0;

	if ( bffrLgthLastTime != bffrLgth )
	{
		// fullBffrLgthHalfSinePeriodValues
		double sinArgIncrement = ( piHalf - threeQuatersOf2Pi ) / ( (double)bffrLgth - (double)1.0f );
		double sinArg = threeQuatersOf2Pi - sinArgIncrement;

		fullBffrLgthHalfSinePeriodValues.resize( bffrLgth );
		std::generate
		(
			fullBffrLgthHalfSinePeriodValues.begin( ), fullBffrLgthHalfSinePeriodValues.end( ),
			[ &/*sinArg, sinArgIncrement*/ ]
		( )
			{
				sinArg += sinArgIncrement;
				return ( std::sin( sinArg ) * (double)0.5f ) + (double)0.5f;
			}
		);

		// halfBffrLgthHalfSinePeriodValues
		sinArgIncrement = ( piHalf - threeQuatersOf2Pi ) / ( (double)( bffrLgth >> 1 ) - (double)1.0f );
		sinArg = threeQuatersOf2Pi - sinArgIncrement;

		halfBffrLgthHalfSinePeriodValues.resize( bffrLgth >> 1 /* = * ½ */ );
		std::generate
		(
			halfBffrLgthHalfSinePeriodValues.begin( ), halfBffrLgthHalfSinePeriodValues.end( ),
			[ &/*sinArg, sinArgIncrement*/ ]
		( )
			{
				sinArg += sinArgIncrement;
				return ( std::sin( sinArg ) * (double)0.5f ) + (double)0.5f;
			}
		);

		bffrLgthLastTime = bffrLgth;
	}

}


void tuneComponent::calcGuitarStringSoundsRampFaktors
(
	std::back_insert_iterator< std::vector<double> > rampBackInsrtr
	, bool halfBffrLgth
	, double rampStartGain
	, double rampEndGain
)
{ // Make ramp = rampStartGain + (gain * (½ sin period ramp))

	double gain = rampEndGain - rampStartGain;

	if ( halfBffrLgth )
	{
		// Calc ramp = rampStartGain + (gain * halfBffrLgthHalfSinePeriodValues)
		std::transform
		(
			halfBffrLgthHalfSinePeriodValues.begin( )
			, halfBffrLgthHalfSinePeriodValues.end( )
			, rampBackInsrtr
			, [ rampStartGain, gain ]
			( double halfSinePeriodValue )
			{
				return rampStartGain + ( gain * halfSinePeriodValue );
			}
		);
	}
	else
	{
		// Calc ramp = rampStartGain + (gain * fullBffrLgthHalfSinePeriodValues)
		std::transform
		(
			fullBffrLgthHalfSinePeriodValues.begin( )
			, fullBffrLgthHalfSinePeriodValues.end( )
			, rampBackInsrtr
			, [ rampStartGain, gain ]
			( double halfSinePeriodValue )
			{
				return rampStartGain + ( gain * halfSinePeriodValue );
			}
		);
	}
}


void tuneComponent::calcGuitarStringSoundsDualRampFaktors
(
	std::back_insert_iterator< std::vector<double> > dualRampBackInsrtr
	, double firstRampStartGain
	, double firstRampEndGain
	, double lastRampStartGain
	, double lastRampEndGain
)
{ // Make exponential, exp2, up/down ramps (= sinusoidal ?)

	calcGuitarStringSoundsRampFaktors( dualRampBackInsrtr, true, firstRampStartGain, firstRampEndGain );

	calcGuitarStringSoundsRampFaktors( dualRampBackInsrtr, true, lastRampStartGain, lastRampEndGain );
}


void tuneComponent::guitarStringSoundsRampFillInRampedTones
(
	std::vector<float>::iterator outGitarStringSoundsItrtr
	, std::vector<GUITARSTRINGSPHASES*> rampedGuitarStringsSinePhases
	, std::vector<double>& rampFaktors
)
{
#define f2PI (6.28318530717958647692)

	float currentPhase;
	float phaseDeltaPerSample;

	// First the ramped sounds
	for ( auto gStringPhase : rampedGuitarStringsSinePhases )
	{
		phaseDeltaPerSample = ( *gStringPhase ).phaseDeltaPerSample;
		currentPhase = ( *gStringPhase ).currentPhase;
		std::transform
		(
			rampFaktors.begin( ), rampFaktors.end( ), outGitarStringSoundsItrtr, outGitarStringSoundsItrtr,
			[ &currentPhase, phaseDeltaPerSample ]
		( double rampVal, float guitarStringSoundsIn ) /*mutable*/
			{
				currentPhase = std::fmod( currentPhase + phaseDeltaPerSample, (float)f2PI );
				return guitarStringSoundsIn + (float)( rampVal * std::sin( currentPhase ) );
			}
		);
		( *gStringPhase ).currentPhase = currentPhase;
	}
}

void tuneComponent::guitarStringSoundsRampFillInTheUnRampedTones
(
	std::vector<float>::iterator outGitarStringSoundsBeginItrtr
	, std::vector<float>::iterator outGitarStringSoundsEndItrtr
	, std::vector<GUITARSTRINGSPHASES*> unRampedGuitarStringsSinePhases
	, double gainToUse
)
{
#define f2PI (6.28318530717958647692)

	float currentPhase;
	float phaseDeltaPerSample;

	// First the ramped sounds
	for ( auto gStringPhase : unRampedGuitarStringsSinePhases )
	{
		phaseDeltaPerSample = ( *gStringPhase ).phaseDeltaPerSample;
		currentPhase = ( *gStringPhase ).currentPhase;
		std::transform
		(
			outGitarStringSoundsBeginItrtr, outGitarStringSoundsEndItrtr, outGitarStringSoundsBeginItrtr,
			[ &currentPhase, phaseDeltaPerSample, gainToUse ]
		( float guitarStringSoundsIn )
			{
				currentPhase = std::fmod( currentPhase + phaseDeltaPerSample, (float)f2PI );
				return guitarStringSoundsIn + (float)( gainToUse * std::sin( currentPhase ) );
			}
		);
		( *gStringPhase ).currentPhase = currentPhase;
	}
}


void tuneComponent::allGuitarStringSoundsOff( )
{
	rampAllStringSounds( true );

	stringGainToUse = 0.0f;
	doPlayGuitarStringSounds = false;

	guitarStringSoundsOnLastTime.assign( 6, false ); // No string sounds off last time
}


void tuneComponent::controlGuitarStringSounds( std::deque<bool> guitarStringSoundsOn )
{
	if ( !std::any_of( guitarStringSoundsOn.begin( ), guitarStringSoundsOn.end( ), [ ]( bool i )
					   {
						   return i;
					   } )
		 && std::any_of( guitarStringSoundsOnLastTime.begin( ), guitarStringSoundsOnLastTime.end( ), [ ]( bool i )
						 {
							 return i;
						 } )
						   )
	{ // Last string off. Sound output must be disabled

		if ( !outputMuteToggleButtonOn && !stringsMuteToggleButtonOn )
		{
			// calc down ramp
			guitarStringSoundsRamp.clear( );
			guitarStringSoundsRamp.resize( currentBufferSizeInUse, 0.0f );
			std::vector<double> theRamp;
			std::back_insert_iterator< std::vector<double> > rampBackInsrtr( theRamp );

			{ // Begin scope of guitarStringSoundsLockMutex
				const ScopedLock sl( guitarStringSoundsLockMutex );

				playGuitarStringSoundsRamp = true; // Lure getNextAudioBlock into part w. guitar strings ramp

				calcGuitarStringSoundsRampFaktors
				(
					rampBackInsrtr
					, false
					, (double)stringGainToUse
					, (double)0.0f
				);
				guitarStringSoundsRampFillInRampedTones
				(
					guitarStringSoundsRamp.begin( )
					, ptrsToGuitarStringsSinePhases
					, theRamp
				);

				stringGainToUse = 0.0f;

				doPlayGuitarStringSounds = false;
			} // End scope of guitarStringSoundsLockMutex
		}
		else
		{
			doPlayGuitarStringSounds = false;
		}


		guitarStringSoundsOnLastTime = guitarStringSoundsOn;

		return;
	}

						 std::vector<GUITARSTRINGSPHASES*> newPtrsToGuitarStringsSinePhases( 0 );
						 std::vector<GUITARSTRINGSPHASES*> addedPtrsToGuitarStringsSinePhases( 0 );
						 std::vector<GUITARSTRINGSPHASES*> removedPtrsToGuitarStringsSinePhases( 0 );
						 std::vector<GUITARSTRINGSPHASES*> unChangedPtrsToGuitarStringsSinePhases( 0 );
						 GUITARSTRINGSPHASES* guitarStringSinePhaseFound;
						 bool unChangedPtrsToGuitarStringsSinePhasesExists = false;
						 bool ptrsToGuitarStringsSinePhasesAdded = false;
						 bool ptrsToGuitarStringsSinePhasesRemoved = false;

						 for ( int i = 0; i < 6; i++ )
						 {
							 if ( guitarStringSoundsOn[ i ] )
							 {
								 if ( guitarStringSoundsOnLastTime[ i ] )
								 {
									 // This string was on last time also. Find it in old ptrsToGuitarStringsSinePhases
									 guitarStringSinePhaseFound =
										 *( std::find_if( ptrsToGuitarStringsSinePhases.begin( ), ptrsToGuitarStringsSinePhases.end( )
														  , [ &gFreq = guitar[ i ] ]( GUITARSTRINGSPHASES* gStrPhas ) { return ( *gStrPhas ).guitarStringFreq == gFreq; } ) );

									 newPtrsToGuitarStringsSinePhases.push_back( guitarStringSinePhaseFound );

									 unChangedPtrsToGuitarStringsSinePhases.push_back( newPtrsToGuitarStringsSinePhases.back( ) );
									 unChangedPtrsToGuitarStringsSinePhasesExists = true;
								 }
								 else
								 {
									 guitarStringsSinePhases[ i ].guitarStringFreq = (float)guitar[ i ];
									 guitarStringsSinePhases[ i ].phaseDeltaPerSample = (float)( float_2PI * (float)guitar[ i ] / currentSampleRateInUse );
									 guitarStringsSinePhases[ i ].currentPhase = -( guitarStringsSinePhases[ i ].phaseDeltaPerSample ); // So this sin starts w. phase = 0;

									 newPtrsToGuitarStringsSinePhases.push_back( &guitarStringsSinePhases[ i ] );

									 addedPtrsToGuitarStringsSinePhases.push_back( newPtrsToGuitarStringsSinePhases.back( ) );
									 ptrsToGuitarStringsSinePhasesAdded = true;
								 }
							 }
							 else
							 {
								 if ( guitarStringSoundsOnLastTime[ i ] )
								 {
									 // This string was on last time also. Find it in old ptrsToGuitarStringsSinePhases and save it in removedPtrsToGuitarStringsSinePhases
									 removedPtrsToGuitarStringsSinePhases.push_back
									 (
										 *( std::find_if( ptrsToGuitarStringsSinePhases.begin( ), ptrsToGuitarStringsSinePhases.end( )
														  , [ &gFreq = guitar[ i ] ]( GUITARSTRINGSPHASES* gStrPhas ) { return ( *gStrPhas ).guitarStringFreq == gFreq; } ) )
									 );
									 ptrsToGuitarStringsSinePhasesRemoved = true;
								 }
							 }
						 }

						 if ( !outputMuteToggleButtonOn && !stringsMuteToggleButtonOn )
						 {
							 // There are guitar string sounds to ramp
							 // Save old gain
							 double oldStringGainToUse = stringGainToUse;
							 // Calc new string gain to use based on # newPtrsToGuitarStringsSinePhases
							 stringGainToUse = outputGain * stringsGain / ( newPtrsToGuitarStringsSinePhases.size( ) );

							 guitarStringSoundsRamp.clear( );
							 guitarStringSoundsRamp.resize( currentBufferSizeInUse, 0.0f );
							 std::vector<double> theRamp( 0 );
							 std::back_insert_iterator< std::vector<double> > rampBackInsrtr( theRamp );

							 { // Begin scope of guitarStringSoundsLockMutex
								 const ScopedLock sl( guitarStringSoundsLockMutex );

							 #define ALWAYS_USE_FULL_BUFFER_RAMPS 1
							 #if !ALWAYS_USE_FULL_BUFFER_RAMPS

								 playGuitarStringSoundsRamp = true; // Lure getNextAudioBlock into part w. guitar strings ramp
								 if ( unChangedPtrsToGuitarStringsSinePhasesExists )
								 {
									 // Some tones are still there as last time

									 if ( ptrsToGuitarStringsSinePhasesRemoved && ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds to ramp down AND guitar string sounds to ramp up

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp untouched sounds to their new gain
										 // Make ramp
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
										 guitarStringSoundsRampFillInTheUnRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Point to last half of buffer
											 , guitarStringSoundsRamp.end( ) // End of buffer
											 , unChangedPtrsToGuitarStringsSinePhases
											 , (double)stringGainToUse
										 );

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Point to last half of buffer
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds to ramp up

										 // Ramp untouched sounds to their new gain

										 // Make ramp
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
										 guitarStringSoundsRampFillInTheUnRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Point to last half of buffer
											 , guitarStringSoundsRamp.end( ) // End of buffer
											 , unChangedPtrsToGuitarStringsSinePhases
											 , (double)stringGainToUse
										 );

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Point to last half of buffer
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesRemoved )
									 {
										 // There are guitar string sounds to ramp down

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
										 guitarStringSoundsRampFillInTheUnRampedTones
										 (
											 guitarStringSoundsRamp.begin( ) // Point to first half of buffer
											 , std::prev( guitarStringSoundsRamp.end( ), currentBufferSizeInUse >> 1 ) // End first half of buffer
											 , unChangedPtrsToGuitarStringsSinePhases
											 , (double)stringGainToUse
										 );

										 // Ramp untouched sounds to their new gain
										 // Make ramp
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Last half of buffer
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
								 }
								 else
								 {
									 // There are no untouched tones

									 if ( ptrsToGuitarStringsSinePhasesRemoved && ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are some guitar string sounds added AND some tones removed

										 // Ramp down removed tones 
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp added sounds to their new gain
										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , true
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 std::next( guitarStringSoundsRamp.begin( ), currentBufferSizeInUse >> 1 ) // Point to last half of buffer
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds added

										 // Ramp sounds to their new gain
										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( ) // Point to last half of buffer
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

									 }
									 else if ( ptrsToGuitarStringsSinePhasesRemoved )
									 {
										 // There are removed guitar string sounds

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
								 }

								 ptrsToGuitarStringsSinePhases = newPtrsToGuitarStringsSinePhases;
								 doPlayGuitarStringSounds = true;

							 #else // !(ALWAYS_USE_FULL_BUFFER_RAMPS)

								 playGuitarStringSoundsRamp = true; // Lure getNextAudioBlock into part w. guitar strings ramp
								 if ( unChangedPtrsToGuitarStringsSinePhasesExists )
								 {
									 // Some tones are still there as last time

									 if ( ptrsToGuitarStringsSinePhasesRemoved && ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds to ramp down AND guitar string sounds to ramp up

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp untouched sounds to their new gain
										 // Make ramp
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds to ramp up

										 // Ramp untouched sounds to their new gain
										 // Make ramp
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesRemoved )
									 {
										 // There are guitar string sounds to ramp down

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp untouched sounds to their new gain
										 // Make ramp
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , oldStringGainToUse
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , unChangedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
								 }
								 else
								 {
									 // There are no untouched tones

									 if ( ptrsToGuitarStringsSinePhasesRemoved && ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are some guitar string sounds added AND some tones removed

										 // Ramp down removed tones 
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
									 else if ( ptrsToGuitarStringsSinePhasesAdded )
									 {
										 // There are guitar string sounds added

										 // Ramp sounds to their new gain

										 // Ramp new tones to the gain to use
										 theRamp.clear( );
										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)0.0f
											 , (double)stringGainToUse
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( ) // Point to last half of buffer
											 , addedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );

									 }
									 else if ( ptrsToGuitarStringsSinePhasesRemoved )
									 {
										 // There are removed guitar string sounds

										 calcGuitarStringSoundsRampFaktors
										 (
											 rampBackInsrtr
											 , false
											 , (double)oldStringGainToUse
											 , (double)0.0f
										 );
										 guitarStringSoundsRampFillInRampedTones
										 (
											 guitarStringSoundsRamp.begin( )
											 , removedPtrsToGuitarStringsSinePhases
											 , theRamp
										 );
									 }
								 }

								 ptrsToGuitarStringsSinePhases = newPtrsToGuitarStringsSinePhases;
								 doPlayGuitarStringSounds = true;

							 #endif // !(ALWAYS_USE_FULL_BUFFER_RAMPS)

							 } // End scope of guitarStringSoundsLockMutex
						 }
						 else
						 {
							 stringGainToUse = outputGain * stringsGain / ( newPtrsToGuitarStringsSinePhases.size( ) );
							 ptrsToGuitarStringsSinePhases = newPtrsToGuitarStringsSinePhases;
							 doPlayGuitarStringSounds = true;
						 }

						 guitarStringSoundsOnLastTime = guitarStringSoundsOn;

}


void tuneComponent::setStringsGain( float gain )
{
	stringsGain = gain;
	stringGainToUse = outputGain * stringsGain / ( ptrsToGuitarStringsSinePhases.size( ) );
}

void tuneComponent::rampAllStringSounds( bool ranpDown )
{
	// Begin scope of guitarStringSoundsLockMutex
	const ScopedLock sl( guitarStringSoundsLockMutex );

	playGuitarStringSoundsRamp = true; // Lure getNextAudioBlock into part w. guitar strings ramp

	guitarStringSoundsRamp.clear( );
	guitarStringSoundsRamp.resize( currentBufferSizeInUse, 0.0f );
	std::vector<double> theRamp;
	std::back_insert_iterator< std::vector<double> > rampBackInsrtr( theRamp );

	if ( ranpDown )
	{
		// Ramp string sounds down to 0
		calcGuitarStringSoundsRampFaktors
		(
			rampBackInsrtr
			, false
			, (double)stringGainToUse
			, (double)0.0f
		);
		guitarStringSoundsRampFillInRampedTones
		(
			guitarStringSoundsRamp.begin( )
			, ptrsToGuitarStringsSinePhases
			, theRamp
		);
	}
	else
	{
		// Ramp string sounds up from 0 to stringGainToUse
		calcGuitarStringSoundsRampFaktors
		(
			rampBackInsrtr
			, false
			, (double)0.0f
			, (double)stringGainToUse
		);
		guitarStringSoundsRampFillInRampedTones
		(
			guitarStringSoundsRamp.begin( )
			, ptrsToGuitarStringsSinePhases
			, theRamp
		);
	}
	// End scope of guitarStringSoundsLockMutex
}

void tuneComponent::setStringsMuteToggleButtonOnFlag( bool flagValue )
{
	if ( doPlayGuitarStringSounds && !outputMuteToggleButtonOn )
	{
		rampAllStringSounds( flagValue );
	}

	stringsMuteToggleButtonOn = flagValue;

}

void tuneComponent::setInputGain( float gain )
{
	inputGain = gain;
}

void tuneComponent::setInputMuteToggleButtonOnFlag( bool flagValue )
{
	inputMuteToggleButtonOn = flagValue;
}

void tuneComponent::setOutputGain( float gain )
{
	outputGain = gain;
	stringGainToUse = outputGain * stringsGain / ( ptrsToGuitarStringsSinePhases.size( ) );
}

void tuneComponent::setOutputMuteToggleButtonOnFlag( bool flagValue )
{
	if ( doPlayGuitarStringSounds && !stringsMuteToggleButtonOn )
	{
		// Begin scope of guitarStringSoundsLockMutex
		const ScopedLock sl( guitarStringSoundsLockMutex );

		playGuitarStringSoundsRamp = true; // Lure getNextAudioBlock into part w. guitar strings ramp

		guitarStringSoundsRamp.clear( );
		guitarStringSoundsRamp.resize( currentBufferSizeInUse, 0.0f );
		std::vector<double> theRamp;
		std::back_insert_iterator< std::vector<double> > rampBackInsrtr( theRamp );

		if ( flagValue )
		{
			// Ramp string sounds down to 0
			calcGuitarStringSoundsRampFaktors
			(
				rampBackInsrtr
				, false
				, (double)stringGainToUse
				, (double)0.0f
			);
			guitarStringSoundsRampFillInRampedTones
			(
				guitarStringSoundsRamp.begin( )
				, ptrsToGuitarStringsSinePhases
				, theRamp
			);
		}
		else
		{
			// Ramp string sounds up from 0 to stringGainToUse
			calcGuitarStringSoundsRampFaktors
			(
				rampBackInsrtr
				, false
				, (double)0.0f
				, (double)stringGainToUse
			);
			guitarStringSoundsRampFillInRampedTones
			(
				guitarStringSoundsRamp.begin( )
				, ptrsToGuitarStringsSinePhases
				, theRamp
			);
		}
		// End scope of guitarStringSoundsLockMutex
	}

	outputMuteToggleButtonOn = flagValue;
}

void tuneComponent::setshowFilters( bool flagValue )
{
	showFiltersToggleButtonOn = flagValue;
}

void tuneComponent::setShowIndicators( bool flagValue )
{
	showIndicatorsToggleButtonOn = flagValue;
}

void tuneComponent::setShowSpectrum( bool flagValue )
{
	showSpectrumToggleButtonOn = flagValue;
}

void tuneComponent::doSetShowFFT( bool flagOn )
{
	if ( showFFTToggleButtonOn ) // FFT on already ?
	{
		// Free resources
		delete gfft;
		gfft = nullptr;
		std::free( fftDataBuffer1 );
		fftDataBuffer1 = nullptr;
		std::free( fftDataBuffer2 );
		fftDataBuffer2 = nullptr;
	}
	if ( flagOn )
	{
		// runtime definition of the data length
		p = fftOrder;
		// initialization of the object factory
		FactoryInit<GFFTList<GFFT, gfftMin, gfftMax>::Result>::apply( gfft_factory );
		// create an instance of the GFFT
		gfft = gfft_factory.CreateObject( p );

		// Data buffers
		fftDataBuffer1 = (double*)std::calloc( fftSizeDouble, sizeof( double ) );
		fftDataBuffer2 = (double*)std::calloc( fftSizeDouble, sizeof( double ) );
		inBuffer1 = ( complex<double>* )fftDataBuffer1;
		fftData1 = fftDataBuffer2;
		inBuffer2 = ( complex<double>* )fftDataBuffer2;
		fftData2 = fftDataBuffer1;
		// buffer pointers used in the data processing
		inBuffer = inBuffer2; // is toggeled buffer 2,1,2....
		fftData = fftData2; // is toggled 1,2,1,...

		bSwitchBufferTo2 = false;

		noOfInputValues = 0;

		// display
		fDelta = (long double)decimatedSampleRate / (long double)fftSize;
		firstFftDataToDisplay = (int)round( (long double)lowestFreqToDisplayDataForHz / fDelta );
		lastFftDataToDisplay = (int)round( (long double)highestFreqToDisplayDataForHz / fDelta );
		resToDisply = (float)( (long double)widthOfTuneWindow * (long double)spaceBtwFftDataToDisplay / (long double)( (long double)lastFftDataToDisplay - (long double)firstFftDataToDisplay ) );
		timeSecundsPerFullAudioRecordBuffer = (float)( 1.0f / fDelta );
		if ( adaptiveNoSecondsComboBoxReady )
		{
			pDisplayControlComponent.lock( )->updateAdaptiveNoSecondsComboBox( timeSecundsPerFullAudioRecordBuffer );
		}
		noOfFullAudioRecordBuffersDuringTimeToFadeAwaySecunds = std::trunc( (float)timeToFadeAwaySecunds / timeSecundsPerFullAudioRecordBuffer );

		showFFTToggleButtonOn = flagOn;
	}
	else
	{
		showFFTToggleButtonOn = flagOn;
	}
}

void tuneComponent::setShowFFT( bool flagOn )
{
	const ScopedLock sl( drawSpectrogramLockMutex );

	doSetShowFFT( flagOn );
}

void tuneComponent::setshowFFTMaxIndictr( bool flagOn )
{
	showFFTMaxIndictrToggleButtonOn = flagOn;
}

void tuneComponent::setShowstringsOffTuneValues( bool flagOn )
{
	showStringsOffTuneValues = flagOn;
}

void tuneComponent::setshowThreshold( bool doShowThreshold )
{
	showThreshold = doShowThreshold;
}

void tuneComponent::setNoValsInAvgFreqsOutOfTuneCalc( int newNoValsInAvgFreqsOutOfTuneCalc )
{
	if ( newNoValsInAvgFreqsOutOfTuneCalc > 0 )
	{
		iNoValsInAvgFreqsOutOfTuneCalc = newNoValsInAvgFreqsOutOfTuneCalc;
		goertzelStatisticsInit( );
	}
}

int tuneComponent::getNoValsInAvgFreqsOutOfTuneCalc( )
{
	return iNoValsInAvgFreqsOutOfTuneCalc;
}

void tuneComponent::setThresholdResultMagnitudeSquaredForShowing( double newThresholdResultMagnitudeSquaredForShowing )
{
	if ( newThresholdResultMagnitudeSquaredForShowing >= 0 )
	{
		for ( auto& goertzelStatistics : dqGoertzelResultStatistics )
		{
			goertzelStatistics.thresholdForShowingResultMagnitudeSquared = newThresholdResultMagnitudeSquaredForShowing;
		}
	}
}

XmlElement* tuneComponent::getXmlTagDISPLAYCONTROL( )
{
	// check we're looking at the right kind of document..
	if ( pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig( ).hasTagName( "GUITARFINETUNECONFIG" ) )
	{
		// now we'll iterate its sub-elements looking for 'DISPLAYCONTROL' elements..
		return pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig( ).getChildByName( "DISPLAYCONTROL" );
	}
	return nullptr;
}

void tuneComponent::startThresholdAutoCalibrate( )
{
	spEksNotModalProgressWindow = std::make_shared<eksNotModalProgressWindow>
		(
			"Auto Calibrate" /*const std::string& msgToShow =*/
			, "Measuring background sound..." /*const std::string& subMsgToShow =*/
			, true /*bool callrUpdtsPrgrss =*/
			//, 60 /*unsigned int timeInSecs =*/
			//, this /*eksNotModalProgressWindowCallBacks* pTheClassToCallBack =*/
			//, 1 /*unsigned int secsBetwTicks =*/
			//, true /*bool hasButton =*/
			//, "OK" /*const std::string& buttonText =*/ 
			);


	measuredNoise.clear( );
	measuredNoise.resize( 6 );

	thresholdAutoCalibrationInProgress = true;

	pDisplayControlComponent.lock( )->setToAutoThresholdTextEditor( ); // Show "Auto" in thresholdTextEditor

}

int tuneComponent::getCurrentBufferSizeInUse( )
{
	return currentBufferSizeInUse;
}

void tuneComponent::makeHannWinCoefficients()
{
	// Make hann Window Coefficients
	double hannArgCoefficient = M_PI / (fftSize - 1);
	std::free(hannWinCoefficients);
	hannWinCoefficients = nullptr;
	hannWinCoefficients = (double*)std::calloc(fftSize, sizeof(double));

	if (hannWinCoefficients)
	{
		for (int k = 0; k < fftSize; k++)
		{
			hannWinCoefficients[k] = std::pow(std::sin(hannArgCoefficient * (double)k), 2);
		}
	}
}

void tuneComponent::setAudioRecordingBuffers( )
{
	std::free( audioRecordBuffer1 );
	audioRecordBuffer1 = nullptr;
	std::free( audioRecordBuffer2 );
	audioRecordBuffer2 = nullptr;
	audioRecordBuffer1 = (float*)std::calloc( fftSize, sizeof( float ) );
	audioRecordBuffer2 = (float*)std::calloc( fftSize, sizeof( float ) );
	if ( bSwitchBufferTo2 )
	{
		audioRecordBufferOut = audioRecordBuffer2;
		audioRecordBufferIn = audioRecordBuffer1;
	}
	else
	{
		audioRecordBufferOut = audioRecordBuffer1;
		audioRecordBufferIn = audioRecordBuffer2;
	}
}

int tuneComponent::getFftOrder( )
{
	return fftOrder;
}


void tuneComponent::setFftOrder( int newFftOrder )
{
	const ScopedLock sl( drawSpectrogramLockMutex );

	fftOrder = newFftOrder;
	fftSize = 1 << newFftOrder;
	fftSizeHalf = 1 << ( newFftOrder - 1 );
	fftSizeDouble = 1 << ( newFftOrder + 1 );

	makeHannWinCoefficients();

	if ( recorderSourceFilteredAudioOn )
	{
		setAudioRecordingBuffers( );
	}

	if ( showFFTToggleButtonOn )
	{
		doSetShowFFT( showFFTToggleButtonOn );
	}
	else
	{
		fDelta = (long double)decimatedSampleRate / (long double)fftSize;
		firstFftDataToDisplay = (int)round( (long double)lowestFreqToDisplayDataForHz / fDelta );
		lastFftDataToDisplay = (int)round( (long double)highestFreqToDisplayDataForHz / fDelta );
		resToDisply = (float)( (long double)widthOfTuneWindow * (long double)spaceBtwFftDataToDisplay / (long double)( (long double)lastFftDataToDisplay - (long double)firstFftDataToDisplay ) );
		timeSecundsPerFullAudioRecordBuffer = (float)( 1.0f / fDelta );
		if ( adaptiveNoSecondsComboBoxReady )
		{
			pDisplayControlComponent.lock( )->updateAdaptiveNoSecondsComboBox( timeSecundsPerFullAudioRecordBuffer );
		}
		noOfFullAudioRecordBuffersDuringTimeToFadeAwaySecunds = std::trunc( (float)timeToFadeAwaySecunds / timeSecundsPerFullAudioRecordBuffer );
	}
}

#ifdef THIS_IS_IOS
//void tuneComponent::setAirPlayBlueToothOnFlags(bool setAirPlayOn, bool setBlueToothOn)
void tuneComponent::setAirPlayOnFlags( bool setAirPlayOn )
{
	airPlayAllowed = setAirPlayOn;
	//blueToothAllowed = setBlueToothOn;
}
#endif // THIS_IS_IOS

void tuneComponent::setNotchFilters( )
{
	AudioDeviceManager::AudioDeviceSetup currentAudioConfig;
	sharedAudioDeviceManager->getAudioDeviceSetup( currentAudioConfig );
	readNotchFilterCoeffsAndConstants( (unsigned int)currentAudioConfig.sampleRate );
}

void tuneComponent::setUse50HzFilterFlag( bool shouldUse50HzFilter )
{
	usePowerGridFrequencyFilter = false; // Disable use of filter while configuring
	if ( shouldUse50HzFilter && use60HzFilter )
	{
		use60HzFilter = false;
	}
	use50HzFilter = shouldUse50HzFilter;
	setNotchFilters( );
	usePowerGridFrequencyFilter = use50HzFilter || use60HzFilter;
}

void tuneComponent::setUse60HzFilterFlag( bool shouldUse60HzFilter )
{
	usePowerGridFrequencyFilter = false; // Disable use of filter while configuring
	if ( shouldUse60HzFilter && use50HzFilter )
	{
		use50HzFilter = false;
	}
	use60HzFilter = shouldUse60HzFilter;
	setNotchFilters( );
	usePowerGridFrequencyFilter = use50HzFilter || use60HzFilter;
}

// Recording control members
void tuneComponent::setRecorderSourceRaw( )
{
	stopRecorderSourceFilteredAudio( );
	if ( !recorderSourceRawAudioOn )
	{
		spAudioRecorderController->setSourceRaw( );
		recorderSourceRawAudioOn = true;
	}
}

void tuneComponent::setRecorderSourceFiltered( )
{
	if ( !recorderSourceFilteredAudioOn )
	{
		spAudioRecorderController->setSourceFiltered( );
		setAudioRecordingBuffers( );
		spAudioRecorderController->filteredAudioSourceAboutToStart( decimatedSampleRate, fftSize );
		spTheAudioRecorderThread = std::make_shared<audioRecorderThread>( spAudioRecorderController );
		recorderSourceFilteredAudioOn = true;
		recorderSourceRawAudioOn = false;
	}
}

void tuneComponent::stopRecorderSourceFilteredAudio( )
{
	if ( recorderSourceFilteredAudioOn )
	{
		spTheAudioRecorderThread.reset( );
		spTheAudioRecorderThread = nullptr;
		recorderSourceFilteredAudioOn = false;
		std::free( audioRecordBuffer1 );
		audioRecordBuffer1 = nullptr;
		std::free( audioRecordBuffer2 );
		audioRecordBuffer2 = nullptr;
	}
}

std::shared_ptr<AudioRecorderControl> tuneComponent::getAudioRecorderController( )
{
	return spAudioRecorderController;
}

void tuneComponent::setAdaptiveBackgroundSoundReductionOn( bool setItOn )
{
	if ( !adaptiveBackgroundSoundReductionIsOn && setItOn )
	{
		for ( auto& stringStatistics : dqGoertzelResultStatistics )
		{
			stringStatistics.oldMagnitudeSquareddResults.assign( noValuesInAdaptiveThresholdCalcs, 0.0f );
		}

		getXmlTagDISPLAYCONTROL( )->setAttribute( "globalThresholdForShowing", Adaptive_globalThresholdForShowing );
		// Write to xml file
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile( );

		adaptiveBackgroundSoundReductionIsOn = setItOn;
		pDisplayControlComponent.lock( )->setToAdapThresholdTextEditor( ); // Show "Auto" in thresholdTextEditor
	}
	if ( adaptiveBackgroundSoundReductionIsOn && !setItOn )
	{
		adaptiveBackgroundSoundReductionIsOn = setItOn;

		saveThresholdForShowingResultsToXml( );
		getXmlTagDISPLAYCONTROL( )->setAttribute( "globalThresholdForShowing", Latest_globalThresholdForShowing );
		// Write to xml file
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile( );

		for ( auto& stringStatistics : dqGoertzelResultStatistics )
		{
			stringStatistics.oldMagnitudeSquareddResults.clear( );
		}
		if ( !thresholdAutoCalibrationInProgress )
		{
			pDisplayControlComponent.lock( )->setToLatestThresholdTextEditor( );
		}
	}
}

void tuneComponent::setNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs( int noBatches )
{
	using namespace decimationAndFilterConstants;

	noOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs = noBatches;
	noValuesInAdaptiveThresholdCalcs = goertzelNoFrequenciesPerString * noOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs;
	noValuesInAdaptiveThresholdCalcsDbl = (double)noValuesInAdaptiveThresholdCalcs;
	noValuesInAdaptiveThresholdCalcsDblMinus1 = noValuesInAdaptiveThresholdCalcsDbl - 1.0f;

	if ( adaptiveBackgroundSoundReductionIsOn )
	{
		for ( auto& stringStatistics : dqGoertzelResultStatistics )
		{
			stringStatistics.oldMagnitudeSquareddResults.resize( noValuesInAdaptiveThresholdCalcs, 0.0f );
		}
	}
}

float tuneComponent::getTimeSecundsPerFullAudioRecordBuffer( )
{
	return timeSecundsPerFullAudioRecordBuffer;
}

void tuneComponent::setAdaptiveNoSecondsComboBoxReady( bool isReady )
{
	adaptiveNoSecondsComboBoxReady = isReady;
}

void tuneComponent::setNoSecondsSoundPerCalcComboBoxReady( bool isReady )
{
	noSecondsSoundPerCalcComboBoxReady = isReady;
}

