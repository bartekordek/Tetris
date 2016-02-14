#pragma once

#include <string>

class String: 
	public std::string
{
public:
	String( void );
	String( const char* inputString );
	String( const String& inputString );
	String( const std::string& inputString );
	virtual ~String();

	const bool Contains( const String& inputString )const;
	const bool Contains( const char* inputString )const;

	String& Replace( const String& inWhat, const String& inFor );
};