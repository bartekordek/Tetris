#pragma once

#include "Singleton.h"
//#include "MyString.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

using String = std::string;

using Mutex = std::mutex;
using CUInt = const unsigned int;
typedef const signed int CInt;
typedef unsigned int UInt;
typedef boost::filesystem::path FsPath;
using Path = boost::filesystem::path;
//typedef Fs::path Path;
//using Path = String;
//using Path = FS::File;

using Thread = std::thread;

template<typename T>
using Vector = std::vector < T > ;

template<typename KEY, typename TYPE>
using UnorderedMap = std::unordered_map<KEY, TYPE>;

template<typename T, typename Y>
using Pair = std::pair < T, Y > ;

void PrintInputParameters( UInt argc, char* argv[] );

using ErrorCode = boost::system::error_code;

const bool FileExists( const Path& fileLocation, ErrorCode& errorCode );

template <typename TYPE>
using SharedPtr = std::shared_ptr<TYPE>;

//template <typename TYPE>
//using MakeSharedPtr = std::make_shared;


class GeneralUtilites
{
public:
	static const std::string FixBoostFilesystemCrash();
protected:
private:
	
	static std::string mBoostFileSystemCrashFix;
};