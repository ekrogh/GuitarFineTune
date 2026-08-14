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
#include "guitarFineTuneGlobalEnums.h"
#include "eksTabbedComponent.h"
#include "xmlGuitarFineTuneConfig.h"
#include "guitarFineTuneFirstClass.h"

#include <thread>         // std::this_thread::sleep_for

//==============================================================================
// Init audio
//==============================================================================
bool errorInGetSharedAudioDeviceManager = false;
std::unique_ptr<AudioDeviceManager> sharedAudioDeviceManager = nullptr;
std::unique_ptr<tuneComponent> pTuneComponent = nullptr;

bool audioSysInitDone = false;

static String getCurrentDefaultAudioDeviceName(AudioDeviceManager& deviceManager, bool isInput)
{
	auto* deviceType = deviceManager.getCurrentDeviceTypeObject();
	jassert(deviceType != nullptr);

	if (deviceType != nullptr)
	{
		auto deviceNames = deviceType->getDeviceNames();
		return deviceNames[deviceType->getDefaultDeviceIndex(isInput)];
	}

	return {};
}


// (returns a shared AudioDeviceManager object that all the can use)
static AudioDeviceManager& getSharedAudioDeviceManager(int numInputChannels, int numOutputChannels)
{
	if (sharedAudioDeviceManager == nullptr)
		sharedAudioDeviceManager = make_unique<AudioDeviceManager>();

	auto* currentDevice = sharedAudioDeviceManager->getCurrentAudioDevice();

	const OwnedArray<AudioIODeviceType>& availableDeviceTypes = sharedAudioDeviceManager->getAvailableDeviceTypes();
	StringArray availableDeviceTypesNames;
	for (auto availableDeviceType : availableDeviceTypes)
	{
		availableDeviceTypesNames.add(availableDeviceType->getTypeName());
	}

	int directSoundIndex = -1;
	if ((directSoundIndex = availableDeviceTypesNames.indexOf("DirectSound")) >= 0)
	{
		sharedAudioDeviceManager->setCurrentAudioDeviceType(availableDeviceTypesNames[directSoundIndex], true);
	}

	if (numInputChannels < 0)
		numInputChannels = (currentDevice != nullptr ? currentDevice->getActiveInputChannels().countNumberOfSetBits() : 1);

	if (numOutputChannels < 0)
		numOutputChannels = (currentDevice != nullptr ? currentDevice->getActiveOutputChannels().countNumberOfSetBits() : 2);


	if (!RuntimePermissions::isGranted(RuntimePermissions::recordAudio))
	{
		if (numInputChannels > 0)
		{
			audioSysInitDone = true;
			RuntimePermissions::request(RuntimePermissions::recordAudio,
				[numInputChannels, numOutputChannels](bool granted)
			{
				if (granted)
				{
					getSharedAudioDeviceManager(numInputChannels, numOutputChannels);
					errorInGetSharedAudioDeviceManager = !(pTuneComponent->audioSysInit());
				}
				else
				{
					errorInGetSharedAudioDeviceManager = true;
					JUCEApplication::getInstance()->systemRequestedQuit();
					return;
				}
			});

			numInputChannels = 0;
		}
	}
	else
	{
		if (!audioSysInitDone)
		{
			errorInGetSharedAudioDeviceManager = !(pTuneComponent->audioSysInit());

			audioSysInitDone = true;
		}
	}

	if (sharedAudioDeviceManager->getCurrentAudioDevice() != nullptr)
	{
		auto setup = sharedAudioDeviceManager->getAudioDeviceSetup();

		auto numInputs = jmax(numInputChannels, setup.inputChannels.countNumberOfSetBits());
		auto numOutputs = jmax(numOutputChannels, setup.outputChannels.countNumberOfSetBits());

		auto oldInputs = setup.inputChannels.countNumberOfSetBits();
		auto oldOutputs = setup.outputChannels.countNumberOfSetBits();

		if (oldInputs != numInputs || oldOutputs != numOutputs || oldInputs == 0)
		{
			if ((sharedAudioDeviceManager->initialise(numInputChannels, numOutputChannels, nullptr, true, {}, nullptr)).isNotEmpty())
			{
				errorInGetSharedAudioDeviceManager = true;
				return *sharedAudioDeviceManager;
			}
			else
			{
				setup.useDefaultInputChannels = setup.useDefaultOutputChannels = false;

				setup.inputChannels.clear();
				setup.outputChannels.clear();

				setup.inputChannels.setRange(0, numInputs, true);
				setup.outputChannels.setRange(0, numOutputs, true);

				if (oldInputs == 0 && numInputs > 0 && setup.inputDeviceName.isEmpty())
					setup.inputDeviceName = getCurrentDefaultAudioDeviceName(*sharedAudioDeviceManager, true);

				if (oldOutputs == 0 && numOutputs > 0 && setup.outputDeviceName.isEmpty())
					setup.outputDeviceName = getCurrentDefaultAudioDeviceName(*sharedAudioDeviceManager, false);

				sharedAudioDeviceManager->setAudioDeviceSetup(setup, false);
			}
		}
	}
	else
	{
		if ((sharedAudioDeviceManager->initialise(numInputChannels, numOutputChannels, nullptr, true, {}, nullptr)).isNotEmpty())
		{
			errorInGetSharedAudioDeviceManager = true;
			return *sharedAudioDeviceManager;
		}

	}

	return *sharedAudioDeviceManager;
}
//==============================================================================
// End Init audio
//==============================================================================

