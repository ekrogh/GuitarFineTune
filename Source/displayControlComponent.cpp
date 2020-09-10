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

//[Headers] You can add your own extra header files here...

#include "tuneComponent.h"
#include "xmlGuitarFineTuneConfig.h"
#include "guitarStringSoundsControl.h"
#include "guitarFineTuneGlobalEnums.h"
//[/Headers]

#include "displayControlComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern std::unique_ptr<tuneComponent> pTuneComponent;
//[/MiscUserDefs]

//==============================================================================
displayControlComponent::displayControlComponent (std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP)
    : pGuitarFineTuneLookAndFeel(pGFTAF),
      pXmlGuitarFineTuneConfig(pXmlGFTConfig),
      viewPortAdded(addVWP)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    freqRangeGroupComponent.reset (new juce::GroupComponent ("freqRangeGroupComponent",
                                                             TRANS("Frequency range")));
    addAndMakeVisible (freqRangeGroupComponent.get());
    freqRangeGroupComponent->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    freqRangeGroupComponent->setColour (juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

    freqRangeGroupComponent->setBounds (0, 298, 320, 136);

    ShowGroupComponent.reset (new juce::GroupComponent ("ShowGroupComponent",
                                                        TRANS("Show")));
    addAndMakeVisible (ShowGroupComponent.get());
    ShowGroupComponent->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    ShowGroupComponent->setColour (juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

    ShowGroupComponent->setBounds (0, 190, 320, 106);

    averageGroupComponent.reset (new juce::GroupComponent ("averageGroupComponent",
                                                           TRANS("Average string tone calculations over")));
    addAndMakeVisible (averageGroupComponent.get());
    averageGroupComponent->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    averageGroupComponent->setColour (juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

    averageGroupComponent->setBounds (0, 100, 320, 88);

    bgsoundExclusionGroupComponent.reset (new juce::GroupComponent ("bgsoundExclusionGroupComponent",
                                                                    TRANS("Background sounds exclusion threshold  ")));
    addAndMakeVisible (bgsoundExclusionGroupComponent.get());
    bgsoundExclusionGroupComponent->setColour (juce::GroupComponent::outlineColourId, juce::Colours::blue);
    bgsoundExclusionGroupComponent->setColour (juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

    bgsoundExclusionGroupComponent->setBounds (0, 8, 320, 88);

    showFFTToggleButton.reset (new juce::ToggleButton ("showFFTToggleButton"));
    addAndMakeVisible (showFFTToggleButton.get());
    showFFTToggleButton->setExplicitFocusOrder (9);
    showFFTToggleButton->setButtonText (TRANS("FFT"));
    showFFTToggleButton->addListener (this);
    showFFTToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    showSpectrumToggleButton.reset (new juce::ToggleButton ("showSpectrumToggleButton"));
    addAndMakeVisible (showSpectrumToggleButton.get());
    showSpectrumToggleButton->setExplicitFocusOrder (8);
    showSpectrumToggleButton->setButtonText (TRANS("Spectrum"));
    showSpectrumToggleButton->addListener (this);
    showSpectrumToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    thresholdTextEditor.reset (new juce::TextEditor ("thresholdTextEditor"));
    addAndMakeVisible (thresholdTextEditor.get());
    thresholdTextEditor->setExplicitFocusOrder (4);
    thresholdTextEditor->setMultiLine (false);
    thresholdTextEditor->setReturnKeyStartsNewLine (false);
    thresholdTextEditor->setReadOnly (false);
    thresholdTextEditor->setScrollbarsShown (true);
    thresholdTextEditor->setCaretVisible (true);
    thresholdTextEditor->setPopupMenuEnabled (true);
    thresholdTextEditor->setColour (juce::TextEditor::textColourId, juce::Colours::cornflowerblue);
    thresholdTextEditor->setColour (juce::TextEditor::highlightColourId, juce::Colour (0xff42a2c8));
    thresholdTextEditor->setText (TRANS("Latest Adapt."));

    thresholdTextEditor->setBounds (10, 27, 102, 24);

    showFilterToggleButton.reset (new juce::ToggleButton ("showFilterToggleButton"));
    addAndMakeVisible (showFilterToggleButton.get());
    showFilterToggleButton->setExplicitFocusOrder (11);
    showFilterToggleButton->setButtonText (TRANS("filter"));
    showFilterToggleButton->addListener (this);
    showFilterToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    noSecondsSoundPerCalcLabel.reset (new juce::Label ("noSecondsSoundPerCalcLabel",
                                                       TRANS("Seconds sound per calculation.")));
    addAndMakeVisible (noSecondsSoundPerCalcLabel.get());
    noSecondsSoundPerCalcLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    noSecondsSoundPerCalcLabel->setJustificationType (juce::Justification::centredLeft);
    noSecondsSoundPerCalcLabel->setEditable (false, false, false);
    noSecondsSoundPerCalcLabel->setColour (juce::Label::textColourId, juce::Colours::cornflowerblue);
    noSecondsSoundPerCalcLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    noSecondsSoundPerCalcLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    noSecondsSoundPerCalcLabel->setBounds (99, 151, 221, 24);

    noSecondsSoundPerCalcComboBox.reset (new juce::ComboBox ("noSecondsSoundPerCalcComboBox"));
    addAndMakeVisible (noSecondsSoundPerCalcComboBox.get());
    noSecondsSoundPerCalcComboBox->setExplicitFocusOrder (5);
    noSecondsSoundPerCalcComboBox->setEditableText (false);
    noSecondsSoundPerCalcComboBox->setJustificationType (juce::Justification::centredRight);
    noSecondsSoundPerCalcComboBox->setTextWhenNothingSelected (juce::String());
    noSecondsSoundPerCalcComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    noSecondsSoundPerCalcComboBox->addListener (this);

    noSecondsSoundPerCalcComboBox->setBounds (10, 151, 86, 24);

    showIndicatorsToggleButton.reset (new juce::ToggleButton ("showIndicatorsToggleButton"));
    addAndMakeVisible (showIndicatorsToggleButton.get());
    showIndicatorsToggleButton->setExplicitFocusOrder (5);
    showIndicatorsToggleButton->setButtonText (TRANS("Indicators"));
    showIndicatorsToggleButton->addListener (this);
    showIndicatorsToggleButton->setToggleState (true, dontSendNotification);
    showIndicatorsToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    showIndicatorsToggleButton->setBounds (10, 206, 133, 25);

    showFFTMaxIndictrToggleButton.reset (new juce::ToggleButton ("showFFTMaxIndictrToggleButton"));
    addAndMakeVisible (showFFTMaxIndictrToggleButton.get());
    showFFTMaxIndictrToggleButton->setExplicitFocusOrder (10);
    showFFTMaxIndictrToggleButton->setButtonText (TRANS("FFT max indicator"));
    showFFTMaxIndictrToggleButton->addListener (this);
    showFFTMaxIndictrToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    stringsOffTuneValuesToggleButton.reset (new juce::ToggleButton ("stringsOffTuneValuesToggleButton"));
    addAndMakeVisible (stringsOffTuneValuesToggleButton.get());
    stringsOffTuneValuesToggleButton->setExplicitFocusOrder (7);
    stringsOffTuneValuesToggleButton->setButtonText (TRANS("strings off tune values (Hz)"));
    stringsOffTuneValuesToggleButton->addListener (this);
    stringsOffTuneValuesToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    autoCalibrateTextButton.reset (new juce::TextButton ("autoCalibrateTextButton"));
    addAndMakeVisible (autoCalibrateTextButton.get());
    autoCalibrateTextButton->setButtonText (TRANS("Auto Calibrate"));
    autoCalibrateTextButton->addListener (this);

    autoCalibrateTextButton->setBounds (139, 27, 107, 24);

    labelLowestFreq.reset (new juce::Label ("labelLowestFreq",
                                            TRANS("Low frequency (1..69)")));
    addAndMakeVisible (labelLowestFreq.get());
    labelLowestFreq->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelLowestFreq->setJustificationType (juce::Justification::centredLeft);
    labelLowestFreq->setEditable (false, false, false);
    labelLowestFreq->setColour (juce::Label::textColourId, juce::Colours::cornflowerblue);
    labelLowestFreq->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelLowestFreq->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelLowestFreq->setBounds (5, 314, 189, 24);

    sliderLowestFreq.reset (new juce::Slider ("sliderLowestFreq"));
    addAndMakeVisible (sliderLowestFreq.get());
    sliderLowestFreq->setExplicitFocusOrder (1);
    sliderLowestFreq->setRange (1, 69, 1);
    sliderLowestFreq->setSliderStyle (juce::Slider::IncDecButtons);
    sliderLowestFreq->setTextBoxStyle (juce::Slider::NoTextBox, false, 56, 24);
    sliderLowestFreq->setColour (juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
    sliderLowestFreq->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0xff42a2c8));
    sliderLowestFreq->addListener (this);

    sliderLowestFreq->setBounds (66, 338, 55, 24);

    sliderHighestFreq.reset (new juce::Slider ("sliderHighestFreq"));
    addAndMakeVisible (sliderHighestFreq.get());
    sliderHighestFreq->setExplicitFocusOrder (2);
    sliderHighestFreq->setRange (343, 441, 1);
    sliderHighestFreq->setSliderStyle (juce::Slider::IncDecButtons);
    sliderHighestFreq->setTextBoxStyle (juce::Slider::NoTextBox, false, 56, 24);
    sliderHighestFreq->setColour (juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
    sliderHighestFreq->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0xff42a2c8));
    sliderHighestFreq->addListener (this);

    sliderHighestFreq->setBounds (66, 397, 55, 24);

    labelHighstFreq.reset (new juce::Label ("labelHighstFreq",
                                            TRANS("High frequency (343 .. 441)")));
    addAndMakeVisible (labelHighstFreq.get());
    labelHighstFreq->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelHighstFreq->setJustificationType (juce::Justification::centredLeft);
    labelHighstFreq->setEditable (false, false, false);
    labelHighstFreq->setColour (juce::Label::textColourId, juce::Colours::cornflowerblue);
    labelHighstFreq->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelHighstFreq->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelHighstFreq->setBounds (5, 370, 221, 24);

    calculationsLabel.reset (new juce::Label ("calculationsLabel",
                                              TRANS("calculations\n")));
    addAndMakeVisible (calculationsLabel.get());
    calculationsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    calculationsLabel->setJustificationType (juce::Justification::centredLeft);
    calculationsLabel->setEditable (false, false, false);
    calculationsLabel->setColour (juce::Label::textColourId, juce::Colours::cornflowerblue);
    calculationsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    calculationsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    calculationsLabel->setBounds (124, 117, 96, 24);

    averageSider.reset (new juce::Slider ("averageSider"));
    addAndMakeVisible (averageSider.get());
    averageSider->setExplicitFocusOrder (3);
    averageSider->setRange (1, 40, 1);
    averageSider->setSliderStyle (juce::Slider::IncDecButtons);
    averageSider->setTextBoxStyle (juce::Slider::NoTextBox, false, 56, 24);
    averageSider->setColour (juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
    averageSider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0xff42a2c8));
    averageSider->addListener (this);

    averageSider->setBounds (66, 117, 55, 24);

    adaptiveToggleButton.reset (new juce::ToggleButton ("adaptiveToggleButton"));
    addAndMakeVisible (adaptiveToggleButton.get());
    adaptiveToggleButton->setButtonText (TRANS("Adaptive"));
    adaptiveToggleButton->setConnectedEdges (juce::Button::ConnectedOnLeft);
    adaptiveToggleButton->addListener (this);
    adaptiveToggleButton->setToggleState (true, dontSendNotification);
    adaptiveToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    adaptiveToggleButton->setBounds (10, 61, 83, 24);

    adaptiveNoSecondsComboBox.reset (new juce::ComboBox ("adaptiveNoSecondsComboBox"));
    addAndMakeVisible (adaptiveNoSecondsComboBox.get());
    adaptiveNoSecondsComboBox->setEditableText (false);
    adaptiveNoSecondsComboBox->setJustificationType (juce::Justification::centredRight);
    adaptiveNoSecondsComboBox->setTextWhenNothingSelected (juce::String());
    adaptiveNoSecondsComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    adaptiveNoSecondsComboBox->addListener (this);

    adaptiveNoSecondsComboBox->setBounds (100, 61, 86, 24);

    adaptiveNoSecondsLabel.reset (new juce::Label ("adaptiveNoSecondsLabel",
                                                   TRANS("Seconds sound in calcs.")));
    addAndMakeVisible (adaptiveNoSecondsLabel.get());
    adaptiveNoSecondsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    adaptiveNoSecondsLabel->setJustificationType (juce::Justification::centredLeft);
    adaptiveNoSecondsLabel->setEditable (false, false, false);
    adaptiveNoSecondsLabel->setColour (juce::Label::textColourId, juce::Colours::cornflowerblue);
    adaptiveNoSecondsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    adaptiveNoSecondsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    adaptiveNoSecondsLabel->setBounds (190, 61, 130, 24);

    thresholdToggleButton.reset (new juce::ToggleButton ("thresholdToggleButton"));
    addAndMakeVisible (thresholdToggleButton.get());
    thresholdToggleButton->setButtonText (TRANS("Threshold"));
    thresholdToggleButton->addListener (this);
    thresholdToggleButton->setColour (juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    thresholdToggleButton->setBounds (183, 233, 112, 25);


    //[UserPreSize]
	noSecondsSoundPerCalcComboBox->setColour(ComboBox::textColourId, Colours::cornflowerblue);
	adaptiveNoSecondsComboBox->setColour(ComboBox::textColourId, Colours::cornflowerblue);

	sliderLowestFreqLabel.reset(getLookAndFeel().createSliderTextBox(*sliderLowestFreq));
	sliderLowestFreqLabel->setBounds(10, 338, 50, 20);
	addAndMakeVisible(sliderLowestFreqLabel.get());
	sliderLowestFreqLabel->setEditable(false, false, false);
	sliderLowestFreqLabel->setVisible(true);
	sliderLowestFreqLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);

	sliderHighestFreqLabel.reset(getLookAndFeel().createSliderTextBox(*sliderHighestFreq));
	sliderHighestFreqLabel->setBounds(10, 397, 50, 20);
	addAndMakeVisible(sliderHighestFreqLabel.get());
	sliderHighestFreqLabel->setEditable(false, false, false);
	sliderHighestFreqLabel->setVisible(true);
	sliderHighestFreqLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);

	averageSiderLabel.reset(getLookAndFeel().createSliderTextBox(*averageSider));
	averageSiderLabel->setBounds(10, 117, 50, 24);
	addAndMakeVisible(averageSiderLabel.get());
	averageSiderLabel->setEditable(false, false, false);
	averageSiderLabel->setVisible(true);
	averageSiderLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);
    //[/UserPreSize]

    setSize (310, 460);


    //[Constructor] You can add your own custom stuff here..
