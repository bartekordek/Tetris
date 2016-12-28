#include <string>

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

#include "FileSystem.h"

using ErrorCode = boost::system::error_code;

namespace Moge
{
	Path::Path(): mFullPath("")
	{
	}

	Path::~Path()
	{
	}

	Path::Path( const char* inputPath ): mFullPath( inputPath )
	{
		SetUpPaths( MyString(inputPath) );
	}

	Path::Path( const MyString& inputPath ): mFullPath( inputPath )
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

	const bool Path::operator==( const MyString& inputPath )const
	{
		return mFullPath ==  inputPath ;
	}

	const bool Path::operator==( const std::string& inputPath )const
	{
		return mFullPath == inputPath;
	}

	Path& Path::operator=( const std::string& inputPath )
	{
		SetUpPaths( MyString( inputPath ) );
		return *this;
	}

	Path& Path::operator=( const MyString& inputPath )
	{
		SetUpPaths( inputPath );
		return *this;
	}

	Path& Path::operator=( const Path& inputPath )
	{
		SetUpPaths( MyString(inputPath.c_str()) );
		return *this;
	}

	Path& Path::operator=( const char* inputPath )
	{
		SetUpPaths( MyString( inputPath ) );
		return *this;
	}

	const bool Path::empty()const
	{
		return mFullPath.empty();
	}

	const MyString& Path::Extension()const
	{
		return mExtension;
	}

	const MyString& Path::FullPath()const
	{
		return mFullPath;
	}

	const MyString& Path::BaseName()const
	{
		return mBaseName;
	}

	const MyString& Path::Directory()const
	{
		return mDirectory;
	}

	const MyString& Path::GetDirectorySeparator()
	{
		return directorySeparator;
	}

	const MyString& Path::GetExtensionSeparator()
	{
		return extensionSeparator;
	}

	const Path Path::GetCurrentDirectory()
	{
		Path path( MyString( boost::filesystem::current_path().string() ) );
		return path;
	}

	const bool Path::Exist()const
	{
		std::string error;
		return FileExists( MyString( mFullPath.c_str() ), error );
	}

	void Path::SetUpPaths( const MyString& fullPath )
	{
		SetFullPath( fullPath );
		mExtension = GetExtension( fullPath );
		mBaseName = GetBaseName( fullPath );
		mDirectory = GetDirectory( fullPath );
	}

	void Path::SetFullPath( const MyString& fullPath )
	{
		mFullPath = fullPath;
	}

#ifdef _WIN32
	MyString Path::directorySeparator = MyString( "\\" );
#else
	MyString Path::directorySeparator = MyString( "/" );
#endif
	MyString Path::extensionSeparator = MyString( "." );

	const MyString GetBaseName( const MyString& path )
	{
		MyString baseName;
		auto separatorPosition = path.rfind( Path::GetDirectorySeparator() );
		if( MyString::npos != separatorPosition )
		{
			baseName = MyString( path.substr( ++separatorPosition ) );
			baseName = baseName.Replace( MyString(".") + GetExtension( path ), MyString( "" ) );
		}
		return baseName;
	}

	const MyString GetExtension( const MyString& path )
	{
		MyString extension;
		auto mExtensionDotPosition = path.rfind( Path::GetExtensionSeparator() );
		if( MyString::npos != mExtensionDotPosition )
		{
			extension = MyString( path.substr( ++mExtensionDotPosition ) );
		}
		return extension;
	}

	const MyString GetDirectory( const MyString& path )
	{
		MyString directory;
		auto lastSlashPosition = path.rfind( Path::GetDirectorySeparator() );
		if( MyString::npos != lastSlashPosition )
		{
			directory = MyString( path.substr( 0, lastSlashPosition ) );
		}
		return directory;
	}

	const bool FileExists( const MyString& path, std::string& errorMessage )
	{
		ErrorCode errocode;
		const bool result = boost::filesystem::is_regular_file( path.c_str(), errocode );
		errorMessage = errocode.message();
		return  result;
	}

	Path operator+( const Path& path, const std::string& inputPath )
	{
		Path result( MyString( path.FullPath().string() + inputPath ) );
		return result;
	}

	Path operator+( const Path& path, const MyString& inputPath )
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
		Path result( string.c_str() );
		return result;
	}
}