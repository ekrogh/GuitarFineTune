#ifndef __eksPimplCPP_CLASS_H__
#define __eksPimplCPP_CLASS_H__

class eksPimplClassImpl;

class eksPimplCPPClass
{
public:
    eksPimplCPPClass ( void );
    ~eksPimplCPPClass( void );

	void setAirPlaysetBlueToothOn(bool setAirPlayOn, bool setBlueToothOn);

private:
    eksPimplClassImpl* _impl;
};

#endif
