/*
  ==============================================================================

    audioControlComponent.cpp
    Created: 11 May 2017 12:44:22pm
    Author:  eks

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "fineTuneFirstClass.h"
#include "xmlGuitarFineTuneConfig.h"
#include "audioControlComponent.h"


//==============================================================================
audioControlComponent::audioControlComponent(fineTuneFirstClass& rFFC)
	: rFineTuneFirstClass(rFFC)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    pAudioDeviceSelectorComponent = new AudioDeviceSelectorComponent(rFineTuneFirstClass.getRSpectrogramComponent().getTheAudioDeviceManager(), 1, 2, 0, 2, false, false, false, true);
	rFineTuneFirstClass.setColorOfAllLabels(pAudioDeviceSelectorComponent);
	// Check if system supports set Audio Preprocessing Enabled/Disabled and set off if so
	deviceSupportsDisableAudioPreprocessing = rFineTuneFirstClass.getRSpectrogramComponent().getTheAudioDeviceManager().getCurrentAudioDevice()->setAudioPreprocessingEnabled(false);
	if (deviceSupportsDisableAudioPreprocessing)
	{
		pAudioDeviceSelectorComponent->addAndMakeVisible(preProcessingToggleButton = new ToggleButton("preProcessingToggleButton"));
		preProcessingToggleButton->setButtonText(TRANS("Enable OS audio preprocessing"));
		preProcessingToggleButton->addListener(this);
		preProcessingToggleButton->setToggleState(false, dontSendNotification);
		preProcessingToggleButton->setColour(ToggleButton::textColourId, Colours::cornflowerblue);
	}

	initControls();

}

audioControlComponent::~audioControlComponent()
{
}

void audioControlComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("audioControlComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void audioControlComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

	if (deviceSupportsDisableAudioPreprocessing)
	{
		preProcessingToggleButton->setBounds(8, hightOfAudioDeviceSelectorComponentWindow - 60, 240, 24);
	}
}

void audioControlComponent::initControls()
{
	if (deviceSupportsDisableAudioPreprocessing)
	{
		bool preProcessingOn = getTagAUDIOCONTROL()->getBoolAttribute("preProcessingOn")..getIntValue();
		rFineTuneFirstClass.getRSpectrogramComponent().getTheAudioDeviceManager().getCurrentAudioDevice()->setAudioPreprocessingEnabled(preProcessingOn);
		preProcessingToggleButton->setToggleState(preProcessingOn, dontSendNotification);
	}
}

XmlElement* audioControlComponent::getTagAUDIOCONTROL()
{
	// check we're looking at the right kind of document..
	if (rFineTuneFirstClass.getRxmlGuitarFineTuneConfig().getGuitarfinetuneconfig()->hasTagName("GUITARFINETUNECONFIG"))
	{
		// now we'll iterate its sub-elements looking for 'AUDIOCONTROL' elements..
		forEachXmlChildElement(*(rFineTuneFirstClass.getRxmlGuitarFineTuneConfig().getGuitarfinetuneconfig()), e)
		{
			if (e->hasTagName("AUDIOCONTROL"))
			{
				// found a AUDIOCONTROL, so use its attributes..
				return e;
			}
		}
	}
	return nullptr;
}

void audioControlComponent::buttonClicked(Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == preProcessingToggleButton)
	{
		//[UserButtonCode_preProcessingToggleButton] -- add your button handler code here..
		//On devices which support it, this allows automatic gain control or other mic processing to be disabled.
		//	If the device doesn't support this operation, it'll return false.
		if (deviceSupportsDisableAudioPreprocessing)
		{
			rFineTuneFirstClass.getRSpectrogramComponent().getTheAudioDeviceManager().getCurrentAudioDevice()->setAudioPreprocessingEnabled(preProcessingToggleButton->getToggleState());
			getTagAUDIOCONTROL()->setAttribute("preProcessingOn", preProcessingToggleButton->getToggleState());
			rFineTuneFirstClass.getRxmlGuitarFineTuneConfig().writeConfigToXmlFile();
		}
		//[/UserButtonCode_preProcessingToggleButton]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}
