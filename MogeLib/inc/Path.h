#pragma once
#include <MogeLib.h>
#include "MyString.h"

namespace Moge
{
    class MogeLib_API Path
    {
    public:
        Path();
        explicit Path( const char* inputPath );
        explicit Path( const MyString& inputPath );
        explicit Path( const std::string& inputPath );
        Path( const Path& inputPath );
        virtual ~Path() = default;
        
        const char* c_str()const;

        const bool operator==( const std::string& inputPath )const;
        const bool operator==( const MyString& inputPath )const;
        const bool operator==( const Path& inputPath )const;

        Path& operator=( const std::string& inputPath );
        Path& operator=( const MyString& inputPath );
        Path& operator=( const Path& inputPath );
        Path& operator=( const char* inputPath );

        const bool empty()const;
        const MyString& Extension()const;
        const MyString& FullPath()const;
        const MyString& BaseName()const;
        const MyString& Directory()const;

        static const MyString& GetDirectorySeparator();
        static const MyString& GetExtensionSeparator();
        static const Path GetCurrentDirectory();
        const bool Exist()const;

    protected:

    private:
        void SetUpPaths( const MyString& fullPath );
        void SetFullPath( const MyString& fullPath );

        MyString mFullPath;
        MyString mExtension;
        MyString mBaseName;
        MyString mDirectory;

        static MyString directorySeparator;
        static MyString extensionSeparator;
    };

    Path operator+( const Path& path, const std::string& inputPath );
    Path operator+( const Path& path, const MyString& inputPath );
    Path operator+( const Path& path, const Path& inputPath );
    Path MogeLib_API operator+( const Path& path, const char* inputPath );
    

    const MyString GetBaseName( const MyString& path );
    const MyString GetExtension( const MyString& path );
    const MyString GetDirectory( const MyString& path );
    const bool FileExists( const MyString& path, std::string& errorMessage );
}