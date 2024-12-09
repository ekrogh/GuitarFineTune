/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "tuneComponent.h"
#include "SimpleLevelMeter.h"
#include "xmlGuitarFineTuneConfig.h"
//[/Headers]

#include "guitarStringSoundsControl.h"

#include <memory>
#include <utility>


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern std::unique_ptr<tuneComponent> pTuneComponent;
extern std::unique_ptr<AudioDeviceManager> sharedAudioDeviceManager;
//[/MiscUserDefs]

//==============================================================================
guitarStringSoundsControl::guitarStringSoundsControl(std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP)
	: pGuitarFineTuneLookAndFeel(std::move(pGFTAF)),
	spAudioRecorderController(pTuneComponent->getAudioRecorderController()),
	pXmlGuitarFineTuneConfig(std::move(pXmlGFTConfig)),
	viewPortAdded(addVWP)
{
	//[Constructor_pre] You can add your own custom stuff here..
	//[/Constructor_pre]

	PlayToneGroupComponent = std::make_unique<GroupComponent>("PlayToneGroupComponent",
		TRANS("Play tone for guitar string"));
	addAndMakeVisible(PlayToneGroupComponent.get());
	PlayToneGroupComponent->setColour(juce::GroupComponent::outlineColourId, juce::Colours::blue);
	PlayToneGroupComponent->setColour(juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

	PlayToneGroupComponent->setBounds(0, 8, 296, 80);

	outputMixGroupComponent = std::make_unique<juce::GroupComponent>("outputMixGroupComponent",
		TRANS("Output mix"));
	addAndMakeVisible(outputMixGroupComponent.get());
	outputMixGroupComponent->setColour(juce::GroupComponent::outlineColourId, juce::Colours::blue);
	outputMixGroupComponent->setColour(juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

	outputMixGroupComponent->setBounds(0, 89, 296, 176);

	E2soundToggleButton = std::make_unique<juce::ToggleButton>("E2soundToggleButton");
	addAndMakeVisible(E2soundToggleButton.get());
	E2soundToggleButton->setTooltip(TRANS("Play guitar string E2 sound"));
	E2soundToggleButton->setExplicitFocusOrder(1);
	E2soundToggleButton->setButtonText(juce::String());
	E2soundToggleButton->addListener(this);
	E2soundToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	E2soundToggleButton->setBounds(18, 52, 28, 24);

	A2soundToggleButton = std::make_unique<juce::ToggleButton>("A2soundToggleButton");
	addAndMakeVisible(A2soundToggleButton.get());
	A2soundToggleButton->setTooltip(TRANS("Play guitar string A2 sound"));
	A2soundToggleButton->setExplicitFocusOrder(2);
	A2soundToggleButton->setButtonText(juce::String());
	A2soundToggleButton->addListener(this);
	A2soundToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);

	A2soundToggleButton->setBounds(55, 52, 28, 24);

	D3soundToggleButton = std::make_unique<juce::ToggleButton>("D3soundToggleButton");
	addAndMakeVisible(D3soundToggleButton.get());
	D3soundToggleButton->setTooltip(TRANS("Play guitar string D3 sound"));
	D3soundToggleButton->setExplicitFocusOrder(3);
	D3soundToggleButton->setButtonText(juce::String());
	D3soundToggleButton->addListener(this);
	D3soundToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);

	D3soundToggleButton->setBounds(92, 52, 28, 24);

	G3soundToggleButton.reset(new juce::ToggleButton("G3soundToggleButton"));
	addAndMakeVisible(G3soundToggleButton.get());
	G3soundToggleButton->setTooltip(TRANS("Play guitar string G3 sound"));
	G3soundToggleButton->setExplicitFocusOrder(4);
	G3soundToggleButton->setButtonText(juce::String());
	G3soundToggleButton->addListener(this);
	G3soundToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);

	G3soundToggleButton->setBounds(129, 52, 28, 24);

	B3soundToggleButton.reset(new juce::ToggleButton("B3soundToggleButton"));
	addAndMakeVisible(B3soundToggleButton.get());
	B3soundToggleButton->setTooltip(TRANS("Play guitar string B3 sound"));
	B3soundToggleButton->setExplicitFocusOrder(5);
	B3soundToggleButton->setButtonText(juce::String());
	B3soundToggleButton->setConnectedEdges(juce::Button::ConnectedOnRight);
	B3soundToggleButton->addListener(this);
	B3soundToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);

	B3soundToggleButton->setBounds(166, 52, 28, 24);

	E4soundToggleButton.reset(new juce::ToggleButton("E4soundToggleButton"));
	addAndMakeVisible(E4soundToggleButton.get());
	E4soundToggleButton->setTooltip(TRANS("Play guitar string E4 sound"));
	E4soundToggleButton->setExplicitFocusOrder(6);
	E4soundToggleButton->setButtonText(juce::String());
	E4soundToggleButton->addListener(this);
	E4soundToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);

	E4soundToggleButton->setBounds(203, 52, 28, 24);

	stringSlider.reset(new juce::Slider("stringSlider"));
	addAndMakeVisible(stringSlider.get());
	stringSlider->setTooltip(TRANS("Guitar strings sound level"));
	stringSlider->setExplicitFocusOrder(7);
	stringSlider->setRange(0, 1, 0.1);
	stringSlider->setSliderStyle(juce::Slider::LinearVertical);
	stringSlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 80, 20);
	stringSlider->setColour(juce::Slider::backgroundColourId, juce::Colours::grey);
	stringSlider->setColour(juce::Slider::trackColourId, juce::Colours::grey);
	stringSlider->setColour(juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
	stringSlider->addListener(this);

	stringSlider->setBounds(20, 159, 48, 67);

	inputSlider.reset(new juce::Slider("inputSlider"));
	addAndMakeVisible(inputSlider.get());
	inputSlider->setTooltip(TRANS("Input sound level."));
	inputSlider->setExplicitFocusOrder(8);
	inputSlider->setRange(0, 1, 0.1);
	inputSlider->setSliderStyle(juce::Slider::LinearVertical);
	inputSlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 80, 20);
	inputSlider->setColour(juce::Slider::backgroundColourId, juce::Colours::grey);
	inputSlider->setColour(juce::Slider::trackColourId, juce::Colours::grey);
	inputSlider->setColour(juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
	inputSlider->addListener(this);

	inputSlider->setBounds(122, 159, 48, 67);

	stringsVolLabel.reset(new juce::Label("stringsVolLabel",
		TRANS("Strings")));
	addAndMakeVisible(stringsVolLabel.get());
	stringsVolLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	stringsVolLabel->setJustificationType(juce::Justification::centred);
	stringsVolLabel->setEditable(false, false, false);
	stringsVolLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	stringsVolLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	stringsVolLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	stringsVolLabel->setBounds(17, 111, 54, 26);

	inputVolLabel.reset(new juce::Label("inputVolLabel",
		TRANS("Input")));
	addAndMakeVisible(inputVolLabel.get());
	inputVolLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	inputVolLabel->setJustificationType(juce::Justification::centred);
	inputVolLabel->setEditable(false, false, false);
	inputVolLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	inputVolLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	inputVolLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	inputVolLabel->setBounds(116, 111, 59, 24);

	inputMuteToggleButton.reset(new juce::ToggleButton("inputMuteToggleButton"));
	addAndMakeVisible(inputMuteToggleButton.get());
	inputMuteToggleButton->setTooltip(TRANS("Mute input"));
	inputMuteToggleButton->setExplicitFocusOrder(9);
	inputMuteToggleButton->setButtonText(TRANS("Mute"));
	inputMuteToggleButton->addListener(this);
	inputMuteToggleButton->setToggleState(true, dontSendNotification);
	inputMuteToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	inputMuteToggleButton->setBounds(116, 226, 60, 24);

	stringsMuteToggleButton.reset(new juce::ToggleButton("stringsMuteToggleButton"));
	addAndMakeVisible(stringsMuteToggleButton.get());
	stringsMuteToggleButton->setTooltip(TRANS("Mute input"));
	stringsMuteToggleButton->setExplicitFocusOrder(9);
	stringsMuteToggleButton->setButtonText(TRANS("Mute"));
	stringsMuteToggleButton->addListener(this);
	stringsMuteToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	stringsMuteToggleButton->setBounds(16, 226, 60, 24);

	outputVolLabel.reset(new juce::Label("outputVolLabel",
		TRANS("Output")));
	addAndMakeVisible(outputVolLabel.get());
	outputVolLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	outputVolLabel->setJustificationType(juce::Justification::centred);
	outputVolLabel->setEditable(false, false, false);
	outputVolLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	outputVolLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	outputVolLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	outputVolLabel->setBounds(214, 111, 64, 24);

	outputSlider.reset(new juce::Slider("outputSlider"));
	addAndMakeVisible(outputSlider.get());
	outputSlider->setTooltip(TRANS("Output sound level."));
	outputSlider->setExplicitFocusOrder(10);
	outputSlider->setRange(0, 1, 0.1);
	outputSlider->setSliderStyle(juce::Slider::LinearVertical);
	outputSlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 80, 20);
	outputSlider->setColour(juce::Slider::backgroundColourId, juce::Colours::grey);
	outputSlider->setColour(juce::Slider::trackColourId, juce::Colours::grey);
	outputSlider->setColour(juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
	outputSlider->addListener(this);

	outputSlider->setBounds(222, 159, 48, 67);

	outputMuteToggleButton.reset(new juce::ToggleButton("outputMuteToggleButton"));
	addAndMakeVisible(outputMuteToggleButton.get());
	outputMuteToggleButton->setTooltip(TRANS("Mute output"));
	outputMuteToggleButton->setExplicitFocusOrder(11);
	outputMuteToggleButton->setButtonText(TRANS("Mute"));
	outputMuteToggleButton->addListener(this);
	outputMuteToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	outputMuteToggleButton->setBounds(216, 226, 60, 24);

	E2label.reset(new juce::Label("E2label",
		TRANS("E2")));
	addAndMakeVisible(E2label.get());
	E2label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	E2label->setJustificationType(juce::Justification::centred);
	E2label->setEditable(false, false, false);
	E2label->setColour(Label::textColourId, Colours::cornflowerblue);
	E2label->setColour(TextEditor::textColourId, Colours::black);
	E2label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	E2label->setBounds(14, 29, 28, 16);

	A2label.reset(new juce::Label("A2label",
		TRANS("A2")));
	addAndMakeVisible(A2label.get());
	A2label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	A2label->setJustificationType(juce::Justification::centred);
	A2label->setEditable(false, false, false);
	A2label->setColour(Label::textColourId, Colours::cornflowerblue);
	A2label->setColour(TextEditor::textColourId, Colours::black);
	A2label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	A2label->setBounds(51, 29, 28, 16);

	D3label.reset(new juce::Label("D3label",
		TRANS("D3")));
	addAndMakeVisible(D3label.get());
	D3label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	D3label->setJustificationType(juce::Justification::centred);
	D3label->setEditable(false, false, false);
	D3label->setColour(Label::textColourId, Colours::cornflowerblue);
	D3label->setColour(TextEditor::textColourId, Colours::black);
	D3label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	D3label->setBounds(88, 29, 28, 16);

	G3label.reset(new juce::Label("G3label",
		TRANS("G3")));
	addAndMakeVisible(G3label.get());
	G3label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	G3label->setJustificationType(juce::Justification::centred);
	G3label->setEditable(false, false, false);
	G3label->setColour(Label::textColourId, Colours::cornflowerblue);
	G3label->setColour(TextEditor::textColourId, Colours::black);
	G3label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	G3label->setBounds(125, 29, 28, 16);

	B3label.reset(new juce::Label("B3label",
		TRANS("B3")));
	addAndMakeVisible(B3label.get());
	B3label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	B3label->setJustificationType(juce::Justification::centred);
	B3label->setEditable(false, false, false);
	B3label->setColour(Label::textColourId, Colours::cornflowerblue);
	B3label->setColour(TextEditor::textColourId, Colours::black);
	B3label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	B3label->setBounds(162, 29, 28, 16);

	E4label.reset(new juce::Label("E4label",
		TRANS("E4")));
	addAndMakeVisible(E4label.get());
	E4label->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	E4label->setJustificationType(juce::Justification::centred);
	E4label->setEditable(false, false, false);
	E4label->setColour(Label::textColourId, Colours::cornflowerblue);
	E4label->setColour(TextEditor::textColourId, Colours::black);
	E4label->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	E4label->setBounds(199, 29, 28, 16);

	recordGroupComponent.reset(new juce::GroupComponent("recordGroupComponent",
		TRANS("Record")));
	addAndMakeVisible(recordGroupComponent.get());
	recordGroupComponent->setTextLabelPosition(juce::Justification::centredLeft);
	recordGroupComponent->setColour(juce::GroupComponent::outlineColourId, juce::Colours::blue);
	recordGroupComponent->setColour(juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

	recordGroupComponent->setBounds(0, 266, 296, 78);

	sourceRawToggleButton.reset(new juce::ToggleButton("sourceRawToggleButton"));
	addAndMakeVisible(sourceRawToggleButton.get());
	sourceRawToggleButton->setExplicitFocusOrder(12);
	sourceRawToggleButton->setButtonText(juce::String());
	sourceRawToggleButton->setRadioGroupId(1);
	sourceRawToggleButton->addListener(this);
	sourceRawToggleButton->setToggleState(true, dontSendNotification);
	sourceRawToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	sourceFilteredToggleButton.reset(new juce::ToggleButton("sourceFilteredToggleButton"));
	addAndMakeVisible(sourceFilteredToggleButton.get());
	sourceFilteredToggleButton->setExplicitFocusOrder(13);
	sourceFilteredToggleButton->setButtonText(juce::String());
	sourceFilteredToggleButton->setRadioGroupId(1);
	sourceFilteredToggleButton->addListener(this);
	sourceFilteredToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	stopRecordingToggleButton.reset(new juce::ToggleButton("stopRecordingToggleButton"));
	addAndMakeVisible(stopRecordingToggleButton.get());
	stopRecordingToggleButton->setExplicitFocusOrder(15);
	stopRecordingToggleButton->setButtonText(juce::String());
	stopRecordingToggleButton->setRadioGroupId(2);
	stopRecordingToggleButton->addListener(this);
	stopRecordingToggleButton->setToggleState(true, dontSendNotification);
	stopRecordingToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	rawSoundLabellabel.reset(new juce::Label("rawSoundLabellabel",
		TRANS("Raw sound\n")));
	addAndMakeVisible(rawSoundLabellabel.get());
	rawSoundLabellabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	rawSoundLabellabel->setJustificationType(juce::Justification::centred);
	rawSoundLabellabel->setEditable(false, false, false);
	rawSoundLabellabel->setColour(Label::textColourId, Colours::cornflowerblue);
	rawSoundLabellabel->setColour(TextEditor::textColourId, Colours::black);
	rawSoundLabellabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	rawSoundLabellabel->setBounds(10, 280, 85, 24);

	FilteredSoundLabel.reset(new juce::Label("FilteredSoundLabel",
		TRANS("Filtered sound\n")));
	addAndMakeVisible(FilteredSoundLabel.get());
	FilteredSoundLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	FilteredSoundLabel->setJustificationType(juce::Justification::centred);
	FilteredSoundLabel->setEditable(false, false, false);
	FilteredSoundLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	FilteredSoundLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	FilteredSoundLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	FilteredSoundLabel->setBounds(94, 280, 104, 24);

	stopLabel.reset(new juce::Label("stopLabel",
		TRANS("Stop")));
	addAndMakeVisible(stopLabel.get());
	stopLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	stopLabel->setJustificationType(juce::Justification::centred);
	stopLabel->setEditable(false, false, false);
	stopLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	stopLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	stopLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	stopLabel->setBounds(246, 280, 48, 24);

	recordLevelGroupComponent.reset(new juce::GroupComponent("recordLevelGroupComponent",
		TRANS("Recording level")));
	addAndMakeVisible(recordLevelGroupComponent.get());
	recordLevelGroupComponent->setColour(juce::GroupComponent::outlineColourId, juce::Colours::blue);
	recordLevelGroupComponent->setColour(juce::GroupComponent::textColourId, juce::Colours::cornflowerblue);

	recordLevelGroupComponent->setBounds(0, 345, 296, 86);

	recordingLevelSlider.reset(new juce::Slider("recordingLevelSlider"));
	addAndMakeVisible(recordingLevelSlider.get());
	recordingLevelSlider->setTooltip(TRANS("Recording sound gain. 0.00 = Auto Gain."));
	recordingLevelSlider->setExplicitFocusOrder(16);
	recordingLevelSlider->setRange(0, 500, 0.01);
	recordingLevelSlider->setSliderStyle(juce::Slider::LinearHorizontal);
	recordingLevelSlider->setTextBoxStyle(juce::Slider::NoTextBox, false, 50, 20);
	recordingLevelSlider->setColour(juce::Slider::backgroundColourId, juce::Colours::grey);
	recordingLevelSlider->setColour(juce::Slider::trackColourId, juce::Colour(0xff42a2c8));
	recordingLevelSlider->setColour(juce::Slider::textBoxTextColourId, juce::Colours::cornflowerblue);
	recordingLevelSlider->addListener(this);

	recordingLevelSlider->setBounds(58, 390, 165, 32);

	startRecordingToggleButton.reset(new juce::ToggleButton("startRecordingToggleButton"));
	addAndMakeVisible(startRecordingToggleButton.get());
	startRecordingToggleButton->setExplicitFocusOrder(14);
	startRecordingToggleButton->setButtonText(juce::String());
	startRecordingToggleButton->setRadioGroupId(2);
	startRecordingToggleButton->addListener(this);
	startRecordingToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	startLabel.reset(new juce::Label("startLabel",
		TRANS("Start")));
	addAndMakeVisible(startLabel.get());
	startLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	startLabel->setJustificationType(juce::Justification::centred);
	startLabel->setEditable(false, false, false);
	startLabel->setColour(juce::Label::textColourId, juce::Colours::cornflowerblue);
	startLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	startLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	startLabel->setBounds(197, 280, 48, 24);

	guitarStringTonesOffToggleButton.reset(new juce::ToggleButton("guitarStringTonesOffToggleButton"));
	addAndMakeVisible(guitarStringTonesOffToggleButton.get());
	guitarStringTonesOffToggleButton->setButtonText(juce::String());
	guitarStringTonesOffToggleButton->setConnectedEdges(juce::Button::ConnectedOnLeft);
	guitarStringTonesOffToggleButton->addListener(this);
	guitarStringTonesOffToggleButton->setToggleState(true, dontSendNotification);

	guitarStringTonesOffToggleButton->setBounds(253, 52, 28, 24);

	allOffLabel.reset(new Label("allOffLabel",
		TRANS("All off")));
	addAndMakeVisible(allOffLabel.get());
	allOffLabel->setFont(juce::Font(FontOptions(15.00f).withStyle("Regular")));
	allOffLabel->setJustificationType(juce::Justification::centred);
	allOffLabel->setEditable(false, false, false);
	allOffLabel->setColour(Label::textColourId, Colours::cornflowerblue);
	allOffLabel->setColour(TextEditor::textColourId, Colours::black);
	allOffLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	allOffLabel->setBounds(234, 29, 56, 16);

	autoGainToggleButton.reset(new juce::ToggleButton("autoGainToggleButton"));
	addAndMakeVisible(autoGainToggleButton.get());
	autoGainToggleButton->setButtonText(TRANS("Auto"));
	autoGainToggleButton->addListener(this);
	autoGainToggleButton->setToggleState(true, dontSendNotification);
	autoGainToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	autoGainToggleButton->setBounds(231, 394, 60, 24);


	//[UserPreSize]
	stringSliderLabel.reset(getLookAndFeel().createSliderTextBox(*stringSlider));
	addAndMakeVisible(stringSliderLabel.get());
	stringSliderLabel->setBounds(20, 139, 48, 20);
	stringSliderLabel->setEditable(true, true, false);
	stringSliderLabel->setVisible(true);
	stringSliderLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);
	stringSliderLabel->addListener(this);

	inputSliderLabel.reset(getLookAndFeel().createSliderTextBox(*inputSlider));
	addAndMakeVisible(inputSliderLabel.get());
	inputSliderLabel->setBounds(122, 139, 48, 20);
	inputSliderLabel->setEditable(true, true, false);
	inputSliderLabel->setVisible(true);
	inputSliderLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);
	inputSliderLabel->addListener(this);

	outputSliderLabel.reset(getLookAndFeel().createSliderTextBox(*outputSlider));
	addAndMakeVisible(outputSliderLabel.get());
	outputSliderLabel->setBounds(222, 139, 48, 20);
	outputSliderLabel->setEditable(true, true, false);
	outputSliderLabel->setVisible(true);
	outputSliderLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);
	outputSliderLabel->addListener(this);

	recordingLevelSlider->setSkewFactorFromMidPoint(10.0f);
	recordingLevelSliderLabel.reset(getLookAndFeel().createSliderTextBox(*recordingLevelSlider));
	recordingLevelSliderLabel->setBounds(8, 396, 50, 20);
	addAndMakeVisible(recordingLevelSliderLabel.get());
	recordingLevelSliderLabel->setEditable(true, true, false);
	recordingLevelSliderLabel->setVisible(true);
	recordingLevelSliderLabel->setKeyboardType(TextInputTarget::VirtualKeyboardType::decimalKeyboard);
	recordingLevelSliderLabel->addListener(this);
	RecordingLevelMeter = std::make_shared<SimpleLevelMeter>(spAudioRecorderController);
	spAudioRecorderController->setPtrRecordingLevelMeter(RecordingLevelMeter);
	addAndMakeVisible(RecordingLevelMeter.get());
	//[/UserPreSize]

	setSize(552, 274);


	//[Constructor] You can add your own custom stuff here..
	//stringSlider->setValue(1, NotificationType::sendNotification);
	//stringSliderLabel->setText(eksLongDoubleToString(1.0f, 2), NotificationType::dontSendNotification);
	//inputSlider->setValue(0, NotificationType::sendNotification);
	//inputSliderLabel->setText(eksLongDoubleToString(0.0f, 2), NotificationType::dontSendNotification);
	//outputSlider->setValue(1, NotificationType::sendNotification);
	//outputSliderLabel->setText(eksLongDoubleToString(1.0f, 2), NotificationType::dontSendNotification);

	pTuneComponent->initPGuitarStringSoundsControl(this);
	// Set audio recorder gain to auto
	recordingLevelSlider->setValue(0.0f, NotificationType::dontSendNotification);
	// Set audio recorder source to raw
	pTuneComponent->setRecorderSourceRaw();
	// Init controls
	initControls();
	//[/Constructor]
}

