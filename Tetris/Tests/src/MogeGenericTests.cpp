#include "MogeGenericTests.h"

#include "Named.h"

TEST_F( MogeGenericTests, NamedSetGetName )
{
	class EmptyClass: public MOGE::Named
	{

	};


	EmptyClass instance;
	const String genericName = "GenericName";
	instance.SetName( genericName );
	ASSERT_EQ( instance.GetName(), genericName );
}