/*
  ==============================================================================

	eksTabbedComponent.cpp
	Created: 27 Jun 2016 8:17:08pm
	Author:  eks

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "displayControlComponent.h"
#include "guitarFineTuneFirstClass.h"
#include "eksTabbedComponent.h"

//==============================================================================
eksTabbedComponent::eksTabbedComponent
(
	Component::SafePointer<guitarFineTuneFirstClass> pGuitarFineTuneFirstClass
)
	: TabbedComponent(TabbedButtonBar::TabsAtTop)
	, ptrGuitarFineTuneFirstClass(pGuitarFineTuneFirstClass)
{
#if (JUCE_IOS || JUCE_ANDROID)
	auto safeArea = Desktop::getInstance().getDisplays().getPrimaryDisplay()->safeAreaInsets;
	if (getWidth() < getHeight())
	{
		setTabBarDepth (jmax ((int) tabBarDepthAndroidIosInVertical, safeArea.getTop() + 10));
	}
	else
	{
		setTabBarDepth (jmax ((int) tabBarDepthAndroidIosInHorizontal, safeArea.getTop() + 5));
	}
	setIndent(safeArea.getLeft());
#else
	setTabBarDepth(tabBarDepthMacWin);
#endif // #if (JUCE_IOS || JUCE_ANDROID)
}

void eksTabbedComponent::currentTabChanged(int newCurrentTabIndex, const String& newCurrentTabName)
{
    ptrGuitarFineTuneFirstClass->currentTabChanged(newCurrentTabIndex, newCurrentTabName);
}


eksTabbedComponent::~eksTabbedComponent()
{
}

//#if (JUCE_IOS)
//void eksTabbedComponent::resized()
//{
//	curCompntBnds = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userArea;
//	if (curCompntBnds.getHeight() >= curCompntBnds.getWidth())
//	{
//		curCompntBnds.reduce(0, iOSSafeMargin);
//	}
//	else
//	{
//		curCompntBnds.removeFromLeft(iOSSafeMargin);
//		curCompntBnds.removeFromRight(iOSSafeMargin);
//
//	}
//    setSize(curCompntBnds.getWidth(), curCompntBnds.getHeight());
//	setBounds(curCompntBnds);
//}
//#endif
