#include "MogeGenericTests.h"

#include "Named.h"
#include "Position.h"
#include "Size.h"

TEST_F( MogeGenericTests, NamedSetGetName )
{
	class EmptyClass: public MogeLib::Name
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
	};

	EmptyClass instance;
	const MogeLib::String genericName = "GenericName";
	instance.SetName( genericName );
	ASSERT_EQ( instance.GetName(), genericName );
}

TEST_F( MogeGenericTests, PositionSetGetTwoArgumentMethod )
{
	class EmptyClass: public MogeLib::Position
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
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
	class EmptyClass: public MogeLib::Position
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
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
	class EmptyClass: public MogeLib::Size
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
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
	class EmptyClass: public MogeLib::Size
	{
	protected:
		virtual void UpdateImplementation()
		{

		}
	};

	EmptyClass instance;
	CUInt width = 10;
	CUInt height = 10;
	instance.SetWidth( width );
	instance.SetHeight( height );
	ASSERT_EQ( instance.GetWidth(), width );
	ASSERT_EQ( instance.GetHeight(), height );
}