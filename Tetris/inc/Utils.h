#ifndef __UTILS__
#define __UTILS__

#include <vector>
#include <boost/filesystem.hpp>
#include <string>
#include <FL/Fl_Box.H>
#include "Orientation.h"

namespace Fs = boost::filesystem;

class CTableCoor
{
public:
	CTableCoor( const unsigned int row, const unsigned int column );
	const unsigned int GetRow()const;
	const unsigned int GetCol()const;
private:
	unsigned m_row;
	unsigned m_column;
};

typedef std::vector<CTableCoor> CoordinatestList;
typedef Fs::path Path;

typedef std::string String;

typedef COrientation::Direction Direction;

typedef std::vector<Fl_Box*> BoxVec;
typedef const unsigned int CUInt;
typedef const signed int CIntg;
typedef unsigned int UInt;

#endif