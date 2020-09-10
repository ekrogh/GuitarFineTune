/*
  ==============================================================================

    eksTabbedComponent.h
    Created: 27 Jun 2016 8:17:08pm
    Author:  eks

  ==============================================================================
*/

#ifndef EKSTABBEDCOMPONENT_H_INCLUDED
#define EKSTABBEDCOMPONENT_H_INCLUDED

class xmlGuitarFineTuneConfig;
class guitarFineTuneFirstClass;

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/

class eksTabbedComponent
	: public TabbedComponent
{
public:
    eksTabbedComponent
    (
        Component::SafePointer<guitarFineTuneFirstClass> pGuitarFineTuneFirstClass
    );
    ~eksTabbedComponent();
	
//#if (JUCE_IOS)
//	void resized() override;
//#endif

	void currentTabChanged(int newCurrentTabIndex, const String& newCurrentTabName) override;

private:
    juce::Rectangle<int> curCompntBnds;

    Component::SafePointer<guitarFineTuneFirstClass> ptrGuitarFineTuneFirstClass;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(eksTabbedComponent)
};


#endif  // EKSTABBEDCOMPONENT_H_INCLUDED
