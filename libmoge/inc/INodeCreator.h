# pragma once
#include "Node.h"
#include "Math/IPositionAdapter.h"
#include "CUL/Path.hpp"
namespace Moge
{
    class MogeLib_API INodeCreator
    {
    public:
        INodeCreator();
        virtual ~INodeCreator();
        virtual void createScreen( const Math::MultiPoint<unsigned int>& size ) = 0;
        virtual std::shared_ptr<Node> createFromImage( const CUL::FS::Path& filePath, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const CUL::MyString& name = CUL::MyString( "" ) ) = 0;
        virtual void removeNode( std::shared_ptr<Node>& node ) = 0;
        virtual const bool exist( std::shared_ptr<Node>& node ) = 0;
        virtual const unsigned int count() = 0;
    protected:
    private:
    };
}