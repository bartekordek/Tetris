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
	return boost::filesystem::is_regular_file( fileLocation, errorCode );
}