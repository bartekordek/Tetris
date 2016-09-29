#include "Picture.h"


#include <iostream>

CPicture::CPicture(): 
	m_width(0),
	m_height(0)
{
}

CPicture::CPicture( const char* location, CUInt width, CUInt height ):
					m_width(width),
					m_height(height)
{
	this->m_location = location;
}

CPicture::~CPicture()
{
}

CPicture& CPicture::operator=( const CPicture& picture )
{
	if( this != &picture )
	{
		Moge::Name::operator=(picture);
		m_location = picture.m_location;
		m_width = picture.m_width;
		m_height = picture.m_height;
	}
	return *this;
}

void CPicture::SetPictureLocation( const char* picLocation )
{
	if( Moge::Path( picLocation ).Exist() )
	{
		m_location = picLocation;
	}
	else
	{
		std::cerr << "FILE" << picLocation << "DOES NOT EXIST." << std::endl;
	}
}

void CPicture::SetPictureSize( CUInt width, CUInt height )
{
	m_width = width;
	m_height = height;
}

const char* CPicture::GetImgLoc()const
{
	return m_location.c_str();
}