#if (JUCE_IOS || JUCE_ANDROID)
	showFFTToggleButton->setBounds (119, 233, 55, 25);
	showSpectrumToggleButton->setBounds (10, 233, 94, 25);
	showFilterToggleButton->setBounds (183, 260, 78, 25);
	showFFTMaxIndictrToggleButton->setBounds (10, 260, 136, 25);
	stringsOffTuneValuesToggleButton->setBounds (119, 206, 176, 25);
	setSize(346, 420);
#endif
	thresholdTextEditor->setJustification(Justification::centred);
    //[/Constructor]
}

displayControlComponent::~displayControlComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	pGuitarFineTuneLookAndFeel.reset();
	pGuitarFineTuneLookAndFeel = nullptr;
    //[/Destructor_pre]

    freqRangeGroupComponent = nullptr;
    ShowGroupComponent = nullptr;
    averageGroupComponent = nullptr;
    bgsoundExclusionGroupComponent = nullptr;
    showFFTToggleButton = nullptr;
    showSpectrumToggleButton = nullptr;
    thresholdTextEditor = nullptr;
    showFilterToggleButton = nullptr;
    noSecondsSoundPerCalcLabel = nullptr;
    noSecondsSoundPerCalcComboBox = nullptr;
    showIndicatorsToggleButton = nullptr;
    showFFTMaxIndictrToggleButton = nullptr;
    stringsOffTuneValuesToggleButton = nullptr;
    autoCalibrateTextButton = nullptr;
    labelLowestFreq = nullptr;
    sliderLowestFreq = nullptr;
    sliderHighestFreq = nullptr;
    labelHighstFreq = nullptr;
    calculationsLabel = nullptr;
    averageSider = nullptr;
    adaptiveToggleButton = nullptr;
    adaptiveNoSecondsComboBox = nullptr;
    adaptiveNoSecondsLabel = nullptr;
    thresholdToggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void displayControlComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff20072b));

    //[UserPaint] Add your own custom painting code here..
	g.fillAll(Colour(0xff20072b));
    //[/UserPaint]
}

void displayControlComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
#if  !(JUCE_IOS || JUCE_ANDROID) // Avoid running Projucers code if Android || iOS
    //[/UserPreResize]

    showFFTToggleButton->setBounds (119, 233, 55, 25);
    showSpectrumToggleButton->setBounds (10, 233, 94, 25);
    showFilterToggleButton->setBounds (183, 260, 78, 25);
    showFFTMaxIndictrToggleButton->setBounds (10, 260, 136, 25);
    stringsOffTuneValuesToggleButton->setBounds (119, 206, 176, 25);
    //[UserResized] Add your own custom resize handling here..
#endif  // !(JUCE_IOS || JUCE_ANDROID) End Avoid running Projucers code

#if (JUCE_WINDOWS || JUCE_MAC || JUCE_ANDROID)
#if JUCE_ANDROID
	if (viewPortAdded)
	{
#endif // JUCE_ANDROID
		auto  curUserArea = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
		if (curUserArea.getWidth() >= curUserArea.getHeight())
		{
			// Horizontal
			setSize(widthOfDisplayControlWindowHorizontal, hightOfDisplayControlWindowHorizontal);
			freqRangeGroupComponent->setBounds(323, 8, 203, 128);
			labelLowestFreq->setBounds(325, 20, 199, 24);
			sliderLowestFreq->setBounds(391, 44, 55, 24);
			sliderLowestFreqLabel->setBounds(335, 44, 50, 24);
			labelHighstFreq->setBounds(325, 72, 200, 24);
			sliderHighestFreq->setBounds(391, 99, 55, 24);
			sliderHighestFreqLabel->setBounds(335, 99, 50, 24);
		}
		else
		{
			//Vertical
			setSize(widthOfDisplayControlWindowVertical, hightOfDisplayControlWindowVertical);
			freqRangeGroupComponent->setBounds(0, 298, 320, 136);
			labelLowestFreq->setBounds(5, 314, 189, 24);
			sliderLowestFreq->setBounds(66, 338, 55, 24);
			sliderLowestFreqLabel->setBounds(10, 338, 50, 20);
			labelHighstFreq->setBounds(5, 370, 221, 24);
			sliderHighestFreq->setBounds(66, 397, 55, 24);
			sliderHighestFreqLabel->setBounds(10, 397, 50, 20);
		}
	#if JUCE_ANDROID
	}
#endif // JUCE_ANDROID
#endif // (JUCE_WINDOWS || JUCE_MAC || JUCE_ANDROID)
    //[/UserResized]
}

void displayControlComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == showFFTToggleButton.get())
    {
        //[UserButtonCode_showFFTToggleButton] -- add your button handler code here..
		if (!showFFTToggleButton->getToggleState())
		{
			showFilterToggleButton->setToggleState(false, juce::NotificationType::sendNotification);
			if (showFFTMaxIndictrToggleButton->getToggleState())
			{
				showFFTMaxIndictrToggleButton->setToggleState(false, juce::NotificationType::sendNotification);
			}
		}
		pTuneComponent->setShowFFT(showFFTToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showFFT", showFFTToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_showFFTToggleButton]
    }
    else if (buttonThatWasClicked == showSpectrumToggleButton.get())
    {
        //[UserButtonCode_showSpectrumToggleButton] -- add your button handler code here..
		if (showSpectrumToggleButton->getToggleState())
		{
			if (showFilterToggleButton->getToggleState())
			{
				showFilterToggleButton->setToggleState(false, NotificationType::sendNotification); // Set to previous selected size
			}
		}
		pTuneComponent->setShowSpectrum(showSpectrumToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showSpectrum", showSpectrumToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_showSpectrumToggleButton]
    }
    else if (buttonThatWasClicked == showFilterToggleButton.get())
    {
        //[UserButtonCode_showFilterToggleButton] -- add your button handler code here..
		static bool oldStateOfShowFFTToggleButton = false;
		static bool oldStateOfShowSpectrumToggleButton = false;
		static bool oldStateOfShowIndicatorsToggleButton = false;
		bool localShowFiltersToggleButtonOn = showFilterToggleButton->getToggleState();
		pTuneComponent->setshowFilters(localShowFiltersToggleButtonOn);
		if (localShowFiltersToggleButtonOn)
		{
			currentFftOrderThatWasSelected = noSecondsSoundPerCalcComboBox->getSelectedId();
			oldStateOfShowFFTToggleButton = showFFTToggleButton->getToggleState();
			showFFTToggleButton->setToggleState(true, NotificationType::sendNotification);
			oldStateOfShowSpectrumToggleButton = showSpectrumToggleButton->getToggleState();
			showSpectrumToggleButton->setToggleState(false, NotificationType::sendNotification);
			oldStateOfShowIndicatorsToggleButton = showIndicatorsToggleButton->getToggleState();
			showIndicatorsToggleButton->setToggleState(false, NotificationType::sendNotification);
			// Set fftsize equal to the buffer size
			noSecondsSoundPerCalcComboBox->setSelectedId((int)(std::log2(pTuneComponent->getCurrentBufferSizeInUse())), NotificationType::sendNotification);
		}
		else
		{
			showFFTToggleButton->setToggleState(oldStateOfShowFFTToggleButton, NotificationType::sendNotification); // Set to previous selected size
			showSpectrumToggleButton->setToggleState(oldStateOfShowSpectrumToggleButton, NotificationType::sendNotification);
			showIndicatorsToggleButton->setToggleState(oldStateOfShowIndicatorsToggleButton, NotificationType::sendNotification);
			noSecondsSoundPerCalcComboBox->setSelectedId(currentFftOrderThatWasSelected, NotificationType::sendNotification);
		}
		// SAve in XML file (though the value there is still not used)
		getXmlTagDISPLAYCONTROL()->setAttribute("showFilter", showFilterToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_showFilterToggleButton]
    }
    else if (buttonThatWasClicked == showIndicatorsToggleButton.get())
    {
        //[UserButtonCode_showIndicatorsToggleButton] -- add your button handler code here..
		if (showIndicatorsToggleButton->getToggleState())
		{
			if (showFilterToggleButton->getToggleState())
			{
				showFilterToggleButton->setToggleState(false, NotificationType::sendNotification); // Set to previous selected size
			}
		}
		pTuneComponent->setShowIndicators(showIndicatorsToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showIndicators", showIndicatorsToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_showIndicatorsToggleButton]
    }
    else if (buttonThatWasClicked == showFFTMaxIndictrToggleButton.get())
    {
        //[UserButtonCode_showFFTMaxIndictrToggleButton] -- add your button handler code here..
		if (showFFTMaxIndictrToggleButton->getToggleState())
		{
			if (!showFFTToggleButton->getToggleState())
			{
				showFFTToggleButton->setToggleState(true, juce::NotificationType::sendNotification);
			}
		}
		pTuneComponent->setshowFFTMaxIndictr(showFFTMaxIndictrToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showFFTMaxIndictr", showFFTMaxIndictrToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_showFFTMaxIndictrToggleButton]
    }
    else if (buttonThatWasClicked == stringsOffTuneValuesToggleButton.get())
    {
        //[UserButtonCode_stringsOffTuneValuesToggleButton] -- add your button handler code here..
		pTuneComponent->setShowstringsOffTuneValues(stringsOffTuneValuesToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showStringsOffTuneValues", stringsOffTuneValuesToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_stringsOffTuneValuesToggleButton]
    }
    else if (buttonThatWasClicked == autoCalibrateTextButton.get())
    {
        //[UserButtonCode_autoCalibrateTextButton] -- add your button handler code here..
		pTuneComponent->startThresholdAutoCalibrate();
		adaptiveToggleButton->setToggleState(false, NotificationType::sendNotification);
		adaptiveToggleButton->setEnabled(false);
        //[/UserButtonCode_autoCalibrateTextButton]
    }
    else if (buttonThatWasClicked == adaptiveToggleButton.get())
    {
        //[UserButtonCode_adaptiveToggleButton] -- add your button handler code here..
		pTuneComponent->setAdaptiveBackgroundSoundReductionOn(adaptiveToggleButton->getToggleState());
        //[/UserButtonCode_adaptiveToggleButton]
    }
    else if (buttonThatWasClicked == thresholdToggleButton.get())
    {
        //[UserButtonCode_thresholdToggleButton] -- add your button handler code here..
		pTuneComponent->setshowThreshold(thresholdToggleButton->getToggleState());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("showThreshold", thresholdToggleButton->getToggleState());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserButtonCode_thresholdToggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void displayControlComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == noSecondsSoundPerCalcComboBox.get())
    {
        //[UserComboBoxCode_noSecondsSoundPerCalcComboBox] -- add your combo box handling code here..
		int selectedId = noSecondsSoundPerCalcComboBox->getSelectedId();
		if (selectedId > 0)
		{
			pTuneComponent->setFftOrder(selectedId);
		}
		getXmlTagDISPLAYCONTROL()->setAttribute("fftOrder", selectedId);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserComboBoxCode_noSecondsSoundPerCalcComboBox]
    }
    else if (comboBoxThatHasChanged == adaptiveNoSecondsComboBox.get())
    {
        //[UserComboBoxCode_adaptiveNoSecondsComboBox] -- add your combo box handling code here..
		pTuneComponent->setNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs(adaptiveNoSecondsComboBox->getSelectedId());
		// SAve in XML file
		getXmlTagDISPLAYCONTROL()->setAttribute("noOfFullAudioRecordBuffersInCalcs", adaptiveNoSecondsComboBox->getSelectedId());
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
        //[/UserComboBoxCode_adaptiveNoSecondsComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void displayControlComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderLowestFreq.get())
    {
        //[UserSliderCode_sliderLowestFreq] -- add your slider handling code here..
		int tmpVal1, tmpVal2;
		pTuneComponent->setLowestAndHighestFreqToDisplayDataForHz((int)(sliderLowestFreq->getValue()), (int)(sliderHighestFreq->getValue()));
		pTuneComponent->getLowestAndHighestFreqToDisplayDataForHz(tmpVal1, tmpVal2);
		sliderLowestFreq->setValue(tmpVal1, dontSendNotification);
		sliderHighestFreq->setValue(tmpVal2, dontSendNotification);
		sliderLowestFreqLabel->setText(eksLongDoubleToString(tmpVal1, 0), NotificationType::dontSendNotification);
		sliderHighestFreqLabel->setText(eksLongDoubleToString(tmpVal2, 0), NotificationType::dontSendNotification);
        //[/UserSliderCode_sliderLowestFreq]
    }
    else if (sliderThatWasMoved == sliderHighestFreq.get())
    {
        //[UserSliderCode_sliderHighestFreq] -- add your slider handling code here..
		int tmpVal1, tmpVal2;
		pTuneComponent->setLowestAndHighestFreqToDisplayDataForHz((int)(sliderLowestFreq->getValue()), (int)(sliderHighestFreq->getValue()));
		pTuneComponent->getLowestAndHighestFreqToDisplayDataForHz(tmpVal1, tmpVal2);
		sliderLowestFreq->setValue(tmpVal1, dontSendNotification);
		sliderHighestFreq->setValue(tmpVal2, dontSendNotification);
		sliderLowestFreqLabel->setText(eksLongDoubleToString(tmpVal1, 0), NotificationType::dontSendNotification);
		sliderHighestFreqLabel->setText(eksLongDoubleToString(tmpVal2, 0), NotificationType::dontSendNotification);
        //[/UserSliderCode_sliderHighestFreq]
    }
    else if (sliderThatWasMoved == averageSider.get())
    {
        //[UserSliderCode_averageSider] -- add your slider handling code here..
		pTuneComponent->setNoValsInAvgFreqsOutOfTuneCalc((int)(averageSider->getValue()));
		averageSider->setValue(pTuneComponent->getNoValsInAvgFreqsOutOfTuneCalc(), dontSendNotification);
		getXmlTagDISPLAYCONTROL()->setAttribute("noCalcsInAverage", (int)(averageSider->getValue()));
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		averageSiderLabel->setText(eksLongDoubleToString(averageSider->getValue(), 0), NotificationType::dontSendNotification);
        //[/UserSliderCode_averageSider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
inline std::string displayControlComponent::eksLongDoubleToString(long double valueToConvert, int noOfDecimals)
{
	char stringOfRoundedSecondsPerBufferBuffer[20] = { 0 };
	auto roundedSecondsPerBuffer = std::round(valueToConvert * std::pow(10, noOfDecimals)) / std::pow(10, noOfDecimals);
	std::sprintf(stringOfRoundedSecondsPerBufferBuffer, "%.*Lf", noOfDecimals, roundedSecondsPerBuffer);
	return stringOfRoundedSecondsPerBufferBuffer;
}

#if (JUCE_IOS || JUCE_ANDROID)
void displayControlComponent::scaleAllComponents()
{
#if JUCE_ANDROID
	if (!viewPortAdded)
	{
#endif // JUCE_ANDROID
		if (auto parent = findParentComponentOfClass<TabbedComponent>())
		{
			static float scaleUsedLastTime = 1.0f;
			static bool firstCall = true;
			Rectangle<int> workRectangle;

			int tabBarDepth = parent->getTabBarDepth();

			auto  curUserArea = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
			float bndsScaleHoriz = (float)(curUserArea.getWidth()) / (float)(widthOfDisplayControlWindowHorizontal);
			float bndsScaleVerti = ((float)(curUserArea.getHeight()) - (float)tabBarDepth) / ((float)hightOfDisplayControlWindowHorizontal);
			float scaleNow = bndsScaleVerti;
			if (bndsScaleHoriz < bndsScaleVerti)
			{
				scaleNow = bndsScaleHoriz;
			}


			if (curUserArea.getWidth() >= curUserArea.getHeight())
			{
				// Horizontal
				workRectangle.setBounds(323, 8, 203, 128);
				freqRangeGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(325, 20, 199, 24);
				labelLowestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(391, 44, 55, 24);
				sliderLowestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(335, 44, 50, 24);
				sliderLowestFreqLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(325, 72, 200, 24);
				labelHighstFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(391, 99, 55, 24);
				sliderHighestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(335, 99, 50, 24);
				sliderHighestFreqLabel->setBounds(workRectangle * scaleUsedLastTime);
			}
			else
			{
				// Vertical
				bndsScaleHoriz = (float)(curUserArea.getWidth()) / (float)(widthOfDisplayControlWindowVertical);
				bndsScaleVerti = ((float)(curUserArea.getHeight()) - (float)tabBarDepth) / ((float)(hightOfDisplayControlWindowVertical + 1));
				if (bndsScaleHoriz < bndsScaleVerti)
				{
					scaleNow = bndsScaleHoriz;
				}
				else
				{
					scaleNow = bndsScaleVerti;
				}
				workRectangle.setBounds(0, 298, 320, 136);
				freqRangeGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(5, 314, 189, 24);
				labelLowestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(66, 338, 55, 24);
				sliderLowestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(10, 338, 50, 24);
				sliderLowestFreqLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(5, 370, 221, 24);
				labelHighstFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(66, 397, 55, 24);
				sliderHighestFreq->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(10, 397, 50, 24);
				sliderHighestFreqLabel->setBounds(workRectangle * scaleUsedLastTime);
			}

			auto curbnds = getBounds();

			if (scaleNow != scaleUsedLastTime)
			{
				float scaleToUse = scaleNow / scaleUsedLastTime;

				curbnds = getBounds();
				curUserArea.setHeight(curUserArea.getHeight() - parent->getTabBarDepth());
				curUserArea.setY(parent->getTabBarDepth());
				setBoundsToFit(curUserArea, Justification::left, false);

				int numChildComponents = this->getNumChildComponents();

				for (int i = 0; i < numChildComponents; ++i)
				{
					if (Component *childComponent = this->getChildComponent(i))
					{
						auto curCpntBnds = childComponent->getBounds();
						auto scaledBounds = curCpntBnds * scaleToUse;
						childComponent->setBounds(scaledBounds);

						auto labelTestComponent = dynamic_cast<juce::Label*> (childComponent);
						if ((labelTestComponent != nullptr) && (scaleToUse > 1) && firstCall)
						{
							Font currentFont = labelTestComponent->getFont();
							currentFont.setHeight(currentFont.getHeightInPoints() * scaleToUse * 0.9);
							labelTestComponent->setFont(currentFont);
						}

						auto textEditorTestComponent = dynamic_cast<juce::TextEditor*> (childComponent);
						if ((textEditorTestComponent != nullptr) && (scaleToUse > 1) && firstCall)
						{
							Font currentFont = textEditorTestComponent->getFont();
							currentFont.setHeight(currentFont.getHeightInPoints() * scaleToUse * 1.3);
							textEditorTestComponent->applyFontToAllText(currentFont);
							textEditorTestComponent->setJustification(Justification::centred);
						}
					}
				}

				scaleUsedLastTime = scaleNow;
				firstCall = false;
			}
		}
#if JUCE_ANDROID
	}
#endif // JUCE_ANDROID
}
#endif // (JUCE_IOS || JUCE_ANDROID)

XmlElement * displayControlComponent::getXmlTagDISPLAYCONTROL()
{
	// check we're looking at the right kind of document..
	if (pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().hasTagName("GUITARFINETUNECONFIG"))
	{
		// now we'll iterate its sub-elements looking for 'DISPLAYCONTROL' elements..
		return pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().getChildByName("DISPLAYCONTROL");
	}
	return nullptr;
}

void displayControlComponent::setToAutoThresholdTextEditor()
{
	thresholdTextEditor->setText("Auto Calibr.", false);
}

void displayControlComponent::setToAdapThresholdTextEditor()
{
	thresholdTextEditor->setText("Adaptive", false);
}

void displayControlComponent::setToLatestThresholdTextEditor()
{
	thresholdTextEditor->setText("Latest Adapt.", false);
}

void displayControlComponent::enableAdaptiveToggleButton()
{
	adaptiveToggleButton->setEnabled(true);
}

void displayControlComponent::initControls()
{
	int lowestFreq, highestFreq;
	pTuneComponent->getLowestAndHighestFreqToDisplayDataForHz(lowestFreq, highestFreq);
	sliderLowestFreq->setValue(lowestFreq, dontSendNotification);
	sliderLowestFreqLabel->setText(eksLongDoubleToString(lowestFreq, 0), NotificationType::dontSendNotification);
	sliderHighestFreq->setValue(highestFreq, dontSendNotification);
	sliderHighestFreqLabel->setText(eksLongDoubleToString(highestFreq, 0), NotificationType::dontSendNotification);

	int noCalcsInAverage = getXmlTagDISPLAYCONTROL()->getIntAttribute("noCalcsInAverage");
	pTuneComponent->setNoValsInAvgFreqsOutOfTuneCalc(noCalcsInAverage);
	averageSider->setValue(noCalcsInAverage, dontSendNotification);
	averageSiderLabel->setText(eksLongDoubleToString(noCalcsInAverage, 0), NotificationType::dontSendNotification);

	thresholdTextEditor->setSelectAllWhenFocused(true);
	thresholdTextEditor->setInputRestrictions(6, "1 2 3 4 5 6 7 8 9 0 . ,");
	thresholdTextEditor->addListener(this);
	auto thresholdResultMagnitudeSquaredForShowing = getXmlTagDISPLAYCONTROL()->getDoubleAttribute("globalThresholdForShowing");
	if (thresholdResultMagnitudeSquaredForShowing >= 0.0f)
	{
		pTuneComponent->setThresholdResultMagnitudeSquaredForShowing(thresholdResultMagnitudeSquaredForShowing);
		pTuneComponent->setAdaptiveBackgroundSoundReductionOn(false);
		adaptiveToggleButton->setToggleState(false, NotificationType::dontSendNotification);
		thresholdTextEditor->setText(String(thresholdResultMagnitudeSquaredForShowing, 3), false);
	}
	else
	{
		switch ((int)thresholdResultMagnitudeSquaredForShowing)
		{
			case Auto_globalThresholdForShowing:
				{
					adaptiveToggleButton->setToggleState(false, NotificationType::dontSendNotification);
					pTuneComponent->setAdaptiveBackgroundSoundReductionOn(false);
					thresholdTextEditor->setText("Auto Calibr.", false);
					break;
				}
			case Adaptive_globalThresholdForShowing:
				{
					adaptiveToggleButton->setToggleState(true, NotificationType::dontSendNotification);
					pTuneComponent->setAdaptiveBackgroundSoundReductionOn(true);
					thresholdTextEditor->setText("Adaptive", false);
					break;
				}
			case Latest_globalThresholdForShowing:
				{
					adaptiveToggleButton->setToggleState(false, NotificationType::dontSendNotification);
					pTuneComponent->setAdaptiveBackgroundSoundReductionOn(false);
					thresholdTextEditor->setText("Latest Adapt.", false);
					break;
				}
			default:
				{
					break;
				}
		}
	}


	auto actShowThreshold = getXmlTagDISPLAYCONTROL()->getBoolAttribute("showThreshold");
	pTuneComponent->setshowThreshold(actShowThreshold);
	thresholdToggleButton->setToggleState(actShowThreshold, NotificationType::dontSendNotification);

	double sampleRate; uint16 lowestGoertzelFreq; uint16 HighestGoertzelFreq;
	pTuneComponent->getCurrentDecimatedSampleRateAndLowestAndHighestGoertzelFreq(sampleRate, lowestGoertzelFreq, HighestGoertzelFreq);
	setLabelHighstFreqText(sampleRate, lowestGoertzelFreq, HighestGoertzelFreq);
	pTuneComponent->setDisplayControlComponentReadyFlag(true);

	auto currentSecondsPerSampleAtDecimatedSampleRate = (double)1.0f / pTuneComponent->getCurrentDecimatedSampleRate();
	auto curSecondsPerBuffer = std::numeric_limits<double>::min();
	noSecondsSoundPerCalcComboBox->clear(NotificationType::dontSendNotification);
	auto fftOrder = 5;
	while (curSecondsPerBuffer < 5)
	{
		curSecondsPerBuffer = (double)(1 << fftOrder) * currentSecondsPerSampleAtDecimatedSampleRate;
		if (curSecondsPerBuffer <= 5)
		{
			// Round to 3 decimals
			noSecondsSoundPerCalcComboBox->addItem(eksLongDoubleToString(curSecondsPerBuffer, 3), fftOrder);

			fftOrder++;
		}
	}
	currentFftOrderThatWasSelected = getXmlTagDISPLAYCONTROL()->getIntAttribute("fftOrder");
	pTuneComponent->setFftOrder(currentFftOrderThatWasSelected);
	noSecondsSoundPerCalcComboBox->setSelectedId(currentFftOrderThatWasSelected, NotificationType::dontSendNotification);
	pTuneComponent->setNoSecondsSoundPerCalcComboBoxReady(true);

	showIndicatorsToggleButton->setToggleState(getXmlTagDISPLAYCONTROL()->getBoolAttribute("showIndicators"), NotificationType::dontSendNotification);
	if (showIndicatorsToggleButton->getToggleState())
	{
		if (showFilterToggleButton->getToggleState())
		{
			showFilterToggleButton->setToggleState(false, NotificationType::sendNotification); // Set to previous selected size
		}
	}
	pTuneComponent->setShowIndicators(showIndicatorsToggleButton->getToggleState());

	showSpectrumToggleButton->setToggleState(getXmlTagDISPLAYCONTROL()->getBoolAttribute("showSpectrum"), NotificationType::dontSendNotification);
	if (showSpectrumToggleButton->getToggleState())
	{
		if (showFilterToggleButton->getToggleState())
		{
			showFilterToggleButton->setToggleState(false, NotificationType::sendNotification); // Set to previous selected size
		}
	}
	pTuneComponent->setShowSpectrum(showSpectrumToggleButton->getToggleState());

	showFFTToggleButton->setToggleState(getXmlTagDISPLAYCONTROL()->getBoolAttribute("showFFT"), NotificationType::dontSendNotification);
	if (!showFFTToggleButton->getToggleState())
	{
		showFilterToggleButton->setToggleState(false, juce::NotificationType::sendNotification);
		if (showFFTMaxIndictrToggleButton->getToggleState())
		{
			showFFTMaxIndictrToggleButton->setToggleState(false, juce::NotificationType::sendNotification);
		}
	}
	pTuneComponent->setShowFFT(showFFTToggleButton->getToggleState());

	showFFTMaxIndictrToggleButton->setToggleState(getXmlTagDISPLAYCONTROL()->getBoolAttribute("showFFT"), NotificationType::dontSendNotification);
	if (showFFTMaxIndictrToggleButton->getToggleState())
	{
		if (!showFFTToggleButton->getToggleState())
		{
			showFFTToggleButton->setToggleState(true, juce::NotificationType::sendNotification);
		}
	}
	pTuneComponent->setshowFFTMaxIndictr(showFFTMaxIndictrToggleButton->getToggleState());



}

void displayControlComponent::textEditorReturnKeyPressed(TextEditor& editorThatIs)
{
	if (&editorThatIs == thresholdTextEditor.get())
	{
		double valueEntered = thresholdTextEditor->getText().replaceCharacter(',', '.').getDoubleValue();
		if (valueEntered >= 0.0f)
		{
			adaptiveToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->setThresholdResultMagnitudeSquaredForShowing(valueEntered);
			pTuneComponent->setAdaptiveBackgroundSoundReductionOn(false);
			thresholdTextEditor->setText(String(valueEntered, 3), false);
			getXmlTagDISPLAYCONTROL()->setAttribute("globalThresholdForShowing", valueEntered);
			pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		}
	}

	if (!itsLostFocus)
	{
		editorThatIs.selectAll();
	}
	else
	{
		itsLostFocus = false;
	}
}

void displayControlComponent::textEditorFocusLost(TextEditor& editorThatIs)
{
	itsLostFocus = true;
	textEditorReturnKeyPressed(editorThatIs);
}

void displayControlComponent::setLabelHighstFreqText(double& decimatedSampleRate, uint16 lowestGoertzelFreq, uint16 HighestGoertzelFreq)
{
	labelLowestFreq->setText("Lowest frequency (1 .. " + String(lowestGoertzelFreq) + ")", dontSendNotification);
	labelHighstFreq->setText("Highest frequency (" + String(HighestGoertzelFreq) + " ... " + String((uint16)(decimatedSampleRate / 2)) + ")", dontSendNotification);
}

void displayControlComponent::showLowestAndHighestFreqToDisplayDataForHz(double& decimatedSampleRate, uint16 lowestGoertzelFreq, uint16 HighestGoertzelFreq)
{
	int lowestFreq, highestFreq;

	pTuneComponent->getLowestAndHighestFreqToDisplayDataForHz(lowestFreq, highestFreq);

	sliderLowestFreq->setRange(1, lowestGoertzelFreq, 1);
	sliderLowestFreq->setValue((double)lowestFreq, dontSendNotification);

	sliderHighestFreq->setValue((double)lowestFreq, dontSendNotification);
	sliderHighestFreq->setRange(HighestGoertzelFreq, (uint16)(decimatedSampleRate / 2), 1);
	sliderHighestFreq->setValue((double)highestFreq);
}


#if JUCE_IOS
void displayControlComponent::mouseDown(const MouseEvent& e)
{
	// Prepares our dragger to drag this Component
	dragger.startDraggingComponent(this, e);
}


void displayControlComponent::mouseDrag(const MouseEvent& e)
{
	// Moves this Component according to the mouse drag event and applies our constraints to it
	dragger.dragComponent(this, e, &constrainer);
}
#endif

void displayControlComponent::initAdaptiveNoSecondsComboBox(float timeSecundsPerFullAudioRecordBuffer)
{
	adaptiveNoSecondsComboBox->clear(NotificationType::dontSendNotification);
	auto noFullBuffersIncrmnts = (int)std::round((float)adaptiveMaxNoOfSecondsIncrements / timeSecundsPerFullAudioRecordBuffer);
	auto actNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs = getXmlTagDISPLAYCONTROL()->getIntAttribute("noOfFullAudioRecordBuffersInCalcs");

	auto noSeconds = 0.0f;
	auto lastDiff = std::numeric_limits<int>::max();
	auto noFullBuffersToselectFirst = std::numeric_limits<int>::min();
	auto noFullBuffers = 1;

	for (; noSeconds < adaptiveMaxNoOfSecondsAlways; noFullBuffers += noFullBuffersIncrmnts)
	{
		if (actNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs > 0)
		{
			if (lastDiff > abs(noFullBuffers - actNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs))
			{
				noFullBuffersToselectFirst = noFullBuffers;
				lastDiff = abs(noFullBuffers - actNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs);
			}
		}
		else
		{
			if (lastDiff > abs(noFullBuffers - initNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs))
			{
				noFullBuffersToselectFirst = noFullBuffers;
				lastDiff = abs(noFullBuffers - initNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs);
			}
		}
		noSeconds = timeSecundsPerFullAudioRecordBuffer * noFullBuffers;
		adaptiveNoSecondsComboBox->addItem(eksLongDoubleToString(noSeconds, 3), noFullBuffers);
	}

	pTuneComponent->setAdaptiveNoSecondsComboBoxReady(true);
	pTuneComponent->setNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs(noFullBuffersToselectFirst);
	adaptiveNoSecondsComboBox->setSelectedId(noFullBuffersToselectFirst, NotificationType::sendNotification);
	// Save in XML file
	getXmlTagDISPLAYCONTROL()->setAttribute("noOfFullAudioRecordBuffersInCalcs", noFullBuffersToselectFirst);
	pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
}

void displayControlComponent::updateAdaptiveNoSecondsComboBox(float timeSecundsPerFullAudioRecordBuffer)
{
	auto curNoSecsSelected = adaptiveNoSecondsComboBox->getItemText(adaptiveNoSecondsComboBox->getSelectedItemIndex()).getFloatValue();

	auto minValForItemDifFromCurNoSecsSelected = std::numeric_limits<float>::max();
	auto curValForItemDiffFromCurNoSecsSelected = std::numeric_limits<float>::max();
	auto nearestNoFullBuffers = 0;
	auto noSeconds = 0.0f;
	adaptiveNoSecondsComboBox->clear(NotificationType::dontSendNotification);
	auto noFullBuffersIncrmnts = (int)std::round((float)adaptiveMaxNoOfSecondsIncrements / timeSecundsPerFullAudioRecordBuffer);
	for (auto noFullBuffers = 1; noSeconds < adaptiveMaxNoOfSecondsAlways; noFullBuffers += noFullBuffersIncrmnts)
	{
		noSeconds = timeSecundsPerFullAudioRecordBuffer * (float)noFullBuffers;
		//find value nearest to the previous selected
		curValForItemDiffFromCurNoSecsSelected = abs(curNoSecsSelected - noSeconds);
		if (curValForItemDiffFromCurNoSecsSelected < minValForItemDifFromCurNoSecsSelected)
		{
			minValForItemDifFromCurNoSecsSelected = curValForItemDiffFromCurNoSecsSelected;
			nearestNoFullBuffers = noFullBuffers;
		}
		adaptiveNoSecondsComboBox->addItem(eksLongDoubleToString(noSeconds, 3), noFullBuffers);
	}
	adaptiveNoSecondsComboBox->setSelectedId(nearestNoFullBuffers, NotificationType::dontSendNotification);
	pTuneComponent->setNoOfFullAudioRecordBuffersPerStringInAdaptiveThresholdCalcs(nearestNoFullBuffers);
	// SAve in XML file
	getXmlTagDISPLAYCONTROL()->setAttribute("noOfFullAudioRecordBuffersInCalcs", nearestNoFullBuffers);
	pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
}

void displayControlComponent::updateNoSecondsSoundPerCalcComboBox(double secondsPerSampleAtDecimatedSampleRate)
{
	auto curNoSecsSelected = noSecondsSoundPerCalcComboBox->getItemText(noSecondsSoundPerCalcComboBox->getSelectedItemIndex()).getDoubleValue();
	auto testStr = eksLongDoubleToString(curNoSecsSelected, 3);

	auto minValForItemDifFromCurNoSecsSelected = std::numeric_limits<double>::max();
	auto curValForItemDiffFromCurNoSecsSelected = std::numeric_limits<double>::max();
	auto nearestFftOrder = 0;
	auto curValForItem = std::numeric_limits<double>::min();
	noSecondsSoundPerCalcComboBox->clear(NotificationType::dontSendNotification);
	auto fftOrder = 5;
	while (curValForItem < 5)
	{
		curValForItem = (double)(1 << fftOrder) * secondsPerSampleAtDecimatedSampleRate;
		if (curValForItem <= 5)
		{
			//find value nearest to the previous selected
			curValForItemDiffFromCurNoSecsSelected = abs(curNoSecsSelected - curValForItem);
			if (curValForItemDiffFromCurNoSecsSelected < minValForItemDifFromCurNoSecsSelected)
			{
				minValForItemDifFromCurNoSecsSelected = curValForItemDiffFromCurNoSecsSelected;
				nearestFftOrder = fftOrder;
			}
			// Round to 3 decimals
			noSecondsSoundPerCalcComboBox->addItem(eksLongDoubleToString(curValForItem, 3), fftOrder);

			fftOrder++;
		}
	}
	noSecondsSoundPerCalcComboBox->setSelectedId(nearestFftOrder, NotificationType::dontSendNotification);
	pTuneComponent->setFftOrder(nearestFftOrder);
	// SAve in XML file
	getXmlTagDISPLAYCONTROL()->setAttribute("fftOrder", nearestFftOrder);
	pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="displayControlComponent"
                 componentName="" parentClasses="public Component, public TextEditor::Listener"
                 constructorParams="std::weak_ptr&lt;tuneComponent&gt; pTC, std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTConfig, std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF, bool addVWP"
                 variableInitialisers="pGuitarFineTuneLookAndFeel(pGFTAF),&#10;pTuneComponent(*(pTC.lock())),&#10;pXmlGuitarFineTuneConfig(pXmlGFTConfig),&#10;viewPortAdded(addVWP)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="310" initialHeight="460">
  <BACKGROUND backgroundColour="ff20072b"/>
  <GROUPCOMPONENT name="freqRangeGroupComponent" id="c7362b1de29895de" memberName="freqRangeGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 298 320 136" outlinecol="ff0000ff"
                  textcol="ff6495ed" title="Frequency range"/>
  <GROUPCOMPONENT name="ShowGroupComponent" id="18d43abc3d561dfe" memberName="ShowGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 190 320 106" outlinecol="ff0000ff"
                  textcol="ff6495ed" title="Show"/>
  <GROUPCOMPONENT name="averageGroupComponent" id="4bdf41a03528b807" memberName="averageGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 100 320 88" outlinecol="ff0000ff"
                  textcol="ff6495ed" title="Average string tone calculations over"/>
  <GROUPCOMPONENT name="bgsoundExclusionGroupComponent" id="8eec11f568403dac" memberName="bgsoundExclusionGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 8 320 88" outlinecol="ff0000ff"
                  textcol="ff6495ed" title="Background sounds exclusion threshold  "/>
  <TOGGLEBUTTON name="showFFTToggleButton" id="cb98d24d22b69990" memberName="showFFTToggleButton"
                virtualName="" explicitFocusOrder="9" pos="119 233 55 25" posRelativeW="b04a3483c2e0c817"
                posRelativeH="b04a3483c2e0c817" txtcol="ff6495ed" buttonText="FFT"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="showSpectrumToggleButton" id="24bafc3c45723958" memberName="showSpectrumToggleButton"
                virtualName="" explicitFocusOrder="8" pos="10 233 94 25" posRelativeH="4a6c5c86fa6e2647"
                txtcol="ff6495ed" buttonText="Spectrum" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTEDITOR name="thresholdTextEditor" id="905ca99215f5a7e4" memberName="thresholdTextEditor"
              virtualName="" explicitFocusOrder="4" pos="10 27 102 24" textcol="ff6495ed"
              hilitecol="ff42a2c8" initialText="Latest Adapt." multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="showFilterToggleButton" id="c1cca4cabec6f71a" memberName="showFilterToggleButton"
                virtualName="" explicitFocusOrder="11" pos="183 260 78 25" posRelativeW="b04a3483c2e0c817"
                posRelativeH="b04a3483c2e0c817" txtcol="ff6495ed" buttonText="filter"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="noSecondsSoundPerCalcLabel" id="93bfaa7a5f0ee8a7" memberName="noSecondsSoundPerCalcLabel"
         virtualName="" explicitFocusOrder="0" pos="99 151 221 24" textCol="ff6495ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Seconds sound per calculation."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <COMBOBOX name="noSecondsSoundPerCalcComboBox" id="3a1c7b2b65d27412" memberName="noSecondsSoundPerCalcComboBox"
            virtualName="" explicitFocusOrder="5" pos="10 151 86 24" editable="0"
            layout="34" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="showIndicatorsToggleButton" id="4a6c5c86fa6e2647" memberName="showIndicatorsToggleButton"
                virtualName="" explicitFocusOrder="5" pos="10 206 133 25" txtcol="ff6495ed"
                buttonText="Indicators" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="showFFTMaxIndictrToggleButton" id="54ca7e47b12dc6a5" memberName="showFFTMaxIndictrToggleButton"
                virtualName="" explicitFocusOrder="10" pos="10 260 136 25" posRelativeW="4a6c5c86fa6e2647"
                posRelativeH="4a6c5c86fa6e2647" txtcol="ff6495ed" buttonText="FFT max indicator"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="stringsOffTuneValuesToggleButton" id="b04a3483c2e0c817"
                memberName="stringsOffTuneValuesToggleButton" virtualName=""
                explicitFocusOrder="7" pos="119 206 176 25" posRelativeW="4a6c5c86fa6e2647"
                posRelativeH="4a6c5c86fa6e2647" txtcol="ff6495ed" buttonText="strings off tune values (Hz)"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="autoCalibrateTextButton" id="26827b73008d69b2" memberName="autoCalibrateTextButton"
              virtualName="" explicitFocusOrder="0" pos="139 27 107 24" buttonText="Auto Calibrate"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="labelLowestFreq" id="fc7c1cdb478c5cb5" memberName="labelLowestFreq"
         virtualName="" explicitFocusOrder="0" pos="5 314 189 24" textCol="ff6495ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Low frequency (1..69)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="sliderLowestFreq" id="25333ca77d7b09" memberName="sliderLowestFreq"
          virtualName="" explicitFocusOrder="1" pos="66 338 55 24" textboxtext="ff6495ed"
          textboxhighlight="ff42a2c8" min="1.0" max="69.0" int="1.0" style="IncDecButtons"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="24" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="sliderHighestFreq" id="5ca110359f4557b5" memberName="sliderHighestFreq"
          virtualName="" explicitFocusOrder="2" pos="66 397 55 24" textboxtext="ff6495ed"
          textboxhighlight="ff42a2c8" min="343.0" max="441.0" int="1.0"
          style="IncDecButtons" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="56" textBoxHeight="24" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="labelHighstFreq" id="a714fd0d42648d8d" memberName="labelHighstFreq"
         virtualName="" explicitFocusOrder="0" pos="5 370 221 24" textCol="ff6495ed"
         edTextCol="ff000000" edBkgCol="0" labelText="High frequency (343 .. 441)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="calculationsLabel" id="e877877927d31f4d" memberName="calculationsLabel"
         virtualName="" explicitFocusOrder="0" pos="124 117 96 24" textCol="ff6495ed"
         edTextCol="ff000000" edBkgCol="0" labelText="calculations&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="averageSider" id="1c6bed300b598e74" memberName="averageSider"
          virtualName="" explicitFocusOrder="3" pos="66 117 55 24" textboxtext="ff6495ed"
          textboxhighlight="ff42a2c8" min="1.0" max="40.0" int="1.0" style="IncDecButtons"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="24" skewFactor="1.0" needsCallback="1"/>
  <TOGGLEBUTTON name="adaptiveToggleButton" id="4e7c0efdb6bdf721" memberName="adaptiveToggleButton"
                virtualName="" explicitFocusOrder="0" pos="10 61 83 24" txtcol="ff6495ed"
                buttonText="Adaptive" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <COMBOBOX name="adaptiveNoSecondsComboBox" id="6d39d632ca88b453" memberName="adaptiveNoSecondsComboBox"
            virtualName="" explicitFocusOrder="0" pos="100 61 86 24" editable="0"
            layout="34" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="adaptiveNoSecondsLabel" id="47157ea430b664a2" memberName="adaptiveNoSecondsLabel"
         virtualName="" explicitFocusOrder="0" pos="190 61 130 24" textCol="ff6495ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Seconds sound in calcs."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TOGGLEBUTTON name="thresholdToggleButton" id="70a70157313b9cd2" memberName="thresholdToggleButton"
                virtualName="" explicitFocusOrder="0" pos="183 233 112 25" txtcol="ff6495ed"
                buttonText="Threshold" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

