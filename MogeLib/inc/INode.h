#pragma once

#include <MogeLib.h>
#include "Named.h"
#include "IRenderable.h"

struct SDL_Rect;

namespace Moge
{
    class MogeLib_API INode: public IRenderable, public Name
    {
    public:
        explicit INode( const MyString& name = MyString( "" ) );
        virtual ~INode();
    protected:
    private:
    };
}