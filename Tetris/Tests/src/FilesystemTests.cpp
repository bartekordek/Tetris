#include "FilesystemTests.h"
#include "FileSystem.h"

TEST_F( FilesystemTests, GetExtension )
{
	Moge::Path file("C:\\SomeDirectory\\SomeFile.extension");
	ASSERT_EQ( file.Extension(), "extension" );
}

TEST_F( FilesystemTests, GetDirectory )
{
	Moge::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.Directory(), "C:\\SomeDirectory" );
}

TEST_F( FilesystemTests, GetBaseName )
{
	Moge::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.BaseName(), "SomeFile" );
}

TEST_F( FilesystemTests, GetFullPath )
{
	Moge::Path file( "C:\\SomeDirectory\\SomeFile.extension" );
	ASSERT_EQ( file.FullPath(), "C:\\SomeDirectory\\SomeFile.extension" );
}

TEST_F( FilesystemTests, FileExistence )
{
	Moge::Path file("C:\\Windows\\System32\\xcopy.exe");
	ASSERT_EQ( file.Exist(), true );
}

TEST_F( FilesystemTests, FileNotExist )
{
	Moge::Path file( "C:\\Windows\\System32\\xcopy312312.exe" );
	ASSERT_EQ( file.Exist(), false );
}