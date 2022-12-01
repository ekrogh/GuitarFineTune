/*
  ==============================================================================

    eksThreadWithProgressWindow.h
    Created: 25 May 2017 2:52:05pm
    Author:  eks

	==============================================================================
	Copy of
		JUCE::ThreadWithProgressWindow
	with the difference, that the Window Is Not Modal.
	And some other stuff
    ==============================================================================
*/

#pragma once


//==============================================================================
/**
A thread that automatically pops up a NON modal dialog box with a progress bar
and cancel button while it's busy running.

These are handy for performing some sort of task while giving the user feedback
about how long there is to go, etc.

E.g. @code
class MyTask  : public eksThreadWithProgressWindow
{
public:
MyTask()    : eksThreadWithProgressWindow ("busy...", true, true)
{
}

void run()
{
for (int i = 0; i < thingsToDo; ++i)
{
// must check this as often as possible, because this is
// how we know if the user's pressed 'cancel'
if (threadShouldExit())
break;

// this will update the progress bar on the dialog box
setProgress (i / (double) thingsToDo);


//   ... do the business here...
}
}
};

void doTheTask()
{
MyTask m;

if (m.runThread())
{
// thread finished normally..
}
else
{
// user pressed the cancel button..
}
}

@endcode

@see Thread, AlertWindow
*/

#include "../JuceLibraryCode/JuceHeader.h"

class JUCE_API  eksThreadWithProgressWindow
	: public Thread
	, private Timer
	, public Button::Listener
{
public:
	//==============================================================================
	/** Creates the thread.

	Initially, the dialog box won't be visible, it'll only appear when the
	runThread() method is called.

	@param windowTitle              the title to go at the top of the dialog box
	@param hasProgressBar           whether the dialog box should have a progress bar (see
	setProgress() )
	@param hasCancelButton          whether the dialog box should have a cancel button
	@param timeOutMsWhenCancelling  when 'cancel' is pressed, this is how long to wait for
	the thread to stop before killing it forcibly (see
	Thread::stopThread() )
	@param cancelButtonText         the text that should be shown in the cancel button
	(if it has one). Leave this empty for the default "Cancel"
	@param componentToCentreAround  if this is non-null, the window will be positioned
	so that it's centred around this component.
	*/
	eksThreadWithProgressWindow
	(
		const std::string& windowTitle = "Progress"
		, bool hasProgressBar = true
		, bool hasButton = false
		, const std::string& buttonText = ""
		, int timeOutWhenButtonPressed = 1000
		, Component* componentToCentreAround = nullptr
	);

	/** Destructor. */
	~eksThreadWithProgressWindow();



	// Just launches the window. No thread is atarted
	void launchWindow();
	
	/** Starts the thread and returns.

	This will start the thread and make the dialog box appear in a NON modal state. When
	the thread finishes normally, or the cancel button is pressed, the window will be
	hidden and the threadComplete() method will be called.

	@param priority   the priority to use when starting the thread - see
	Thread::startThread() for values
	*/
	void launchThread(Priority priority = Priority::high);

	/** The thread should call this periodically to update the position of the progress bar.

	@param newProgress  the progress, from 0.0 to 1.0
	@see setStatusMessage
	*/
	void setProgress(double newProgress);

	/** The thread can call this to change the message that's displayed in the dialog box. */
	void setStatusMessage(const String& newStatusMessage);

	/** Returns the AlertWindow that is being used. */
	AlertWindow& getAlertWindow() const noexcept { return *alertWindow; }

	//==============================================================================
	/** This method is called (on the message thread) when the operation has finished.
	You may choose to use this callback to delete the eksThreadWithProgressWindow object.
	*/
	virtual void threadComplete( bool ){};

	void buttonClicked( Button* buttonThatWasClicked ) override;

	void stopAll();

private:
	//==============================================================================
	void timerCallback() override;

	double progress;
	std::unique_ptr<AlertWindow> alertWindow;
	String message;
	CriticalSection messageLock;
	const int timeOutMsWhenFromButtonPressed;
	//bool wasCancelledByUser;

	bool threadWasStarted = false;
	bool stopNow = false;
	bool buttonWasClicked = false;
	bool windowHasButton = false;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(eksThreadWithProgressWindow)
};
