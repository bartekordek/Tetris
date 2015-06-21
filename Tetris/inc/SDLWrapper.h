#ifndef __SDL__WRAP__
#define __SDL__WRAP__

#include "Utils.h"
#include "MainGrid.h"
#include "SDL/SDL.h"

/*
* @brief Simple wrapper for SDL graphic library (1.2).
* @details
*/
class CSDLWrapper
{
public:
	static CSDLWrapper* Instance();
	static void Destroy();
	/*
	 * @brief Creates window with specific size.
	 * @param[in] const unsigned int width of window.
	 * @param[in] const unsigned int height of window.
	 */
	void CreateWindow( CUInt width = 0, CUInt height = 0 );
	/*
	 * @brief Adds image to pool.
	 * @param[in] std::string file path.
	 */
	void AddImage( const String& path );
	/*
	 * @brief Applies selected image to selected place.
	 * @param[in] const unsigned int index of image.
	 * @param[in] const unsigned int postion in x.
	 * @param[in] const unsigned int postion in y.
	 */
	void ApplyImage( CUInt imgIndex, CUInt x, CUInt y );
	/*
	 * @brief Display method for main grid.
	 * @param[in] CMainGrid object.
	 */
	void Display( const CMainGrid& grid );
	/*
	 * @brief Actualizes window.
	 */
	void Actualize();
	/*
	 * @brief MainLoop.
	 */
	void MainLoop();

private:
	CSDLWrapper();
	virtual ~CSDLWrapper();
	static CSDLWrapper* s_instance;
	void m_ShowImages();

	UInt m_width;
	UInt m_height;
	SDL_Surface* screen;
	std::vector<SDL_Surface*> images;
};

#endif 