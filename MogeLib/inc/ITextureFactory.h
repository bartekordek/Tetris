#pragma once

#include "MogeLib.h"
#include "CUL::FS::Path.h"
#include "Node.h"
#include <memory>

namespace  Moge 
{
    class MogeLib_API ITextureFactory
    {
    public:
        ITextureFactory() = default;
        virtual ~ITextureFactory() = default;
        virtual std::shared_ptr<ITexture> createTexture( const CUL::FS::Path& path ) = 0;
        virtual std::shared_ptr<ITexture>& findTexture( const CUL::FS::Path& path ) = 0;
        virtual void removeTexture( const std::shared_ptr<ITexture>& texture ) = 0;
    protected:
    private:
    };
}