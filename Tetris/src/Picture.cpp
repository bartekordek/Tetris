#include "Picture.h"
#include <iostream>

CPicture::CPicture(): 
	m_location(""), 
	m_name(""), 
	m_width(0),
	m_height(0)
{

}

CPicture::CPicture( const boost::filesystem::path& location,
					const unsigned int width,
					const unsigned int height ):
					m_location(location),
					m_width(width),
					m_height(height)

{

}

CPicture::~CPicture()
{

}

void CPicture::Draw( const unsigned int xPost, const unsigned int yPos )
{

}

CPicture& CPicture::operator=( const CPicture& picture )
{
	m_location = picture.m_location;
	m_name = picture.m_name;
	m_width = picture.m_width;
	m_height = picture.m_height;

	return *this;
}

void CPicture::SetPictureLocation( const boost::filesystem::path& picLocation )
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

void CPicture::SetPictureSize( const unsigned int width, const unsigned int height )
{
	m_width = width;
	m_height = height;
}

const std::string CPicture::GetImgLoc()const
{
	return m_location.string();
}

const unsigned int CPicture::GetImgWidth()const
{
	return m_width;
}

const unsigned int CPicture::GetImgHeight()const
{
	return m_height;
}