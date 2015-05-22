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
	m_startButton->callback( m_StartButtonCallBack );
}

Fl_Button* FLTKWrapper::m_CreateNewButton( 
	const unsigned int xPos, 
	const unsigned int yPos, 
	const std::string& buttonText,
	const unsigned int width,
	const unsigned int height)
{
	std::string* bName = new std::string( buttonText );
	return new Fl_Button( xPos, yPos, width, height, bName->c_str() );
}

void FLTKWrapper::SetWinColor()
{
	m_window->color( FL_BLACK );
}

void FLTKWrapper::StartEventHandler()
{
	Fl::run(); // Event handler started.
}

void FLTKWrapper::Display( const CMainGrid& grid )
{
	const unsigned int rowsCount = grid.GetRowsCount();
	const unsigned int colsCount = grid.GetColumnsCount();
	const unsigned int slabCount = rowsCount*colsCount;
	std::string gridImageLocation = grid.GetSlabPictureLoc();	
	Fl_BMP_Image* image = new Fl_BMP_Image( gridImageLocation.c_str() );

	for( unsigned int i = 0; i < slabCount; ++i )
	{
		DisplayImage( image, CTableCoor( grid.GetSlabRow( i ) * 10, grid.GetSlabCol( i ) * 10 ) );
		// TODO Remove magic numbers (10, 10) - image size of bmps i made
	}
	m_window->show();
}

void FLTKWrapper::m_StartButtonCallBack( Fl_Widget*, void* )
{
	CGame::Instance()->StartGame();
}

void FLTKWrapper::Display( const CBrick& brick )
{
	std::string brickPicture = CBrick::GetImage();
	Fl_BMP_Image* image = new Fl_BMP_Image( brickPicture.c_str() );
	const CoordinatestList coordList = brick.GetBlockPositions() ;
	Display( image, coordList );
}

void FLTKWrapper::Display( Fl_RGB_Image* image, const CoordinatestList& coordinates )
{
	for( auto it = coordinates.begin(); it != coordinates.end(); ++it )
	{
		DisplayImage( image, CTableCoor( it->GetRow(), it->GetCol() ) );
	}
}

void FLTKWrapper::DisplayImage( Fl_RGB_Image* image,
								const CTableCoor& where,
								const unsigned width,
								const unsigned height)
{
	Fl_Box* box = new Fl_Box( where.GetRow(), where.GetCol(), width, height );
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