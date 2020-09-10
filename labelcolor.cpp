	setColorOfAllLabels(audioSetupComp);

	void setColorOfAllLabels(juce::Component* cmpontToHandle);

void AudioSettings::setColorOfAllLabels(juce::Component* cmpontToHandle)
{
	int numChildComponents = cmpontToHandle->getNumChildComponents();

	if (numChildComponents == 0)
	{
		juce::Label* testLabel = dynamic_cast<juce::Label*> (cmpontToHandle);

		if (testLabel != NULL)
		{
			cmpontToHandle->setColour(Label::textColourId, Colours::cornflowerblue);
		}
	}
	else
	{
		for (int i = 0; i < numChildComponents; ++i)
		{
			if (Component* childComponent = cmpontToHandle->getChildComponent(i))
			{
				//setColorOfAllLabels(childComponent);
			}
		}
	}
}