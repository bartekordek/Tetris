#pragma once

#include <string>

#if _MSC_VER
#pragma warning( disable : 4251)
#endif

namespace Moge
{
class MyString: public std::string
{
public:
	MyString();
	explicit MyString( const char* inputString );
	MyString( const MyString& inputString );
	explicit MyString( const std::string& inputString );
	virtual ~MyString();

	MyString& operator=( const char* someString );
	MyString& operator=( const MyString& someString );

	const bool Contains( const MyString& inputString )const;
	const bool Contains( const char* inputString )const;

	MyString& Replace( const MyString& inWhat, const MyString& inFor );
	const std::string ToLower()const;
	const std::string string()const;

protected:
private:
};

MyString operator+( const MyString& string1, const MyString& string2 );
}