guitarStringSoundsControl::~guitarStringSoundsControl()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	if (RecordingLevelMeter)
	{
		RecordingLevelMeter = nullptr;
		RecordingLevelMeter.reset();
	}
	if (spAudioRecorderController)
	{
		spAudioRecorderController = nullptr;
		spAudioRecorderController.reset();
	}
	//pGuitarFineTuneLookAndFeel.reset();
	//pGuitarFineTuneLookAndFeel = nullptr;
	//[/Destructor_pre]

	PlayToneGroupComponent = nullptr;
	outputMixGroupComponent = nullptr;
	E2soundToggleButton = nullptr;
	A2soundToggleButton = nullptr;
	D3soundToggleButton = nullptr;
	G3soundToggleButton = nullptr;
	B3soundToggleButton = nullptr;
	E4soundToggleButton = nullptr;
	stringSlider = nullptr;
	inputSlider = nullptr;
	stringsVolLabel = nullptr;
	inputVolLabel = nullptr;
	inputMuteToggleButton = nullptr;
	stringsMuteToggleButton = nullptr;
	outputVolLabel = nullptr;
	outputSlider = nullptr;
	outputMuteToggleButton = nullptr;
	E2label = nullptr;
	A2label = nullptr;
	D3label = nullptr;
	G3label = nullptr;
	B3label = nullptr;
	E4label = nullptr;
	recordGroupComponent = nullptr;
	sourceRawToggleButton = nullptr;
	sourceFilteredToggleButton = nullptr;
	stopRecordingToggleButton = nullptr;
	rawSoundLabellabel = nullptr;
	FilteredSoundLabel = nullptr;
	stopLabel = nullptr;
	recordLevelGroupComponent = nullptr;
	recordingLevelSlider = nullptr;
	startRecordingToggleButton = nullptr;
	startLabel = nullptr;
	guitarStringTonesOffToggleButton = nullptr;
	allOffLabel = nullptr;
	autoGainToggleButton = nullptr;


	//[Destructor]. You can add your own custom destruction code here..
	//sharedAudioDeviceManager = nullptr;
	//[/Destructor]
}

