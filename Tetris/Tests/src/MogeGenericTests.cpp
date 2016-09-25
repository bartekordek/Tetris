#include "MogeGenericTests.h"

#include "Named.h"
#include "Size.h"
#include "MyString.h"

TEST_F( MogeGenericTests, NamedSetGetName )
{
	class EmptyClass: public Moge::Name
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
	};

	EmptyClass instance;
	const Moge::MyString genericName = "GenericName";
	instance.SetName( genericName );
	ASSERT_EQ( instance.GetName(), genericName );
}