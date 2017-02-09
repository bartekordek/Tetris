#pragma once

#include <string>

namespace Moge
{
	class IKey
	{
	public:
		IKey() = default;
		virtual ~IKey() = default;

		virtual void setKeyName( const std::string& keyName ) = 0;
		virtual const std::string& getKeyName()const = 0;
		virtual const bool getKeyIsDown()const = 0;
		virtual void setKeyIsDown( const bool isDown ) = 0;
	protected:
	private:
		
	};
}