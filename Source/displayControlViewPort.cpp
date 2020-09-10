/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "displayControlComponent.h"
//[/Headers]

#include "displayControlViewPort.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
displayControlViewPort::displayControlViewPort (std::shared_ptr<displayControlComponent> pDCC )
    : rDisplayControlComponent(*(pDCC.get()))
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (viewport = new Viewport ("new viewport"));
    viewport->setScrollBarsShown (true, false);
    viewport->setScrollBarThickness (20);

    viewport->setBounds (0, 0, 376, 240);


    //[UserPreSize]
	viewport->setViewedComponent(pDCC.get());
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	viewport->setScrollOnDragEnabled(true);
    //[/Constructor]
}

displayControlViewPort::~displayControlViewPort()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    viewport = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void displayControlViewPort::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
   g.fillAll (Colour (0xff20072b));
    //[/UserPaint]
}

void displayControlViewPort::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
#if JUCE_IOS || JUCE_ANDROID
// Set bounds for this
	Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    viewport->setSize(viewport->getWidth(), r.getHeight());
    viewport->setScrollBarThickness (20);
	setSize(getWidth(), r.getHeight());
	//if (r.getWidth() > r.getHeight())
	//{
	//	viewport->setBounds(r.getX(), r.getY(), rDisplayControlComponent.getWidth() + 10, (r.getHeight()) / 2);
 //       rDisplayControlComponent.setSize(viewport->getMaximumVisibleWidth(), hightOfDisplayControlWindow);
	//}
	//else
	//{
	//	viewport->setBounds(r.getX(), r.getY(), r.getWidth(), (r.getHeight()) / 2);
 //       rDisplayControlComponent.setSize(viewport->getMaximumVisibleWidth(), hightOfDisplayControlWindow);
	//}
#endif
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

<JUCER_COMPONENT documentType="Component" className="displayControlViewPort" componentName=""
                 parentClasses="public Component" constructorParams="std::shared_ptr&lt;displayControlComponent&gt; pDCC "
                 variableInitialisers="rDisplayControlComponent(*(pDCC.get()))"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <VIEWPORT name="new viewport" id="c3fa20f550df0802" memberName="viewport"
            virtualName="" explicitFocusOrder="0" pos="0 0 376 240" vscroll="1"
            hscroll="0" scrollbarThickness="20" contentType="0" jucerFile=""
            contentClass="displayControlComponent" constructorParams="pTC, pXmlGFTConfig"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
