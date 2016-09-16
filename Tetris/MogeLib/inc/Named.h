#pragma once

#include <MOGE.h>
#include "MyString.h"

namespace MogeLib
{
	class MOGE_API Name
	{
	public:
		Name( const MyString& name = "" );
		Name( const Name& name );
		virtual ~Name();

		void SetName( const MyString& name );
		const MyString& GetName()const;

		Name& operator=( const Name& name );

	protected:
	private:
		MyString mName;

	};
}