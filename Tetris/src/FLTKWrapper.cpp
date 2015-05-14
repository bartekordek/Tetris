#include "FLTKWrapper.h"
#include <cstddef>
#include <FL/fl_draw.H>


FLTKWrapper::FLTKWrapper(): m_window( NULL )
{
}

FLTKWrapper::~FLTKWrapper()
{
	delete m_window;
}

FLTKWrapper* FLTKWrapper::Instance()
{
	if( NULL == s_instance )
	{
		s_instance = new FLTKWrapper();
	}
	return s_instance;
}

void FLTKWrapper::InitWindow( const unsigned int xSize, const unsigned ySize )
{
	m_window = new Fl_Window( xSize, ySize, "Tetris" );
}

void FLTKWrapper::ShowWindow()
{
	Fl::run();
}

void FLTKWrapper::Display( const CMainGrid& grid )
{
	const unsigned int rowsCount = grid.GetRowsCount();
	const unsigned int colsCount = grid.GetColumnsCount();
	const unsigned int slabCount = rowsCount*colsCount;
	std::string gridImageLocation = grid.GetSlabPictureLoc( 0 );
	const unsigned imgWidth = grid.GetImgWidth( 0, 0 );
	const unsigned imgHeight = grid.GetImgHeight( 0, 0 );

	Fl_BMP_Image* image = new Fl_BMP_Image( gridImageLocation.c_str() );

	m_window->show();
	for( unsigned int i = 0; i < slabCount; ++i )
	{
		DisplayImage( image, grid.GetSlabPositionX( i ) * 10, grid.GetSlabPositionY( i ) * 10, 10, 10 );
		// TODO Remove magic numbers (10, 10) - image size of bmps i made.
	}
	m_window->show();
}

void FLTKWrapper::DisplayImage( 
	Fl_BMP_Image* image,
	const unsigned int xPos,
	const unsigned int yPos,
	const unsigned int width,
	const unsigned int height )
{
	Fl_Box* box = new Fl_Box( xPos, yPos, 10, 10 );
	box->image( image );
	m_boxArray.push_back( box );
}

FLTKWrapper& FLTKWrapper::operator = ( const FLTKWrapper& wrapper )
{
	return FLTKWrapper();
}

FLTKWrapper::FLTKWrapper( const FLTKWrapper& wrapper )
{

}

FLTKWrapper* FLTKWrapper::s_instance = NULL;