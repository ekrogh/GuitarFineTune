/*
  ==============================================================================

    audioControlComponent.h
    Created: 11 May 2017 12:44:22pm
    Author:  eks

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
class fineTuneFirstClass;

//==============================================================================
/*
*/
class audioControlComponent
	: public Component
	, public ButtonListener
{
public:
    audioControlComponent(fineTuneFirstClass& rFFC);
    ~audioControlComponent();

    void paint (Graphics&) override;
    void resized() override;
	void buttonClicked(Button* buttonThatWasClicked) override;

private:
	void initControls();
	XmlElement* getTagAUDIOCONTROL();

	ScopedPointer<ToggleButton> preProcessingToggleButton;
	fineTuneFirstClass& rFineTuneFirstClass;
	ScopedPointer<AudioDeviceSelectorComponent> pAudioDeviceSelectorComponent = nullptr;

	bool deviceSupportsDisableAudioPreprocessing = false;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (audioControlComponent)
};
