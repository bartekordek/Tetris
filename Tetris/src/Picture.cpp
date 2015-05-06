#include "Picture.h"
#include <iostream>

CPicture::CPicture(): 
	m_location(""), 
	m_name(""), 
	m_xSize(0),
	m_ySize(0)
{

}

CPicture::CPicture( const boost::filesystem::path& location )
{

}

void CPicture::Draw( const unsigned int xPost, const unsigned int yPos )
{

}

CPicture& CPicture::operator=( const CPicture& picture )
{
	m_location = picture.m_location;
	m_name = picture.m_name;
	m_xSize = picture.m_xSize;
	m_ySize = picture.m_ySize;

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
	m_xSize = width;
	m_ySize = height;
}

const std::string CPicture::GetImgLoc()const
{
	return m_location.string();
}

const unsigned int CPicture::GetImgWidth()const
{
	return m_xSize;
}

const unsigned int CPicture::GetImgHeight()const
{
	return m_ySize;
}