#include "RenderableSDLTexture.h"
#include "Math/PositionDouble2D.h"
#include "Math/SizeDouble2D.h"
#include "Vector3DSimple.h"

namespace Moge
{
	RenderableSDLTexture::RenderableSDLTexture()
	{
		this->position.reset( new Math::PositionDouble2D() );
		this->size.reset( new Math::SizeDouble2D() );
		this->scale.reset( new Math::Vector3DSimple<double>() );
	}
	
	//Math::IPosition<double>& RenderableSDLTexture::getPosition()
	//{
	//	return *this->position.get();
	//}
	//
	//Math::ISize<double>& RenderableSDLTexture::getSize()
	//{
	//	return *this->size.get();
	//}

	const Math::IPosition<double>& RenderableSDLTexture::getPosition()const
	{
		return *this->position.get();
	}

	void RenderableSDLTexture::setPosition( const Math::IPosition< double >& pos )
	{
		*this->position = pos;
	}

	const Math::ISize<double>& RenderableSDLTexture::getSize()const
	{
		return *this->size.get();
	}

	const Math::IVector3D< double >& RenderableSDLTexture::getScale() const
	{
		return *this->scale;
	}

	const  std::shared_ptr<ITexture>& RenderableSDLTexture::getTexture() const
	{
		return this->texture;
	}

	void RenderableSDLTexture::setTexture( const std::shared_ptr< ITexture >& texture )
	{
		this->texture = texture;
	}

	const RenderableType RenderableSDLTexture::getRenderableType() const
	{
		return RenderableType::TEXTURED;
	}
}