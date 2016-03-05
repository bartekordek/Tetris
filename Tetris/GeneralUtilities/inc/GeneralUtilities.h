#pragma once

#include "Singleton.h"
#include "FileSystem.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>

using Mutex = std::mutex;
using CUInt = const unsigned int;
typedef const signed int CInt;
typedef unsigned int UInt;
typedef boost::filesystem::path FsPath;

using Path = FS::File;

using Thread = std::thread;

template<typename T>
using Vector = std::vector < T > ;

template<typename KEY, typename TYPE>
using UnorderedMap = std::unordered_map<KEY, TYPE>;

template <typename TYPE>
using Set = std::set<TYPE>;

template<typename T, typename Y>
using Pair = std::pair < T, Y > ;

void PrintInputParameters( UInt argc, char* argv[] );

using ErrorCode = boost::system::error_code;

const bool FileExists( const Path& fileLocation, ErrorCode& errorCode );

template <typename TYPE>
using SharedPtr = std::shared_ptr<TYPE>;

class GeneralUtilites
{
public:
	static const std::string FixBoostFilesystemCrash();
protected:
private:
	
	static std::string mBoostFileSystemCrashFix;
};