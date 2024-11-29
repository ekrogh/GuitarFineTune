/*
  ==============================================================================

    eksLookAndFeel.h
    Created: 26 Apr 2018 8:06:02pm
    Author:  eks

  ==============================================================================
*/

#pragma once
class eksLookAndFeel : public LookAndFeel_V4
{
public:
	eksLookAndFeel(bool addVWP)
		: viewPortAdded(addVWP)
	{
	}

	Font getComboBoxFont(ComboBox& /*box*/) override
	{
		return eksLookAndFeelComboBoxFont;
	}

	Font getTextButtonFont(TextButton&, int /*buttonHeight*/) override
	{
		return eksLookAndFeelTextButtonFont;
	}

	Label* createSliderTextBox(Slider& slider) override
	{
		Label* localLbl = LookAndFeel_V4::createSliderTextBox(slider);
		pSliderTextBoxes.push_back(localLbl);
		return localLbl;
	}

	void drawToggleButton(Graphics& g, ToggleButton& button,
		bool isMouseOverButton, bool isButtonDown) override
	{
		auto fontSize = jmin(15.0f, button.getHeight() * 0.75f);
	#if (JUCE_IOS || JUCE_ANDROID)
	#if JUCE_ANDROID
		if (!viewPortAdded)
		{
	#endif // JUCE_ANDROID
            if  ((eksLookAndFeelTextButtonFont.getHeight() * 0.75f) > fontSize)
            {
                fontSize = eksLookAndFeelTextButtonFont.getHeight() * 0.75f;
            }
	#if JUCE_ANDROID
		}
	#endif // JUCE_ANDROID
	#endif // (JUCE_IOS || JUCE_ANDROID)

		auto tickWidth = fontSize * 1.1f;

		drawTickBox(g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
			tickWidth, tickWidth,
			button.getToggleState(),
			button.isEnabled(),
			isMouseOverButton,
			isButtonDown);

		g.setColour(button.findColour(ToggleButton::textColourId));
		g.setFont(fontSize);

		if (!button.isEnabled())
			g.setOpacity(0.5f);

		g.drawFittedText(button.getButtonText(),
			button.getLocalBounds().withTrimmedLeft(roundToInt(tickWidth) + 10)
			.withTrimmedRight(2),
			Justification::centredLeft, 10);
	}

	void drawGroupComponentOutline(Graphics& g, int width, int height,
		const String& text, const Justification& position,
		GroupComponent& group) override
	{
		float textH = 15.0f;
	#if (JUCE_IOS || JUCE_ANDROID)
	#if JUCE_ANDROID
		if (!viewPortAdded)
		{
		#endif // JUCE_ANDROID
			textH = eksLookAndFeelTextButtonFont.getHeight() * 0.75f;
		#if JUCE_ANDROID
		}
	#endif // JUCE_ANDROID
	#endif // (JUCE_IOS || JUCE_ANDROID)

		const float indent = 3.0f;
		const float textEdgeGap = 4.0f;
		auto cs = 5.0f;

		Font f = juce::Font(FontOptions(textH).withStyle("Regular"));

		Path p;
		auto x = indent;
		auto y = f.getAscent() - 3.0f;
		auto w = jmax(0.0f, width - x * 2.0f);
		auto h = jmax(0.0f, height - y - indent);
		cs = jmin(cs, w * 0.5f, h * 0.5f);
		auto cs2 = 2.0f * cs;

		auto textW = 0.0f;
		if (!text.isEmpty())
		{
			GlyphArrangement glyphs;
			glyphs.addLineOfText(f, text, 0.0f, 0.0f);
			textW = jlimit(0.0f, jmax(0.0f, w - cs2 - textEdgeGap * 2), glyphs.getBoundingBox(0, text.length(), true).getWidth() + textEdgeGap * 2.0f);
		}

		//auto textW = text.isEmpty() ? 0 : jlimit(0.0f, jmax(0.0f, w - cs2 - textEdgeGap * 2), f.getStringWidth(text) + textEdgeGap * 2.0f);
		auto textX = cs + textEdgeGap;

		if (position.testFlags(Justification::horizontallyCentred))
			textX = cs + (w - cs2 - textW) * 0.5f;
		else if (position.testFlags(Justification::right))
			textX = w - cs - textW - textEdgeGap;

		p.startNewSubPath(x + textX + textW, y);
		p.lineTo(x + w - cs, y);

		p.addArc(x + w - cs2, y, cs2, cs2, 0, MathConstants<float>::halfPi);
		p.lineTo(x + w, y + h - cs);

		p.addArc(x + w - cs2, y + h - cs2, cs2, cs2, MathConstants<float>::halfPi, MathConstants<float>::pi);
		p.lineTo(x + cs, y + h);

		p.addArc(x, y + h - cs2, cs2, cs2, MathConstants<float>::pi, MathConstants<float>::pi * 1.5f);
		p.lineTo(x, y + cs);

		p.addArc(x, y, cs2, cs2, MathConstants<float>::pi * 1.5f, MathConstants<float>::twoPi);
		p.lineTo(x + textX, y);

		auto alpha = group.isEnabled() ? 1.0f : 0.5f;

		g.setColour(group.findColour(GroupComponent::outlineColourId)
			.withMultipliedAlpha(alpha));

		g.strokePath(p, PathStrokeType(2.0f));

		g.setColour(group.findColour(GroupComponent::textColourId)
			.withMultipliedAlpha(alpha));
		g.setFont(f);
		g.drawText(text,
			roundToInt(x + textX), 0,
			roundToInt(textW),
			roundToInt(textH),
			Justification::centred, true);
	}
	
	void setEksLookAndFeelComboBoxFont(Font fontToUse) 
	{
		eksLookAndFeelComboBoxFont = fontToUse;
	}

	void setEksLookAndFeelTextButtonFont(Font fontToUse)
	{
		eksLookAndFeelTextButtonFont = fontToUse;
	}

	void scaleAllsliderTextBoxes(float scaleToUse)
	{
		static bool firstTime = true;
		static Rectangle<int> curCpntBnds;
		for (auto pSliderTextBox : pSliderTextBoxes)
		{
			if (firstTime)
			{
				curCpntBnds = pSliderTextBox->getBounds();
				firstTime = false;
			}
//			auto scaledBounds = curCpntBnds * scaleToUse;
			pSliderTextBox->setBounds(curCpntBnds * scaleToUse);
//			Font currentFont = pSliderTextBox->getFont();
//			currentFont.setHeight(currentFont.getHeightInPoints() * scaleToUse * 0.9f);
//			pSliderTextBox->setFont(currentFont);
			pSliderTextBox->setFont(eksLookAndFeelTextButtonFont);
		}
	}

	void scaleEksLookAndFeelFonts(float scaleToUse)
	{
		eksLookAndFeelComboBoxFont.setHeight((juce::Font(FontOptions(15.00f).withStyle("Regular"))).getHeight() * scaleToUse);
		eksLookAndFeelTextButtonFont.setHeight((juce::Font(FontOptions(15.00f).withStyle("Regular"))).getHeight() * scaleToUse);
	}

private:
	Font eksLookAndFeelComboBoxFont = juce::Font(FontOptions(15.00f).withStyle("Regular"));
	Font eksLookAndFeelTextButtonFont = juce::Font(FontOptions(15.00f).withStyle("Regular"));
	bool viewPortAdded = false;
	std::vector<Label*> pSliderTextBoxes;
};
