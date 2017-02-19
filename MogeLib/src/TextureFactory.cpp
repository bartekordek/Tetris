#include "TextureFactory.h"
#include "Engine.h"
#include "SurfaceFactory.h"

namespace Moge
{
	TextureFactory::TextureFactory( Engine* engine ): ITextureFactory( engine )//, surfaceFactory( engine->getNodeFactory() )
	{
	}

	TextureFactory::~TextureFactory()
	{
	}

	ITexture* TextureFactory::createTexture( const Path& path )
	{
		auto surface = this->getEngine()->getNodeFactory();
		return nullptr;
	}

	ITexture* TextureFactory::findTexture( const Path& path )
	{
		return nullptr;
	}

	void TextureFactory::removeTexture( ITexture* texture )
	{
		
	}
}