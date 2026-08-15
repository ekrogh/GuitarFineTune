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
#include "eksLookAndFeel.h"
//[/Headers]

#include "eksAudioControlComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
extern std::unique_ptr<AudioDeviceManager> sharedAudioDeviceManager;
extern std::unique_ptr<tuneComponent> pTuneComponent;
//[/MiscUserDefs]

//==============================================================================
eksAudioControlComponent::eksAudioControlComponent(std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTCfg, std::shared_ptr<eksLookAndFeel> pGFTAF, bool addVWP)
	: pGuitarFineTuneLookAndFeel(pGFTAF)
	, pXmlGuitarFineTuneConfig(pXmlGFTCfg)
	, viewPortAdded(addVWP)
{
	//[Constructor_pre] You can add your own custom stuff here..
	//[/Constructor_pre]
	pAudioDeviceSelectorComponent.reset(new juce::AudioDeviceSelectorComponent(*sharedAudioDeviceManager, 1, 2, 0, 2, false, false, false, false));
	addAndMakeVisible(pAudioDeviceSelectorComponent.get());
	pAudioDeviceSelectorComponent->setName("pAudioDeviceSelectorComponent");

	pAudioDeviceSelectorComponent->setBounds(1, 1, 330, 360);

	Use_50_Hz_FilterToggleButton.reset(new juce::ToggleButton("Use_50_Hz_FilterToggleButton"));
	addAndMakeVisible(Use_50_Hz_FilterToggleButton.get());
	Use_50_Hz_FilterToggleButton->setButtonText(TRANS("Use 50 Hz Filter"));
	Use_50_Hz_FilterToggleButton->addListener(this);
	Use_50_Hz_FilterToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    Use_50_Hz_FilterToggleButton->setBounds(1, 370, 75, 24);
//    Use_50_Hz_FilterToggleButton->setSize(75, 24);

	Use_60_Hz_FilterToggleButton.reset(new juce::ToggleButton("Use_60_Hz_FilterToggleButton"));
	addAndMakeVisible(Use_60_Hz_FilterToggleButton.get());
	Use_60_Hz_FilterToggleButton->setButtonText(TRANS("Use 60 Hz Filter"));
	Use_60_Hz_FilterToggleButton->addListener(this);
	Use_60_Hz_FilterToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

    Use_60_Hz_FilterToggleButton->setBounds(147, 370, 75, 24);
//    Use_60_Hz_FilterToggleButton->setSize(75, 24);

	preProcessingToggleButton.reset(new juce::ToggleButton("preProcessingToggleButton"));
	addAndMakeVisible(preProcessingToggleButton.get());
	preProcessingToggleButton->setButtonText(TRANS("Disable OS audio preprocessing"));
	preProcessingToggleButton->addListener(this);
	preProcessingToggleButton->setColour(juce::ToggleButton::textColourId, juce::Colours::cornflowerblue);

	preProcessingToggleButton->setBounds(1, 403, 231, 24);

	//[UserPreSize]
	// Check if system supports set Audio Preprocessing Enabled/Disabled and set off if so
	AudioIODevice* CurrentAudioDevice = sharedAudioDeviceManager->getCurrentAudioDevice();
	if (CurrentAudioDevice != nullptr)
	{
		changedDeviceSupportsDisableAudioPreprocessing =
			previousDeviceSupportsDisableAudioPreprocessing !=
			(deviceSupportsDisableAudioPreprocessing = CurrentAudioDevice->setAudioPreprocessingEnabled(true));
		previousDeviceSupportsDisableAudioPreprocessing = deviceSupportsDisableAudioPreprocessing;

		if (deviceSupportsDisableAudioPreprocessing)
		{
			preProcessingToggleButton->setEnabled(true);
			preProcessingToggleButton->setVisible(true);
			if (changedDeviceSupportsDisableAudioPreprocessing)
			{
				bool disableOsAudioPreProcessing = getXmlTagAUDIOCONTROL()->getBoolAttribute("disableOsAudioPreProcessing");
				sharedAudioDeviceManager->getCurrentAudioDevice()->setAudioPreprocessingEnabled(disableOsAudioPreProcessing);
				preProcessingToggleButton->setToggleState(disableOsAudioPreProcessing, dontSendNotification);
			}
		}
		else
		{
			preProcessingToggleButton->setEnabled(false);
			preProcessingToggleButton->setVisible(false);
		}
	}
#if JUCE_ANDROID
	Use_50_Hz_FilterToggleButton->setBounds(1, heightAudioDeviceSelectorComponent + 1, 150, 24);
	Use_60_Hz_FilterToggleButton->setBounds(147, heightAudioDeviceSelectorComponent + 1, 149, 24);
	preProcessingToggleButton->setBounds(1, heightAudioDeviceSelectorComponent + 1 + 24, 231, 24);
#else
	auto heightAudioDeviceSelectorComponent = pAudioDeviceSelectorComponent->getHeight();
//	Use_50_Hz_FilterToggleButton->setBounds(1, heightAudioDeviceSelectorComponent - 15, 150, 24);
//	Use_60_Hz_FilterToggleButton->setBounds(147, heightAudioDeviceSelectorComponent - 15, 149, 24);
	preProcessingToggleButton->setBounds(1, heightAudioDeviceSelectorComponent + 24 - 15, 231, 24);
#endif // JUCE_ANDROID
	//[/UserPreSize]

	setSize(600, 400);


	//[Constructor] You can add your own custom stuff here..
	initControls();
	//[/Constructor]
}

