#include "MogeGenericTests.h"

#include "Named.h"
#include "Position.h"
#include "Size.h"

TEST_F( MogeGenericTests, NamedSetGetName )
{
	class EmptyClass: public MOGE::Name
	{

	};

	EmptyClass instance;
	const MOGE::String genericName = "GenericName";
	instance.SetName( genericName );
	ASSERT_EQ( instance.GetName(), genericName );
}

TEST_F( MogeGenericTests, PositionSetGetTwoArgumentMethod )
{
	class EmptyClass: public MOGE::Position
	{

	};

	EmptyClass instance;
	CUInt x = 0;
	CUInt y = 0;
	instance.SetXY( x, y );
	ASSERT_EQ( instance.GetX(), x );
	ASSERT_EQ( instance.GetY(), y );
}

TEST_F( MogeGenericTests, PositionSetGetOneArgumentMethod )
{
	class EmptyClass: public MOGE::Position
	{

	};

	EmptyClass instance;
	CUInt x = 0;
	CUInt y = 0;
	instance.SetX( x );
	instance.SetY( y );
	ASSERT_EQ( instance.GetX(), x );
	ASSERT_EQ( instance.GetY(), y );
}

TEST_F( MogeGenericTests, SizeSetGetTwoArgumentMethod )
{
	class EmptyClass: public MOGE::Size
	{

	};

	EmptyClass instance;
	CUInt width = 10;
	CUInt height = 10;
	instance.SetWH( width, height );
	ASSERT_EQ( instance.GetWidth(), width );
	ASSERT_EQ( instance.GetHeight(), height );
}

TEST_F( MogeGenericTests, SizeSetGetOneArgumentMethod )
{
	class EmptyClass: public MOGE::Size
	{

	};

	EmptyClass instance;
	CUInt width = 10;
	CUInt height = 10;
	instance.SetWidth( width );
	instance.SetHeight( height );
	ASSERT_EQ( instance.GetWidth(), width );
	ASSERT_EQ( instance.GetHeight(), height );
}