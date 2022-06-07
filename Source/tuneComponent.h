/*
  ==============================================================================

	08. nov. 2016
		Eigil Krogh Sorensen

  ==============================================================================
*/
#pragma once

#define _USE_MATH_DEFINES // For use in math.h

//#define USE_JUCE_FFT
#undef USE_JUCE_FFT

#ifndef USE_JUCE_FFT
	#include "gfft.h"
#endif

#include <math.h>
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
#include "float.h"

#if ( JUCE_IOS )
    class guitarFineTuneFirstClass;
#endif // #if ( JUCE_IOS )
class displayControlComponent;
class guitarStringSoundsControl;
class eksNotModalProgressWindow;
class xmlGuitarFineTuneConfig;
class audioRecorderThread;

#include "AudioRecorder.h"
#include "eksNotModalProgressWindowCallBacks.h"
#include "decimationAndFilterConstants.h"
#include "post_decimation_NOTCH_filters_Coeffs.h"
#include "pre_decimation_FIR_filter_Coeffs.h"

#include "guitarFineTuneGlobalEnums.h"

#include "guitarStringSoundsControl.h"

#if ( JUCE_IOS )
    #include "guitarFineTuneFirstClass.h"
#endif // #if ( JUCE_IOS )

using namespace std;
using namespace std::chrono;

class tuneComponent
	: public ChangeListener
	, private Thread
	, private AsyncUpdater
	, public AudioAppComponent
	, public eksNotModalProgressWindowCallBacks
	, public ModalComponentManager::Callback
#if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)
	, private Timer
