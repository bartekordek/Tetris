#include "RenderableSDLTexture.h"
#include "Math/PositionDouble2D.h"
#include "Math/SizeDouble2D.h"
namespace Moge
{
	RenderableSDLTexture::RenderableSDLTexture()
	{
		this->position.reset( new Math::PositionDouble2D() );
		this->size.reset( new Math::SizeDouble2D() );
	}
	
	Math::IPosition<double>* RenderableSDLTexture::getPosition()
	{
		return this->position.get();
	}

	const Math::IPosition<double>* RenderableSDLTexture::getPosition()const
	{
		return this->position.get();
	}
	
	Math::ISize<double>* RenderableSDLTexture::getSize()
	{
		return this->size.get();
	}

	const Math::ISize<double>* RenderableSDLTexture::getSize()const
	{
		return this->size.get();
	}

	const ITexture* RenderableSDLTexture::getTexture() const
	{
		return this->texture.get();
	}

	void RenderableSDLTexture::setTexture( const std::shared_ptr< ITexture >& texture )
	{
		this->texture = texture;
	}

}