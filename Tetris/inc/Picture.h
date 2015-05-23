#ifndef __PICTURE__Y__
#define __PICTURE__Y__

#include <boost/filesystem.hpp>

class CPicture
{
public:
	CPicture();
	CPicture( const boost::filesystem::path& location, 
			  const unsigned int width = 10, 
			  const unsigned int height = 10 );
	void Draw( const unsigned int xPost, const unsigned int yPos );
	CPicture& operator=( const CPicture& picture );
	void SetPictureLocation( const boost::filesystem::path& picLocation );
	void SetPictureSize( const unsigned int width, const unsigned int height );
	const std::string GetImgLoc()const;
	const unsigned int GetImgWidth()const;
	const unsigned int GetImgHeight()const;

private:
	boost::filesystem::path m_location;
	std::string m_name;
	unsigned int m_width;
	unsigned int m_height;

};


#endif