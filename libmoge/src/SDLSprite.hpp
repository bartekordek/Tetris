#pragma once

#include <memory>

#include "ISprite.hpp"
#include "SDL2Wrapper/ISprite.hpp"
#include "INode.h"
#include "Visible.h"

namespace Moge
{
    class MogeLib_API SDLSprite:
        public ISprite,
        private IRenderable
    {
    public:
        SDLSprite();
        SDLSprite( const SDLSprite& r );
        virtual ~SDLSprite();

        SDLSprite& operator=( const SDLSprite& right );
        const bool operator==( const SDLSprite& right )const;

        const CUL::Math::Vector3Dd& getPosition()const override;
        void setX( const double x ) override;
        void setY( const double y ) override;
        void setZ( const double z ) override;
        const CUL::Math::Vector3Dd& getSize()const override;
        const CUL::Math::Vector3Dd& getAbsSize()const override;
        const CUL::Math::Vector3Dd& getScale()const override;
        void setScale( const CUL::Math::Vector3Dd& scale )override;
        void setPosition( const CUL::Math::Vector3Dd& pos ) override;

        void setSprite( SDL2W::ISprite* sprite );
        void setTexture( ITexture* texture ) override;
        ITexture* getTexture() override;
        IRenderable* getRenderable() override;
        const RenderableType getRenderableType()const override;

    protected:
    private:
        CUL::Math::Vector3Dd scale{ 1.0, 1.0, 1.0 };
        CUL::Math::Vector3Dd absSize;
        SDL2W::ISprite* m_sdlSprite = nullptr;
        CUL::Math::Vector3Dd m_pos;
        ITexture* m_texture = nullptr;
    };
}
