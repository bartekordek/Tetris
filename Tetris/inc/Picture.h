#pragma once

#include <FileSystem.h>
#include <Named.h>


using Path = MogeLib::Path;

class CPicture: public MogeLib::Name
{
public:
	CPicture();
	CPicture( const Path location, CUInt width = 10, CUInt height = 10 );
	~CPicture();
	CPicture& operator=( const CPicture& picture );
	void SetPictureLocation( const Path picLocation );
	void SetPictureSize( CUInt width, CUInt height );
	const Path GetImgLoc()const;
	CUInt GetImgWidth()const;
	CUInt GetImgHeight()const;

private:
	Path m_location;
	UInt m_width;
	UInt m_height;

};