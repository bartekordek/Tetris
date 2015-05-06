#include "FLTKWrapper.h"
#include <cstddef>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_BMP_Image.H>



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

	m_window->show();
	for( unsigned int i = 0; i < slabCount; ++i )
	{
		DisplayImage( gridImageLocation, grid.GetSlabPositionX( i ) * 10, grid.GetSlabPositionY( i ) * 10, 10, 10 );
		// TODO Remove magic numbers (10, 10) - image size of bmps i made.
	}
}

void FLTKWrapper::DisplayImage( const std::string& imagePath,
								const unsigned int xPos,
								const unsigned int yPos,
								const unsigned int width,
								const unsigned int height )
{
	m_boxArray.push_back( new Fl_Box( xPos, yPos, 10, 10 ) );
	Fl_BMP_Image image( imagePath.c_str() );
	m_boxArray.back()->image( image );	
}

FLTKWrapper& FLTKWrapper::operator = ( const FLTKWrapper& wrapper )
{
	return FLTKWrapper();
}

FLTKWrapper::FLTKWrapper( const FLTKWrapper& wrapper )
{

}

FLTKWrapper* FLTKWrapper::s_instance = NULL;