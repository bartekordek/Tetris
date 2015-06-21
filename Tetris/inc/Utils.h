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
typedef Fs::path Path;
typedef std::string String;
typedef COrientation::Direction Direction;

template<typename T>
using Vector = std::vector < T > ;

#endif