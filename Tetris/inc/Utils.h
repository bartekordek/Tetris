#ifndef __UTILS__
#define __UTILS__

#include <vector>
#include <boost/filesystem.hpp>
#include <string>
#include "Orientation.h"

namespace Fs = boost::filesystem;

typedef const unsigned int CUInt;
typedef const signed int CIntg;
typedef unsigned int UInt;

class CTableCoor
{
public:
	CTableCoor( CUInt row, CUInt column );
	CUInt Row()const;
	CUInt Col()const;
	void Row( CUInt row );
	void Col( CUInt col );
	void ChangePosition( CUInt row, CUInt col );
	CTableCoor& operator=( const CTableCoor& coor );

private:
	unsigned m_row;
	unsigned m_column;
};

typedef std::vector<CTableCoor> CoordinatestList;
typedef Fs::path Path;

typedef std::string String;

typedef COrientation::Direction Direction;
#endif