//==============================================================================
void guitarStringSoundsControl::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff2b0720));

	//[UserPaint] Add your own custom painting code here..
	g.fillAll(Colour(0xff20072b));
	//[/UserPaint]
}

void guitarStringSoundsControl::resized()
{
	//[UserPreResize] Add your own custom resize code here..
#if (JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX || JUCE_ANDROID)
#if JUCE_ANDROID
	if (viewPortAdded)
	{
#endif // JUCE_ANDROID

		//[/UserPreResize]

		sourceRawToggleButton->setBounds(46 - (24 / 2), 304, 24, 24);
		sourceFilteredToggleButton->setBounds(141 - (24 / 2), 304, 24, 24);
		stopRecordingToggleButton->setBounds(268 - (24 / 2), 304, 24, 24);
		rawSoundLabellabel->setBounds(10, 280, 85, 24);
		startRecordingToggleButton->setBounds(220 - (24 / 2), 304, 24, 24);
		//[UserResized] Add your own custom resize handling here..
		auto  curUserArea = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
		if (curUserArea.getWidth() >= curUserArea.getHeight())
		{
			// Horizontal
			setSize(widthOfGuitarStringSoundsControlWindowHorizontal,
				hightOfGuitarStringSoundsControlWindowHorizontal);
			recordGroupComponent->setBounds(296, 90, 120, 176);
			rawSoundLabellabel->setBounds(302, 104, roundToInt(104 * 1.0000f), 24);
			sourceRawToggleButton->setBounds(354 - (24 / 2), 128, 24, 24);
			FilteredSoundLabel->setBounds(302, 150, 108, 24);
			sourceFilteredToggleButton->setBounds(354 - (24 / 2), 174, 24, 24);
			startLabel->setBounds(303, 200, 48, 24);
			startRecordingToggleButton->setBounds(328 - (24 / 2), 224, 24, 24);
			stopLabel->setBounds(356, 200, 48, 24);
			stopRecordingToggleButton->setBounds(380 - (24 / 2), 224, 24, 24);
			recordLevelGroupComponent->setBounds(417, 90, 135, 176);
			RecordingLevelMeter->setBounds(439, 104, 24, 155);
			recordingLevelSliderLabel->setBounds(492 - 2, 106, 50, 20);
			recordingLevelSlider->setSliderStyle(Slider::LinearVertical);
			recordingLevelSlider->setBounds(490 - 2, 106 + 20, 55, 161 - 20 - 24 - 5);
			autoGainToggleButton->setBounds(486 - 1, 237, 60, 24);
		}
		else
		{
			//Vertical
			setSize(widthOfGuitarStringSoundsControlWindowVertical,
				hightOfGuitarStringSoundsControlWindowVertical);
			recordGroupComponent->setBounds(0, 266, 296, 78);
			rawSoundLabellabel->setBounds(16, 280, 85, 24);
			sourceRawToggleButton->setBounds(46 - (24 / 2), 304, 24, 24);
			FilteredSoundLabel->setBounds(101, 280, 104, 24);
			sourceFilteredToggleButton->setBounds(141 - (24 / 2), 304, 24, 24);
			startLabel->setBounds(208, 280, 48, 24);
			startRecordingToggleButton->setBounds(220 - (24 / 2), 304, 24, 24);
			stopLabel->setBounds(256, 280, 48, 24);
			stopRecordingToggleButton->setBounds(268 - (24 / 2), 304, 24, 24);
			recordLevelGroupComponent->setBounds(0, 345, 296, 86);
			RecordingLevelMeter->setBounds(8, 365, 280, 24);
			recordingLevelSliderLabel->setBounds(8, 399, 50, 20);
			recordingLevelSlider->setSliderStyle(Slider::LinearHorizontal);
			recordingLevelSlider->setBounds(8 + 50, 393, 215 - 50, 32);
			autoGainToggleButton->setBounds(231, 397, 60, 24);
		}
#if JUCE_ANDROID
	}
#endif // JUCE_ANDROID
#endif // (JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX || JUCE_ANDROID)
	//[/UserResized]
}

