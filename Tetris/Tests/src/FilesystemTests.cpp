#include "FilesystemTests.h"
#include "FileSystem.h"

TEST_F( FilesystemTests, GetExtension )
{
	MOGE::Path file("C:\\SomeDirectory\\SomeFile.extension");
	ASSERT_EQ( file.Extension(), "extension" );
}

TEST_F( FilesystemTests, GetDirectory )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.Directory(), "C:\\SomeDirectory" );
}

TEST_F( FilesystemTests, GetBaseName )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.BaseName(), "SomeFile" );
}

TEST_F( FilesystemTests, GetFullPath )
{
	MOGE::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.FullPath(), "C:\\SomeDirectory\\SomeFile.extension" );
}

TEST_F( FilesystemTests, FileExistence )
{
	MOGE::Path file("C:\\Windows\\System32\\xcopy.exe");
	ASSERT_EQ( file.Exist(), true );
}

TEST_F( FilesystemTests, FileNotExist )
{
	MOGE::Path file( "C:\\Windows\\System32\\xcopy312312.exe" );
	ASSERT_EQ( file.Exist(), false );
}