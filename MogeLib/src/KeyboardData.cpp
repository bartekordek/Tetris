#include "KeyboardData.h"

namespace Moge
{
	KeyboardData::KeyboardData( const std::string& data ): data( data )
	{
	}

	KeyboardData::KeyboardData( const KeyboardData& keyboardData ):data( keyboardData.data )
	{
	}

	KeyboardData::~KeyboardData()
	{
	}

	KeyboardData& KeyboardData::operator=( const KeyboardData& keyboardData )
	{
		if( &keyboardData != this )
		{
			this->data = keyboardData.data;
		}
		return *this;
	}

	void KeyboardData::setData( const std::string& data )
	{
		this->data = data;
	}

	const std::string& KeyboardData::getData() const
	{
		return this->data;
	}
}