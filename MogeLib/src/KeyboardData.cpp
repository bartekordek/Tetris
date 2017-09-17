#include "KeyboardData.h"
#include "SDL_events.h"

namespace Moge
{
	KeyboardData::KeyboardData( const std::string& keyName, const bool keyIsDown ):
		keyName( keyName ), 
		keyIsDown( keyIsDown )
	{
	}


	KeyboardData::KeyboardData( const KeyboardData& keyboardData ):
		keyName( keyboardData.keyName ), 
		keyIsDown( keyboardData.keyIsDown )
	{
	}

	KeyboardData& KeyboardData::operator=( const KeyboardData& keyboardData )
	{
		if( &keyboardData != this )
		{
			this->keyName = keyboardData.keyName;
			this->keyIsDown = keyboardData.keyIsDown;
		}
		return *this;
	}

	void KeyboardData::setKeyName( const std::string& name )
	{
		this->keyName = name;
	}

	const std::string& KeyboardData::getKeyName() const
	{
		return this->keyName;
	}

	void KeyboardData::setKeyIsDown( const bool isKeyIsDown )
	{
		this->keyIsDown = isKeyIsDown;
	}

	const bool KeyboardData::getKeyIsDown() const
	{
		return this->keyIsDown;
	}
}