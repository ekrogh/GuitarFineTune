#ifndef __eksPimplOBJECT_C_INTERFACE_H__
#define __eksPimplOBJECT_C_INTERFACE_H__

class eksPimplClassImpl
{
public:
    eksPimplClassImpl ( void );
    ~eksPimplClassImpl( void );

	void setAirPlaysetBlueToothOn(bool setAirPlayOn, bool setBlueToothOn);

private:
    void * self;
};

#endif
