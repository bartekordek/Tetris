#include "Slab.h"

CSlab::CSlab(const CPicture& picture): 
	m_hasBorder( false ),
	m_picture( picture ),
	m_position( CPosition() )
{

}

CSlab::CSlab( const CSlab& slab ): 
	m_hasBorder( slab.m_hasBorder ),
	m_picture( slab.m_picture ),
	m_position( CPosition() )
{

}

CSlab::CSlab( const unsigned int xPos, const unsigned int yPos ):
	m_hasBorder( false ),
	m_picture( CPicture() ),
	m_position( CPosition( xPos, yPos ) )
{
}

void CSlab::SetPicture( const boost::filesystem::path& picLocation, const unsigned int width, const unsigned int height )
{
	m_picture.SetPictureLocation( picLocation );
	m_picture.SetPictureSize( width, height );
}

const std::string CSlab::GetImgLoc()const
{
	return m_picture.GetImgLoc();
}

const unsigned int CSlab::GetImgWidth()const
{
	return m_picture.GetImgWidth();
}

const unsigned int CSlab::GetImgHeight()const
{
	return m_picture.GetImgHeight();
}

const unsigned int CSlab::GetX()const
{
	return m_position.GetX();
}

const unsigned int CSlab::GetY()const
{
	return m_position.GetY();
}