/*
  ==============================================================================

	JUCE demo code - use at your own risk!

  ==============================================================================
*/

//#ifndef _USE_MATH_DEFINES
//#define _USE_MATH_DEFINES // For use in math.h
//#endif // !_USE_MATH_DEFINES


class xmlGuitarFineTuneConfig;

//#if ((defined (_WIN32) || defined (_WIN64)) && _DEBUG)
//#include "vld.h"
//#endif //  (JUCE_WINDOWS && _DEBUG)

#include "../JuceLibraryCode/JuceHeader.h"

#include "displayControlComponent.h"
#include "guitarFineTuneFirstClass.h"

//==============================================================================
class guitarFineTune
	: public JUCEApplication
{
public:
	//==============================================================================
	guitarFineTune()
	{
#if JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX
#ifndef _DEBUG
		pSplash = new SplashScreen("Welcome to GuitarFineTune!", ImageFileFormat::loadFrom(BinaryData::fineTune_icon_Small_png, (size_t)BinaryData::fineTune_icon_Small_pngSize), true);
		//juce::MessageManager::getInstance()->runDispatchLoopUntil(100);
#endif // _DEBUG
#endif // JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX
	}

	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	//==============================================================================
	void initialise(const String& /*commandLine*/) override
	{

		ptrGuitarFineTuneFirstClass = std::make_shared<guitarFineTuneFirstClass>();

#if JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX
#ifndef _DEBUG
		pSplash->deleteAfterDelay(RelativeTime::milliseconds(1), true);
#endif // _DEBUG
#endif // JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX

	}

	void shutdown() override
	{
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}



private:
#ifndef _DEBUG
	SplashScreen* pSplash;
#endif // _DEBUG
	std::shared_ptr<guitarFineTuneFirstClass> ptrGuitarFineTuneFirstClass;


};


//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(guitarFineTune)
