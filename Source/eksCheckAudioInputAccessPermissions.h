/*
  ==============================================================================

 eksCheckAudioInputAccessPermissions.h

	14. sept. 2020
		created  /eks

  ==============================================================================
*/

namespace juce
{


	class eksCheckAudioInputAccessPermissions : public AudioIODevice
	{
	public:
		//==============================================================================

		bool checkAudioInputAccessPermissions( )

	private:
		//==============================================================================
		eksCheckAudioInputAccessPermissions( );

		//==============================================================================
		struct Pimpl;
		friend struct Pimpl;
		std::unique_ptr<Pimpl> pimpl;

		JUCE_DECLARE_NON_COPYABLE( eksCheckAudioInputAccessPermissions )
	};

} // namespace juce
