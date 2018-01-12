#pragma once

#include "IMainGameLoop.hpp"
#include "IKeyboardObservable.h"
#include "IRenderer2D.h"
#include "ITextureFactory2D.h"
#include "LckPrim.h"

#include "SDL2Wrapper/ISDL2Wrapper.hpp"

#include <memory>
#include <map>

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Surface;
namespace Moge
{
    class SDLRenderer: 
        public IRenderer2D, 
        public ITextureFactory2D,
        public IKeyboardObservable,
        public IMainGameLoop
    {
    public:
        SDLRenderer();
        virtual ~SDLRenderer();
        void createWindow( 
            const Math::IPosition<int>& winPos, 
            const Math::ISize<unsigned int>& winSize, 
            const std::string& winName = "Unnamed window." ) override;
        void setBackgroundColor( const ColorE color ) override;
        void setBackgroundColor( const ColorS& color ) override;
        void forceDestroy() override;

        void render( const IRenderable& renderable ) override;
        void render( 
            const ITexture& texture, 
            const Math::IPosition<double>& position, 
            const Math::Vector3D<double>& targetSize ) override;
        void render( const IPrimitive& primitive, const Math::IPosition<double>& position, const Math::Vector3D<double>& targetSize ) override;
        void updateScreen()override;
        void clear() override;

        std::shared_ptr<ITexture> createTexture( const CUL::FS::Path& path ) override;
        std::shared_ptr<ITexture>& findTexture( const CUL::FS::Path& path ) override;
        void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
        void runMainLoop() override;
        void stopMainLoop() override;

    protected:
    private:
        SDL2W::ISDL2Wrapper* sdl2Wrapper = nullptr;
        SDL_Surface* CreateSurfaceFromImage( const CUL::FS::Path& imagePath );
        IKey* createKey( const int keySignature, const unsigned char* sdlKey )const;
        const std::shared_ptr<std::map<unsigned int, std::shared_ptr<IKey>>> createKeys()const;

        SDL_Renderer* renderer = nullptr;
        SDL_Window* window = nullptr;
        bool rendererWasDestroyed = false;
        std::map<char*,std::shared_ptr<ITexture>> textures;
        LckPrim<bool> eventLoopActive{ true };
        std::shared_ptr<std::map<unsigned int, std::shared_ptr<IKey>>> keys;
    };
}