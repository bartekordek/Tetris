#include "NameTests.h"
#include "Named.h"

TEST_F( NameTests, CopyConstructorWorks )
{
	MogeLib::String genericName = "Generic name.";
	MogeLib::Name oldName( genericName );
	MogeLib::Name newName( oldName );
	ASSERT_EQ( newName.GetName(), oldName.GetName() );
}

TEST_F( NameTests, ConstructorWithParameterWorks )
{
	MogeLib::String genericName = "Generic name.";
	MogeLib::Name name( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}

TEST_F( NameTests, AccessorsWork )
{
	MogeLib::String genericName = "Generic name.";
	MogeLib::Name name;
	name.SetName( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}