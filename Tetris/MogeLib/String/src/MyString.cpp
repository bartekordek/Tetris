#include "MyString.h"
#include <boost\algorithm\string.hpp>

namespace Moge
{
	MyString::MyString(): std::string( "" )
	{
	}

	MyString::MyString( const char* inputString ):std::string( inputString )
	{
	}

	MyString::MyString( const MyString& inputString ):std::string( inputString )
	{
	}

	MyString::MyString( const std::string& inputString ):std::string( inputString )
	{

	}

	MyString::~MyString()
	{
	}


	const bool MyString::Contains( const MyString& inputString )const
	{
		return Contains( inputString.c_str() );
	}

	const bool MyString::Contains( const char* inputString )const
	{
		if( std::string::npos == std::string::find( inputString ) )
		{
			return false;
		}
		return true;
	}

	MyString& MyString::Replace( const MyString& inWhat, const MyString& inFor )
	{
		auto inWhatPosition = std::string::find( inWhat.c_str() );
		if( std::string::npos != inWhatPosition )
		{
			std::string::replace( inWhatPosition, inWhat.length(), inFor.c_str() );
		}
		return *this;
	}

	const std::string MyString::ToLower()const
	{
		std::string result = static_cast<std::string>( *this );
		boost::algorithm::to_lower( result );
		return result;
	}

	const std::string MyString::string()const
	{
		return static_cast<std::string>( *this );
	}

	MyString operator+( const MyString& string1, const MyString& string2 )
	{
		MyString string( string1.string() + string2.string() );
		return string;
	}
}