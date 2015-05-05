#ifndef __PICTURE__Y__
#define __PICTURE__Y__

#include <boost/filesystem.hpp>

class CPicture
{
public:
	CPicture();
	CPicture( const boost::filesystem::path& location );
	void Draw( const unsigned int xPost, const unsigned int yPos );
	CPicture& operator=( const CPicture& picture );
	void SetPictureLocation( const boost::filesystem::path& picLocation );
	void SetPictureSize( const unsigned int width, const unsigned int height );
	const std::string& GetImgLoc()const;


private:
	boost::filesystem::path m_location;
	std::string m_name;
	unsigned int m_xSize;
	unsigned int m_ySize;

};


#endif