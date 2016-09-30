#include "Named.h"

namespace Moge
{
	Name::Name(const MyString& name): mName(name)
	{
	}

	Name::Name(const Name& name):mName(name.mName)
	{
	}

	Name::~Name()
	{
	}

	void Name::SetName( const MyString& name )
	{
		mName = name;
	}

	const MyString& Name::GetName()const
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