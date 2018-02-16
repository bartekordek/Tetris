#pragma once

#include "INode.h"
#include "ITexture.hpp"

namespace Moge
{
    class MogeLib_API ISprite:
        public INode
    {
    public:
        ISprite();
        virtual ~ISprite();

        virtual void setTexture( ITexture* texture ) = 0;
        virtual ITexture* getTexture() = 0;

    protected:
    private:
    };
}