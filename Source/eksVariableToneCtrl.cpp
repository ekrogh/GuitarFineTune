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
eksVariableToneCtrl::eksVariableToneCtrl
(
    std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig
    , std::shared_ptr<eksLookAndFeel> pGFTAF
)
    : pGuitarFineTuneLookAndFeel(pGFTAF)
    , pXmlGuitarFineTuneConfig(pXmlGFTConfig)
    , DocumentWindow("Variable Tone Control", Colour(0xFF2B0720), DocumentWindow::allButtons)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    FrequenceSlider.reset (new juce::Slider ("FrequenceSlider"));
    //addAndMakeVisible (FrequenceSlider.get());
    FrequenceSlider->setRange (0, 20000, 0);
    FrequenceSlider->setSliderStyle (juce::Slider::LinearVertical);
    FrequenceSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    FrequenceSlider->addListener (this);

    FrequenceSlider->setBounds (0, 0, 150, 448);


    //[UserPreSize]
    setContentOwned(FrequenceSlider.get(), true);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

eksVariableToneCtrl::~eksVariableToneCtrl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
        //FrequenceSlider->removeListener(this);
        //FrequenceSlider = nullptr;
    //[/Destructor_pre]

    //FrequenceSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void eksVariableToneCtrl::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff2b0720));

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

void eksVariableToneCtrl::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == FrequenceSlider.get())
    {
        //[UserSliderCode_FrequenceSlider] -- add your slider handling code here..
        //[/UserSliderCode_FrequenceSlider]
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
                 parentClasses="public juce::Component" constructorParams="std::shared_ptr&lt;tuneComponent&gt; pTC, std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTConfig, std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF, bool addVWP"
                 variableInitialisers="pGuitarFineTuneLookAndFeel(pGFTAF),&#10;pTuneComponent(pTC),&#10;spAudioRecorderController(pTC-&gt;getAudioRecorderController()),&#10;pXmlGuitarFineTuneConfig(pXmlGFTConfig),&#10;viewPortAdded(addVWP)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff2b0720"/>
  <SLIDER name="FrequenceSlider" id="b44be89bb3688130" memberName="FrequenceSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0 150 448" min="0.0"
          max="20000.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

