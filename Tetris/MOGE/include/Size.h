#pragma once
#include "GeneralUtilities.h"

namespace MOGE
{
	class Size
	{
	public:
		Size();
		Size( CUInt width, CUInt height );
		Size( const Size& size );
		virtual ~Size();

		Size& operator=( const Size& size );

		CUInt GetWidth()const;
		CUInt GetHeight()const;

		void SetWidth( CUInt width );
		void SetHeight( CUInt height );
		void Set( CUInt width, CUInt height );

	protected:
	private:
		UInt mWidth;
		UInt mHeight;
	};
}