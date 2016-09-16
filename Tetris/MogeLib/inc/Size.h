#pragma once

#include <MOGE.h>
#include "Aliases.h"

namespace MogeLib
{
	class MOGE_API Size
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
		void SetWH( CUInt width, CUInt height );
		void SetWH( const Size& size );

	protected:
	private:
		UInt mWidth;
		UInt mHeight;
	};
}