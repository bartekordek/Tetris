#pragma once
#include "IMainGameLoop.hpp"
#include "IKeyboardObservable.h"
#include "IRenderer2D.h"
#include "ITextureFactory2D.h"
#include <memory>
#include <map>
namespace Moge
{
    class SDL2WrapperAdapter final:
        public IRenderer2D,
        public ITextureFactory2D,
        public IKeyboardObservable,
        public IMainGameLoop
    {
    public:
        SDL2WrapperAdapter();
        ~SDL2WrapperAdapter();
        void createWindow(
            const CUL::Math::Vector3Di& winPos,
            const CUL::Math::Vector3Du& winSize,
            const std::string& winName = "Unnamed window." ) override;
        void setBackgroundColor( const ColorE color ) override;
        void setBackgroundColor( const ColorS& color ) override;
        void forceDestroy() override;

        void render( const IRenderable& renderable ) override;
        void render(
            const ITexture& texture,
            const CUL::Math::Vector3Dd& position,
            const CUL::Math::Vector3Dd& targetSize ) override;
        void render( 
            const IPrimitive& primitive,
            const CUL::Math::Vector3Dd& position, 
            const CUL::Math::Vector3Dd& targetSize ) override;
        void updateScreen()override;
        void clear() override;

        std::shared_ptr<ITexture> createTexture( const CUL::FS::Path& path ) override;
        std::shared_ptr<ITexture>& findTexture( const CUL::FS::Path& path ) override;
        void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
        void runMainLoop() override;
        void stopMainLoop() override;
    protected:
    private:
    };
}