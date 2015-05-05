#ifndef __MAIN_GRID_Y__
#define __MAIN_GRID_Y__

#include <vector>
#include <boost/filesystem.hpp>
#include "Slab.h"

class CMainGrid
{
public:
	CMainGrid( 
		const unsigned int rowsCount = 0, 
		const unsigned int columnsCount = 0, 
		const unsigned int initialX = 0, 
		const unsigned int initialY = 0 );
	virtual ~CMainGrid();

	void SetSize( const unsigned int rowsCount,
				  const unsigned int columnsCount,
				  const unsigned int initialX = 0,
				  const unsigned int initialY = 0 );
	void SetBackgroundPicture( 
		const boost::filesystem::path& picLocation, 
		const unsigned int width, 
		const unsigned int height );

	const unsigned int GetRowsCount()const;
	const unsigned int GetColumnsCount()const;

	const std::string& GetSlabPictureLoc( const unsigned int column, const unsigned int row )const;

private:
	std::vector<CSlab> m_slab;
	unsigned int m_columnsCount;
	unsigned int m_rowsCount;
};

#endif