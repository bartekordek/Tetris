#include "Path.h"

namespace MOGE
{
	Path::Path():
		mPath(""),
		mBaseName(""),
		mExtension(""),
		mDirectory("")
	{
	}

	Path::Path( const Path& path )
	{
		*(this) = path;
	}

	Path::~Path()
	{
	}


	Path& Path::operator=( const Path& path )
	{
		if( this != &path )
		{
			this->mPath = path.mPath;
			this->mBaseName = path.mBaseName;
			this->mExtension = path.mExtension;
			this->mDirectory = path.mDirectory;
		}
		return *this;
	}

	void Path::SetPath( const Path& path )
	{

	}

	void Path::SetPath( const String& path )
	{

	}

	void Path::SetPath( const std::string& path )
	{

	}

	const String& Path::GetPath()const
	{
		return mPath;
	}

	const String& Path::GetBaseName()const
	{
		return mBaseName;
	}

	const String& Path::GetExtension()const
	{
		return mExtension;
	}

	const String& Path::GetDirectory()const
	{
		return mDirectory;
	}

	const String Path::ExtractExtension( const String& path )
	{
		String result = "";
		auto mDotPosition = path.rfind( extensionSeparator );
		if( String::npos != mDotPosition )
		{
			result = path.substr( mDotPosition );
		}
		return result;
	}

