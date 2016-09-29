#pragma once

#include <FileSystem.h>
#include "Named.h"
#include "Aliases.h"

#include <memory>

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
	const char* GetImgLoc()const;

private:
	Moge::Path m_location;
	UInt m_width;
	UInt m_height;

};