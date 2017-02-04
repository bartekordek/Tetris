#include "FileOperations.h"
#include <fstream>

FileOperations::FileOperations()
{
}

FileOperations::~FileOperations()
{
}

void FileOperations::loadFile( const std::string& fileName )
{
	std::ifstream infile( fileName );
	std::string line;
	while( std::getline( infile, line ) )
	{
		this->lines.push_back( line );
	}
}

const std::vector<std::string>& FileOperations::getLines()const
{
	return this->lines;
}

void FileOperations::write2File( const std::vector< std::string > lines, const std::string& outputFileName )
{
	std::fstream file;
	file.open( outputFileName, std::fstream::out );
	for( const std::string& line : lines )
	{
		file << line << std::endl;
	}
	file.close();
}