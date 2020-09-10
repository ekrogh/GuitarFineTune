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

class xmlGuitarFineTuneConfig;
class tuneComponent;
class guitarStringSoundsControl;

#include "eksLookAndFeel.h"

#include "guitarStringSoundsControl.h"

#include "guitarFineTuneGlobalEnums.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class displayControlComponent  : public Component,
                                 public TextEditor::Listener,
                                 public juce::Button::Listener,
                                 public juce::ComboBox::Listener,
                                 public juce::Slider::Listener
{
public:
    //==============================================================================
    displayControlComponent (std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP);
    ~displayControlComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void textEditorReturnKeyPressed(TextEditor& editorThatIs) override;
	void textEditorFocusLost(TextEditor& editorThatIs) override;
	void setToAutoThresholdTextEditor();
	void setToAdapThresholdTextEditor();
	void setToLatestThresholdTextEditor();
	void enableAdaptiveToggleButton();
	void initControls();
	void showLowestAndHighestFreqToDisplayDataForHz(double& decimatedSampleRate, uint16 lowestGoertzelFreq, uint16 HighestGoertzelFreq);
	void setLabelHighstFreqText(double& sampleRate, uint16 lowestGoertzelFreq, uint16 HighestGoertzelFreq);
	void updateAdaptiveNoSecondsComboBox(float timeSecundsPerFullAudioRecordBuffer);
	void initAdaptiveNoSecondsComboBox(float timeSecundsPerFullAudioRecordBuffer);
	void updateNoSecondsSoundPerCalcComboBox(double secondsPerSampleAtDecimatedSampleRate);
	inline std::string eksLongDoubleToString(long double valueToConvert, int noOfDecimals);
#if JUCE_IOS
	void mouseDown(const MouseEvent& e) override;
	void mouseDrag(const MouseEvent& e) override;
#endif
#if (JUCE_IOS || JUCE_ANDROID)
	void scaleAllComponents();
#endif // (JUCE_IOS || JUCE_ANDROID)
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::unique_ptr<Label> sliderLowestFreqLabel;
	std::unique_ptr<Label> sliderHighestFreqLabel;
	std::unique_ptr<Label> averageSiderLabel;
	std::shared_ptr<eksLookAndFeel> pGuitarFineTuneLookAndFeel = nullptr;
	Font myComboBoxFont = Font(15.00f, Font::plain).withTypefaceStyle("Regular");
	bool itsLostFocus = false;
	int currentFftOrderThatWasSelected = 0;

#if JUCE_IOS
	ComponentBoundsConstrainer constrainer;
	ComponentDragger dragger;
#endif
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig;
	bool viewPortAdded = false;
	XmlElement* getXmlTagDISPLAYCONTROL();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> freqRangeGroupComponent;
    std::unique_ptr<juce::GroupComponent> ShowGroupComponent;
    std::unique_ptr<juce::GroupComponent> averageGroupComponent;
    std::unique_ptr<juce::GroupComponent> bgsoundExclusionGroupComponent;
    std::unique_ptr<juce::ToggleButton> showFFTToggleButton;
    std::unique_ptr<juce::ToggleButton> showSpectrumToggleButton;
    std::unique_ptr<juce::TextEditor> thresholdTextEditor;
    std::unique_ptr<juce::ToggleButton> showFilterToggleButton;
    std::unique_ptr<juce::Label> noSecondsSoundPerCalcLabel;
    std::unique_ptr<juce::ComboBox> noSecondsSoundPerCalcComboBox;
    std::unique_ptr<juce::ToggleButton> showIndicatorsToggleButton;
    std::unique_ptr<juce::ToggleButton> showFFTMaxIndictrToggleButton;
    std::unique_ptr<juce::ToggleButton> stringsOffTuneValuesToggleButton;
    std::unique_ptr<juce::TextButton> autoCalibrateTextButton;
    std::unique_ptr<juce::Label> labelLowestFreq;
    std::unique_ptr<juce::Slider> sliderLowestFreq;
    std::unique_ptr<juce::Slider> sliderHighestFreq;
    std::unique_ptr<juce::Label> labelHighstFreq;
    std::unique_ptr<juce::Label> calculationsLabel;
    std::unique_ptr<juce::Slider> averageSider;
    std::unique_ptr<juce::ToggleButton> adaptiveToggleButton;
    std::unique_ptr<juce::ComboBox> adaptiveNoSecondsComboBox;
    std::unique_ptr<juce::Label> adaptiveNoSecondsLabel;
    std::unique_ptr<juce::ToggleButton> thresholdToggleButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (displayControlComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

