#pragma once

#include <MOGE.h>
#include <string>

#pragma warning( disable : 4251)

namespace MogeLib
{
	class MOGE_API String: public std::string
	{
	public:
		String();
		String( const char* inputString );
		String( const String& inputString );
		String( const std::string& inputString );
		virtual ~String();

		const bool Contains( const String& inputString )const;
		const bool Contains( const char* inputString )const;

		String& Replace( const String& inWhat, const String& inFor );
		const std::string ToLower()const;

		const std::string string()const;
	};

	String operator+( const String& string1, const String& string2 );
}