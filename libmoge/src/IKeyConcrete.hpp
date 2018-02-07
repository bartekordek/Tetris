#pragma once
#include "IKey.hpp"
#include "SDL2Wrapper/IKey.hpp"
namespace Moge
{
    class IKeyConcrete final: public IKey
    {
    public:
        IKeyConcrete();
        ~IKeyConcrete();
        void setKeyName( const std::string& keyName ) override;
        const std::string& getKeyName()const override;
        const bool getKeyIsDown()const override;
        void setKeyIsDown( const bool isDown ) override;

        void setSDLKey( SDL2W::IKey* key );

    protected:
    private:
        SDL2W::IKey* m_key = nullptr;
        
    };
}