#pragma once

#include <string>

namespace MogeLib
{
	class MyString: public std::string
	{
	public:
		MyString();
		MyString( const char* inputString );
		MyString( const MyString& inputString );
		MyString( const std::string& inputString );
		virtual ~MyString();

		const bool Contains( const MyString& inputString )const;
		const bool Contains( const char* inputString )const;

		MyString& Replace( const MyString& inWhat, const MyString& inFor );
		const std::string ToLower()const;

		const std::string string()const;
	};

	MyString operator+( const MyString& string1, const MyString& string2 );
}