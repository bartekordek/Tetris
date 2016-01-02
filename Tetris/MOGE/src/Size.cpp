#include "Size.h"

namespace MOGE
{
	Size::Size(): mWidth( 0 ), mHeight( 0 )
	{
	}

	Size::Size( CUInt width, CUInt height ):mWidth( width ), mHeight( height )
	{
	}

	Size::Size( const Size& size )
	{
		*this = size;
	}

	Size::~Size()
	{
	}

	Size& Size::operator=( const Size& size )
	{
		if( this != &size )
		{
			mWidth = size.mWidth;
			mHeight = size.mHeight;
		}
		return *this;
	}

	CUInt Size::GetWidth()const
	{
		return mWidth;
	}

	CUInt Size::GetHeight()const
	{
		return mHeight;
	}

	void Size::SetWidth( CUInt width )
	{
		mWidth = width;
	}

	void Size::SetHeight( CUInt height )
	{
		mHeight = height;
	}

	void Size::Set( CUInt width, CUInt height )
	{
		mWidth = width;
		mHeight = height;
	}
}