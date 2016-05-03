#include "NameTests.h"
#include "Named.h"

TEST_F( NameTests, CopyConstructorWorks )
{
	MOGE::String genericName = "Generic name.";
	MOGE::Name oldName( genericName );
	MOGE::Name newName( oldName );
	ASSERT_EQ( newName.GetName(), oldName.GetName() );
}

TEST_F( NameTests, ConstructorWithParameterWorks )
{
	MOGE::String genericName = "Generic name.";
	MOGE::Name name( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}

TEST_F( NameTests, AccessorsWork )
{
	MOGE::String genericName = "Generic name.";
	MOGE::Name name;
	name.SetName( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}