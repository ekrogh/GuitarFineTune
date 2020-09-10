/*
  ==============================================================================

	guitarFineTuneFirstClass.cpp
	Created: 27 Jun 2016 8:08:09pm
	Author:  eks

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#include "eksLookAndFeel.h"
#include "eksAudioControlComponent.h"
#include "helpPage.h"
#include "displayControlComponent.h"
#include "tuneComponent.h"
#include "guitarStringSoundsControl.h"
#include "displayControlComponent.h"
#include "guitarFineTuneGlobalEnums.h"
#include "eksTabbedComponent.h"
#include "xmlGuitarFineTuneConfig.h"
#include "guitarFineTuneFirstClass.h"


//==============================================================================
guitarFineTuneFirstClass::guitarFineTuneFirstClass()
	: DocumentWindow(std::string(ProjectInfo::projectName) + " v. " + std::string(ProjectInfo::versionString), Colours::lightgrey, DocumentWindow::allButtons)

#if (JUCE_IOS || JUCE_ANDROID)
	, curCompntBnds(0, 40, widthOfTuneWindow, hightOfTuneWindow - 40)
#else
	, curCompntBnds(16, 8, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin)
#endif
{
#if (JUCE_ANDROID)
	// Add viewport ?
	Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
	if
		(
		((r.getWidth() < r.getHeight()) && (r.getWidth() < 360 || r.getHeight() < 533))
			|| ((r.getWidth() > r.getHeight()) && (r.getWidth() < 533 || r.getHeight() < 338))
			)
	{
		addViewPort = true;
	}
	else
	{
		addViewPort = false;
	}
#else // (JUCE_ANDROID)
	addViewPort = false;
#endif // (JUCE_ANDROID)

	// Look and Feel first
	pGuitarFineTuneLookAndFeel = std::make_shared<eksLookAndFeel>(addViewPort);

	// Instantiate clases
	// Open config from xml file
	pXmlGuitarFineTuneConfig = std::make_shared<xmlGuitarFineTuneConfig>();
	// Tabs
	pEksTabbedComponent = std::make_shared<eksTabbedComponent>(this);
	pTuneComponent = std::make_shared<tuneComponent>(pXmlGuitarFineTuneConfig);

	pGuitarStringSoundsControl = std::make_shared<guitarStringSoundsControl>
		(
			pTuneComponent
			, pXmlGuitarFineTuneConfig
			, pGuitarFineTuneLookAndFeel
			, addViewPort
		);
	pDisplayControlComponent = std::make_shared<displayControlComponent>
		(
			pTuneComponent
			, pXmlGuitarFineTuneConfig
			, pGuitarFineTuneLookAndFeel
			, addViewPort
		);
	pEksAudioControlComponent = std::make_shared<eksAudioControlComponent>
		(
			pTuneComponent
			, pXmlGuitarFineTuneConfig
			, pGuitarFineTuneLookAndFeel
			, addViewPort
		);
	pAboutPage = std::make_shared<aboutPage>();

	pEksTabbedComponent->addTab
	(
		TRANS("Tune")
		, Colour(0xFF20072B)
		, pTuneComponent.get()
		, true, tabNoTuneWindow
	);

#if (JUCE_ANDROID)
// Add viewport ?
	if (addViewPort)
	{
			addViewPort = true;

			// Place controls in ViewPorts
			pGuitarStringSoundsControlViewPort = std::make_shared<Viewport>("pGuitarStringSoundsControlViewPort");
			pGuitarStringSoundsControlViewPort->setScrollBarsShown(true, true);
			pGuitarStringSoundsControlViewPort->setScrollBarThickness(10);
			pGuitarStringSoundsControlViewPort->setViewedComponent(pGuitarStringSoundsControl.get());
			pGuitarStringSoundsControlViewPort->setScrollOnDragEnabled(true);
			pDisplayControlComponentViewPort = std::make_shared<Viewport>("pDisplayControlComponentViewPort");
			pDisplayControlComponentViewPort->setScrollBarsShown(true, true);
			pDisplayControlComponentViewPort->setScrollBarThickness(10);
			pDisplayControlComponentViewPort->setViewedComponent(pDisplayControlComponent.get());
			pDisplayControlComponentViewPort->setScrollOnDragEnabled(true);
			pEksAudioControlComponentViewPort = std::make_shared<Viewport>("pEksAudioControlComponentViewPort");
			pEksAudioControlComponentViewPort->setScrollBarsShown(true, true);
			pEksAudioControlComponentViewPort->setScrollBarThickness(10);
			pEksAudioControlComponentViewPort->setViewedComponent(pEksAudioControlComponent.get());
			pEksAudioControlComponentViewPort->setScrollOnDragEnabled(true);

			pEksTabbedComponent->addTab
			(
				TRANS("Sound Control")
				, Colour(0xFF20072B)
				, pGuitarStringSoundsControlViewPort.get()
				, true, tabNoGuitarStringSoundsControlWindow
			);

			pEksTabbedComponent->addTab
			(
				TRANS("Display Control")
				, Colour(0xFF20072B)
				, pDisplayControlComponentViewPort.get()
				, true, tabNoDisplayControlWindow);
			setColorOfAllLabels(pDisplayControlComponent.get());

			// put ViewPorts in Tabbed Component
			pEksTabbedComponent->addTab
			(
				TRANS("Audio Control")
				, Colour(0xFF20072B)
				, pEksAudioControlComponentViewPort.get()
				, true, tabNoEksAudioControlComponent
			);
	}
	else
	{
		// No ViewPorts
#endif // (JUCE_ANDROID)
		pEksTabbedComponent->addTab
		(
			TRANS("Sound Control")
			, Colour(0xFF20072B)
			, pGuitarStringSoundsControl.get()
			, true, tabNoGuitarStringSoundsControlWindow
		);

		pEksTabbedComponent->addTab
		(
			TRANS("Display Control")
			, Colour(0xFF20072B)
			, pDisplayControlComponent.get()
			, true, tabNoDisplayControlWindow);
		setColorOfAllLabels(pDisplayControlComponent.get());

		pEksTabbedComponent->addTab
		(
			TRANS("Audio Control")
			, Colour(0xFF20072B)
			, pEksAudioControlComponent.get()
			, true, tabNoEksAudioControlComponent
		);

#if (JUCE_ANDROID)
	}
#endif // (JUCE_ANDROID)

	pEksTabbedComponent->addTab
	(
		TRANS("Help")
		, Colour(0xFF20072B)
		, pAboutPage.get()
		, true, tabNoAboutPage
	);
	setColorOfAllLabels(pAboutPage.get());

	pEksTabbedComponent->setCurrentTabIndex(tabNoTuneWindow);


	bGoSetSizes = true;

	pTuneComponent->initObjects(pDisplayControlComponent);
//	pDisplayControlComponent->initControls();

#if JUCE_WINDOWS || JUCE_MAC
	curCompntBnds.setBounds(0, 0, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin);
	setSize(curCompntBnds.getWidth(), curCompntBnds.getHeight()); // This
	DocumentWindow::centreWithSize(widthOfGuitarStringSoundsControlWindowHorizontal, hightOfGuitarStringSoundsControlWindowHorizontal);
#elif (JUCE_IOS || JUCE_ANDROID)
	curCompntBnds = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    if  (curCompntBnds.getHeight() >= curCompntBnds.getWidth())
    {
//    curCompntBnds.removeFromTop(40);
        curCompntBnds.reduce(0, 40);
    }
    else
    {
        curCompntBnds.removeFromLeft(40);
        curCompntBnds.removeFromRight(40);
    }
#endif
	setUsingNativeTitleBar(true);
#if JUCE_MAC
	setTitleBarButtonsRequired(closeButton | minimiseButton, true);
#else // JUCE_WINDOWS
	setTitleBarButtonsRequired(closeButton | minimiseButton, false);
#endif // JUCE_MAC
	setResizable(false, false);
	//	setResizable(true, true);
	DocumentWindow::setVisible(true);
	setContentOwned(pEksTabbedComponent.get(), true);

	pEksAudioControlComponent->resized();

	setLookAndFeel(pGuitarFineTuneLookAndFeel.get());

	pDisplayControlComponent->initControls();
}

void guitarFineTuneFirstClass::currentTabChanged(int newCurrentTabIndex, const String& /*newCurrentTabName*/)
{
	currentTabIndex = newCurrentTabIndex;

	if (bGoSetSizes)
	{
#if (JUCE_IOS || JUCE_ANDROID)
		curCompntBnds = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
#else
		switch (newCurrentTabIndex)
		{
			case tabNoTuneWindow:
			{
				curCompntBnds.setBounds(0, 0, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin);
				break;
			}
			case tabNoEksAudioControlComponent:
			{
				curCompntBnds.setBounds(0, 0, widthOfEksAudioControlComponentWindow, hightOfEksAudioControlComponentWindow);
				break;
			}
			case tabNoGuitarStringSoundsControlWindow:
			{
				Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
				if (r.getWidth() >= r.getHeight())
				{
					curCompntBnds.setBounds(0, 0, widthOfGuitarStringSoundsControlWindowHorizontal, hightOfGuitarStringSoundsControlWindowHorizontal);
				}
				else
				{
					curCompntBnds.setBounds(0, 0, widthOfGuitarStringSoundsControlWindowVertical, hightOfGuitarStringSoundsControlWindowVertical);
				}
				break;
			}
			case tabNoDisplayControlWindow:
			{
				Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
				if (r.getWidth() >= r.getHeight())
				{
					//Horizontal
					curCompntBnds.setBounds(0, 0, widthOfDisplayControlWindowHorizontal, hightOfDisplayControlWindowHorizontal);
				}
				else
				{
					// Vertical
					curCompntBnds.setBounds(0, 0, widthOfDisplayControlWindowVertical, hightOfDisplayControlWindowVertical);
				}
				break;
			}
			case tabNoAboutPage:
			{
				curCompntBnds.setBounds(0, 0, widthOfAboutPage, hightOfAboutPage);
				break;
			}
			default:
			{
				break;
			}
		}

		setSize(curCompntBnds.getWidth(), curCompntBnds.getHeight()); // This
#endif

		resized();
	}
}

