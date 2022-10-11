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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

class xmlGuitarFineTuneConfig;
class tuneComponent;
class eksLookAndFeel;

//[/Headers]



//==============================================================================
/**
																	//[Comments]
	An auto-generated component, created by the Projucer.

	Describe your class and how it works here!
																	//[/Comments]
*/
class eksVariableToneCtrl : public juce::DocumentWindow,
	public juce::Slider::Listener
{
public:
	//==============================================================================
	eksVariableToneCtrl(std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF);
	//~eksVariableToneCtrl() override;

	//==============================================================================
	//[UserMethods]     -- You can add your own custom methods in this section.
	void closeButtonPressed()
	{
		//FrequenceSlider->removeListener(this);
		//FrequenceSlider = nullptr;
		delete this;
	}
	//[/UserMethods]

	void paint(juce::Graphics& g) override;
	void resized() override;
	void sliderValueChanged(juce::Slider* sliderThatWasMoved) override;



private:
	//[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<eksLookAndFeel> pGuitarFineTuneLookAndFeel = nullptr;
	std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGuitarFineTuneConfig = nullptr;
	//[/UserVariables]

	//==============================================================================
	std::unique_ptr<juce::Slider> FrequenceSlider;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(eksVariableToneCtrl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

