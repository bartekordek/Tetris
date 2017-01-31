#include "KeySDL.h"

namespace Moge
{
	KeySDL::KeySDL()
	{
	}

	KeySDL::KeySDL( const KeySDL& key ): keyName( key.keyName ), m_keyIsDown( key.m_keyIsDown )
	{
		
	}

	KeySDL::~KeySDL()
	{
	}

	KeySDL& KeySDL::operator=( const KeySDL& key )
	{
		if( this != &key )
		{
			this->keyName = key.keyName;
			this->m_keyIsDown = key.m_keyIsDown;
		}
		return *this;
	}

	void KeySDL::setKeyName( const char* keyName )
	{
		this->keyName = keyName;
	}

	const char* KeySDL::getKeyName() const
	{
		return this->keyName.c_str();
	}

	void KeySDL::setKeyState( const bool keyIsDow )
	{
		this->m_keyIsDown = keyIsDow;
	}

	const bool KeySDL::keyIsDown() const
	{
		return this->m_keyIsDown;
	}

}