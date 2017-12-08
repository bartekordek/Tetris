#include "SDL2WrapperAdapter.hpp"

using namespace Moge;

SDL2WrapperAdapter::SDL2WrapperAdapter()
{
}


SDL2WrapperAdapter::~SDL2WrapperAdapter()
{
}

#if _MSC_VER
__pragma(warning( push )) \
__pragma(warning( disable:4100 ))
#endif
void SDL2WrapperAdapter::createWindow(
    const Math::IPosition<int>& winPos,
    const Math::ISize<unsigned int>& winSize,
    const std::string& winName )
{

}


void SDL2WrapperAdapter::setBackgroundColor( const ColorE color )
{

}

void SDL2WrapperAdapter::setBackgroundColor( const ColorS& color )
{

}

void SDL2WrapperAdapter::forceDestroy()
{

}

void SDL2WrapperAdapter::render( const IRenderable& renderable )
{

}

void SDL2WrapperAdapter::render(
    const ITexture& texture,
    const Math::IPosition<double>& position,
    const Math::Vector3D<double>& targetSize )
{

}

void SDL2WrapperAdapter::render( const IPrimitive& primitive, const Math::IPosition<double>& position, const Math::Vector3D<double>& targetSize )
{

}

void SDL2WrapperAdapter::updateScreen()
{

}

void SDL2WrapperAdapter::clear()
{

}

std::shared_ptr<ITexture> SDL2WrapperAdapter::createTexture( const Path& path )
{
    std::shared_ptr<ITexture> result;
    return result;
}

std::shared_ptr<ITexture>& SDL2WrapperAdapter::findTexture( const Path& path )
{
    static std::shared_ptr<ITexture> result;
    return result;
}
void SDL2WrapperAdapter::removeTexture( const std::shared_ptr<ITexture>& texture )
{

}

#if _MSC_VER
__pragma(warning( pop ))
#endif

void SDL2WrapperAdapter::runMainLoop()
{

}

void SDL2WrapperAdapter::stopMainLoop()
{

}