void guitarFineTuneFirstClass::paint(Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(Colours::white);

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

#if (JUCE_IOS || JUCE_ANDROID)
void guitarFineTuneFirstClass::parentSizeChanged()
{
	currentTabChanged(pEksTabbedComponent->getCurrentTabIndex(), "");
}
#endif

#if (JUCE_IOS || JUCE_ANDROID)
float guitarFineTuneFirstClass::scaleToGuitarStringSoundsControlWindow()
{
	float bndsScaleHoriz;
	float bndsScaleVerti;
	float scaleNow;
	if (curCompntBnds.getWidth() >= curCompntBnds.getHeight())
	{
		// Horizontal
		bndsScaleHoriz = (float)(curCompntBnds.getWidth()) / (float)(widthOfGuitarStringSoundsControlWindowHorizontal);
		bndsScaleVerti = ((float)(curCompntBnds.getHeight())
			- (float)tabBarDepthAndroidIosInHorizontal) / ((float)(hightOfGuitarStringSoundsControlWindowHorizontal));
		if (bndsScaleHoriz < bndsScaleVerti)
		{
			scaleNow = bndsScaleHoriz;
		}
		else
		{
			scaleNow = bndsScaleVerti;
		}
		pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInHorizontal * scaleNow);
	}
	else
	{
		// Vertical
		bndsScaleHoriz = (float)(curCompntBnds.getWidth()) / (float)(widthOfGuitarStringSoundsControlWindowVertical);
		bndsScaleVerti = ((float)(curCompntBnds.getHeight())
			- (float)tabBarDepthAndroidIosInVertical) / ((float)(hightOfGuitarStringSoundsControlWindowVertical + 1));
		if (bndsScaleHoriz < bndsScaleVerti)
		{
			scaleNow = bndsScaleHoriz;
		}
		else
		{
			scaleNow = bndsScaleVerti;
		}
		pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInVertical * scaleNow);
	}

	return scaleNow;
}
#endif // (JUCE_IOS || JUCE_ANDROID)

