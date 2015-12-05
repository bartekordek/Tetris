#ifndef __UTILS__
#define __UTILS__

#include <vector>
#include <boost/filesystem.hpp>
#include <string>
#include "Orientation.h"
#include <thread>
#include <mutex>

typedef std::mutex Mutex;

typedef std::string String;

namespace Fs = boost::filesystem;
typedef const unsigned int CUInt;
typedef const signed int CInt;
typedef unsigned int UInt;
//typedef Fs::path Path;
typedef String Path;
typedef COrientation::Direction Direction;
typedef std::thread Thread;

template<typename T>
using Vector = std::vector < T > ;
#endif