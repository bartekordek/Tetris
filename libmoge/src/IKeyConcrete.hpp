#pragma once

#include "IKey.hpp"
#include "SDL2Wrapper/Input/IKey.hpp"
#include "CUL/UselessMacros.hpp"

NAMESPACE_BEGIN( Moge )

class IKeyConcrete final:
    public IKey
{
public:
    IKeyConcrete();
    IKeyConcrete( const IKeyConcrete& r );
    ~IKeyConcrete();

    IKeyConcrete& operator=( const IKeyConcrete& r );

    CUL::CnstMyStr& getKeyName()const override;
    const bool getKeyIsDown()const override;

    void setSDLKey( SDL2W::IKey* key );

protected:
private:
    SDL2W::IKey* m_key = nullptr;
        
};

NAMESPACE_END( Moge )