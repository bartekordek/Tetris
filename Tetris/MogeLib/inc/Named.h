#pragma once

#include <MOGE.h>
#include "MyString.h"

namespace MogeLib
{
	class MOGE_API Name
	{
	public:
		Name( const String& name = "" );
		Name( const Name& name );
		virtual ~Name();

		void SetName( const String& name );
		const String& GetName()const;

		Name& operator=( const Name& name );

	protected:
	private:
		String mName;

	};
}