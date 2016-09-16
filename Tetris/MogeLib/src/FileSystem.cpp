#include <string>

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

#include "FileSystem.h"

using ErrorCode = boost::system::error_code;

namespace MogeLib
{
	Path::Path(): mFullPath("")
	{
	}

	Path::~Path()
	{
	}

	Path::Path( const char* inputPath ): mFullPath( inputPath )
	{
		SetUpPaths( inputPath );
	}

	Path::Path( const String& inputPath ): mFullPath( inputPath )
	{
		SetUpPaths( inputPath );
	}

	Path::Path( const Path& inputPath ): mFullPath( inputPath.c_str() )
	{
		SetUpPaths( mFullPath );
	}

	const char* Path::c_str()const
	{
		return mFullPath.c_str();
	}

	const bool Path::operator==( const Path& inputPath )const
	{
		return mFullPath ==  inputPath.mFullPath;
	}

	const bool Path::operator==( const String& inputPath )const
	{
		return mFullPath ==  inputPath ;
	}

	const bool Path::operator==( const std::string& inputPath )const
	{
		return mFullPath == inputPath;
	}

	Path& Path::operator=( const std::string& inputPath )
	{
		SetUpPaths( inputPath );
		return *this;
	}

	Path& Path::operator=( const String& inputPath )
	{
		SetUpPaths( inputPath );
		return *this;
	}

	Path& Path::operator=( const Path& inputPath )
	{
		SetUpPaths( inputPath.c_str() );
		return *this;
	}

	Path& Path::operator=( const char* inputPath )
	{
		SetUpPaths( inputPath );
		return *this;
	}

	const bool Path::empty()const
	{
		return mFullPath.empty();
	}

	const String& Path::Extension()const
	{
		return mExtension;
	}

	const String& Path::FullPath()const
	{
		return mFullPath;
	}

	const String& Path::BaseName()const
	{
		return mBaseName;
	}

	const String& Path::Directory()const
	{
		return mDirectory;
	}

	const String& Path::GetDirectorySeparator()
	{
		return directorySeparator;
	}

	const String& Path::GetExtensionSeparator()
	{
		return extensionSeparator;
	}

	const Path Path::GetCurrentDirectory()
	{
		Path path( boost::filesystem::current_path().string() );
		return path;
	}

	const bool Path::Exist()const
	{
		return FileExists( mFullPath.c_str() );
	}

	void Path::SetUpPaths( const String& fullPath )
	{
		mFullPath = fullPath;
		mExtension = GetExtension( fullPath );
		mBaseName = GetBaseName( fullPath );
		mDirectory = GetDirectory( fullPath );
	}

	void Path::SetFullPath( const String& fullPath )
	{
		mFullPath = fullPath;
	}

#ifdef _WIN32
	String Path::directorySeparator = "\\";
#else
	String Path::directorySeparator = "/";
#endif
	String Path::extensionSeparator = ".";

	const String GetBaseName( const String& path )
	{
		String baseName = "";
		auto separatorPosition = path.rfind( Path::GetDirectorySeparator() );
		if( String::npos != separatorPosition )
		{
			baseName = path.substr( ++separatorPosition );
			baseName = baseName.Replace( String(".") + GetExtension( path ), String( "" ) );
		}
		return baseName;
	}

	const String GetExtension( const String& path )
	{
		String extension = "";
		auto mExtensionDotPosition = path.rfind( Path::GetExtensionSeparator() );
		if( String::npos != mExtensionDotPosition )
		{
			extension = path.substr( ++mExtensionDotPosition );
		}
		return extension;
	}

	const String GetDirectory( const String& path )
	{
		String directory = "";
		auto lastSlashPosition = path.rfind( Path::GetDirectorySeparator() );
		if( String::npos != lastSlashPosition )
		{
			directory = path.substr( 0, lastSlashPosition );
		}
		return directory;
	}

	const bool FileExists( const String& path, std::string& errorMessage )
	{
		ErrorCode errocode;
		const bool result = boost::filesystem::is_regular_file( path.c_str(), errocode );
		errorMessage = errocode.message();
		return  result;
	}

	Path operator+( const Path& path, const std::string& inputPath )
	{
		Path result( path.FullPath().string() + inputPath );
		return result;
	}

	Path operator+( const Path& path, const String& inputPath )
	{
		Path result( path.FullPath() + inputPath );
		return result;
	}

	Path operator+( const Path& path, const Path& inputPath )
	{
		Path result( path.FullPath() + inputPath.FullPath() );
		return result;
	}

	Path operator+( const Path& path, const char* inputPath )
	{
		std::string string = std::string( path.c_str() ) + std::string( inputPath );
		Path result( string );
		return result;
	}
}