#pragma once

#include <string>

class String: std::string
{
public:
	String( void );
	String( const char* inputString );
	String( const String& inputString );
	String( const std::string& inputString );
	virtual ~String();

	String& operator=( const std::string& right );
	String& operator=( const String& right );
	const bool operator==( const std::string& right )const;
	const bool operator==( const String& right )const;

	const std::string& string()const;
	const char* c_str()const;

	const int Length()const;

	String& Replace( const String& inWhat, const String& inFor );

	const int rfind( const char* characters )const;
	const int rfind( const char character )const;

	const bool empty()const;

	const bool Contains( const String& inputString )const;
	const bool Contains( const char* inputString )const;
	const int find( const String& inputString )const;
	const int find( const char* inputString )const;

	static int npos;

private:
	
};