#pragma once

#include "EngineTests.h"
#include "File.h"

class ImageCreatorTests: public EngineTests
{
protected:
    ImageCreatorTests() = default;
    virtual ~ImageCreatorTests() = default;

    virtual void SetUp()
    {
        ASSERT_EQ( testBmpFile.Exist(), true );
    }

    virtual void TearDown()
    {
    }

    static void SetUpTestCase();
    static Moge::Path testBmpFile;

};