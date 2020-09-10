/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "dumpWindow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
dumpWindow::dumpWindow ()
    : DocumentWindow("dump", Colours::lightgrey, DocumentWindow::allButtons)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (dumpWindowTextEditor = new TextEditor ("dumpWindowTextEditor"));
    dumpWindowTextEditor->setMultiLine (true);
    dumpWindowTextEditor->setReturnKeyStartsNewLine (true);
    dumpWindowTextEditor->setReadOnly (false);
    dumpWindowTextEditor->setScrollbarsShown (true);
    dumpWindowTextEditor->setCaretVisible (true);
    dumpWindowTextEditor->setPopupMenuEnabled (true);
    dumpWindowTextEditor->setText (TRANS("Dette er en text\n"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	DocumentWindow::setVisible(true);
    //[/Constructor]
}

dumpWindow::~dumpWindow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    dumpWindowTextEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void dumpWindow::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff20072b));

    //[UserPaint] Add your own custom painting code here..
   g.fillAll (Colour (0xff20072b));
    //[/UserPaint]
}

void dumpWindow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    dumpWindowTextEditor->setBounds (2, 2, 343, 319);
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

<JUCER_COMPONENT documentType="Component" className="dumpWindow" componentName=""
                 parentClasses="public DocumentWindow" constructorParams="" variableInitialisers="DocumentWindow(&quot;dump&quot;, Colours::lightgrey, DocumentWindow::allButtons)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff20072b"/>
  <TEXTEDITOR name="dumpWindowTextEditor" id="e834d5ae234a7980" memberName="dumpWindowTextEditor"
              virtualName="" explicitFocusOrder="0" pos="2 2 343 319" initialText="Dette er en text&#10;"
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
