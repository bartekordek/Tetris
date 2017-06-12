#pragma once
#include "MogeLib.h"
#include <string>
namespace Moge
{
	class MogeLib_API Format
	{
	public:
		static const std::string formatNumber( const unsigned int value, const unsigned int width );
		static void align( std::string& value, const bool toTheRigh );
		static const std::string moveCharacters( const std::string& value, const bool toTheRight );
		static void moveCharactersFast( std::string& value, const bool toTheRigh );
	protected:
	private:
		Format() = delete;
		virtual ~Format() = delete;
	};
}