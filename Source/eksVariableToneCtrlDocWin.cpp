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
//[/Headers]

#include "eksVariableToneCtrlDocWin.h"
#include "eksVariableToneCtrl.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
eksVariableToneCtrlDocWin::eksVariableToneCtrlDocWin(std::shared_ptr<xmlGuitarFineTuneConfig> pXmlGFTConfig, std::shared_ptr<eksLookAndFeel> pGFTAF)
	: DocumentWindow("Variable Tone Control", Colour(0xFF2B0720), DocumentWindow::allButtons)
{
	//[Constructor_pre] You can add your own custom stuff here..
	spEksVariableToneCtrl = std::make_shared <eksVariableToneCtrl>(pXmlGFTConfig, pGFTAF);
	setContentOwned(spEksVariableToneCtrl.get(), false);
	//[/Constructor_pre]


	//[UserPreSize]
	//[/UserPreSize]

	setSize(350, 450);


	//[Constructor] You can add your own custom stuff here..
	//[/Constructor]
}

eksVariableToneCtrlDocWin::~eksVariableToneCtrlDocWin()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//[/Destructor_pre]



	//[Destructor]. You can add your own custom destruction code here..
	//[/Destructor]
}

//==============================================================================
void eksVariableToneCtrlDocWin::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff505050));

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void eksVariableToneCtrlDocWin::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
	//[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="eksVariableToneCtrlDocWin"
				 componentName="" parentClasses="public juce::DocumentWindow"
				 constructorParams="std::shared_ptr&lt;xmlGuitarFineTuneConfig&gt; pXmlGFTConfig, std::shared_ptr&lt;eksLookAndFeel&gt; pGFTAF"
				 variableInitialisers="DocumentWindow(&quot;Variable Tone Control&quot;, Colour(0xFF2B0720), DocumentWindow::allButtons)"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff505050"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

