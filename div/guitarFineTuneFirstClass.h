/*
  ==============================================================================

    guitarFineTuneFirstClass.h
    Created: 27 Jun 2016 8:08:09pm
    Author:  eks

  ==============================================================================
*/

#ifndef FIRNETUNEFIRSTCLASS_H_INCLUDED
#define FIRNETUNEFIRSTCLASS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class eksTabbedComponent;
class aboutPage;
class guitarStringSoundsControl;
class eksAudioControlComponent;
class testEksThreadWithProgressWindow;
class eksLookAndFeel;

//==============================================================================
/*
*/
class guitarFineTuneFirstClass
	: public DocumentWindow
{
public:
    guitarFineTuneFirstClass();
    ~guitarFineTuneFirstClass();

	void currentTabChanged(int newCurrentTabIndex, const String& /*newCurrentTabName*/);
	void paint(Graphics& g) override;
	void closeButtonPressed() override;
#if (JUCE_IOS || JUCE_ANDROID)
	float scaleToGuitarStringSoundsControlWindow();
#endif // (JUCE_IOS || JUCE_ANDROID)
	void resized() override;
	void setColorOfAllLabels(juce::Component* cmpontToHandle);
#if (JUCE_IOS || JUCE_ANDROID)
	void parentSizeChanged() override;
#endif

private:

	std::shared_ptr<eksLookAndFeel> pGuitarFineTuneLookAndFeel = nullptr;
	std::shared_ptr<eksTabbedComponent> pEksTabbedComponent = nullptr;
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig = nullptr;
	std::shared_ptr<tuneComponent> pTuneComponent = nullptr;
	std::shared_ptr<eksAudioControlComponent> pEksAudioControlComponent = nullptr;
	std::shared_ptr<Viewport> pEksAudioControlComponentViewPort = nullptr;
	std::shared_ptr<guitarStringSoundsControl> pGuitarStringSoundsControl = nullptr;
	std::shared_ptr<Viewport> pGuitarStringSoundsControlViewPort = nullptr;
	std::shared_ptr<displayControlComponent> pDisplayControlComponent = nullptr;
	std::shared_ptr<Viewport> pDisplayControlComponentViewPort = nullptr;
	std::shared_ptr<aboutPage> pAboutPage = nullptr;

	int audioDeviceSelectorComponentHight;

	int currentTabIndex = tabNoTuneWindow;

	bool addViewPort = false;

	juce::Rectangle<int> curCompntBnds;

	bool bGoSetSizes = false;

	//Label colours
	int labelTextColorId = juce::Label::textColourId;
	juce::Colour labelColor = juce::Colours::cornflowerblue;



	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(guitarFineTuneFirstClass)
};


#endif  // FIRNETUNEFIRSTCLASS_H_INCLUDED
