#pragma once

#include "gtest/gtest.h"

#include "FileSystem.h"

class ImageCreatorTests: public ::testing::Test
{
protected:
	ImageCreatorTests()
	{
	}

	virtual ~ImageCreatorTests()
	{
	}

	virtual void SetUp()
	{
		ASSERT_EQ( testBmpFile.Exist(), true );
	}

	virtual void TearDown()
	{
	}

	static void SetUpTestCase()
	{
		testBmpFile = MogeLib::Path::GetCurrentDirectory() + "\\..\\pic\\BackGroundBlock.bmp";
	}

	static MogeLib::Path testBmpFile;
};