#ifndef __PICTURE__Y__
#define __PICTURE__Y__

#include "Utils.h"

class CPicture
{
public:
	CPicture();
	CPicture( const Path& location, 
			  const unsigned int width = 10, 
			  const unsigned int height = 10 );
	void Draw( const unsigned int xPost, const unsigned int yPos );
	CPicture& operator=( const CPicture& picture );
	void SetPictureLocation( const Path& picLocation );
	void SetPictureSize( const unsigned int width, const unsigned int height );
	const String GetImgLoc()const;
	const unsigned int GetImgWidth()const;
	const unsigned int GetImgHeight()const;

private:
	Path m_location;
	String m_name;
	unsigned int m_width;
	unsigned int m_height;

};


#endif