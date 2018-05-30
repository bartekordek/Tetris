#pragma once

#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
#include "CUL/Color.hpp"
#include "ISprite.hpp"
#include "IRenderer.h"
#include "ITexture.hpp"

namespace Moge
{
    using ColorSUI = CUL::ColorSUI;
    using ColorE = CUL::ColorE;
    using NodePtr = std::shared_ptr<INode>;
    using TexPtr = std::shared_ptr<ITexture>;
    using Path = CUL::FS::Path;
    using Vector3Di = CUL::Math::Vector3Di;
    class MogeLib_API IWindow
    {
    public:
        IWindow();
        virtual ~IWindow();

        virtual ISprite* createSprite(
            const Path& filePath,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) = 0;

        virtual ISprite* createSprite(
            ITexture* tex,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) = 0;
        virtual ITexture* createTexture( const Path& path ) = 0;

        virtual void removeNode( INode* node ) = 0;
        virtual const bool exist( const INode* node )const = 0;
        virtual const unsigned int count()const = 0;

        virtual void setBackgroundColor( const ColorE color ) = 0;
        virtual void setBackgroundColor( const ColorSUI& color ) = 0;

    protected:
    private:
    };
}