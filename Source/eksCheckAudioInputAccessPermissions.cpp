/*
  ==============================================================================

 eksCheckAudioInputAccessPermissions.cpp

    14. sept. 2020
        created  /eks

  ==============================================================================
*/


class eksCheckAudioInputAccessPermissions;



//==============================================================================
struct eksCheckAudioInputAccessPermissions::Pimpl
{
    Pimpl ()
    {
        JUCE_IOS_AUDIO_LOG ("Creating eksCheckAudioInputAccessPermissions");
    }

    ~Pimpl() override
    {
    }


    bool checkAudioInputAccessPermissions( )
    {
        NSString* mediaType = AVMediaTypeAudio;
        AVAuthorizationStatus authStatus = [ AVCaptureDevice authorizationStatusForMediaType : mediaType ];
        if ( authStatus == AVAuthorizationStatusAuthorized )
        {
            return true;
        }
        else if ( authStatus == AVAuthorizationStatusDenied )
        {
            return false;
        }
        else if ( authStatus == AVAuthorizationStatusRestricted )
        {
            return true;
        }
        else if ( authStatus == AVAuthorizationStatusNotDetermined )
        {
            [AVCaptureDevice requestAccessForMediaType : mediaType completionHandler : ^ ( BOOL granted )
            {
                if ( granted )
                {
                    NSLog( @"Granted access to %@", mediaType );
                    return true;
                }
                else
                {
                    NSLog( @"Not granted access to %@", mediaType );
                    return false;
                }
            }] ;
        }
        else
        {
            return false;
        }
        return false;
    }
};

//==============================================================================
eksCheckAudioInputAccessPermissions::eksCheckAudioInputAccessPermissions ()
    :pimpl( new Pimpl(  ) )
{
}

//==============================================================================


bool eksCheckAudioInputAccessPermissions::setAudioPreprocessingEnabled (bool enabled)  { return pimpl->setAudioPreprocessingEnabled (enabled); }
bool eksCheckAudioInputAccessPermissions::checkAudioInputAccessPermissions  { return pimpl->setAudioPreprocessingEnabled (); }
