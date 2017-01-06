#include "KeyboardData.h"

namespace Moge
{
KeyboardData::KeyboardData()
{
}

KeyboardData::KeyboardData( SDL_Event* sdlEvent ): sdlEvent( sdlEvent )
{
}

KeyboardData::~KeyboardData()
{
}

KeyboardData& KeyboardData::operator=( const KeyboardData& keyboardData )
{
	if( &keyboardData != this )
	{
		this->sdlEvent = keyboardData.sdlEvent;
	}
	return *this;
}

void KeyboardData::setEvent( SDL_Event* sdlEvent )
{
	this->sdlEvent = sdlEvent;
}

SDL_Event* KeyboardData::getSdlEvent() const
{
	return this->sdlEvent;
}
}