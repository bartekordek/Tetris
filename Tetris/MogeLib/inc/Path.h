#pragma once

#include "GeneralUtilities.h"

namespace MOGE
{
	class Path
	{
	public:
		Path();
		Path( const Path& path );
		~Path();

		Path& operator=( const Path& path );

		void SetPath( const Path& path );
		void SetPath( const String& path );
		void SetPath( const std::string& path );

		const String& GetPath()const;
		const String& GetBaseName()const;
		const String& GetExtension()const;
		const String& GetDirectory()const;

		static const String ExtractExtension( const String& path );

	protected:
		static String mDirectorySeparator;
		static String mExtensionSeparator;

	private:

		String mPath;
		String mBaseName;
		String mExtension;
		String mDirectory;

	};
}