#include "Named.h"

namespace MOGE
{
	Named::Named()
	{
	}

	Named::~Named()
	{
	}

	void Named::SetName( const String& name )
	{
		mName = name;
	}

	const String& Named::GetName()const
	{
		return mName;
	}
}