void guitarFineTuneFirstClass::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	pEksTabbedComponent->setBounds(curCompntBnds);
#if (JUCE_IOS || JUCE_ANDROID)
	setBounds(curCompntBnds);
	if (!addViewPort)
	{
		DocumentWindow::setBounds(curCompntBnds);

		float bndsScaleHoriz;
		float bndsScaleVerti;
		float scaleNow;
		switch (currentTabIndex)
		{
			case tabNoTuneWindow:
				{
					scaleToGuitarStringSoundsControlWindow();
					break;
				}
			case tabNoGuitarStringSoundsControlWindow:
				{
					scaleNow = scaleToGuitarStringSoundsControlWindow();
					pGuitarFineTuneLookAndFeel->scaleEksLookAndFeelFonts(scaleNow);
					pGuitarFineTuneLookAndFeel->scaleAllsliderTextBoxes(scaleNow);
					pGuitarStringSoundsControl->scaleAllComponents();
					break;
				}
			case tabNoDisplayControlWindow:
				{
					if (curCompntBnds.getWidth() >= curCompntBnds.getHeight())
					{
						// Horizontal
						bndsScaleHoriz = (float)(curCompntBnds.getWidth()) / (float)(widthOfDisplayControlWindowHorizontal);
						bndsScaleVerti = ((float)(curCompntBnds.getHeight())
							- (float)tabBarDepthAndroidIosInHorizontal) / ((float)(hightOfDisplayControlWindowHorizontal));
						if (bndsScaleHoriz < bndsScaleVerti)
						{
							scaleNow = bndsScaleHoriz;
						}
						else
						{
							scaleNow = bndsScaleVerti;
						}
						pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInHorizontal * scaleNow);
					}
					else
					{
						// Vertical
						bndsScaleHoriz = (float)(curCompntBnds.getWidth()) / (float)(widthOfDisplayControlWindowVertical);
						bndsScaleVerti = ((float)(curCompntBnds.getHeight())
							- (float)tabBarDepthAndroidIosInVertical) / ((float)(hightOfDisplayControlWindowVertical + 1));
						if (bndsScaleHoriz < bndsScaleVerti)
						{
							scaleNow = bndsScaleHoriz;
						}
						else
						{
							scaleNow = bndsScaleVerti;
						}
						pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInVertical * scaleNow);
					}
					pGuitarFineTuneLookAndFeel->scaleEksLookAndFeelFonts(scaleNow);
					pGuitarFineTuneLookAndFeel->scaleAllsliderTextBoxes(scaleNow);
					pDisplayControlComponent->scaleAllComponents();
					break;
				}
			case tabNoEksAudioControlComponent:
				{
					bndsScaleHoriz = (float)(curCompntBnds.getWidth()) / (float)(widthOfEksAudioControlComponentWindow);
					bndsScaleVerti = ((float)(curCompntBnds.getHeight())
						- (float)tabBarDepthAndroidIosInHorizontal) / ((float)(hightOfEksAudioControlComponentWindow));
					if (bndsScaleHoriz < bndsScaleVerti)
					{
						scaleNow = bndsScaleHoriz;
					}
					else
					{
						scaleNow = bndsScaleVerti;
					}
					if (curCompntBnds.getWidth() >= curCompntBnds.getHeight())
					{
						// Horizontal
						pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInHorizontal * scaleNow);
					}
					else
					{
						// Vertical
						pEksTabbedComponent->setTabBarDepth(tabBarDepthAndroidIosInVertical * scaleNow);
					}
					pGuitarFineTuneLookAndFeel->scaleEksLookAndFeelFonts(scaleNow);
					pGuitarFineTuneLookAndFeel->scaleAllsliderTextBoxes(scaleNow);
					pEksAudioControlComponent->scaleAllComponents();
					break;
				}
			case tabNoAboutPage:
				{
					scaleNow = scaleToGuitarStringSoundsControlWindow();
					pGuitarFineTuneLookAndFeel->scaleEksLookAndFeelFonts(scaleNow);
					pGuitarFineTuneLookAndFeel->scaleAllsliderTextBoxes(scaleNow);
					pAboutPage->scaleAllComponents();
					break;
				}
			default:
				{
					break;
				}
		}
	}
