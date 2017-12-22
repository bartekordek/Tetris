#include "File.h"
#include <fstream>

namespace Moge
{
    void File::loadFile( const CUL::FS::Path& filePath )
    {
        std::ifstream infile( filePath.getPath() );
        std::string line;
        while( std::getline( infile, line ) )
        {
            this->contents.push_back( line );
        }
    }

    const std::string& File::getLine( const unsigned lineIndex ) const
    {
        if( lineIndex >= static_cast<unsigned int>( this->contents.size() )  )
        {
            static std::string tempres( "" );
            return tempres;
        }
        return this->contents.at( lineIndex );
    }

    const std::vector< std::string* > File::find( const std::string& pattern )
    {
        std::vector< std::string* > result;
        for( std::string& line: this->contents )
        {
            if( line.find( pattern ) != std::string::npos )
            {
                result.push_back( &line );
            }
        }
        return result;
    }

    const std::vector<std::string> & File::getContents() const
    {
        return this->contents;
    }

    void File::addLine( const std::string& line )
    {
        this->contents.push_back( line );
    }

    void File::writeContents2( const CUL::FS::Path& filePath )
    {
        std::fstream file;
        file.open( filePath.getPath(), std::fstream::out );
        for( const std::string& line : this->contents )
        {
            file << line << std::endl;
        }
        file.close();
    }

    const bool File::isEmpty() const
    {
        return this->contents.size() == 0;
    }
}