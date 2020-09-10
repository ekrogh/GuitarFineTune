
void SpectrogramComponent::calcGuitarStringSoundsRamp
(
	upRampGuitarStringsSinePhases
	, upRamp
	, upSeqLgth
	, unchangedGuitarStringsSinePhases
);

void SpectrogramComponent::calcGuitarStringSoundsRamp
(
	std::deque<GUITARSTRINGSPHASES>& firstRampGuitarStringsSinePhases
	, std::deque<double>& firstRampFaktors
	, unsigned int firstRampLgth
	, std::deque<GUITARSTRINGSPHASES>& lastRampGuitarStringsSinePhases
	, std::deque<double>& lastRampFaktors
	, unsigned int lastRampLgth
	, std::deque<GUITARSTRINGSPHASES>& unchangedGuitarStringsSinePhases
)
{
	float currentPhase;
	float phaseDeltaPerSample;
	guitarStringSoundsRamp.clear();
	guitarStringSoundsRamp.resize(rampLgth, 0.0f);
	for (auto& gStringPhase : guitarStringsSinePhases)
	{
		currentPhase = gStringPhase.currentPhase;
		phaseDeltaPerSample = gStringPhase.phaseDeltaPerSample;
		for (auto& curGuitarStringSoundSample : guitarStringSoundsRamp)
		{
			curGuitarStringSoundSample += std::sin(gStringPhase.currentPhase);
			// increment the phase step for the next sample
			currentPhase = std::fmod(currentPhase + phaseDeltaPerSample, float_2PI);
		}
		gStringPhase.currentPhase = currentPhase;
		gStringPhase.phaseDeltaPerSample = phaseDeltaPerSample;
	}
	std::transform(guitarStringSoundsRampFaktors.begin(), guitarStringSoundsRampFaktors.end(), guitarStringSoundsRamp.begin(), guitarStringSoundsRamp.begin(), std::multiplies<float>());
}