void guitarStringSoundsControl::buttonClicked(juce::Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	static bool recorderSourceRawAudioOn = true;
	static bool recorderSourceFilteredAudioOn = false;
	static bool recorderIsRecording = false;
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == E2soundToggleButton.get())
	{
		//[UserButtonCode_E2soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::E2idx] = E2soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::E2idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_E2soundToggleButton]
	}
	else if (buttonThatWasClicked == A2soundToggleButton.get())
	{
		//[UserButtonCode_A2soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::A2idx] = A2soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::A2idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_A2soundToggleButton]
	}
	else if (buttonThatWasClicked == D3soundToggleButton.get())
	{
		//[UserButtonCode_D3soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::D3idx] = D3soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::D3idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_D3soundToggleButton]
	}
	else if (buttonThatWasClicked == G3soundToggleButton.get())
	{
		//[UserButtonCode_G3soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::G3idx] = G3soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::G3idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_G3soundToggleButton]
	}
	else if (buttonThatWasClicked == B3soundToggleButton.get())
	{
		//[UserButtonCode_B3soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::B3idx] = B3soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::B3idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_B3soundToggleButton]
	}
	else if (buttonThatWasClicked == E4soundToggleButton.get())
	{
		//[UserButtonCode_E4soundToggleButton] -- add your button handler code here..
		guitarStringSoundsOn[tuneComponent::E4idx] = E4soundToggleButton->getToggleState();
		if (guitarStringSoundsOn[tuneComponent::E4idx])
		{
			guitarStringTonesOffToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
		}
		else
		{
			if (!std::any_of(guitarStringSoundsOn.begin(), guitarStringSoundsOn.end(), [](bool i) { return i; }))
			{
				guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::sendNotification);
			}
			else
			{
				pTuneComponent->controlGuitarStringSounds(guitarStringSoundsOn);
			}
		}
		//[/UserButtonCode_E4soundToggleButton]
	}
	else if (buttonThatWasClicked == inputMuteToggleButton.get())
	{
		//[UserButtonCode_inputMuteToggleButton] -- add your button handler code here..
		inputMuteToggleButtonOn = inputMuteToggleButton->getToggleState();
		pTuneComponent->setInputMuteToggleButtonOnFlag(inputMuteToggleButtonOn);
		if (!inputMuteToggleButtonOn)
		{
			pTuneComponent->setInputGain((float)(inputSlider->getValue()));
			//pTuneComponent->setInputGain((float)(juce::Decibels::decibelsToGain(inputSlider->getValue())));
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("muteInput", inputMuteToggleButtonOn);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_inputMuteToggleButton]
	}
	else if (buttonThatWasClicked == stringsMuteToggleButton.get())
	{
		//[UserButtonCode_stringsMuteToggleButton] -- add your button handler code here..
		stringsMuteToggleButtonOn = stringsMuteToggleButton->getToggleState();
		pTuneComponent->setStringsMuteToggleButtonOnFlag(stringsMuteToggleButtonOn);
		if (!stringsMuteToggleButtonOn)
		{
			pTuneComponent->setStringsGain((float)(stringSlider->getValue()));
			//pTuneComponent->setStringsGain((float)(juce::Decibels::decibelsToGain(stringSlider->getValue())));
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("muteStrings", stringsMuteToggleButtonOn);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_stringsMuteToggleButton]
	}
	else if (buttonThatWasClicked == outputMuteToggleButton.get())
	{
		//[UserButtonCode_outputMuteToggleButton] -- add your button handler code here..
		outputMuteToggleButtonOn = outputMuteToggleButton->getToggleState();
		pTuneComponent->setOutputMuteToggleButtonOnFlag(outputMuteToggleButtonOn);
		if (!outputMuteToggleButtonOn)
		{
			pTuneComponent->setOutputGain((float)(outputSlider->getValue()));
			//pTuneComponent->setOutputGain((float)(juce::Decibels::decibelsToGain(outputSlider->getValue())));
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("muteOutput", outputMuteToggleButtonOn);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_outputMuteToggleButton]
	}
	else if (buttonThatWasClicked == sourceRawToggleButton.get())
	{
		//[UserButtonCode_sourceRawToggleButton] -- add your button handler code here..
		if (!recorderSourceRawAudioOn && (sourceRawToggleButton->getToggleState()))
		{
			if (recorderIsRecording)
			{
				stopRecordingToggleButton->setToggleState(true, juce::NotificationType::dontSendNotification);
				startRecordingToggleButton->setToggleState(false, juce::NotificationType::dontSendNotification);
				spAudioRecorderController->stopAudioRecorderRecording();
				recorderIsRecording = false;
			}
			pTuneComponent->setRecorderSourceRaw();
			recorderSourceRawAudioOn = true;
			recorderSourceFilteredAudioOn = false;
		}
		//[/UserButtonCode_sourceRawToggleButton]
	}
	else if (buttonThatWasClicked == sourceFilteredToggleButton.get())
	{
		//[UserButtonCode_sourceFilteredToggleButton] -- add your button handler code here..
		if (!recorderSourceFilteredAudioOn && (sourceFilteredToggleButton->getToggleState()))
		{
			if (recorderIsRecording)
			{
				stopRecordingToggleButton->setToggleState(true, juce::NotificationType::dontSendNotification);
				startRecordingToggleButton->setToggleState(false, juce::NotificationType::dontSendNotification);
				spAudioRecorderController->stopAudioRecorderRecording();
				recorderIsRecording = false;
			}
			pTuneComponent->setRecorderSourceFiltered();
			recorderSourceFilteredAudioOn = true;
			recorderSourceRawAudioOn = false;
		}

		//[/UserButtonCode_sourceFilteredToggleButton]
	}
	else if (buttonThatWasClicked == stopRecordingToggleButton.get())
	{
		//[UserButtonCode_stopRecordingToggleButton] -- add your button handler code here..
		if (recorderIsRecording && (stopRecordingToggleButton->getToggleState()))
		{
			spAudioRecorderController->stopAudioRecorderRecording();
			recorderIsRecording = false;
		}
		//[/UserButtonCode_stopRecordingToggleButton]
	}
	else if (buttonThatWasClicked == startRecordingToggleButton.get())
	{
		//[UserButtonCode_startRecordingToggleButton] -- add your button handler code here..
		if (!recorderIsRecording && (startRecordingToggleButton->getToggleState()))
		{
			spAudioRecorderController->startAudioRecorderRecording();
			recorderIsRecording = true;
		}
		//[/UserButtonCode_startRecordingToggleButton]
	}
	else if (buttonThatWasClicked == guitarStringTonesOffToggleButton.get())
	{
		//[UserButtonCode_guitarStringTonesOffToggleButton] -- add your button handler code here..
		if (guitarStringTonesOffToggleButton->getToggleState())
		{
			pTuneComponent->allGuitarStringSoundsOff(); // ramp down all string sounds and set flags etc.
			E2soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			A2soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			D3soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			G3soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			B3soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			E4soundToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			guitarStringSoundsOn.assign(6, false); // No guitar String Sounds On

		}
		else
		{
			guitarStringTonesOffToggleButton->setToggleState(true, NotificationType::dontSendNotification);
		}
		//[/UserButtonCode_guitarStringTonesOffToggleButton]
	}
	else if (buttonThatWasClicked == autoGainToggleButton.get())
	{
		//[UserButtonCode_autoGainToggleButton] -- add your button handler code here..
		auto newGainIsZero = true;
		if (autoGainToggleButton->getToggleState())
		{
			spAudioRecorderController->setRecordingGain(0.0f);
			recordingLevelSlider->setValue(0.0f, NotificationType::dontSendNotification);
			getXmlTagSOUNDCONTROL()->setAttribute("autoGain", true);
			getXmlTagSOUNDCONTROL()->setAttribute("recordingGain", 0.0f);
		}
		else
		{
			spAudioRecorderController->setAutoGainOn(false);
			auto curRecGain = spAudioRecorderController->getCurrentRecordingGain();
			recordingLevelSlider->setValue(curRecGain, NotificationType::dontSendNotification);
			newGainIsZero = false;
			getXmlTagSOUNDCONTROL()->setAttribute("autoGain", false);
			getXmlTagSOUNDCONTROL()->setAttribute("recordingGain", curRecGain);
		}
		oldRecordGainWasZero = newGainIsZero;
		setRecordLevelSlider(newGainIsZero);
		// SAve in XML file
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_autoGainToggleButton]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}

