#pragma once

#include "IKey.h"
#include <string>

namespace Moge
{
	class KeySDL: public IKey
	{
	public:
		KeySDL();
		KeySDL( const KeySDL& key );
		virtual ~KeySDL();
		KeySDL& operator=( const KeySDL& key );

		void setKeyName( const char* keyName ) override;
		const char* getKeyName()const override;
		void setKeyState( const bool keyIsDown ) override;
		const bool keyIsDown()const override;
	protected:
	private:
		std::string keyName;
		bool m_keyIsDown = false;
	};
}