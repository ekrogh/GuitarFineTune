/*
  ==============================================================================

	SimpleLevelMeter.cpp
	Created: 21 Mar 2018 1:43:31pm
		from juce::SimpleLevelMeter
	Author:  eks

  ==============================================================================
*/

#include "AudioRecorder.h"
#include "tuneComponent.h"
#include "SimpleLevelMeter.h"

extern std::shared_ptr<tuneComponent> pTuneComponent;
extern std::shared_ptr<AudioDeviceManager> sharedAudioDeviceManager;

SimpleLevelMeter::SimpleLevelMeter(std::shared_ptr<AudioRecorderControl> spARC)
	: spAudioRecorderControl(spARC)
{
	startTimerHz(5);
}

SimpleLevelMeter::~SimpleLevelMeter()
{
	stopTimer();
	if (pTuneComponent)
	{
		pTuneComponent->stopRecorderSourceFilteredAudio();
	}
	if (spAudioRecorderControl)
	{
		spAudioRecorderControl->StopAudioDeviceIOCallback(); // Stop audioDeviceIOCallback
		spAudioRecorderControl->stopAudioRecorderRecording();
	}

}

void SimpleLevelMeter::timerCallback() // Called from Thread
{
	if (newLevelValue && isShowing())
	{
		repaint();
		newLevelValue = false;
	}
}

void SimpleLevelMeter::updateLevelMeter(float newLevel)
{
	level = newLevel;
	newLevelValue = true;
}

void SimpleLevelMeter::drawLevelMeter(Graphics& g, int width, int height, float levelMeterLevel)
{
	auto outerCornerSize = 3.0f;
	auto outerBorderWidth = 2.0f;
	auto totalBlocks = 20;
	auto spacingFraction = 0.03f;

	g.setColour(findColour(ResizableWindow::backgroundColourId));
	g.fillRoundedRectangle(0.0f, 0.0f, static_cast<float> (width), static_cast<float> (height), outerCornerSize);

	auto doubleOuterBorderWidth = 2.0f * outerBorderWidth;
	auto numBlocks = roundToInt(totalBlocks * levelMeterLevel);

	if (width >= height)
	{
		// Horizontal
		auto blockWidth = (width - doubleOuterBorderWidth) / static_cast<float> (totalBlocks);
		auto blockHeight = height - doubleOuterBorderWidth;

		auto blockRectWidth = (1.0f - 2.0f * spacingFraction) * blockWidth;
		auto blockRectSpacing = spacingFraction * blockWidth;

		auto blockCornerSize = 0.1f * blockWidth;

		auto c = findColour(Slider::thumbColourId);

		for (auto i = 0; i < totalBlocks; ++i)
		{
			if (i >= numBlocks)
				g.setColour(c.withAlpha(0.5f));
			else
				g.setColour(i < totalBlocks - 1 ? c : Colours::red);

			g.fillRoundedRectangle(outerBorderWidth + (i * blockWidth) + blockRectSpacing,
				outerBorderWidth,
				blockRectWidth,
				blockHeight,
				blockCornerSize);
		}
	}
	else
	{
		// Vertical
		auto blockWidth = width - doubleOuterBorderWidth;
		auto blockHeight = (height - doubleOuterBorderWidth) / static_cast<float> (totalBlocks);

		auto yStart = height - blockHeight;

		auto blockRectHeight = (1.0f - 2.0f * spacingFraction) * blockHeight;
		auto blockRectSpacing = spacingFraction * blockHeight;

		auto blockCornerSize = 0.1f * blockHeight;

		auto c = findColour(Slider::thumbColourId);

		for (auto i = 0; i < totalBlocks; ++i)
		{
			if (i >= numBlocks)
				g.setColour(c.withAlpha(0.5f));
			else
				g.setColour(i < totalBlocks - 1 ? c : Colours::red);

			g.fillRoundedRectangle
			(
				outerBorderWidth
				, yStart - (i * blockHeight) - blockRectSpacing
				, blockWidth
				, blockRectHeight
				, blockCornerSize
			);
		}
	}
}
void SimpleLevelMeter::paint(Graphics& g)
{
	drawLevelMeter(g, getWidth(), getHeight(), level);
	//getLookAndFeel().drawLevelMeter(g, getWidth(), getHeight(), level);
}
