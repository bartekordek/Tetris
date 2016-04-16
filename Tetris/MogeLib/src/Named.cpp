#include "Named.h"

namespace MOGE
{
	Named::Named(const String& name): mName(name)
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