#pragma once

#include "MultiPoint.h"
#include "ObjectNode.h"
#include "File.h"

namespace Moge
{
    class ScreenNode;
    class MogeLib_API IEngine
    {
    public:
        IEngine()
        {
        }

        virtual ~IEngine()
        {
        }

        virtual void addObject( const CUL::FS::Path& filePath, const Math::MultiPoint<int>& position, const MyString& name = MyString( "" ) ) = 0;
        virtual void addObject( const ObjectNode node, const MyString& name = MyString( "" ) );
        virtual const std::shared_ptr<ScreenNode> getScreen()const;
        virtual void CreateScreen( const Math::MultiPoint<unsigned int>& resolution = Math::MultiPoint<unsigned int>( 2 ) ) = 0;
        virtual void StartMainLoop() = 0;
        virtual void StopMainLoop() = 0;

    protected:
    private:
    };
}