#ifndef __UTILS__
#define __UTILS__

#include <vector>
#include <boost/filesystem.hpp>
#include "Orientation.h"

namespace Fs = boost::filesystem;

class CTableCoor
{
public:
	CTableCoor( const unsigned row, const unsigned column );
	const unsigned GetRow()const;
	const unsigned GetCol()const;
private:
	unsigned m_row;
	unsigned m_column;
};

typedef std::vector<CTableCoor> CoordinatestList;
typedef Fs::path Path;

typedef std::string string;

typedef COrientation::Direction Direction;

#endif