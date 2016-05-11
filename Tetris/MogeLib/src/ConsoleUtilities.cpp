#include "ConsoleUtilities.h"

#include <iostream>

namespace MOGE
{
	void ConsoleUtilities::PrintInputParameters( int argc, char *argv[] )
	{
		for( int i = 0; i < argc; ++i )
		{
			std::cout << "ARG[" << i << "] = " << argv[i] << std::endl;
		}
	}
}