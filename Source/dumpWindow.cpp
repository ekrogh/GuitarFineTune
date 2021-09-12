/*
  ==============================================================================

    dumpWindow.cpp
    Created: 4 Jul 2017 1:51:41pm
    Author:  eks

  ==============================================================================
*/

#include "dumpWindow.h"

dumpWindow::dumpWindow()
	: DocumentWindow("dump", Colours::lightgrey, DocumentWindow::allButtons)
{
	dumpWindowTextEditor = new TextEditor();
	dumpWindowTextEditor->setMultiLine(true);
	dumpWindowTextEditor->setReturnKeyStartsNewLine(true);
	dumpWindowTextEditor->setReadOnly(false);
	dumpWindowTextEditor->setScrollbarsShown(true);
	dumpWindowTextEditor->setCaretVisible(true);
	dumpWindowTextEditor->setPopupMenuEnabled(true);
	dumpWindowTextEditor->setText(TRANS("Dette er en text\n"));
	dumpWindowTextEditor->setBounds(2, 2, 343, 319);
	
	setContentOwned(dumpWindowTextEditor, true);

	setUsingNativeTitleBar(true);
#if JUCE_MAC || JUCE_LINUX
	setTitleBarButtonsRequired(closeButton | minimiseButton, true);
#else // JUCE_WINDOWS
	setTitleBarButtonsRequired(closeButton | minimiseButton, false);
#endif // JUCE_MAC || JUCE_LINUX
	DocumentWindow::centreWithSize(350, 330);
	DocumentWindow::setVisible(true);


}

dumpWindow::~dumpWindow()
{
	dumpWindowTextEditor = nullptr;
}

//==============================================================================
void dumpWindow::paint(Graphics& g)
{
	g.fillAll(Colour(0xff20072b));
}

void dumpWindow::resized()
{
	dumpWindowTextEditor->setBounds(2, 2, 343, 319);
}

void dumpWindow::closeButtonPressed()
{
	delete this;
}
