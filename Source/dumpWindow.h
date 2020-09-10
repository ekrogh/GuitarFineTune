/*
  ==============================================================================

    dumpWindow.h
    Created: 4 Jul 2017 1:51:41pm
    Author:  eks

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================

class dumpWindow
	: public DocumentWindow
{
public:
	//==============================================================================
	dumpWindow();
	~dumpWindow();

	void paint(Graphics& g) override;
	void resized() override;

	void closeButtonPressed() override;

private:
	//==============================================================================
	ScopedPointer<TextEditor> dumpWindowTextEditor;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(dumpWindow)
};
