#pragma once

#include <cstdint>

namespace Moge
{
	class IKey
	{
	public:
		IKey() = default;
		virtual ~IKey() = default;

		virtual void setKeyName( const char* keyName ) = 0;
		virtual const char* getKeyName()const = 0;
		virtual const bool keyIsDown()const = 0;
		virtual void setKeyState( const bool isDown ) = 0;
	protected:
	private:
		
	};
}