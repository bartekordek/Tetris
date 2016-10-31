#pragma once

#include <FileSystem.h>
#include "Named.h"
#include "Aliases.h"

class Path;
class CPicture: public Moge::Name
{
public:
	CPicture();
	CPicture( const char* path, CUInt width = 10, CUInt height = 10 );
	~CPicture();
	CPicture& operator=( const CPicture& picture );
	void SetPictureLocation( const char* picLocation );
	void SetPictureSize( CUInt width, CUInt height );

private:
	Moge::Path location;
	UInt width;
	UInt height;
};