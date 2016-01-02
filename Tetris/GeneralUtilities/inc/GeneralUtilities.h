#pragma once

#include <vector>
#include <utility>
#include <boost/filesystem.hpp>
#include <string>

#include <thread>
#include <mutex>
#include "Singleton.h"
typedef std::mutex Mutex;

typedef std::string String;

//namespace Fs = boost::filesystem;
typedef const unsigned int CUInt;
typedef const signed int CInt;
typedef unsigned int UInt;
//typedef Fs::path Path;
typedef String Path;

using Thread = std::thread;

template<typename T>
using Vector = std::vector < T > ;

template<typename T, typename Y>
using Pair = std::pair < T, Y > ;

void PrintInputParameters( UInt argc, char* argv[] );

using ErrorCode = boost::system::error_code;

const bool FileExists( const Path& fileLocation, ErrorCode& errorCode );

template <typename TYPE>
using SharedPtr = std::shared_ptr<TYPE>;