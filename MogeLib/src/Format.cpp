#include "Format.h"
using namespace Moge;

const std::string Format::formatNumber( const unsigned value, const unsigned width )
{
	const std::string valueAsString = std::to_string( value );
	return valueAsString;
}

void Format::align( std::string& value, const bool toTheRight )
{
	char outerChar = '0';
	const unsigned n = static_cast<unsigned>( value.size() );
	if( toTheRight )
	{
		outerChar = value.back();
	}
	else
	{
		outerChar = value.front();
	}
	if( ' ' == outerChar )
	{
		unsigned int i = 0;
		do
		{
			moveCharactersFast( value, toTheRight );
			if( toTheRight )
			{
				outerChar = value.back();
			}
			else
			{
				outerChar = value.front();
			}
		} while( outerChar == ' ' && i++ <= n );
	}
}

const std::string Format::moveCharacters( const std::string& value, const bool toTheRight )
{
	std::string result = value;
	if( true == toTheRight )
	{
		const int sSize = static_cast<int>( value.size() );
		for( int i = sSize - 1; i > 0; --i )
		{
			result[i] = result[i - 1];
		}
	}
	return result;
}

void Format::moveCharactersFast( std::string& value, const bool toTheRight )
{
	const int sSize = static_cast<int>( value.size() );
	if( true == toTheRight )
	{
		for( int i = sSize - 1; i > 0; --i )
		{
			value[i] = value[i - 1];
		}
		value[0] = ' ';
	}
	else
	{
		for( int i = 0; i < sSize - 1; ++i )
		{
			value[i] = value[i + 1];
		}
		value[sSize - 1] = ' ';
	}
}