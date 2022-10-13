/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "tuneComponent.h"
#include "xmlGuitarFineTuneConfig.h"
//[/Headers]

#include "eksVariableToneCtrl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern std::shared_ptr<tuneComponent> pTuneComponent;
extern std::shared_ptr<AudioDeviceManager> sharedAudioDeviceManager;
//[/MiscUserDefs]

//==============================================================================
eksVariableToneCtrl::eksVariableToneCtrl(std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF)
	: pGuitarFineTuneLookAndFeel(pGFTAF),
	pXmlGuitarFineTuneConfig(pXmlGFTConfig)
{
	//[Constructor_pre] You can add your own custom stuff here..
	//[/Constructor_pre]

	sendOuttoggleButton.reset(new juce::ToggleButton("sendOuttoggleButton"));
	addAndMakeVisible(sendOuttoggleButton.get());
	sendOuttoggleButton->setButtonText(TRANS("Activate Multiply with tones"));
	sendOuttoggleButton->setButtonText(TRANS("Multiply with tones"));
	sendOuttoggleButton->addListener(this);

	sendOuttoggleButton->setBounds(194, 64, 150, 24);

	FrequencySlider.reset(new juce::Slider("FrequencySlider"));
	addAndMakeVisible(FrequencySlider.get());
	FrequencySlider->setTooltip(TRANS("Freq [Hz]"));
	FrequencySlider->setRange(0, 500, 0);
	FrequencySlider->setSliderStyle(juce::Slider::LinearVertical);
	FrequencySlider->setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
	FrequencySlider->addListener(this);

	FrequencySlider->setBounds(0, 0, 150, 448);

	showFftToggleButton.reset(new juce::ToggleButton("showFftToggleButton"));
	addAndMakeVisible(showFftToggleButton.get());
	showFftToggleButton->setButtonText(TRANS("Show FFT"));
	showFftToggleButton->addListener(this);

	showFftToggleButton->setBounds(194, 130, 150, 24);

	addNoiseToggleButton.reset(new juce::ToggleButton("addNoiseToggleButton"));
	addAndMakeVisible(addNoiseToggleButton.get());
	addNoiseToggleButton->setButtonText(TRANS("Add noise"));
	addNoiseToggleButton->addListener(this);

	addNoiseToggleButton->setBounds(194, 204, 150, 24);


	//[UserPreSize]
	//setContentOwned(FrequencySlider.get(), false);
	//[/UserPreSize]

	setSize(300, 450);


	//[Constructor] You can add your own custom stuff here..
	//[/Constructor]
}

eksVariableToneCtrl::~eksVariableToneCtrl()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//[/Destructor_pre]

	sendOuttoggleButton = nullptr;
	FrequencySlider = nullptr;
	showFftToggleButton = nullptr;
	addNoiseToggleButton = nullptr;


	//[Destructor]. You can add your own custom destruction code here..
	//[/Destructor]
}

//==============================================================================
void eksVariableToneCtrl::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff2b0720));

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void eksVariableToneCtrl::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
	//[/UserResized]
}

void eksVariableToneCtrl::buttonClicked(juce::Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == sendOuttoggleButton.get())
	{
		//[UserButtonCode_sendOuttoggleButton] -- add your button handler code here..
		bool toggleState = sendOuttoggleButton->getToggleState();
		if (!toggleState)
		{
			showFftToggleButtonStateSave = showFftToggleButton->getToggleState();
			showFftToggleButton->setToggleState(false, dontSendNotification);
		}
		pTuneComponent->controlVariableTone
		(
			(float)(FrequencySlider->getValue())
			, true
			, toggleState
		);
		if (toggleState)
		{
			showFftToggleButton->setToggleState(showFftToggleButtonStateSave, sendNotification);
		}
		//[/UserButtonCode_sendOuttoggleButton]
	}
	else if (buttonThatWasClicked == showFftToggleButton.get())
	{
		//[UserButtonCode_showFftToggleButton] -- add your button handler code here..
		pTuneComponent->controlVariableToneFFT
		(
			showFftToggleButton->getToggleState()
		);
		//[/UserButtonCode_showFftToggleButton]
	}
	else if (buttonThatWasClicked == addNoiseToggleButton.get())
	{
		//[UserButtonCode_addNoiseToggleButton] -- add your button handler code here..
		//[/UserButtonCode_addNoiseToggleButton]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}

void eksVariableToneCtrl::sliderValueChanged(juce::Slider* sliderThatWasMoved)
{
	//[UsersliderValueChanged_Pre]
	//[/UsersliderValueChanged_Pre]

	if (sliderThatWasMoved == FrequencySlider.get())
	{
		//[UserSliderCode_FrequencySlider] -- add your slider handling code here..
		pTuneComponent->controlVariableTone
		(
			(float)(FrequencySlider->getValue())
			, false
			, true
		);
		//[/UserSliderCode_FrequencySlider]
	}

	//[UsersliderValueChanged_Post]
	//[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="eksVariableToneCtrl" componentName=""
				 parentClasses="public juce::Component" constructorParams="        std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTConfig          , std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF  "
				 variableInitialisers="pGuitarFineTuneLookAndFeel(pGFTAF)&#10;pXmlGuitarFineTuneConfig(pXmlGFTConfig)&#10;DocumentWindow(&quot;Variable Tone Control&quot;, Colour(0xFF2B0720), DocumentWindow::allButtons)"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="0" initialWidth="300" initialHeight="450">
  <BACKGROUND backgroundColour="ff2b0720"/>
  <TOGGLEBUTTON name="sendOuttoggleButton" id="26573501e1f0d42" memberName="sendOuttoggleButton"
				virtualName="" explicitFocusOrder="0" pos="194 64 150 24" buttonText="Multiply with tones"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="FrequencySlider" id="b44be89bb3688130" memberName="FrequencySlider"
		  virtualName="" explicitFocusOrder="0" pos="0 0 150 448" tooltip="Freq [Hz]"
		  min="0.0" max="500.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxLeft"
		  textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
		  needsCallback="1"/>
  <TOGGLEBUTTON name="showFftToggleButton" id="3728d4ec9e263c3f" memberName="showFftToggleButton"
				virtualName="" explicitFocusOrder="0" pos="194 130 150 24" buttonText="Show FFT"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="addNoiseToggleButton" id="b8377889ac180534" memberName="addNoiseToggleButton"
				virtualName="" explicitFocusOrder="0" pos="194 204 150 24" buttonText="Add noise"
				connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

