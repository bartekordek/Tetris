#pragma once

#include "gtest/gtest.h"

namespace Moge
{
    class Engine;
}

class EngineTests: public ::testing::Test
{
protected:
    EngineTests() = default;
    virtual ~EngineTests() = default;

    static void SetUpTestCase();
    static void TearDownTestCase();

    static Moge::Engine* engine;
};

