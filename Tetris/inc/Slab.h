#ifndef __CSLAB__
#define __CSLAB__

#include "Picture.h"
#include "Position.h"

class CSlab
{
public:
	CSlab( const CPicture& picture );
	CSlab( const CSlab& slab );
	CSlab( const unsigned int xPos, const unsigned int yPos );
	void SetPicture( const boost::filesystem::path& picLocation, const unsigned int width, const unsigned int height );
	const std::string GetImgLoc()const;
	const unsigned int GetImgWidth()const;
	const unsigned int GetImgHeight()const;
	const unsigned int GetX()const;
	const unsigned int GetY()const;

private:
	bool m_hasBorder;
	CPicture m_picture;
	CPosition m_position;
};

#endif