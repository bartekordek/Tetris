#include "Picture.h"
#include <iostream>

CPicture::CPicture(): 
	m_location(""), 
	m_name(""), 
	m_width(0),
	m_height(0)
{
}

CPicture::CPicture( const Path location, CUInt width, CUInt height ):
					m_location(location),
					m_width(width),
					m_height(height)
{
}

CPicture::~CPicture()
{
}

CPicture& CPicture::operator=( const CPicture& picture )
{
	if( this != &picture )
	{
		m_location = picture.m_location;
		m_name = picture.m_name;
		m_width = picture.m_width;
		m_height = picture.m_height;
	}
	return *this;
}

void CPicture::SetPictureLocation( Path picLocation )
{
	boost::system::error_code errorText;
	if( true == boost::filesystem::is_regular_file( picLocation, errorText ) )
	{
		m_location = picLocation;
	}
	else
	{
		std::cerr << "IMAGE LOCATION ERROR: " << errorText << std::endl;
	}
}

void CPicture::SetPictureSize( CUInt width, CUInt height )
{
	m_width = width;
	m_height = height;
}

const String CPicture::GetImgLoc()const
{
//	return m_location.string();
	return m_location;
}

CUInt CPicture::GetImgWidth()const
{
	return m_width;
}

CUInt CPicture::GetImgHeight()const
{
	return m_height;
}