#pragma once

#include "Path.h"
#include <vector>

namespace Moge
{
	class MogeLib_API File
	{
	public:
		File() = default;
		virtual ~File() = default;
		void loadFile( const Path& filePath );
		const std::string& getLine( const unsigned int lineIndex )const;
		const std::vector<std::string*> find( const std::string& pattern );
		const std::vector<std::string>& getContents()const;
		void addLine( const std::string& line );
		void writeContents2( const Path& filePath );
		const bool isEmpty()const;
	protected:
	private:
		Path path;
		std::vector<std::string> contents;
	};
}