//==============================================================================
guitarFineTuneFirstClass::guitarFineTuneFirstClass()
#if (JUCE_ANDROID)
	: DocumentWindow(std::string(ProjectInfo::projectName)
	+ " v. " + std::string(ProjectInfo::versionString)
	+ "." + std::to_string(ANDROID_VERSION_CODE)
	, Colour(0xFF20072B)
	, DocumentWindow::allButtons)
	, curCompntBnds(0, 0, 0, 0)
#else
	: DocumentWindow(std::string(ProjectInfo::projectName) + " v. " + std::string(ProjectInfo::versionString), Colours::lightgrey, DocumentWindow::allButtons)
#if (JUCE_IOS)
	, curCompntBnds(0, iOSSafeMargin, widthOfTuneWindow, hightOfTuneWindow - iOSSafeMargin)
#else
	, curCompntBnds(16, 8, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin)
#endif
#endif
{
	// make sharedAudioDeviceManager
	if (sharedAudioDeviceManager == nullptr)
	{
		sharedAudioDeviceManager = make_unique<AudioDeviceManager>();
	}


#if (JUCE_ANDROID)
	// Add viewport ?
	Rectangle<int> r = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userBounds.toNearestInt();
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

#if ( JUCE_IOS )
	{
		// Check if this is an old iPhone and no SafeMargin is required
		juce::String deviceDescription = SystemStats::getDeviceDescription();

		if ((deviceDescription.containsIgnoreCase("iPad")) || (noSafeZoneiPhoneiPads.count(deviceDescription.toStdString()) != 0))
		{
			thisIsASafeZoneiPhoneOriPad = false;
		}
		else
		{
			thisIsASafeZoneiPhoneOriPad = true;
		}
	}
#endif // #if ( JUCE_IOS )

	// Look and Feel first
	pGuitarFineTuneLookAndFeel = std::make_shared<eksLookAndFeel>(addViewPort);

	// Instantiate classes
	// Open config from xml file
	pXmlGuitarFineTuneConfig = std::make_shared<xmlGuitarFineTuneConfig>();
	// Tabs
	pEksTabbedComponent =
		std::make_shared<eksTabbedComponent>
		(
		SafePointer(this)
		);

#if ( JUCE_IOS )
	{
		pTuneComponent =
			std::make_unique<tuneComponent>
			(
			pXmlGuitarFineTuneConfig, SafePointer(this)
			);
	}
#else
	{
		pTuneComponent =
			std::make_unique<tuneComponent>
			(
			pXmlGuitarFineTuneConfig
			);
	}
#endif // #if ( JUCE_IOS )


	pGuitarStringSoundsControl = std::make_shared<guitarStringSoundsControl>
		(
		pXmlGuitarFineTuneConfig
		, pGuitarFineTuneLookAndFeel
		, addViewPort
		);
	pDisplayControlComponent = std::make_shared<displayControlComponent>
		(
		pXmlGuitarFineTuneConfig
		, pGuitarFineTuneLookAndFeel
		, addViewPort
		);
	pEksAudioControlComponent = std::make_shared<eksAudioControlComponent>
		(
		pXmlGuitarFineTuneConfig
		, pGuitarFineTuneLookAndFeel
		, addViewPort
		);
	pAboutPage = std::make_shared<aboutPage>();
	pAboutPage->setConfig(pXmlGuitarFineTuneConfig.get());

	pEksTabbedComponent->addTab
	(
		TRANS("Tune")
		, Colour(0xFF20072B)
		, pTuneComponent.get()
		, true, tabTuneWindow
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
		pGuitarStringSoundsControlViewPort->setScrollOnDragMode(juce::Viewport::ScrollOnDragMode::all);
		pDisplayControlComponentViewPort = std::make_shared<Viewport>("pDisplayControlComponentViewPort");
		pDisplayControlComponentViewPort->setScrollBarsShown(true, true);
		pDisplayControlComponentViewPort->setScrollBarThickness(10);
		pDisplayControlComponentViewPort->setViewedComponent(pDisplayControlComponent.get());
		pDisplayControlComponentViewPort->setScrollOnDragMode(juce::Viewport::ScrollOnDragMode::all);
		pEksAudioControlComponentViewPort = std::make_shared<Viewport>("pEksAudioControlComponentViewPort");
		pEksAudioControlComponentViewPort->setScrollBarsShown(true, true);
		pEksAudioControlComponentViewPort->setScrollBarThickness(10);
		pEksAudioControlComponentViewPort->setViewedComponent(pEksAudioControlComponent.get());
		pEksAudioControlComponentViewPort->setScrollOnDragMode(juce::Viewport::ScrollOnDragMode::all);

		pEksTabbedComponent->addTab
		(
			TRANS("Sound Control")
			, Colour(0xFF20072B)
			, pGuitarStringSoundsControlViewPort.get()
			, true, tabGuitarStringSoundsControlWindow
		);

		pEksTabbedComponent->addTab
		(
			TRANS("Display Control")
			, Colour(0xFF20072B)
			, pDisplayControlComponentViewPort.get()
			, true, tabDisplayControlWindow);
		setColorOfAllLabels(pDisplayControlComponent.get());

		// put ViewPorts in Tabbed Component
		pEksTabbedComponent->addTab
		(
			TRANS("Audio Control")
			, Colour(0xFF20072B)
			, pEksAudioControlComponentViewPort.get()
			, true, tabEksAudioControlComponent
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
			, true, tabGuitarStringSoundsControlWindow
		);

		pEksTabbedComponent->addTab
		(
			TRANS("Display Control")
			, Colour(0xFF20072B)
			, pDisplayControlComponent.get()
			, true, tabDisplayControlWindow);
		setColorOfAllLabels(pDisplayControlComponent.get());

		pEksTabbedComponent->addTab
		(
			TRANS("Audio Control")
			, Colour(0xFF20072B)
			, pEksAudioControlComponent.get()
			, true, tabEksAudioControlComponent
		);

	#if (JUCE_ANDROID)
	}
#endif // (JUCE_ANDROID)

	pEksTabbedComponent->addTab
	(
		TRANS("Help")
		, Colour(0xFF20072B)
		, pAboutPage.get()
		, true, tabAboutPage
	);
	setColorOfAllLabels(pAboutPage.get());

	pEksTabbedComponent->setCurrentTabIndex(tabTuneWindow);

	getSharedAudioDeviceManager(numInputChannels, numOutputChannels);

	if (!errorInGetSharedAudioDeviceManager)
	{
		bGoSetSizes = true;

		pTuneComponent->initObjects(pDisplayControlComponent);
		//	pDisplayControlComponent->initControls();

	#if (JUCE_WINDOWS || JUCE_MAC || JUCE_LINUX)
		curCompntBnds.setBounds(0, 0, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin);
		setSize(curCompntBnds.getWidth(), curCompntBnds.getHeight()); // This
		DocumentWindow::centreWithSize(widthOfGuitarStringSoundsControlWindowHorizontal, hightOfGuitarStringSoundsControlWindowHorizontal);
	#elif (JUCE_ANDROID || JUCE_IOS)
		setBounds (Desktop::getInstance().getDisplays().getPrimaryDisplay()->userBounds.toNearestInt());
		curCompntBnds = getLocalBounds();
	#endif
		setUsingNativeTitleBar(true);
	#if JUCE_MAC || JUCE_LINUX
		setTitleBarButtonsRequired(closeButton | minimiseButton, true);
	#else // JUCE_WINDOWS
		setTitleBarButtonsRequired(closeButton | minimiseButton, false);
	#endif // JUCE_MAC || JUCE_LINUX
		setResizable(false, false);
		//	setResizable(true, true);
		DocumentWindow::setVisible(true);

#if (JUCE_ANDROID || JUCE_IOS)
		Desktop::getInstance().setKioskModeComponent (this);
		setFullScreen (true);
		setContentOwned (pEksTabbedComponent.get(), false);
#else
		setContentOwned(pEksTabbedComponent.get(), true);
#endif

		setLookAndFeel(pGuitarFineTuneLookAndFeel.get());

		pDisplayControlComponent->initControls();
	}

}

