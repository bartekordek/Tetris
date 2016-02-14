#include "GeneralUtilities.h"
#include <iostream>

void PrintInputParameters( UInt argc, char* argv[] )
{
	while( argc-- )
	{
		std::cout << "Argument " << argc << ": " << argv[argc] << std::endl;
	}
}

const bool FileExists( const Path& fileLocation, ErrorCode& errorCode )
{
	return boost::filesystem::is_regular_file( FsPath( fileLocation.c_str() ), errorCode );
}

std::string GeneralUtilites::mBoostFileSystemCrashFix;

const std::string GeneralUtilites::FixBoostFilesystemCrash()
{
	//boost::filesystem::path::imbue();
	boost::filesystem::path::imbue( std::locale( "C" ) );
	return std::string();
}