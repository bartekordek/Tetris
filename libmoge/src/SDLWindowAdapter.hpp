#pragma once
#include "IWindow.hpp"
#include "SDL2Wrapper/IWindow.hpp"
#include <map>
namespace Moge
{
    class SDL2WindowAdapter final:
        public IWindow
    {
    public:
        SDL2WindowAdapter();
        ~SDL2WindowAdapter();

        ISprite* createSprite(
            const Path& filePath,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) override;

        ISprite* createSprite(
            ITexture* tex,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) override;
        ITexture* createTexture( const Path& path ) override;

        void removeNode( INode* node ) override;
        const bool exist( const INode* node )const override;
        const unsigned int count()const override;

        void setSDLWin( SDL2W::IWindow* win );

        void setBackgroundColor( const ColorE color ) override;
        void setBackgroundColor( const ColorSUI& color ) override;

    protected:
    private:
        SDL2W::IWindow* m_sdlWindow = nullptr;
        std::map<INode*,NodePtr> nodes;
        std::map<std::string, TexPtr> m_textures;
    };
}