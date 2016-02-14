#include "FileSystem.h"

namespace FS
{
#ifdef _WIN32
	String File::sSeparator = String( "\\" );
#else
	String File::sSeparator = "/";
#endif

	File::File():
		mFullPath("")
	{
	}

	File::~File()
	{
	}

	File::File( const char* inputPath ):
		mFullPath( inputPath )
	{

	}

	File::File( const std::string& inputPath ):
		mFullPath( inputPath )
	{
	}

	File::File( const String& inputPath ):
		mFullPath( inputPath )
	{
	}

	File::File( const File& inputPath ):
		mFullPath( inputPath.string() )
	{
	}

	const std::string& File::string()const
	{
		return mFullPath;
	}

	const char* File::c_str()const
	{
		return mFullPath.c_str();
	}

	const bool File::operator==( const File& inputPath )const
	{
		return mFullPath ==  inputPath.mFullPath;
	}

	const bool File::operator==( const String& inputPath )const
	{
		return mFullPath ==  inputPath ;
	}

	const bool File::operator==( const std::string& inputPath )const
	{
		return mFullPath == inputPath;
	}

	File& File::operator=( const std::string& inputPath )
	{
		mFullPath = inputPath;
		return *this;
	}

	File& File::operator=( const String& inputPath )
	{
		mFullPath = inputPath;
		return *this;
	}

	File& File::operator=( const File& inputPath )
	{
		if( this != &inputPath )
		{
			mFullPath = inputPath.mFullPath;
		}
		return *this;
	}

	const bool File::empty()const
	{
		return mFullPath.empty();
	}

	const String& File::extension()const
	{
		return mExtension;
	}

	void File::SetUpPaths( const String& fullPath )
	{
		SetFullPath( fullPath );
		GetExtension();
		GetBaseName();
	}

	void File::SetFullPath( const String& fullPath )
	{
		mFullPath = fullPath;
	}

	void File::GetExtension()
	{
		auto mExtensionDotPosition = mFullPath.rfind( '.' );
		if( String::npos != mExtensionDotPosition )
		{
			mExtension = mFullPath.substr( mExtensionDotPosition, mFullPath.length() );
		}
	}

	void File::GetBaseName()
	{
		auto separatorPosition = mFullPath.rfind( sSeparator.c_str() );
		if( String::npos != separatorPosition )
		{
			mBaseName = mFullPath.substr( separatorPosition, mFullPath.length() );
			mBaseName = mBaseName.Replace( mExtension, String( "" ) );
		}
	}
}