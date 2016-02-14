#pragma once

#include "GeneralUtilities.h"

class CPicture
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
	String m_name;
	UInt m_width;
	UInt m_height;

};