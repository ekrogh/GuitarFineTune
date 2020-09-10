/*
  ==============================================================================

	eksThreadWithProgressWindow.cpp
	Created: 25 May 2017 2:52:05pm
	Author:  eks

	==============================================================================
	Copy of
	JUCE::ThreadWithProgressWindow
	with the difference, that the Window Is Not Modal.
	And some other stuff

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "eksThreadWithProgressWindow.h"


eksThreadWithProgressWindow::eksThreadWithProgressWindow
(
	const std::string& windowTitle
	, bool hasProgressBar
	, bool hasButton
	, const std::string& buttonText
	, int timeOutWhenButtonPressed
	, Component* componentToCentreAround
)
	: Thread("eksThreadWithProgressWindow")
	, progress(0.0)
	, timeOutMsWhenFromButtonPressed(timeOutWhenButtonPressed)
	, windowHasButton(hasButton)
{
	alertWindow.reset
		(
			LookAndFeel::getDefaultLookAndFeel().createAlertWindow
			(
				windowTitle, String(),
				buttonText == "" ? TRANS("Cancel")
				: String(buttonText),
				String(), String(),
				AlertWindow::NoIcon, hasButton ? 1 : 0,
				componentToCentreAround
			)
		);

	// if there are no buttons, we won't allow the user to interrupt the thread.
	alertWindow->setEscapeKeyCancels(false);

	if (hasProgressBar)
		alertWindow->addProgressBarComponent(progress);

}

eksThreadWithProgressWindow::~eksThreadWithProgressWindow()
{
	stopNow = true;
	stopThread(timeOutMsWhenFromButtonPressed);
}


void eksThreadWithProgressWindow::launchWindow()
{
	startTimer(100);

	{ // Start scope for const ScopedLock sl(messageLock);
		const ScopedLock sl(messageLock);

		// Set colors
		alertWindow->setColour(AlertWindow::textColourId, Colours::cornflowerblue);
		alertWindow->setColour(AlertWindow::backgroundColourId, Colour(0xff20072b));
		
		int numChildComponents = alertWindow->getNumChildComponents();
		// Set progress bar colors.
		for (int i = 0; i < numChildComponents; ++i)
		{
			if (juce::ProgressBar* theProgressBar = dynamic_cast<juce::ProgressBar*> (alertWindow->getChildComponent(i)))
			{
				theProgressBar->setColour(ProgressBar::foregroundColourId, Colour(0xFF42A2C8));
				theProgressBar->setColour(ProgressBar::backgroundColourId, Colour(0xFF808080));
				break;
			}
		}
		// Set add this to button listner
		if (windowHasButton)
		{
			for (int i = 0; i < numChildComponents; ++i)
			{
				if (juce::TextButton* theTextButton = dynamic_cast<juce::TextButton*> (alertWindow->getChildComponent(i)))
				{
					theTextButton->addListener(this);
					break;
				}
			}
		}
		alertWindow->setMessage(message);
		alertWindow->setAlwaysOnTop(true);
		alertWindow->setVisible(true);
	}
}

void eksThreadWithProgressWindow::launchThread(int priority)
{
	jassert(MessageManager::getInstance()->isThisTheMessageThread());

	startThread(priority);
	threadWasStarted = true;

	launchWindow();
}

void eksThreadWithProgressWindow::setProgress(const double newProgress)
{
	progress = newProgress;
}

void eksThreadWithProgressWindow::setStatusMessage(const String& newStatusMessage)
{
	const ScopedLock sl(messageLock);
	message = newStatusMessage;
}

void eksThreadWithProgressWindow::timerCallback()
{
	if (threadWasStarted)
	{
		bool threadStillRunning = isThreadRunning();

		if (!threadStillRunning || stopNow)
		{
			stopTimer();
			stopThread(timeOutMsWhenFromButtonPressed);
			alertWindow->setVisible(false);

			threadComplete(buttonWasClicked);
			return; // (this may be deleted now)
		}
	}
	else
	{
		if (stopNow)
		{
			stopTimer();
			alertWindow->setVisible(false);
			threadComplete(buttonWasClicked);
			return; // (this may be deleted now)
		}
	}

	const ScopedLock sl(messageLock);
	alertWindow->setMessage(message);
}

void eksThreadWithProgressWindow::buttonClicked( Button* )
{
	stopNow = true;
	buttonWasClicked = true;
}


void eksThreadWithProgressWindow::stopAll()
{
	stopNow = true;
	buttonWasClicked = false;
}
