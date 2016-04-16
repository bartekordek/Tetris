#include "FilesystemTests.h"
#include "FileSystem.h"

TEST_F( FilesystemTests, GetExtension )
{
	MOGE::Path file("C:\\SomeDirectory\\SomeFile.extension");
	EXPECT_EQ( file.Extension(), "extension" );
}

TEST_F( FilesystemTests, GetDirectory )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	EXPECT_EQ( file.Directory(), "C:\\SomeDirectory" );
}

TEST_F( FilesystemTests, GetBaseName )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	EXPECT_EQ( file.BaseName(), "SomeFile" );
}

TEST_F( FilesystemTests, GetFullPath )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	EXPECT_EQ( file.FullPath(), "C:\\SomeDirectory\\SomeFile.extension" );
}