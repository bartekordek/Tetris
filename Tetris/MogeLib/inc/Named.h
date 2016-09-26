#pragma once

#include <MogeLib.h>
#include "MyString.h"

namespace Moge
{
	class MogeLib_API Name
	{
	public:
		explicit Name( const MyString& name = MyString("") );
		explicit Name( const Name& name );
		virtual ~Name();

		void SetName( const MyString& name );
		const MyString& GetName()const;

		Name& operator=( const Name& name );

	protected:
	private:
		MyString mName;

	};
}