/*
  ==============================================================================

	xmlGuitarFineTuneConfig.h
	Created: 8 May 2017 4:54:41pm
	Author:  eks

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "guitarFineTuneGlobalEnums.h"

#include <deque>

//==============================================================================
/*
*/
class xmlGuitarFineTuneConfig : public Component
{
public:
	xmlGuitarFineTuneConfig();
	~xmlGuitarFineTuneConfig();

	void writeConfigToXmlFile();
	XmlElement& getGuitarfinetuneconfig() { return *guitarfinetuneconfig; };

private:
	void makeNewVerConfigFile();

	File myXmlDir = File::getSpecialLocation(File::userApplicationDataDirectory).getFullPathName() + "/guitarFineTune";
	File myXmlFile = File::getSpecialLocation(File::userApplicationDataDirectory).getFullPathName() + "/guitarFineTune/config_" + std::string(ProjectInfo::versionString) + ".Xml";

	std::unique_ptr<XmlElement> guitarfinetuneconfig = std::make_unique<XmlElement>("GUITARFINETUNECONFIG");
	std::unique_ptr<XmlElement> soundcontrol = std::make_unique<XmlElement>("SOUNDCONTROL");
	std::unique_ptr<XmlElement> displaycontrol = std::make_unique<XmlElement>("DISPLAYCONTROL");
	std::unique_ptr<XmlElement> audiocontrol = std::make_unique<XmlElement>("AUDIOCONTROL");

	typedef struct
	{
		String attributeName;
		var value;
	} typATTRIBUTE;

	std::deque<typATTRIBUTE> soundControlAttributes
	{
		  { "autoGain", true }
		, { "recordingGain", 0.0f }
	};

	std::deque<typATTRIBUTE> displayControlAttributes
	{
		  { "globalThresholdForShowing", -2 }
		, { "E2threshold", 0.0 }
		, { "A2threshold", 0.0 }
		, { "D3threshold", 0.0 }
		, { "G3threshold", 0.0 }
		, { "B3threshold", 0.0 }
		, { "E4threshold", 0.0 }
		, { "noOfFullAudioRecordBuffersInCalcs", initNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs }
		, { "showIndicators", true }
		, { "showSpectrum", false }
		, { "showFFT", false }
		, { "showThreshold", false }
		, { "showFFTMaxIndictr", false }
		, { "showFilter", false }
		, { "showStringsOffTuneValues", false }
		, { "noCalcsInAverage", 5 }
		, { "fftOrder", 8 }
		, { "lowestFreq", 69 }
		, { "highestFreq", 343 }
	};

	std::deque<typATTRIBUTE> audioControlAttributes
	{
		  { "disableOsAudioPreProcessing", true }
		, { "use50HzFilter", false }
		, { "use60HzFilter", false }
	};


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(xmlGuitarFineTuneConfig)
};
