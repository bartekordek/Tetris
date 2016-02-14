#pragma once

#include "MyString.h"

namespace FS
{
	class File
	{
	public:
		File();
		virtual ~File();

		File( const char* inputPath );
		File( const std::string& inputPath );
		File( const String& inputPath );
		File( const File& inputPath );
		
		const std::string& string()const;

		const bool operator==( const std::string& inputPath )const;
		const bool operator==( const String& inputPath )const;
		const bool operator==( const File& inputPath )const;

		File& operator=( const std::string& inputPath );
		File& operator=( const String& inputPath );
		File& operator=( const File& inputPath );

		const bool empty()const;
		const String& extension()const;

	protected:
	private:
		void SetUpPaths( const String& fullPath );
		void SetFullPath( const String& fullPath );
		void GetExtension();
		void GetBaseName();

		String mFullPath;
		String mExtension;
		String mBaseName;
		String mPathWithoutFile;

		static String sSeparator;
	};
}