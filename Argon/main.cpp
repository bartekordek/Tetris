#include "libArgon.hpp"

int main(int argc, char *argv[])
{
	const std::string fileName( argv[1] );
	Argon argon( fileName );
    if( argon.Init() )
    {
        argon.MainLoop();
    }
	return 0;
}
