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

class eksVariableToneCtrl;
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
class eksVariableToneCtrlDocWin  : public juce::DocumentWindow
{
public:
    //==============================================================================
    eksVariableToneCtrlDocWin (std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF);
    ~eksVariableToneCtrlDocWin() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void closeButtonPressed()
    {
        setVisible(false);
    }
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr<eksVariableToneCtrl> spEksVariableToneCtrl = nullptr;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (eksVariableToneCtrlDocWin)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

