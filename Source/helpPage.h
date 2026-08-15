/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.10

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "guitarFineTuneGlobalEnums.h"
#include "xmlGuitarFineTuneConfig.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class aboutPage  : public Component
{
public:
    //==============================================================================
    aboutPage ();
    ~aboutPage() override;

    //==============================================================================
	//[UserMethods]     -- You can add your own custom methods in this section.
	void setConfig(xmlGuitarFineTuneConfig* config) { pXmlGuitarFineTuneConfig = config; }
	//[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    xmlGuitarFineTuneConfig* pXmlGuitarFineTuneConfig = nullptr;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> aboutLabel;
    std::unique_ptr<juce::HyperlinkButton> hyperlinkButton;
    std::unique_ptr<juce::Label> eigilLabel;
    std::unique_ptr<juce::HyperlinkButton> emailButton;
    std::unique_ptr<juce::HyperlinkButton> UsersGuide;
    std::unique_ptr<juce::Label> juceVer__label;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (aboutPage)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