eksAudioControlComponent::~eksAudioControlComponent()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//pGuitarFineTuneLookAndFeel.reset( );
	//pGuitarFineTuneLookAndFeel = nullptr;
	//[/Destructor_pre]

	//pAudioDeviceSelectorComponent = nullptr;
	Use_50_Hz_FilterToggleButton = nullptr;
	Use_60_Hz_FilterToggleButton = nullptr;
	preProcessingToggleButton = nullptr;


	//[Destructor]. You can add your own custom destruction code here..
	//sharedAudioDeviceManager->closeAudioDevice();
	//sharedAudioDeviceManager = nullptr;
	//[/Destructor]
}

//==============================================================================
void eksAudioControlComponent::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff20072b));

	//[UserPaint] Add your own custom painting code here..
	setColorOfAllLabels(pAudioDeviceSelectorComponent.get());
	//[/UserPaint]
}

void eksAudioControlComponent::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	{
		const int margin = 6;
		auto localBounds = getLocalBounds();
		auto* lf = dynamic_cast<eksLookAndFeel*> (&getLookAndFeel());
		float scale = lf ? lf->getCurrentScale() : 1.0f;

		const int rowH = (int) (28 * scale);

		int prefW = (int) (600 * scale);
		int prefH = (int) (600 * scale);

		auto area = localBounds.reduced (margin);
		if (area.getWidth() > prefW)  area = area.withWidth (prefW).withCentre (localBounds.getCentre());
		if (area.getHeight() > prefH) area = area.withHeight (prefH).withCentre (localBounds.getCentre());

		if (preProcessingToggleButton->isVisible())
		{
			preProcessingToggleButton->setBounds(area.removeFromBottom(rowH));
			area.removeFromBottom(margin);
		}

		// 50/60 Hz buttons side by side
		auto hzRow = area.removeFromBottom(rowH);
		area.removeFromBottom((int)(margin * scale));
		juce::FlexBox hzFb;
		hzFb.flexDirection = juce::FlexBox::Direction::row;
		hzFb.items.add(juce::FlexItem(*Use_50_Hz_FilterToggleButton).withFlex(1).withMargin({ 0, (float)margin * scale / 2, 0, 0 }));
		hzFb.items.add(juce::FlexItem(*Use_60_Hz_FilterToggleButton).withFlex(1).withMargin({ 0, 0, 0, (float)margin * scale / 2 }));
		hzFb.performLayout(hzRow.toFloat());

		// AudioDeviceSelectorComponent fills the rest
		pAudioDeviceSelectorComponent->setBounds(area);
	}
	AudioIODevice* CurrentAudioDevice = sharedAudioDeviceManager->getCurrentAudioDevice();
	if (CurrentAudioDevice != nullptr)
	{
		changedDeviceSupportsDisableAudioPreprocessing =
			previousDeviceSupportsDisableAudioPreprocessing !=
			(deviceSupportsDisableAudioPreprocessing = CurrentAudioDevice->setAudioPreprocessingEnabled(true));
		previousDeviceSupportsDisableAudioPreprocessing = deviceSupportsDisableAudioPreprocessing;

		if (deviceSupportsDisableAudioPreprocessing)
		{
			preProcessingToggleButton->setEnabled(true);
			preProcessingToggleButton->setVisible(true);
			if (changedDeviceSupportsDisableAudioPreprocessing)
			{
				bool disableOsAudioPreProcessing = getXmlTagAUDIOCONTROL()->getBoolAttribute("disableOsAudioPreProcessing");
				sharedAudioDeviceManager->getCurrentAudioDevice()->setAudioPreprocessingEnabled(disableOsAudioPreProcessing);
				preProcessingToggleButton->setToggleState(disableOsAudioPreProcessing, dontSendNotification);
			}
		}
		else
		{
			preProcessingToggleButton->setEnabled(false);
			preProcessingToggleButton->setVisible(false);
		}
	}

	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
	//[/UserResized]
}

