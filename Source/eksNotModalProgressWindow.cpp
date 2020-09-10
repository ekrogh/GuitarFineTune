/*
  ==============================================================================

	eksNotModalProgressWindow.cpp
	Created: 26 May 2017 5:29:48pm
	Author:  eks

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "eksThreadWithProgressWindow.h"
#include "eksNotModalProgressWindowCallBacks.h"
#include "eksNotModalProgressWindow.h"

//==============================================================================
eksNotModalProgressWindow::eksNotModalProgressWindow
(
	const std::string& msgToShow
	, const std::string& subMsgToShow
	, bool callrUpdtsPrgrss
	, unsigned int timeInSecs
	, eksNotModalProgressWindowCallBacks* pTheClassToCallBack
	, unsigned int secsBetwTicks
	, bool hasButton
	, const std::string& buttonText
)
	: eksThreadWithProgressWindow(msgToShow, true, hasButton, buttonText)
	, secsTimeToSpend(timeInSecs)
	, secsBetweenTics(secsBetwTicks)
	, callerUpdatesProgress(callrUpdtsPrgrss)
	, pEksNotModalProgressWindowCallBacks(pTheClassToCallBack)
{
	//spTuneComponent = std::make_shared<tuneComponent>(*pTheClass);
	setStatusMessage(subMsgToShow);
	setProgress(-1.0); // setting a value beyond the range 0 -> 1 will show a spinning bar..

	if (callerUpdatesProgress && (pTheClassToCallBack == nullptr))
	{
		launchWindow(); // No task running
	}
	else
	{
		launchThread();
	}
}

void eksNotModalProgressWindow::run()
{
	bool makeTickCalls = ((secsBetweenTics != 0) && (pEksNotModalProgressWindowCallBacks != nullptr));
	unsigned int secsCntrForTickCallBack = secsBetweenTics;

	for (unsigned int i = 0; i < secsTimeToSpend; ++i)
	{
		if (threadShouldExit())
			return;
		
		if (!callerUpdatesProgress)
		{
			setProgress(i / (double)secsTimeToSpend);
		}

		wait(1000);

		if (makeTickCalls)
		{
			secsCntrForTickCallBack--;
			if (secsCntrForTickCallBack == 0)
			{
				pEksNotModalProgressWindowCallBacks->eksNotModalProgressWindowTimrTicksCallBack(true);
				secsCntrForTickCallBack = secsBetweenTics;
			}
		}
	}

	setProgress(-1.0); // setting a value beyond the range 0 -> 1 will show a spinning bar..
	setStatusMessage("Done!");
}

// This method gets called on the message thread once our thread has finished..
void eksNotModalProgressWindow::threadComplete(bool userPressedButton)
{
	if (userPressedButton)
	{
		//AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
		//	"Progress window",
		//	"You pressed the button!");

		if (pEksNotModalProgressWindowCallBacks != nullptr)
		{
			pEksNotModalProgressWindowCallBacks->eksNotModalProgressWindowTimrThreadCompleteCallBack(true);
		}
	}
	else
	{
		// thread finished normally..
		//AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon,
		//	"Progress window",
		//	"Thread finished ok!");

		if (pEksNotModalProgressWindowCallBacks != nullptr)
		{
			pEksNotModalProgressWindowCallBacks->eksNotModalProgressWindowTimrThreadCompleteCallBack(false);
		}
	}

}
