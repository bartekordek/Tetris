#include "StringTests.h"
#include "Format.h"

StringTests::StringTests()
{
}


StringTests::~StringTests()
{
}

TEST_F( StringTests, AlginRight )
{
	std::string testNmb( "123      " );
	Moge::Format::align( testNmb, true );
	GTEST_ASSERT_EQ( testNmb, "      123" );
}

TEST_F( StringTests, AlginLeft )
{
	std::string testNmb( " 123" );
	Moge::Format::align( testNmb, false );
	GTEST_ASSERT_EQ( testNmb, "123 " );
}

TEST_F( StringTests, AlginRightWrong )
{
	std::string testNmb( " 123" );
	Moge::Format::align( testNmb, true );
	GTEST_ASSERT_EQ( testNmb, " 123" );
}