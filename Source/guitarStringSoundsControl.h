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
#include "JuceHeader.h"
#include <deque>

class xmlGuitarFineTuneConfig;
class tuneComponent;
struct SimpleLevelMeter;
class AudioRecorderControl;
class eksLookAndFeel;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class guitarStringSoundsControl  : public Component,
                                   public Label::Listener,
                                   public juce::Button::Listener,
                                   public juce::Slider::Listener
{
public:
    //==============================================================================
    guitarStringSoundsControl (std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP);
    ~guitarStringSoundsControl() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void labelTextChanged(Label* labelThatHasChanged) override;
#if (JUCE_IOS || JUCE_ANDROID)
	void scaleAllComponents();
#endif // (JUCE_IOS || JUCE_ANDROID)
	void disableAllStringTonesAndMutes();
	inline std::string eksLongDoubleToString(long double valueToConvert, int noOfDecimals);
	inline void setRecordLevelSlider(bool newGainIsZero);
	void initControls();
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool oldRecordGainWasZero = true;
	std::shared_ptr<eksLookAndFeel> pGuitarFineTuneLookAndFeel = nullptr;
	std::unique_ptr<Label> stringSliderLabel;
	std::unique_ptr<Label> inputSliderLabel;
	std::unique_ptr<Label> outputSliderLabel;
	std::unique_ptr<Label> recordingLevelSliderLabel;
	std::deque<bool> guitarStringSoundsOn = { false, false, false, false, false, false };
	bool inputMuteToggleButtonOn = true;
	bool stringsMuteToggleButtonOn = false;
	bool outputMuteToggleButtonOn = false;
	std::shared_ptr<AudioRecorderControl> spAudioRecorderController = nullptr;
	std::shared_ptr<SimpleLevelMeter> RecordingLevelMeter = nullptr;
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig = nullptr;
	bool viewPortAdded = false;
	XmlElement* getXmlTagSOUNDCONTROL();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> PlayToneGroupComponent;
    std::unique_ptr<juce::GroupComponent> outputMixGroupComponent;
    std::unique_ptr<juce::ToggleButton> E2soundToggleButton;
    std::unique_ptr<juce::ToggleButton> A2soundToggleButton;
    std::unique_ptr<juce::ToggleButton> D3soundToggleButton;
    std::unique_ptr<juce::ToggleButton> G3soundToggleButton;
    std::unique_ptr<juce::ToggleButton> B3soundToggleButton;
    std::unique_ptr<juce::ToggleButton> E4soundToggleButton;
    std::unique_ptr<juce::Slider> stringSlider;
    std::unique_ptr<juce::Slider> inputSlider;
    std::unique_ptr<juce::Label> stringsVolLabel;
    std::unique_ptr<juce::Label> inputVolLabel;
    std::unique_ptr<juce::ToggleButton> inputMuteToggleButton;
    std::unique_ptr<juce::ToggleButton> stringsMuteToggleButton;
    std::unique_ptr<juce::Label> outputVolLabel;
    std::unique_ptr<juce::Slider> outputSlider;
    std::unique_ptr<juce::ToggleButton> outputMuteToggleButton;
    std::unique_ptr<juce::Label> E2label;
    std::unique_ptr<juce::Label> A2label;
    std::unique_ptr<juce::Label> D3label;
    std::unique_ptr<juce::Label> G3label;
    std::unique_ptr<juce::Label> B3label;
    std::unique_ptr<juce::Label> E4label;
    std::unique_ptr<juce::GroupComponent> recordGroupComponent;
    std::unique_ptr<juce::ToggleButton> sourceRawToggleButton;
    std::unique_ptr<juce::ToggleButton> sourceFilteredToggleButton;
    std::unique_ptr<juce::ToggleButton> stopRecordingToggleButton;
    std::unique_ptr<juce::Label> rawSoundLabellabel;
    std::unique_ptr<juce::Label> FilteredSoundLabel;
    std::unique_ptr<juce::Label> stopLabel;
    std::unique_ptr<juce::GroupComponent> recordLevelGroupComponent;
    std::unique_ptr<juce::Slider> recordingLevelSlider;
    std::unique_ptr<juce::ToggleButton> startRecordingToggleButton;
    std::unique_ptr<juce::Label> startLabel;
    std::unique_ptr<juce::ToggleButton> guitarStringTonesOffToggleButton;
    std::unique_ptr<juce::Label> allOffLabel;
    std::unique_ptr<juce::ToggleButton> autoGainToggleButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (guitarStringSoundsControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