void guitarFineTuneFirstClass::currentTabChanged(int newCurrentTabIndex, const String& /*newCurrentTabName*/)
{
	currentTabIndex = newCurrentTabIndex;

	if (bGoSetSizes)
	{

	#if ( JUCE_ANDROID || JUCE_IOS )
		// On mobile, the window stays full screen, just need to re-layout content.
	#else // (JUCE Win || JUCE_MAC || JUCE_LINUX)
		switch (newCurrentTabIndex)
		{
			case tabTuneWindow:
				{
					curCompntBnds.setBounds(0, 0, widthOfTuneWindow, hightOfTuneWindow + tabBarDepthMacWin);
					break;
				}
			case tabEksAudioControlComponent:
				{
					curCompntBnds.setBounds(0, 0, widthOfEksAudioControlComponentWindow, hightOfEksAudioControlComponentWindow);
					break;
				}
			case tabGuitarStringSoundsControlWindow:
				{
					Rectangle<int> r = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userBounds.toNearestInt();
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
			case tabDisplayControlWindow:
				{
					Rectangle<int> r = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userBounds.toNearestInt();
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
			case tabAboutPage:
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

bool guitarFineTuneFirstClass::isTabletDevice() const
{
	auto r = Desktop::getInstance().getDisplays().getPrimaryDisplay()->userBounds;
	return jmin (r.getWidth(), r.getHeight()) >= 600;
}

float guitarFineTuneFirstClass::getMasterScaleFactor() const
{
	// Zoom is only active if enabled in config
	bool enableZoom = false;
	if (auto* audioCtrl = pXmlGuitarFineTuneConfig->getGuitarfinetuneconfig().getChildByName ("AUDIOCONTROL"))
		enableZoom = audioCtrl->getBoolAttribute ("enableZoom");

	if (! enableZoom)
		return 1.0f;

	// Zoom is primarily for tablets as requested
	if (! isTabletDevice())
		return 1.0f;

	auto r = getLocalBounds();
	if (r.isEmpty()) return 1.0f;

	// Calculate scale based on how much larger the tablet is than a typical phone
	float baseline = 400.0f; // Typical phone short dimension
	float currentMin = (float) jmin (r.getWidth(), r.getHeight());

	return jlimit (1.0f, 2.0f, currentMin / baseline);
}

void guitarFineTuneFirstClass::resized()
{
	DocumentWindow::resized();

	auto safeArea = Desktop::getInstance().getDisplays().getPrimaryDisplay()->safeAreaInsets;
	curCompntBnds = getLocalBounds();

#if (JUCE_ANDROID || JUCE_IOS)
	curCompntBnds = safeArea.subtractedFrom (curCompntBnds);
#endif

	pEksTabbedComponent->setBounds (curCompntBnds);

#if (JUCE_IOS || JUCE_ANDROID)
	float scaleNow = getMasterScaleFactor();
	pGuitarFineTuneLookAndFeel->scaleEksLookAndFeelFonts (scaleNow);
	pGuitarFineTuneLookAndFeel->scaleAllsliderTextBoxes (scaleNow);

	// Propagate tab bar depth scale
	float baseTabDepth = (curCompntBnds.getWidth() >= curCompntBnds.getHeight()) ?
						 (float) tabBarDepthAndroidIosInHorizontal :
						 (float) tabBarDepthAndroidIosInVertical;
	pEksTabbedComponent->setTabBarDepth (baseTabDepth * scaleNow);
#endif

	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
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

	sharedAudioDeviceManager->closeAudioDevice();
	pEksAudioControlComponent = nullptr;
	pTuneComponent = nullptr;
	sharedAudioDeviceManager = nullptr;
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
