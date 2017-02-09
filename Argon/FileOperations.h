#pragma once

#include <string>
#include <vector>

class FileOperations
{
public:
	FileOperations();
	virtual ~FileOperations();
	void loadFile( const std::string& fileName );
	const std::vector<std::string>& getLines()const;
	static void write2File( const std::vector<std::string>& lines, const std::string& outputFileName );

private:
	std::vector<std::string> lines;
};

