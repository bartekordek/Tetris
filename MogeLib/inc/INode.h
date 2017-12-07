#pragma once

#include <MogeLib.h>
#include "CUL/Named.hpp"
#include "IRenderable.h"

struct SDL_Rect;

namespace Moge
{
    class MogeLib_API INode: public IRenderable, public CUL::Name
    {
    public:
        explicit INode( const CUL::MyString& name = CUL::MyString( "" ) );
        virtual ~INode();
    protected:
    private:
    };
}