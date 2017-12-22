#pragma once

#include <MogeLib.h>
#include "CUL/Path.hpp"
#include <vector>

namespace Moge
{
    class MogeLib_API File
    {
    public:
        File() = default;
        virtual ~File() = default;
        void loadFile( const CUL::FS::Path& filePath );
        const std::string& getLine( const unsigned int lineIndex )const;
        const std::vector<std::string*> find( const std::string& pattern );
        const std::vector<std::string>& getContents()const;
        void addLine( const std::string& line );
        void writeContents2( const CUL::FS::Path& filePath );
        const bool isEmpty()const;
    protected:
    private:
        CUL::FS::Path path;
        std::vector<std::string> contents;
    };
}