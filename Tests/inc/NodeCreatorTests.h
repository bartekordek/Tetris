#pragma once

#include "EngineTests.h"
#include <Filesystem.h>

class NodeCreatorTests: public EngineTests
{
protected:
    NodeCreatorTests() = default;
	virtual ~NodeCreatorTests() = default;

	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
	
	static void SetUpTestCase()
	{
		testBmpFile = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
	}

	static void TearDownTestCase()
	{
	}

	static Moge::Path testBmpFile;
};