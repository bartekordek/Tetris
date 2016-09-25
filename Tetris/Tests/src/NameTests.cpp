#include "NameTests.h"
#include "Named.h"
#include "MyString.h"

TEST_F( NameTests, CopyConstructorWorks )
{
	Moge::MyString genericName = "Generic name.";
	Moge::Name oldName( genericName );
	Moge::Name newName( oldName );
	ASSERT_EQ( newName.GetName(), oldName.GetName() );
}

TEST_F( NameTests, ConstructorWithParameterWorks )
{
	Moge::MyString genericName = "Generic name.";
	Moge::Name name( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}

TEST_F( NameTests, AccessorsWork )
{
	Moge::MyString genericName = "Generic name.";
	Moge::Name name;
	name.SetName( genericName );
	ASSERT_EQ( name.GetName(), genericName );
}