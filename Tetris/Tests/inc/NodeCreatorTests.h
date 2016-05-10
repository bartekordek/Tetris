#pragma once

#include "gtest/gtest.h"
#include <Filesystem.h>

class NodeCreatorTests: public ::testing::Test
{
protected:
	NodeCreatorTests()
	{
	}

	virtual ~NodeCreatorTests()
	{
	}

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
	
	static void SetUpTestCase()
	{
		testBmpFile = MOGE::Path::GetCurrentDirectory() + "\\..\\pic\\BackGroundBlock.bmp";
	}

	static void TearDownTestCase()
	{
	}

	static MOGE::Path testBmpFile;
};