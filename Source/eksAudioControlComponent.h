/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"

class tuneComponent;
class xmlGuitarFineTuneConfig;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class eksAudioControlComponent  : public Component,
                                  public juce::Button::Listener
{
public:
    //==============================================================================
    eksAudioControlComponent( std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTCfg, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP );
    ~eksAudioControlComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	XmlElement* getXmlTagAUDIOCONTROL();
#if (JUCE_IOS || JUCE_ANDROID)
	void scaleAllComponents();
#endif // (JUCE_IOS || JUCE_ANDROID)
	void initControls();
	void setColorOfAllLabels(juce::Component* cmpontToHandle);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<eksLookAndFeel> pGuitarFineTuneLookAndFeel = nullptr;
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig = nullptr;
	bool viewPortAdded = false;
    bool deviceSupportsDisableAudioPreprocessing = false;
    bool previousDeviceSupportsDisableAudioPreprocessing = false;
    bool changedDeviceSupportsDisableAudioPreprocessing = false;
        //Label colours
	int labelTextColorId = juce::Label::textColourId;
	juce::Colour labelColor = juce::Colours::cornflowerblue;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::AudioDeviceSelectorComponent> pAudioDeviceSelectorComponent;
    std::unique_ptr<juce::ToggleButton> Use_50_Hz_FilterToggleButton;
    std::unique_ptr<juce::ToggleButton> Use_60_Hz_FilterToggleButton;
    std::unique_ptr<juce::ToggleButton> preProcessingToggleButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (eksAudioControlComponent)
};

//[EndFile] You can add extra defines here...
//==============================================================================
//[/EndFile]

