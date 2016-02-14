#include "MyString.h"

String::String(void): mString( "" )
{
}

String::String( const char* inputString ):mString( inputString )
{
}

String::String( const String& inputString ):mString( inputString.string() )
{
}

String::String( const std::string& inputString ):mString( inputString )
{

}

String::~String()
{
}

String& String::operator=( const std::string& right )
{
	if( mString != right )
	{
		mString = right;
	}
	return *this;
}

String& String::operator=( const String& right )
{
	if( this != &right )
	{
		mString = right.string();
	}
	return *this;
}

const bool String::operator==( const std::string& right )const
{
	if( 0 == mString.compare( right ) )
	{
		return true;
	}
	return false;
}

const bool String::operator==( const String& right )const
{
	if( 0 == mString.compare( right.string() ) )
	{
		return true;
	}
	return false;
}

const std::string& String::string()const
{
	return mString;
}

const bool String::Contains( const String& inputString )const
{
	return Contains( inputString.c_str() );
}

const char* String::c_str()const
{
	return mString.c_str();
}

const bool String::Contains( const char* inputString )const
{
	if( std::string::npos == mString.find( inputString ) )
	{
		return false;
	}
	return true;
}

const int String::find( const String& inputString )const
{
	return mString.find( inputString.c_str() );
}

const int String::find( const char* inputString )const
{
	return mString.find( inputString );
}

String& String::Replace( const String& inWhat, const String& inFor )
{
	auto inWhatPosition = mString.find( inWhat.c_str() );
	if( std::string::npos != inWhatPosition )
	{
		mString.replace( inWhatPosition, inWhat.Length(), inFor.c_str() );
	}
	return *this;
}

const int String::rfind( const char* characters )const
{
	return mString.rfind( characters );
}

const int String::rfind( const char character )const
{
	return mString.rfind( character );
}

const bool String::empty()const
{
	return mString.empty();
}

const int String::Length()const
{
	return mString.length();
}

int String::npos = -1;