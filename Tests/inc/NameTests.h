#pragma once

#include "MyString.h"
#include "gtest/gtest.h"

class NameTests: public ::testing::Test
{
protected:
	NameTests()
	{
	}

	virtual ~NameTests()
	{
	}

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
	Moge::MyString genericName = Moge::MyString( "Generic name." );
};