/*
  ==============================================================================

	eksNotModalProgressWindow.h
	Created: 26 May 2017 5:29:48pm
	Author:  eks

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class eksNotModalProgressWindowCallBacks;
class eksThreadWithProgressWindow;

class eksNotModalProgressWindow
	: public eksThreadWithProgressWindow
{
public:
	typedef std::function<void(bool)> Callback;

	eksNotModalProgressWindow
	(
		  const std::string& msgToShow = "Progress"
		, const std::string& subMsgToShow = "eksNotModalProgressWindow"
		, bool callrUpdtsPrgrss = true
		, unsigned int timeInSecs = 10
		, eksNotModalProgressWindowCallBacks* pTheClassToCallBack = nullptr
		, unsigned int secsBetwTicks = 0
		, bool hasButton = false
		, const std::string& buttonText = ""
	);

	~eksNotModalProgressWindow() {};

	void run() override;
	void threadComplete(bool userPressedButton) override;

private:
	unsigned int secsTimeToSpend = 0;
	unsigned int secsBetweenTics = 100;
	bool callerUpdatesProgress = true;


	eksNotModalProgressWindowCallBacks* pEksNotModalProgressWindowCallBacks;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(eksNotModalProgressWindow)
};
