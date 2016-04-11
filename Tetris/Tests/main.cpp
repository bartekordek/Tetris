#include "gtest/gtest.h"
#include "FilesystemTests.h"

#include <string>

int main( int argc, char **argv )
{
	::testing::InitGoogleTest( &argc, argv );
	const int result = RUN_ALL_TESTS();
	std::getchar();
	return result;
}