#include "Picture.h"


#include <iostream>

CPicture::CPicture(): 
	width(0),
	height(0)
{
}

CPicture::CPicture( const char* location, CUInt width, CUInt height ):
					location( location ),
					width(width),
					height(height)
{
}

CPicture::~CPicture()
{
}

CPicture& CPicture::operator=( const CPicture& picture )
{
	if( this != &picture )
	{
		Moge::Name::operator=(picture);
		location = picture.location;
		width = picture.width;
		height = picture.height;
	}
	return *this;
}

void CPicture::SetPictureLocation( const char* picLocation )
{
	if( Moge::Path( picLocation ).Exist() )
	{
		this->location = picLocation;
	}
	else
	{
		std::cerr << "FILE" << picLocation << "DOES NOT EXIST." << std::endl;
	}
}

void CPicture::SetPictureSize( CUInt width, CUInt height )
{
	this->width = width;
	this->height = height;
}