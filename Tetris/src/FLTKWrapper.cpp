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
	m_window = new Fl_Window( 0, 0, xSize, ySize, "Tetris" );
	m_startButton = m_CreateNewButton( 200, 200, "Start" );
}

Fl_Button* FLTKWrapper::m_CreateNewButton( 
	const unsigned int xPos, 
	const unsigned int yPos, 
	const std::string& buttonText,
	const unsigned int width,
	const unsigned int height)
{
	return new Fl_Button( xPos, yPos, width, height, buttonText.c_str() );
}

void FLTKWrapper::ShowWindow()
{
	Fl::run(); // Here program freezes. FLTK is waiting for user input.
}

void FLTKWrapper::Display( const CMainGrid& grid )
{
	const unsigned int rowsCount = grid.GetRowsCount();
	const unsigned int colsCount = grid.GetColumnsCount();
	const unsigned int slabCount = rowsCount*colsCount;
	std::string gridImageLocation = grid.GetSlabPictureLoc( 0 );	
	Fl_BMP_Image* image = new Fl_BMP_Image( gridImageLocation.c_str() );

	for( unsigned int i = 0; i < slabCount; ++i )
	{
		DisplayImage( image, CPoint( grid.GetSlabPositionX( i ) * 10, grid.GetSlabPositionY( i ) * 10 ) );
		// TODO Remove magic numbers (10, 10) - image size of bmps i made
	}
	m_window->show();
}

void FLTKWrapper::Display( const CBrick& brick )
{

}

void FLTKWrapper::DisplayImage( Fl_RGB_Image* image,
								const CPoint& where,
								const unsigned width,
								const unsigned height)
{
	Fl_Box* box = new Fl_Box( where.GetX(), where.GetY(), width, height );
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