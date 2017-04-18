#pragma once
#include "IRenderable.h"
#include "ITexture.h"
#include <memory>

namespace Moge
{
	class RenderableSDLTexture: public IRenderable
	{
	public:
		RenderableSDLTexture();
		virtual ~RenderableSDLTexture() = default;

		const Math::IPosition<double>& getPosition()const override;
		void setPosition( const Math::IPosition<double>& pos ) override;
		const Math::ISize<double>& getSize()const override;
		const Math::IVector3D<double>& getScale()const override;
		const RenderableType getRenderableType()const override;

		const std::shared_ptr<ITexture>& getTexture()const override;
		void setTexture( const std::shared_ptr<ITexture>& texture );
	protected:
	private:
		std::shared_ptr<ITexture> texture;
		std::unique_ptr<Math::IPosition<double>> position;
		std::unique_ptr<Math::ISize<double>> size;
		std::unique_ptr<Math::IVector3D<double>> scale;
	};
}
