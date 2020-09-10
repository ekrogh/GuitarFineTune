/*
  ==============================================================================

	SimpleLevelMeter.h
	Created: 21 Mar 2018 1:43:31pm
		from juce::SimpleLevelMeter
	Author:  eks

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

class AudioRecorderControl;
class tuneComponent;

struct SimpleLevelMeter
	: public Component
	, public Timer
{
	SimpleLevelMeter(std::shared_ptr<AudioRecorderControl> spARC);

	~SimpleLevelMeter();

	void timerCallback() override;

	void updateLevelMeter(float newLevel);

	void drawLevelMeter(Graphics& g, int width, int height, float level);

	void paint(Graphics& g) override;

	float level = 0;

	bool newLevelValue = false;

	std::shared_ptr<AudioRecorderControl> spAudioRecorderControl = nullptr;

	//bool wasShowing = false;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleLevelMeter)
};
