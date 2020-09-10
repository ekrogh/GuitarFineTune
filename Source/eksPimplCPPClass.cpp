#ifdef THIS_IS_IOS

#include "eksPimplCPPClass.h"
#include "eksPimplObject-C-Interface.h"
#include <string>

eksPimplCPPClass::eksPimplCPPClass( void )
    : _impl ( new eksPimplClassImpl() )
{
}

eksPimplCPPClass::~eksPimplCPPClass( void )
{
    if ( _impl ) { delete _impl; _impl = nullptr; }
}

void eksPimplCPPClass::setAirPlaysetBlueToothOn(bool setAirPlayOn, bool setBlueToothOn)
{
    _impl->setAirPlaysetBlueToothOn(setAirPlayOn, setBlueToothOn);
}

#endif // THIS_IS_IOS
