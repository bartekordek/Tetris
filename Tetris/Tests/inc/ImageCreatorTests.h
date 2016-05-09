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
		ASSERT_EQ( genericWindowsImagePath.Exist(), true );
	}

	virtual void TearDown()
	{
	}

	MOGE::Path genericWindowsImagePath = "C:\\Windows\\SysWOW64\\oobe\\background.bmp";
};