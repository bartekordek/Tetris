#pragma once

#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
#include "CUL/Color.hpp"
#include "INode.h"
#include "IRenderer.h"
#include "CUL/IIterator.hpp"

namespace Moge
{
    using ColorS = CUL::ColorS;
    using ColorE = CUL::ColorE;
    using NodePtr = std::shared_ptr<INode>;
    using Path = CUL::FS::Path;
    using Vector3Di = CUL::Math::Vector3Di;
    class MogeLib_API IWindow
    {
    public:
        IWindow();
        virtual ~IWindow();

        virtual INode* create(
            const Path& filePath,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) = 0;
        virtual void removeNode( const INode* node ) = 0;
        virtual const bool exist( const INode* node )const = 0;
        virtual const unsigned int count()const = 0;
        virtual const CUL::IIterator<NodePtr>* getNodes()const = 0;

        virtual void setBackgroundColor( const ColorE color ) = 0;
        virtual void setBackgroundColor( const ColorS& color ) = 0;

    protected:
    private:
    };
}