#endif
{
public:
	tuneComponent
    (
        std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig
        #if ( JUCE_IOS )
           , Component::SafePointer<guitarFineTuneFirstClass> pGuitarFineTuneFirstClass
        #endif // #if ( JUCE_IOS )
    );

	~tuneComponent();

	template<class T>
	inline typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type almost_equal(T x, T y, int ulp)
	{
		// the machine epsilon has to be scaled to the magnitude of the values used
		// and multiplied by the desired precision in ULPs (units in the last place)
		//return std::abs(x - y) <= std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
		return std::abs(x - y) < std::numeric_limits<T>::epsilon() * std::abs(std::min(x, y)) * ulp
			// unless the result is subnormal
			|| std::abs(x - y) < std::numeric_limits<T>::min();
	}

	void guitarStringsTonesXCoordsAndNamesCalc();

	bool readFIRFilterCoeffs(unsigned int FS);

	bool readNotchFilterCoeffsAndConstants(unsigned int FS);

	bool readFilterConstants(unsigned int FS);

	bool setPreAndPostFiltersAndConstantsBasedOnSampleRate(double newSampleRate);

	void guitarStringSoundsCleanUp
	(
		double sampleRate
	);

	void prepareToPlay(int samplesPerBlockExpected, double newSampleRate) override;

	void handleAsyncUpdate() override; // Called from AsyncUpdater

	void changeListenerCallback(ChangeBroadcaster*) override;

	void releaseResources() override;

	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;

	void paint(Graphics& g) override;

	void resized() override;
	void parentSizeChanged() override;

	void filterAndPushNextSampleIntoFifo(float sample);

#ifdef USE_JUCE_FFT
	void jucePerformFrequencyOnlyForwardTransform(float* d);
#else
	void gfftPerformFrequencyOnlyForwardTransform(double* d);
#endif


	void run() override; // Called from Thread

	inline std::string eksLongDoubleToString(long double valueToConvert);
	//inline std::string eksLongDoubleToString(long double valueToConvert, int noOfDecimals);

	void drawSpectrogram();

	void initObjects(std::weak_ptr<displayControlComponent> pObj1);
	void initPGuitarStringSoundsControl(Component::SafePointer<guitarStringSoundsControl> pGuitarStringSoundsControl);

	//AudioDeviceManager& getTheAudioDeviceManager();

	void getLowestAndHighestFreqToDisplayDataForHz(int& lowestFreq, int& highestFreq);
	bool setLowestAndHighestFreqToDisplayDataForHz(int lowestFreq, int highestFreq);

	void setDisplayControlComponentReadyFlag(bool isReady);

	double getCurrentDecimatedSampleRate();
	void getCurrentDecimatedSampleRateAndLowestAndHighestGoertzelFreq(double& curSampleRate, uint16& lowestGoertzelFreq, uint16& highestGoertzelFreq);

	void allGuitarStringSoundsOff();
	void controlGuitarStringSounds(std::deque<bool> guitarStringSoundsOn);

	void setInputGain(float gain);
	void setInputMuteToggleButtonOnFlag(bool flagValue);
	void setOutputGain(float gain);
	void setOutputMuteToggleButtonOnFlag(bool flagValue);
	void setStringsGain(float gain);
	void setStringsMuteToggleButtonOnFlag(bool flagValue);
	void rampAllStringSounds(bool ranpDown);
	void doSetShowFFT(bool flagOn);
	void setShowFFT(bool flagValue);
	void setshowFFTMaxIndictr(bool flagOn);
	void setShowstringsOffTuneValues(bool flagOn);
	void setshowThreshold(bool doShowThreshold);

	void setNoValsInAvgFreqsOutOfTuneCalc(int newNoValsInAvgFreqsOutOfTuneCalc);
	int getNoValsInAvgFreqsOutOfTuneCalc();

	void setshowFilters(bool flagValue);
	void setShowSpectrum(bool flagValue);
	void setShowIndicators(bool flagValue);

	void setThresholdResultMagnitudeSquaredForShowing(double newthresholdResultMagnitudeSquaredForShowing);
	void startThresholdAutoCalibrate();
	
	void makeHannWinCoefficients();

	int getCurrentBufferSizeInUse();
	void setAudioRecordingBuffers();
	int getFftOrder();
	void setFftOrder(int newFftOrder);

#ifdef THIS_IS_IOS
	void setAirPlayOnFlags(bool setAirPlayOn);
	//void setAirPlayBlueToothOnFlags(bool setAirPlayOn, bool setBlueToothOn);
#endif // THIS_IS_IOS

	void setNotchFilters();
	void setUse50HzFilterFlag(bool);
	void setUse60HzFilterFlag(bool);

	void goertzelInit();
	void goertzelReset();
	void goertzelStatisticsInit();
	void goertzelCalcResults();

	// Recording members
	void setRecorderSourceRaw();
	void setRecorderSourceFiltered();
	void stopRecorderSourceFilteredAudio();
	std::shared_ptr<AudioRecorderControl> getAudioRecorderController();

	void setAdaptiveBackgroundSoundReductionOn(bool setItOn);
	void setNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs(int noBatches);
	void saveThresholdForShowingResultsToXml();
	float getTimeSecundsPerFullAudioRecordBuffer();
	void setAdaptiveNoSecondsComboBoxReady(bool isReady);
	void setNoSecondsSoundPerCalcComboBoxReady(bool isReady);

	bool audioSysInit( );

	enum
	{
		preferreAudioBufferSize = 1024
	};

	enum
	{
		fftOrderAtStart = 8
	};

	enum
	{
		spaceBtwFftDataToDisplay = 1
		, wantedSystemSampleRate = 44100
	};

	enum // number of elements to use in calc of averages
	{
		//vMaxLevelsSize = 10
		vIdxOMaxsSize = 3
		, vScaleFactrsSize = 5
		, vDefaultNoValsInAvgFreqsOutOfTuneCalc = 1
	};

	enum // number of elements to use in calc of averages
	{
		goertzelFreqsAroundGuitarStringFreqs = 13
		, outOfTuneRedColor = 255
	};

	enum // guitar strings indexes in arrays/deques
	{
		E2idx = 0
		, A2idx = 1
		, D3idx = 2
		, G3idx = 3
		, B3idx = 4
		, E4idx = 5
	};


private:
    #if (JUCE_IOS || JUCE_MAC || JUCE_LINUX)
        void timerCallback() override;
    #endif
    #if ( JUCE_IOS )
		Component::SafePointer<guitarFineTuneFirstClass> ptrGuitarFineTuneFirstClass;	
    #endif // #if ( JUCE_IOS )

	std::shared_ptr<AudioRecorderControl> spAudioRecorderController;
	std::shared_ptr<audioRecorderThread> spTheAudioRecorderThread = nullptr;
	bool recorderSourceRawAudioOn = false;
	bool recorderSourceFilteredAudioOn = false;
	bool recordRawAudioOn = false;
	bool recordFilteredAudioOn = false;

	void modalStateFinished(int) override;
	bool openAudioDeviceThatWillOpenWithLegalSampleRate();

	juce::AudioDeviceManager::AudioDeviceSetup audioConfigAtStartUp;
	String audioDeviceTypeAtStartUp;
	//std::string audioDeviceTypeAtStartUp;
	std::string currentaudioDeviceTypeInUse;
	int currentBufferSizeInUse = -10;
	double currentSampleRateInUse;

	File myAudioStateXmlFile =
		File::getSpecialLocation(File::userApplicationDataDirectory).getFullPathName()
			+ "/guitarFineTune/audioState.Xml";
	std::unique_ptr<XmlElement> curAudioState = nullptr;
	bool audioStateXmlFileExistedAtStart = false;



	int fftOrder = fftOrderAtStart;
	int fftSize = 1 << fftOrderAtStart;
	int fftSizeHalf = 1 << (fftOrderAtStart - 1);
	int fftSizeDouble = 1 << (fftOrderAtStart + 1);

	double* hannWinCoefficients = nullptr;

	Image spectrogramImage{ Image::RGB, widthOfTuneWindow, hightOfTuneWindow, true };
	juce::Graphics spectrImGraphcs{ spectrogramImage };


#ifdef USE_JUCE_FFT
	std::unique_ptr<dsp::FFT> forwardFFT;
#else
	////////// gfft /////////////////
	// initialization of the object factory
	Loki::Factory<AbstractFFT<double>, unsigned int> gfft_factory;

	// create a "holder" for the GFFT
	AbstractFFT<double>* gfft;
#endif

	// runtime definition of the data length
	int p = fftOrderAtStart; //Same as JUCEs FFT

	// Data buffers
	float* audioRecordBuffer1 = nullptr;
	float* audioRecordBuffer2 = nullptr;
	float* audioRecordBufferOut = audioRecordBuffer1;
	float* audioRecordBufferIn = audioRecordBuffer2;

#ifdef USE_JUCE_FFT
	float* fftDataBuffer1 = nullptr;
	float* fftDataBuffer2 = nullptr;
	// Holders for fftDataBuffer pointers:
	// a complex<float>* and a float* to each fftDataBuffer
	float* inBuffer1 = fftDataBuffer1;
	float* fftData1 = fftDataBuffer2;
	float* inBuffer2 = fftDataBuffer2;
	float* fftData2 = fftDataBuffer1;
	// buffer pointers used in the data processing
	float* inBuffer = inBuffer2; // is toggeled buffer 2,1,2....
	float* fftData = fftData2; // is toggled 1,2,1,...
#else
	double* fftDataBuffer1 = nullptr;
	double* fftDataBuffer2 = nullptr;
	// Holders for fftDataBuffer pointers:
	// a complex<double>* and a double* to each fftDataBuffer
	complex<double>* inBuffer1 = (complex<double>*)fftDataBuffer1;
	double* fftData1 = fftDataBuffer2;
	complex<double>* inBuffer2 = (complex<double>*)fftDataBuffer2;
	double* fftData2 = fftDataBuffer1;
	// buffer pointers used in the data processing
	complex<double>* inBuffer = inBuffer2; // is toggeled buffer 2,1,2....
	double* fftData = fftData2; // is toggled 1,2,1,...
#endif

	int firstFftDataToDisplay = 0;
	int lastFftDataToDisplay = 0;
	float resToDisply = 0;

	bool showFFTToggleButtonOn = false;
	bool showFFTMaxIndictrToggleButtonOn = false;
	bool showStringsOffTuneValues = false;
	bool showIndicatorsToggleButtonOn = true;
	bool showSpectrumToggleButtonOn = true;
	bool showFiltersToggleButtonOn = false;
	bool generateNoiseToggleButtonOn = false;

	CriticalSection drawSpectrogramLockMutex;
	CriticalSection guitarStringSoundsLockMutex;

	// Goertzel bins
	typedef struct
	{
		unsigned int guitarStringFreq;
		float xCoordinat;
		long double targetFreq; // target freq. for this bin
		long double coeff;
		long double Q1, Q2;
		long double resultMagnitudeSquared;
	} GOERTZELBIN;
	std::vector<GOERTZELBIN> dqGoertzelBins1;
	std::vector<GOERTZELBIN> dqGoertzelBins2;
	std::vector<GOERTZELBIN>* pDqGoertzelBinsIn = &dqGoertzelBins2;
	std::vector<GOERTZELBIN>* pDqGoertzelBinsOut = &dqGoertzelBins1;


	// Goertzel result statistics
	bool showThreshold = initShowThreshold;
	bool adaptiveBackgroundSoundReductionIsOn = initAdaptiveBackgroundSoundReductionIsOn;
	//int goertzelNoFrequenciesPerString = 0;
	int noOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs = initNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs;
	int noValuesInAdaptiveThresholdCalcs = initNoSamplesWantedInBgSoundCalcs;
	long double noValuesInAdaptiveThresholdCalcsDbl = initNoSamplesWantedInBgSoundCalcs;
	long double noValuesInAdaptiveThresholdCalcsDblMinus1 = (long double)(initNoSamplesWantedInBgSoundCalcs - 1);
	
	typedef struct nameGOERTZELRESULTSTATISTICS
	{
		GOERTZELBIN goertzelBin;
		std::string stringName = "E2";
		long double thresholdForShowingResultMagnitudeSquared;
		bool showThisOne;
		bool thisOneShownLastTime = false;
		std::deque<long double> freqsOutOfTune;
		long double meanFreqsOutOfTune;
		double meanOutOfTuneXCoordinat;
		std::vector<double> oldMagnitudeSquareddResults;
	} GOERTZELRESULTSTATISTICS;
	std::vector<GOERTZELRESULTSTATISTICS> dqGoertzelResultStatistics;

	long double max_goertzelValue = -DBL_MAX + 1;

	unsigned int iNoValsInAvgFreqsOutOfTuneCalc = vDefaultNoValsInAvgFreqsOutOfTuneCalc;

	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig;
	XmlElement* getXmlTagDISPLAYCONTROL();
	std::shared_ptr<eksNotModalProgressWindow> spEksNotModalProgressWindow;
	bool thresholdAutoCalibrationInProgress = false;
	std::vector<std::vector<long double>> measuredNoise;
	enum { noSamplesWantedInMeasuredNoiseCalcs = 100 };
	long double noSamplesWantedInMeasuredNoiseCalcsMinus1 = (long double)(noSamplesWantedInMeasuredNoiseCalcs - 1);


	float float_2PI = MathConstants<float>::pi * 2.0f;

	//% There are six strings on a guitar, each with an open notes of
	//	% E2, A2, D3, G3, B3, and E4, each with corresponding frequencies of
	//	% 82 Hz, 110 Hz, 147 Hz, 196 Hz, 247 Hz, 330 Hz(Fletcher 207).
	//	% These frequencies represent the root tone of each string.Nov 28, 1999
	enum // guitar strings
	{
		E2 = 82
		, A2 = 110
		, D3 = 147
		, G3 = 196
		, B3 = 247
		, E4 = 330
	};
	unsigned int guitar[6] = { E2, A2, D3, G3, B3, E4 };
	std::string guitarStringNames[6] = { "E2", "A2", "D3", "G3", "B3", "E4" };

	// Guitar strings sines phases
	typedef struct /*tGUITARSTRINGSPHASES*/
	{
		float guitarStringFreq;
		float currentPhase;
		float phaseDeltaPerSample;
	} GUITARSTRINGSPHASES;
	std::vector<GUITARSTRINGSPHASES> guitarStringsSinePhases;
	std::vector<GUITARSTRINGSPHASES*> ptrsToGuitarStringsSinePhases;

	//Guitar strings xCoords and Names
	typedef struct nameGUITARSTRINGTONEXCOORDANDNAME
	{
		float stringXCoord = 0.0f;
		std::string stringName = "E2";
	} GUITARSTRINGTONEXCOORDANDNAME;
	std::deque<GUITARSTRINGTONEXCOORDANDNAME> guitarStringsTonesXCoordsAndNames;


	bool bSwitchBufferTo2 = false;
	int noOfInputValues = 0;
	bool nextSpectrumDataBlockReady = false;


	void calcNewGuitarStringsSinePhasesFromSampleRate(double sampleRate);

	void calcHalfSinePeriodValues
	(
		unsigned int bffrLgth
	);

	void calcGuitarStringSoundsRampFaktors
	(
		std::back_insert_iterator< std::vector<double> > rampBackInsrtr
		, bool halfBffrLgth
		, double rampStartGain
		, double rampEndGain
	);

	void calcGuitarStringSoundsDualRampFaktors
	(
		std::back_insert_iterator< std::vector<double> > dualRampBackInsrtr
		, double firstRampStartGain
		, double firstRampEndGain
		, double lastRampStartGain
		, double lastRampEndGain
	);

	void guitarStringSoundsRampFillInRampedTones
	(
		std::vector<float>::iterator outGitarStringSoundsItrtr
		, std::vector<GUITARSTRINGSPHASES*> rampedGuitarStringsSinePhases
		, std::vector<double>& rampFaktors
	);

	void guitarStringSoundsRampFillInTheUnRampedTones
	(
		std::vector<float>::iterator outGitarStringSoundsBeginItrtr
		, std::vector<float>::iterator outGitarStringSoundsEndItrtr
		, std::vector<GUITARSTRINGSPHASES*> unRampedGuitarStringsSinePhases
		, double gainToUse
	);

	std::deque<bool> guitarStringSoundsOnLastTime = { false, false, false, false, false, false };
	std::vector<float> guitarStringSoundsRamp;
	std::vector<double> fullBffrLgthHalfSinePeriodValues;
	std::vector<double> halfBffrLgthHalfSinePeriodValues;
	const double threeQuatersOf2Pi = (double)3.0f * MathConstants<double>::pi / (double)2.0f;
	const double piHalf = MathConstants<double>::pi / (double)2.0f;
	bool playGuitarStringSoundsRamp = false;
	float stringGainToUse = 1.0;
	float stringsGain = 1.0;
	bool doPlayGuitarStringSounds = false;
	bool stringsMuteToggleButtonOn = false;
	float inputGain = 0.0;
	bool inputMuteToggleButtonOn = true;
	float outputGain = 1.0;
	bool outputMuteToggleButtonOn = false;

	long double fDelta = 0.f;
	float timeSecundsPerFullAudioRecordBuffer = 0.f;
	float noOfFullAudioRecordBuffersDuringTimeToFadeAwaySecunds = 0.f;
	int sampleSpace = 0;
	double decimatedSampleRate = 0.0;
	int preDecimationFilterIndxToSampleInInBuffer = 0; // index of sample in inbuffer ("bufferToFill")
	int generateNoiseIndxToSampleInInBuffer = 0; // index of sample in inbuffer ("bufferToFill")
	int generateImpulseIndxToSampleInInBuffer = 0; // index of sample in inbuffer ("bufferToFill")
	bool adaptiveNoSecondsComboBoxReady = false;
	bool noSecondsSoundPerCalcComboBoxReady = false;

	unsigned int cNotchNoOfCoeffs = 0;
	unsigned int dNotchNoOfCoeffs = 0;
	std::vector<double>::const_iterator cNotchCoeffsBegin;
	std::vector<double>::const_iterator dNotchCoeffsBegin;
	std::deque<double> postDecimationFilterYValues;
	std::deque<double> postDecimationFilterXValues;


	// Pre decimation FIR filter
	unsigned int noCoeffsForPreDecimationFIRFilter;
	vector<double>::const_iterator bFIRCoeffsInvertedBegin;
	vector<double>::const_iterator bFIRCoeffsInvertedEnd;
	std::vector<double> inBufferFIR;
//	std::deque<double> inBufferFIR;


	Component::SafePointer<guitarStringSoundsControl> ptrGuitarStringSoundsControl = nullptr;
	std::weak_ptr<displayControlComponent> pDisplayControlComponent;
	//	std::shared_ptr<displayControlComponent> pDisplayControlComponent;
	bool bDisplayControlComponentReady = false;
	bool timeSecundsPerFullAudioRecordBufferReady = false;
	bool goForInitAdaptiveNoSecondsComboBox = false;

	WaitableEvent weSpectrumDataReady;

	int lowestFreqToDisplayDataForHz = static_cast<int>(E2) - static_cast<int>(goertzelFreqsAroundGuitarStringFreqs);
	int highestFreqToDisplayDataForHz = static_cast<int>(E4) + static_cast<int>(goertzelFreqsAroundGuitarStringFreqs);
	long double freqToXCoordFactor = (long double)widthOfTuneWindow / (long double)((long double)highestFreqToDisplayDataForHz - (long double)lowestFreqToDisplayDataForHz);
	bool firstSampleIn = true;
	double greenFactorForGuitarStringsOutOfTone = (double)(0x80 / goertzelFreqsAroundGuitarStringFreqs);
	double redFactorForGuitarStringsOutOfTone = (double)(255 / goertzelFreqsAroundGuitarStringFreqs);


	juce::Font defaultFontOfSpectrImGraphcs;
	float hightOfDefaultFontOfSpectrImGraphcs;
	int strHalfStringNamesWidth;


#ifdef THIS_IS_IOS
	bool airPlayAllowed = true;
	//bool blueToothAllowed = false;
#endif // THIS_IS_IOS

	bool use50HzFilter = false;
	bool use60HzFilter = false;
	bool usePowerGridFrequencyFilter = use50HzFilter || use60HzFilter;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(tuneComponent)
};