void eksAudioControlComponent::buttonClicked(juce::Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == Use_50_Hz_FilterToggleButton.get())
	{
		//[UserButtonCode_Use_50_Hz_FilterToggleButton] -- add your button handler code here..
		auto theUse50HzFilterToggleButtonToggleState = Use_50_Hz_FilterToggleButton->getToggleState();
		if (Use_60_Hz_FilterToggleButton->getToggleState() && theUse50HzFilterToggleButtonToggleState)
		{
			Use_60_Hz_FilterToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			getXmlTagAUDIOCONTROL()->setAttribute("use60HzFilter", false);
		}
		pTuneComponent->setUse50HzFilterFlag(theUse50HzFilterToggleButtonToggleState);
		getXmlTagAUDIOCONTROL()->setAttribute("use50HzFilter", theUse50HzFilterToggleButtonToggleState);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_Use_50_Hz_FilterToggleButton]
	}
	else if (buttonThatWasClicked == Use_60_Hz_FilterToggleButton.get())
	{
		//[UserButtonCode_Use_60_Hz_FilterToggleButton] -- add your button handler code here..
		auto theUse60HzFilterToggleButtonToggleState = Use_60_Hz_FilterToggleButton->getToggleState();
		if (Use_50_Hz_FilterToggleButton->getToggleState() && theUse60HzFilterToggleButtonToggleState)
		{
			Use_50_Hz_FilterToggleButton->setToggleState(false, NotificationType::dontSendNotification);
			getXmlTagAUDIOCONTROL()->setAttribute("use50HzFilter", false);
		}
		pTuneComponent->setUse60HzFilterFlag(theUse60HzFilterToggleButtonToggleState);
		getXmlTagAUDIOCONTROL()->setAttribute("use60HzFilter", theUse60HzFilterToggleButtonToggleState);
		pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		//[/UserButtonCode_Use_60_Hz_FilterToggleButton]
	}
	else if (buttonThatWasClicked == preProcessingToggleButton.get())
	{
		//[UserButtonCode_preProcessingToggleButton] -- add your button handler code here..
		//On devices which support it, this allows automatic gain control or other mic processing to be disabled.
		//	If the device doesn't support this operation, it'll return false.
		if (deviceSupportsDisableAudioPreprocessing)
		{
			sharedAudioDeviceManager->getCurrentAudioDevice()->setAudioPreprocessingEnabled(preProcessingToggleButton->getToggleState());
			getXmlTagAUDIOCONTROL()->setAttribute("disableOsAudioPreProcessing", preProcessingToggleButton->getToggleState());
			pXmlGuitarFineTuneConfig->writeConfigToXmlFile();
		}
		//[/UserButtonCode_preProcessingToggleButton]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void eksAudioControlComponent::initControls()
{
	if (deviceSupportsDisableAudioPreprocessing)
	{
		bool disableOsAudioPreProcessing = getXmlTagAUDIOCONTROL()->getBoolAttribute("disableOsAudioPreProcessing");
		sharedAudioDeviceManager->getCurrentAudioDevice()->setAudioPreprocessingEnabled(disableOsAudioPreProcessing);
		preProcessingToggleButton->setToggleState(disableOsAudioPreProcessing, dontSendNotification);
	}

	bool use50HzFilter = getXmlTagAUDIOCONTROL()->getBoolAttribute("use50HzFilter");
	pTuneComponent->setUse50HzFilterFlag(use50HzFilter);
	Use_50_Hz_FilterToggleButton->setToggleState(use50HzFilter, dontSendNotification);


	bool use60HzFilter = getXmlTagAUDIOCONTROL()->getBoolAttribute("use60HzFilter");
	pTuneComponent->setUse60HzFilterFlag(use60HzFilter);
	Use_60_Hz_FilterToggleButton->setToggleState(use60HzFilter, dontSendNotification);
}

XmlElement* eksAudioControlComponent::getXmlTagAUDIOCONTROL()
{
	// check we're looking at the right kind of document..
	if (pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().hasTagName("GUITARFINETUNECONFIG"))
	{
		// now we'll iterate its sub-elements looking for 'AUDIOCONTROL' elements..
		return pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().getChildByName("AUDIOCONTROL");
	}
	return nullptr;
}

void eksAudioControlComponent::setColorOfAllLabels(juce::Component* cmpontToHandle)
{
	int numChildComponents = cmpontToHandle->getNumChildComponents();

	if (numChildComponents == 0)
	{
		juce::Label* testLabel = dynamic_cast<juce::Label*> (cmpontToHandle);

		if (testLabel != nullptr)
		{
			cmpontToHandle->setColour(labelTextColorId, labelColor);
		}
	}
	else
	{
		for (int i = 0; i < numChildComponents; ++i)
		{
			if (Component* childComponent = cmpontToHandle->getChildComponent(i))
			{
				setColorOfAllLabels(childComponent);
			}
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="eksAudioControlComponent"
				 componentName="" parentClasses="public Component" constructorParams="std::shared_ptr&lt;tuneComponent&gt; pTC, std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTCfg, std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF, bool addVWP"
				 variableInitialisers="pGuitarFineTuneLookAndFeel(pGFTAF),&#10;pTuneComponent(pTC),&#10;pXmlGuitarFineTuneConfig(pXmlGFTCfg),&#10;viewPortAdded(addVWP)"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff20072b"/>
  <GENERICCOMPONENT name="pAudioDeviceSelectorComponent" id="cc329320c6ff23df" memberName="pAudioDeviceSelectorComponent"
					virtualName="" explicitFocusOrder="0" pos="1 1 330 360" class="juce::AudioDeviceSelectorComponent"
					params="pTuneComponent-&gt;getTheAudioDeviceManager(), 1, 2, 0, 2, false, false, false, false"/>
  <TOGGLEBUTTON name="Use_50_Hz_FilterToggleButton" id="c433e96a5b85c9c6" memberName="Use_50_Hz_FilterToggleButton"
				virtualName="" explicitFocusOrder="0" pos="1 370 150 24" txtcol="ff6495ed"
				buttonText="Use 50 Hz Filter" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Use_60_Hz_FilterToggleButton" id="33692e736c9a48bf" memberName="Use_60_Hz_FilterToggleButton"
				virtualName="" explicitFocusOrder="0" pos="147 370 149 24" txtcol="ff6495ed"
				buttonText="Use 60 Hz Filter" connectedEdges="0" needsCallback="1"
				radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="preProcessingToggleButton" id="c6dac38986b59bb8" memberName="preProcessingToggleButton"
				virtualName="" explicitFocusOrder="0" pos="1 403 231 24" txtcol="ff6495ed"
				buttonText="Disable OS audio preprocessing" connectedEdges="0"
				needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

