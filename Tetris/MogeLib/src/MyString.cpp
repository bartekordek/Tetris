#include "MyString.h"

namespace MOGE
{
	String::String( void ): std::string( "" )
	{
	}

	String::String( const char* inputString ):std::string( inputString )
	{
	}

	String::String( const String& inputString ):std::string( inputString )
	{
	}

	String::String( const std::string& inputString ):std::string( inputString )
	{

	}

	String::~String()
	{
	}


	const bool String::Contains( const String& inputString )const
	{
		return Contains( inputString.c_str() );
	}

	const bool String::Contains( const char* inputString )const
	{
		if( std::string::npos == std::string::find( inputString ) )
		{
			return false;
		}
		return true;
	}

	String& String::Replace( const String& inWhat, const String& inFor )
	{
		auto inWhatPosition = std::string::find( inWhat.c_str() );
		if( std::string::npos != inWhatPosition )
		{
			std::string::replace( inWhatPosition, inWhat.length(), inFor.c_str() );
		}
		return *this;
	}
}