#endif // (JUCE_IOS || JUCE_ANDROID)
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
	DocumentWindow::resized();
//	pEksTabbedComponent->resized();
	//[/UserResized]
}

void guitarFineTuneFirstClass::closeButtonPressed()
{
	// This is called when the user tries to close this window. Here, we'll just
	// ask the app to quit when this happens, but you can change this to do
	// whatever you need.
	JUCEApplication::getInstance()->systemRequestedQuit();
}

guitarFineTuneFirstClass::~guitarFineTuneFirstClass()
{
	Component::setLookAndFeel(nullptr);
	LookAndFeel::setDefaultLookAndFeel(nullptr);
}

void guitarFineTuneFirstClass::setColorOfAllLabels(juce::Component* cmpontToHandle)
{
	int numChildComponents = cmpontToHandle->getNumChildComponents();

	if (numChildComponents == 0)
	{
		juce::Label* testLabel = dynamic_cast<juce::Label*> (cmpontToHandle);

		if (testLabel != nullptr)
		{
			cmpontToHandle->setColour(labelTextColorId, labelColor);
		}
	}
	else
	{
		for (int i = 0; i < numChildComponents; ++i)
		{
			if (Component* childComponent = cmpontToHandle->getChildComponent(i))
			{
				setColorOfAllLabels(childComponent);
			}
		}
	}
}