void guitarStringSoundsControl::sliderValueChanged(juce::Slider* sliderThatWasMoved)
{
	//[UsersliderValueChanged_Pre]
	//[/UsersliderValueChanged_Pre]

	if (sliderThatWasMoved == stringSlider.get())
	{
		//[UserSliderCode_stringSlider] -- add your slider handling code here..
		auto newGain = stringSlider->getValue();
		stringSliderLabel->setText(eksLongDoubleToString(newGain, 2), NotificationType::dontSendNotification);
		if (!stringsMuteToggleButtonOn)
		{
			pTuneComponent->setStringsGain((float)newGain);
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("stringGain", newGain);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserSliderCode_stringSlider]
	}
	else if (sliderThatWasMoved == inputSlider.get())
	{
		//[UserSliderCode_inputSlider] -- add your slider handling code here..
		auto newGain = inputSlider->getValue();
		inputSliderLabel->setText(eksLongDoubleToString(newGain, 2), NotificationType::dontSendNotification);
		if (!inputMuteToggleButtonOn)
		{
			pTuneComponent->setInputGain((float)newGain);
			//pTuneComponent->setInputGain((float)(juce::Decibels::decibelsToGain(inputSlider->getValue())));
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("inputGain", newGain);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserSliderCode_inputSlider]
	}
	else if (sliderThatWasMoved == outputSlider.get())
	{
		//[UserSliderCode_outputSlider] -- add your slider handling code here..
		auto newGain = outputSlider->getValue();
		outputSliderLabel->setText(eksLongDoubleToString(newGain, 2), NotificationType::dontSendNotification);
		if (!outputMuteToggleButtonOn)
		{
			pTuneComponent->setOutputGain((float)newGain);
			//pTuneComponent->setOutputGain((float)(juce::Decibels::decibelsToGain(outputSlider->getValue())));
		}
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("outputGain", newGain);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserSliderCode_outputSlider]
	}
	else if (sliderThatWasMoved == recordingLevelSlider.get())
	{
		//[UserSliderCode_recordingLevelSlider] -- add your slider handling code here..
		auto newGain = (float)(recordingLevelSlider->getValue());

		spAudioRecorderController->setRecordingGain(newGain);

		auto newGainIsZero = (newGain == 0);

		if (newGainIsZero != oldRecordGainWasZero)
		{
			// Changed to/from 0.00f
			autoGainToggleButton->setToggleState(newGainIsZero, NotificationType::dontSendNotification);
		}
		setRecordLevelSlider(newGainIsZero);
		oldRecordGainWasZero = newGainIsZero;
		// SAve in XML file
		getXmlTagSOUNDCONTROL()->setAttribute("autoGain", newGainIsZero);
		getXmlTagSOUNDCONTROL()->setAttribute("recordingGain", newGain);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserSliderCode_recordingLevelSlider]
	}

	//[UsersliderValueChanged_Post]
	//[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void guitarStringSoundsControl::labelTextChanged(Label* labelThatHasChanged)
{
	if (labelThatHasChanged == recordingLevelSliderLabel.get())
	{
		auto labelTextIs = recordingLevelSliderLabel->getText();
		if (labelTextIs != "Auto")
		{
			auto newGain = labelTextIs.getFloatValue();

			recordingLevelSlider->setValue(newGain, NotificationType::sendNotification);

			setRecordLevelSlider(newGain == 0.0f);
		}
		else
		{
			recordingLevelSlider->setValue(0.0f, NotificationType::sendNotification);
		}
	}
}

