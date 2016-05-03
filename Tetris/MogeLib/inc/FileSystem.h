#pragma once
#include <MOGE.h>
#include "MyString.h"
#include <Aliases.h>

namespace MOGE
{
	class MOGE_API Path
	{
	public:
		Path();
		virtual ~Path();

		Path( const char* inputPath );
		Path( const std::string& inputPath );
		Path( const String& inputPath );
		Path( const Path& inputPath );
		
		const std::string& string()const;
		const char* c_str()const;

		const bool operator==( const std::string& inputPath )const;
		const bool operator==( const String& inputPath )const;
		const bool operator==( const Path& inputPath )const;

		Path& operator=( const std::string& inputPath );
		Path& operator=( const String& inputPath );
		Path& operator=( const Path& inputPath );

		const bool empty()const;
		const String& Extension()const;
		const String& FullPath()const;
		const String& BaseName()const;
		const String& Directory()const;

		static const String& GetDirectorySeparator();
		static const String& GetExtensionSeparator();
		const bool Exist()const;
		

	protected:

	private:
		void SetUpPaths( const String& fullPath );
		void SetFullPath( const String& fullPath );

		String mFullPath;
		String mExtension;
		String mBaseName;
		String mDirectory;

		static String directorySeparator;
		static String extensionSeparator;
	};

	

	const String GetBaseName( const String& path );
	const String GetExtension( const String& path );
	const String GetDirectory( const String& path );
	const bool FileExists( const String& path, ErrorCode& errocode = ErrorCode() );
}