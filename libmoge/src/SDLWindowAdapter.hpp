#pragma once
#include "IWindow.hpp"

#include "SDL2Wrapper/IWindow.hpp"
#include "CUL/IList.hpp"
namespace Moge
{
    class SDL2WindowAdapter final: public IWindow
    {
    public:
        SDL2WindowAdapter();
        ~SDL2WindowAdapter();

        INode* create(
            const Path& filePath,
            const Vector3Di& position = Vector3Di( 0, 0, 0 ),
            const CUL::MyString& name = CUL::MyString( "" ) ) override;
        void removeNode( const INode* node );
        const bool exist( const INode* node )const override;
        const unsigned int count()const override;
        const CUL::IIterator<NodePtr>* getNodes()const override;

        void setSDLWin( SDL2W::IWindow* win );

        void setBackgroundColor( const ColorE color ) override;
        void setBackgroundColor( const ColorS& color ) override;

    protected:
    private:
        SDL2W::IWindow* m_sdlWindow = nullptr;
        std::unique_ptr< CUL::IList<NodePtr>> nodes;
    };
}