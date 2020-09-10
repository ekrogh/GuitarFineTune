#ifdef THIS_IS_IOS

#import "eksPimplObject.h"
#import "AVFoundation/AVFoundation.h"

@implementation eksPimplObject

eksPimplClassImpl::eksPimplClassImpl( void )
    : self( [[eksPimplObject alloc] init] )
{   }

eksPimplClassImpl::~eksPimplClassImpl( void )
{
    [(id)self dealloc];
}

void eksPimplClassImpl::setAirPlaysetBlueToothOn(bool setAirPlayOn, bool setBlueToothOn)
{
	[(id)self setAirPlaysetBlueToothOn:setAirPlayOn:setBlueToothOn];
}

- (void) setAirPlaysetBlueToothOn: (bool)setAirPlayOn :(bool)setBlueToothOn
{
	
	NSError* error;

	auto categoryOptions = [[AVAudioSession sharedInstance] categoryOptions];
	
	bool airPlayIsOn = categoryOptions & AVAudioSessionCategoryOptionAllowAirPlay;
	bool blueToothIsOn = categoryOptions & AVAudioSessionCategoryOptionAllowBluetooth;
	if ((setAirPlayOn == airPlayIsOn) && (setBlueToothOn == blueToothIsOn))
		return; // All set as wanted
	
	[[AVAudioSession sharedInstance] setActive: true error: &error];	// Set the session category & options:
	
	auto session = [AVAudioSession sharedInstance];

	NSString* category = AVAudioSessionCategoryPlayAndRecord;
	
	NSUInteger options = AVAudioSessionCategoryOptionMixWithOthers;
	
	if (setAirPlayOn)
	{
		options |= AVAudioSessionCategoryOptionAllowAirPlay;
	}
	if (setBlueToothOn)
	{
		options |= AVAudioSessionCategoryOptionAllowBluetooth;
	}

	[session setCategory: category withOptions: options error: &error];

	[[AVAudioSession sharedInstance] setActive: true error: &error];	// Set the session category & options:
	
}

@end

#endif // THIS_IS_IOS