#if (JUCE_IOS || JUCE_ANDROID)
void guitarStringSoundsControl::scaleAllComponents()
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

			auto  curUserArea = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
			float bndsScaleHoriz = (float)(curUserArea.getWidth()) / (float)(widthOfGuitarStringSoundsControlWindowHorizontal);
			float bndsScaleVerti = ((float)(curUserArea.getHeight()) - (float)tabBarDepth) / ((float)hightOfGuitarStringSoundsControlWindowHorizontal);
			float scaleNow = bndsScaleVerti;
			if (bndsScaleHoriz < bndsScaleVerti)
			{
				scaleNow = bndsScaleHoriz;
			}

			if (curUserArea.getWidth() >= curUserArea.getHeight())
			{
				// Horizontal
				workRectangle.setBounds(298, 89, 120, 176);
				recordGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(306, 103, roundToInt(104 * 1.0000f), 24);
				rawSoundLabellabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(354 - (24 / 2)), 127, 24, 24);
				sourceRawToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(302, 149, 112, 24);
				FilteredSoundLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(354 - (24 / 2)), 173, 24, 24);
				sourceFilteredToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(303, 199, 48, 24);
				startLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(328 - (24 / 2)), 223, 24, 24);
				startRecordingToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(356, 199, 48, 24);
				stopLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(380 - (24 / 2)), 223, 24, 24);
				stopRecordingToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(419, 90, 134, 176);
				recordLevelGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(439, 103, 24, 155);
				RecordingLevelMeter->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(492 - 2, 105, 50, 20);
				recordingLevelSliderLabel->setBounds(workRectangle * scaleUsedLastTime);
				recordingLevelSlider->setSliderStyle(Slider::LinearVertical);
				workRectangle.setBounds(490 - 2, 105 + 20, 55, 161 - 20 - 24 - 5);
				recordingLevelSlider->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(486 - 1), 236, 60, 24);
				autoGainToggleButton->setBounds(workRectangle * scaleUsedLastTime);
			}
			else
			{
				// Vertical
				bndsScaleHoriz = (float)(curUserArea.getWidth()) / (float)(widthOfGuitarStringSoundsControlWindowVertical);
				bndsScaleVerti = ((float)(curUserArea.getHeight()) - (float)tabBarDepth) / ((float)(hightOfGuitarStringSoundsControlWindowVertical + 1));
				if (bndsScaleHoriz < bndsScaleVerti)
				{
					scaleNow = bndsScaleHoriz;
				}
				else
				{
					scaleNow = bndsScaleVerti;
				}
				workRectangle.setBounds(0, 266, 296, 78);
				recordGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(1, 280, 87, 24);
				rawSoundLabellabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(46 - (24 / 2)), 304, 24, 24);
				sourceRawToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(90, 280, 108, 24);
				FilteredSoundLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(141 - (24 / 2)), 304, 24, 24);
				sourceFilteredToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(195, 280, 48, 24);
				startLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(220 - (24 / 2)), 304, 24, 24);
				startRecordingToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(244, 280, 48, 24);
				stopLabel->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(268 - (24 / 2)), 304, 24, 24);
				stopRecordingToggleButton->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(0, 346, 296, 85);
				recordLevelGroupComponent->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(8, 364, 280, 24);
				RecordingLevelMeter->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(8, 398, 50, 20);
				recordingLevelSliderLabel->setBounds(workRectangle * scaleUsedLastTime);
				recordingLevelSlider->setSliderStyle(Slider::LinearHorizontal);
				workRectangle.setBounds(8 + 50, 392, 215 - 50, 32);
				recordingLevelSlider->setBounds(workRectangle * scaleUsedLastTime);
				workRectangle.setBounds(std::round(231), 396, 60, 24);
				autoGainToggleButton->setBounds(workRectangle * scaleUsedLastTime);
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
					if (Component* childComponent = this->getChildComponent(i))
					{
						auto curCpntBnds = childComponent->getBounds();
						auto scaledBounds = curCpntBnds * scaleToUse;
						childComponent->setBounds(scaledBounds);
						//						auto curCpntBndsAfter = childComponent->getBounds();

						auto labelTestComponent = dynamic_cast<juce::Label*> (childComponent);
						if ((labelTestComponent != nullptr) && (scaleToUse > 1) && firstCall)
						{
							Font currentFont = labelTestComponent->getFont();
							auto newFontHeight = currentFont.getHeightInPoints() * scaleToUse * 0.9;
							labelTestComponent->setFont(FontOptions(newFontHeight));
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

void guitarStringSoundsControl::disableAllStringTonesAndMutes()
{
	E2soundToggleButton->setToggleState(false, dontSendNotification);
	A2soundToggleButton->setToggleState(false, dontSendNotification);
	D3soundToggleButton->setToggleState(false, dontSendNotification);
	G3soundToggleButton->setToggleState(false, dontSendNotification);
	B3soundToggleButton->setToggleState(false, dontSendNotification);
	E4soundToggleButton->setToggleState(false, dontSendNotification);
	guitarStringSoundsOn = { false, false, false, false, false, false };

	//stringsMuteToggleButton->setToggleState(false, dontSendNotification);
	//outputMuteToggleButton->setToggleState(false, dontSendNotification);
}

inline std::string guitarStringSoundsControl::eksLongDoubleToString(long double valueToConvert, int noOfDecimals)
{
	char stringOfRoundedSecondsPerBufferBuffer[20] = { 0 };
	auto roundedSecondsPerBuffer = std::round(valueToConvert * std::pow(10, noOfDecimals)) / std::pow(10, noOfDecimals);
	std::snprintf(stringOfRoundedSecondsPerBufferBuffer, 20, "%.*Lf", noOfDecimals, roundedSecondsPerBuffer);
	return stringOfRoundedSecondsPerBufferBuffer;
}

inline void guitarStringSoundsControl::setRecordLevelSlider(bool newGainIsZero)
{
	if (!newGainIsZero)
	{
		recordingLevelSliderLabel->setText(eksLongDoubleToString(recordingLevelSlider->getValue(), 2), NotificationType::dontSendNotification);
	}
	else
	{
		recordingLevelSliderLabel->setText("Auto", NotificationType::dontSendNotification);
		recordingLevelSlider->setValue(0.0f, NotificationType::sendNotification);
	}
}


XmlElement* guitarStringSoundsControl::getXmlTagSOUNDCONTROL()
{
	// check we're looking at the right kind of document..
	if (pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().hasTagName("GUITARFINETUNECONFIG"))
	{
		// now we'll iterate its sub-elements looking for 'SOUNDCONTROL' elements..
		return pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().getChildByName("SOUNDCONTROL");
	}
	return nullptr;
}

void guitarStringSoundsControl::initControls()
{
	// autoGainToggleButton
	auto autoGainOn = getXmlTagSOUNDCONTROL()->getBoolAttribute("autoGain");
	autoGainToggleButton->setToggleState(autoGainOn, NotificationType::dontSendNotification);

	if (autoGainOn)
	{
		spAudioRecorderController->setRecordingGain(0.0f);
		recordingLevelSlider->setValue(0.0f, NotificationType::dontSendNotification);
		recordingLevelSliderLabel->setText("Auto", NotificationType::dontSendNotification);
		getXmlTagSOUNDCONTROL()->setAttribute("autoGain", true);
		getXmlTagSOUNDCONTROL()->setAttribute("recordingGain", 0.0f);
	}
	else
	{
		// recordingLevelSlider
		auto recGainToUse = getXmlTagSOUNDCONTROL()->getDoubleAttribute("recordingGain");
		if (recGainToUse > 0.0f)
		{
			spAudioRecorderController->setRecordingGain((float)recGainToUse);
			recordingLevelSlider->setValue(recGainToUse, NotificationType::dontSendNotification);
			spAudioRecorderController->setAutoGainOn(false);
			recordingLevelSliderLabel->setText(eksLongDoubleToString(recGainToUse, 2), NotificationType::dontSendNotification);
		}
		else
		{
			spAudioRecorderController->setRecordingGain(0.0f);
			recordingLevelSlider->setValue(0.0f, NotificationType::dontSendNotification);
			recordingLevelSliderLabel->setText("Auto", NotificationType::dontSendNotification);
			getXmlTagSOUNDCONTROL()->setAttribute("autoGain", true);
			getXmlTagSOUNDCONTROL()->setAttribute("recordingGain", 0.0f);
		}
	}

	// strings
	// stringsMuteToggleButton
	stringsMuteToggleButtonOn = getXmlTagSOUNDCONTROL()->getBoolAttribute("muteStrings");
	pTuneComponent->setStringsMuteToggleButtonOnFlag(stringsMuteToggleButtonOn);
	stringsMuteToggleButton->setToggleState(stringsMuteToggleButtonOn, NotificationType::dontSendNotification);
	// stringSlider
	auto gainToUse = getXmlTagSOUNDCONTROL()->getDoubleAttribute("stringGain");
	stringSliderLabel->setText(eksLongDoubleToString(gainToUse, 2), NotificationType::dontSendNotification);
	stringSlider->setValue(gainToUse, NotificationType::dontSendNotification);
	if (stringsMuteToggleButtonOn)
	{
		pTuneComponent->setStringsGain((float)0.0f);
	}
	else
	{
		pTuneComponent->setStringsGain((float)gainToUse);
	}

	// input
	// inputMuteToggleButton
	inputMuteToggleButtonOn = getXmlTagSOUNDCONTROL()->getBoolAttribute("muteInput");
	pTuneComponent->setInputMuteToggleButtonOnFlag(inputMuteToggleButtonOn);
	inputMuteToggleButton->setToggleState(inputMuteToggleButtonOn, NotificationType::dontSendNotification);
	// inputSlider
	gainToUse = getXmlTagSOUNDCONTROL()->getDoubleAttribute("inputGain");
	inputSliderLabel->setText(eksLongDoubleToString(gainToUse, 2), NotificationType::dontSendNotification);
	inputSlider->setValue(gainToUse, NotificationType::dontSendNotification);
	if (inputMuteToggleButtonOn)
	{
		pTuneComponent->setInputGain((float)0.0f);
	}
	else
	{
		pTuneComponent->setInputGain((float)gainToUse);
	}

	// output
	// outputMuteToggleButton
	outputMuteToggleButtonOn = getXmlTagSOUNDCONTROL()->getBoolAttribute("muteOutput");
	pTuneComponent->setOutputMuteToggleButtonOnFlag(outputMuteToggleButtonOn);
	outputMuteToggleButton->setToggleState(outputMuteToggleButtonOn, NotificationType::dontSendNotification);
	// outputSlider
	gainToUse = getXmlTagSOUNDCONTROL()->getDoubleAttribute("outputGain");
	outputSliderLabel->setText(eksLongDoubleToString(gainToUse, 2), NotificationType::dontSendNotification);
	outputSlider->setValue(gainToUse, NotificationType::dontSendNotification);
	if (outputMuteToggleButtonOn)
	{
		pTuneComponent->setOutputGain((float)0.0f);
	}
	else
	{
		pTuneComponent->setOutputGain((float)gainToUse);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="guitarStringSoundsControl"
				 componentName="" parentClasses="public Component, public Label::Listener"
				 constructorParams="std::shared_ptr&lt;tuneComponent&gt; pTC, std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTConfig, std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF, bool addVWP"
				 variableInitialisers="pGuitarFineTuneLookAndFeel(pGFTAF),&#10;pTuneComponent(pTC),&#10;spAudioRecorderController(pTC-&gt;getAudioRecorderController()),&#10;pXmlGuitarFineTuneConfig(pXmlGFTConfig),&#10;viewPortAdded(addVWP)"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="0" initialWidth="552" initialHeight="274">
  <BACKGROUND backgroundColour="ff2b0720"/>
  <GROUPCOMPONENT name="PlayToneGroupComponent" id="d6161cadd7499374" memberName="PlayToneGroupComponent"
				  virtualName="" explicitFocusOrder="0" pos="0 8 296 80" outlinecol="ff0000ff"
				  textcol="ff6495ed" title="Play tone for guitar string"/>
  <GROUPCOMPONENT name="outputMixGroupComponent" id="b4ab67277d108ecf" memberName="outputMixGroupComponent"
				  virtualName="" explicitFocusOrder="0" pos="0 89 296 176" outlinecol="ff0000ff"
				  textcol="ff6495ed" title="Output mix"/>
  <TOGGLEBUTTON name="E2soundToggleButton" id="879b6ad3bd7013d5" memberName="E2soundToggleButton"
				virtualName="" explicitFocusOrder="1" pos="18 52 28 24" posRelativeW="7718ccff506e5223"
				tooltip="Play guitar string E2 sound" txtcol="ff6495ed" buttonText=""
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="A2soundToggleButton" id="fdbdf3e31c08fcf1" memberName="A2soundToggleButton"
				virtualName="" explicitFocusOrder="2" pos="55 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" tooltip="Play guitar string A2 sound"
				txtcol="ff6495ed" buttonText="" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="D3soundToggleButton" id="6157881167c196a8" memberName="D3soundToggleButton"
				virtualName="" explicitFocusOrder="3" pos="92 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" tooltip="Play guitar string D3 sound"
				txtcol="ff6495ed" buttonText="" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="G3soundToggleButton" id="4b9f6d8f86db8a5f" memberName="G3soundToggleButton"
				virtualName="" explicitFocusOrder="4" pos="129 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" tooltip="Play guitar string G3 sound"
				txtcol="ff6495ed" buttonText="" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="B3soundToggleButton" id="68aa403cfb54dc23" memberName="B3soundToggleButton"
				virtualName="" explicitFocusOrder="5" pos="166 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" tooltip="Play guitar string B3 sound"
				txtcol="ff6495ed" buttonText="" connectedEdges="2" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="E4soundToggleButton" id="f9569ab7e4f3bf36" memberName="E4soundToggleButton"
				virtualName="" explicitFocusOrder="6" pos="203 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" tooltip="Play guitar string E4 sound"
				txtcol="ff6495ed" buttonText="" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <SLIDER name="stringSlider" id="88f92d492d7e9371" memberName="stringSlider"
		  virtualName="" explicitFocusOrder="7" pos="20 159 48 67" tooltip="Guitar strings sound level"
		  bkgcol="ff808080" trackcol="ff808080" textboxtext="ff6495ed"
		  min="0.00000000000000000000" max="1.00000000000000000000" int="0.10000000000000000555"
		  style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
		  textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
		  needsCallback="1"/>
  <SLIDER name="inputSlider" id="1d879d9308af2530" memberName="inputSlider"
		  virtualName="" explicitFocusOrder="8" pos="122 159 48 67" tooltip="Input sound level."
		  bkgcol="ff808080" trackcol="ff808080" textboxtext="ff6495ed"
		  min="0.00000000000000000000" max="1.00000000000000000000" int="0.10000000000000000555"
		  style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
		  textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
		  needsCallback="1"/>
  <LABEL name="stringsVolLabel" id="2f880349b02139a3" memberName="stringsVolLabel"
		 virtualName="" explicitFocusOrder="0" pos="17 111 54 26" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Strings" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <LABEL name="inputVolLabel" id="dd7e02ffa74ea7e8" memberName="inputVolLabel"
		 virtualName="" explicitFocusOrder="0" pos="116 111 59 24" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Input" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="inputMuteToggleButton" id="df81ce34b481c7a1" memberName="inputMuteToggleButton"
				virtualName="" explicitFocusOrder="9" pos="116 226 60 24" tooltip="Mute input"
				txtcol="ff6495ed" buttonText="Mute" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="stringsMuteToggleButton" id="59766bb4cc64bebb" memberName="stringsMuteToggleButton"
				virtualName="" explicitFocusOrder="9" pos="16 226 60 24" tooltip="Mute input"
				txtcol="ff6495ed" buttonText="Mute" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <LABEL name="outputVolLabel" id="20c8f398c413e9ba" memberName="outputVolLabel"
		 virtualName="" explicitFocusOrder="0" pos="214 111 64 24" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Output" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <SLIDER name="outputSlider" id="c06226447f3da2b4" memberName="outputSlider"
		  virtualName="" explicitFocusOrder="10" pos="222 159 48 67" tooltip="Output sound level."
		  bkgcol="ff808080" trackcol="ff808080" textboxtext="ff6495ed"
		  min="0.00000000000000000000" max="1.00000000000000000000" int="0.10000000000000000555"
		  style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
		  textBoxWidth="80" textBoxHeight="20" skewFactor="1.00000000000000000000"
		  needsCallback="1"/>
  <TOGGLEBUTTON name="outputMuteToggleButton" id="36f49e5873740165" memberName="outputMuteToggleButton"
				virtualName="" explicitFocusOrder="11" pos="216 226 60 24" tooltip="Mute output"
				txtcol="ff6495ed" buttonText="Mute" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <LABEL name="E2label" id="67d979411aed1b7b" memberName="E2label" virtualName=""
		 explicitFocusOrder="0" pos="14 29 28 16" posRelativeW="879b6ad3bd7013d5"
		 posRelativeH="879b6ad3bd7013d5" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="E2" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="A2label" id="e4f9b6b015a3ba5e" memberName="A2label" virtualName=""
		 explicitFocusOrder="0" pos="51 29 28 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="A2" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="D3label" id="33a59f7e035099ba" memberName="D3label" virtualName=""
		 explicitFocusOrder="0" pos="88 29 28 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="D3" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="G3label" id="f863756d90c2521f" memberName="G3label" virtualName=""
		 explicitFocusOrder="0" pos="125 29 28 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="G3" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="B3label" id="e7effe69709a11a3" memberName="B3label" virtualName=""
		 explicitFocusOrder="0" pos="162 29 28 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="B3" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <LABEL name="E4label" id="bfb8d02e510111c8" memberName="E4label" virtualName=""
		 explicitFocusOrder="0" pos="199 29 28 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="E4" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="recordGroupComponent" id="cd16513729f04f9e" memberName="recordGroupComponent"
				  virtualName="" explicitFocusOrder="0" pos="0 266 296 78" outlinecol="ff0000ff"
				  textcol="ff6495ed" title="Record" textpos="33"/>
  <TOGGLEBUTTON name="sourceRawToggleButton" id="c3092f7ac718147b" memberName="sourceRawToggleButton"
				virtualName="" explicitFocusOrder="12" pos="46c 304 24 24" txtcol="ff6495ed"
				buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="1"
				state="1"/>
  <TOGGLEBUTTON name="sourceFilteredToggleButton" id="c34e91d074dddcca" memberName="sourceFilteredToggleButton"
				virtualName="" explicitFocusOrder="13" pos="141c 304 24 24" txtcol="ff6495ed"
				buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="1"
				state="0"/>
  <TOGGLEBUTTON name="stopRecordingToggleButton" id="4c18855b27d3e04a" memberName="stopRecordingToggleButton"
				virtualName="" explicitFocusOrder="15" pos="268c 304 24 24" txtcol="ff6495ed"
				buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="2"
				state="1"/>
  <LABEL name="rawSoundLabellabel" id="6e4514cab36098c9" memberName="rawSoundLabellabel"
		 virtualName="" explicitFocusOrder="0" pos="10 280 85 24" posRelativeW="1856a4a0e60549ea"
		 textCol="ff6495ed" edTextCol="ff000000" edBkgCol="0" labelText="Raw sound&#10;"
		 editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
		 fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <LABEL name="FilteredSoundLabel" id="1856a4a0e60549ea" memberName="FilteredSoundLabel"
		 virtualName="" explicitFocusOrder="0" pos="94 280 104 24" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Filtered sound&#10;"
		 editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
		 fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <LABEL name="stopLabel" id="575ff7fc186f1f00" memberName="stopLabel"
		 virtualName="" explicitFocusOrder="0" pos="246 280 48 24" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Stop" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="recordLevelGroupComponent" id="401ad11573ae449a" memberName="recordLevelGroupComponent"
				  virtualName="" explicitFocusOrder="0" pos="0 345 296 86" outlinecol="ff0000ff"
				  textcol="ff6495ed" title="Recording level"/>
  <SLIDER name="recordingLevelSlider" id="b91b5c169ea1058f" memberName="recordingLevelSlider"
		  virtualName="" explicitFocusOrder="16" pos="58 390 165 32" tooltip="Recording sound gain. 0.00 = Auto Gain."
		  bkgcol="ff808080" trackcol="ff42a2c8" textboxtext="ff6495ed"
		  min="0.00000000000000000000" max="500.00000000000000000000" int="0.01000000000000000021"
		  style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
		  textBoxWidth="50" textBoxHeight="20" skewFactor="1.00000000000000000000"
		  needsCallback="1"/>
  <TOGGLEBUTTON name="startRecordingToggleButton" id="3ad5e15e8c3aa226" memberName="startRecordingToggleButton"
				virtualName="" explicitFocusOrder="14" pos="220c 304 24 24" txtcol="ff6495ed"
				buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="2"
				state="0"/>
  <LABEL name="startLabel" id="a086e1c4d59b594a" memberName="startLabel"
		 virtualName="" explicitFocusOrder="0" pos="197 280 48 24" textCol="ff6495ed"
		 edTextCol="ff000000" edBkgCol="0" labelText="Start" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
		 fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
		 bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="guitarStringTonesOffToggleButton" id="fafc8c680d7aedfd"
				memberName="guitarStringTonesOffToggleButton" virtualName=""
				explicitFocusOrder="0" pos="253 52 28 24" posRelativeW="879b6ad3bd7013d5"
				posRelativeH="879b6ad3bd7013d5" buttonText="" connectedEdges="1"
				needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="allOffLabel" id="a6238fce8002cd98" memberName="allOffLabel"
		 virtualName="" explicitFocusOrder="0" pos="234 29 56 16" posRelativeW="67d979411aed1b7b"
		 posRelativeH="67d979411aed1b7b" textCol="ff6495ed" edTextCol="ff000000"
		 edBkgCol="0" labelText="All off" editableSingleClick="0" editableDoubleClick="0"
		 focusDiscardsChanges="0" fontname="Default font" fontsize="15.00000000000000000000"
		 kerning="0.00000000000000000000" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="autoGainToggleButton" id="80c3beefd1a5f264" memberName="autoGainToggleButton"
				virtualName="" explicitFocusOrder="0" pos="231 394 60 24" txtcol="ff6495ed"
				buttonText="Auto" connectedEdges="0" needsCallback="1" radioGroupId="0"
				state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
