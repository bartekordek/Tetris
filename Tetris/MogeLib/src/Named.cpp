#include "Named.h"

namespace MOGE
{
	Name::Name(const String& name): mName(name)
	{
	}

	Name::Name(const Name& name):mName(name.mName)
	{
	}

	Name::~Name()
	{
	}

	void Name::SetName( const String& name )
	{
		mName = name;
	}

	const String& Name::GetName()const
	{
		return mName;
	}

	Name& Name::operator=( const Name& name )
	{
		if( this != &name )
		{
			this->mName = name.mName;
		}
		return *this;
	}
}