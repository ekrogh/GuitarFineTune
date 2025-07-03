/*
  ==============================================================================

    guitarFineTuneGlobalEnums.h
    Created: 21 Jun 2016 3:09:03pm
    Author:  eks

  ==============================================================================
*/

#pragma once

#include <set>

enum
{
	  tabBarDepthAndroidIosInVertical = 20
	, tabBarDepthAndroidIosInHorizontal = 27
	, tabBarDepthMacWin = 27

	, tabTuneWindow = 0
	, widthOfTuneWindow = 770
	, hightOfTuneWindow = 200

	, tabGuitarStringSoundsControlWindow = 1
	, widthOfGuitarStringSoundsControlWindowHorizontal = 558
	, hightOfGuitarStringSoundsControlWindowHorizontal = 295
	, widthOfGuitarStringSoundsControlWindowVertical = 300
	, hightOfGuitarStringSoundsControlWindowVertical = 430

	, tabDisplayControlWindow = 2
	, widthOfDisplayControlWindowHorizontal = 528
	, hightOfDisplayControlWindowHorizontal = 325
	, widthOfDisplayControlWindowVertical = 346
	, hightOfDisplayControlWindowVertical = 468

	, tabEksAudioControlComponent = 3
	, widthOfEksAudioControlComponentWindow = 330
#if JUCE_ANDROID
	, heightAudioDeviceSelectorComponent = 205
#endif // JUCE_ANDROID
#if (JUCE_IOS || JUCE_ANDROID)
	, hightOfEksAudioControlComponentWindow = 350
#else
	#if JUCE_LINUX
		, hightOfEksAudioControlComponentWindow = 425
	#else
		, hightOfEksAudioControlComponentWindow = 400
	#endif // JUCE_LINUX
#endif // (JUCE_IOS || JUCE_ANDROID)

	, tabAboutPage = 4
	, widthOfAboutPage = 300
	, hightOfAboutPage = 260

	, iOSSafeMargin = 40
	, androidSafeMargin = 20
};


enum xmlSpecialValues
{
	// Special values for displayControlAttribute globalThresholdForShowing
	  Auto_globalThresholdForShowing = -1
	, Adaptive_globalThresholdForShowing = -2
	, Latest_globalThresholdForShowing = -3
};


// Adaptive Background Sound Exclusion
enum AdaptiveBackgroundSoundExclusion
{
	  initShowThreshold = 0
	, initAdaptiveBackgroundSoundReductionIsOn = 0
	, initNoSamplesWantedInBgSoundCalcs = 100
	, initNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs = 3
	, adaptiveMaxNoOfBuffers = 80
	, adaptiveMaxNoOfSecondsAlways = 60
	, adaptiveMaxNoOfSecondsIncrements = 6
};


// Fading arrows
enum FadingArrows
{
	timeToFadeAwaySecunds = 2
};

// Num in- and outputs
enum  NumInAndOutputs
{
	  numInputChannels = 1
	, numOutputChannels = 1
};

enum
{
      eksAVAuthorizationStatusNotDetermined    = 0
    , eksAVAuthorizationStatusRestricted       = 1
    , eksAVAuthorizationStatusDenied           = 2
    , eksAVAuthorizationStatusAuthorized       = 3
};
