#include "MogeGenericTests.h"

#include "CUL/Named.hpp"
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
    const Moge::MyString genericName = Moge::MyString( "GenericName" );
    instance.SetName( genericName );
    ASSERT_EQ( instance.GetName(), genericName );
}