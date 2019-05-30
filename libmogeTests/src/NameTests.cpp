#include "NameTests.h"
#include "Named.h"

TEST_F( NameTests, CopyConstructorWorks )
{
    Moge::Name oldName( genericName );
    Moge::Name newName( oldName );
    ASSERT_EQ( newName.GetName(), oldName.GetName() );
}

TEST_F( NameTests, ConstructorWithParameterWorks )
{
    Moge::Name name( genericName );
    ASSERT_EQ( name.GetName(), genericName );
}

TEST_F( NameTests, AccessorsWork )
{
    Moge::Name name;
    name.SetName( genericName );
    ASSERT_EQ( name.GetName(), genericName );
}