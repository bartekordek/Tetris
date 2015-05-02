#include "Picture.h"

CPicture::CPicture(): 
	m_location(""), 
	m_name(""), 
	m_xSize(0),
	m_ySize(0)
{

}

CPicture::CPicture( boost::filesystem::path location )
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