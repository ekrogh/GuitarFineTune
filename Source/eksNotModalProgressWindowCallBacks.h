/*
  ==============================================================================

    eksNotModalProgressWindowCallBacks.h
    Created: 27 May 2017 3:22:06pm
    Author:  eks

  ==============================================================================
*/

#pragma once
class eksNotModalProgressWindowCallBacks
{
public:
	virtual void eksNotModalProgressWindowTimrTicksCallBack( bool ) {};
	virtual void eksNotModalProgressWindowTimrThreadCompleteCallBack( bool ) {};
	
	virtual ~eksNotModalProgressWindowCallBacks() {}
};
