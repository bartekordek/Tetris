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
		Math::IPosition<double>* getPosition()override;
		const Math::IPosition<double>* getPosition()const override;
		Math::ISize<double>* getSize() override;
		const Math::ISize<double>* getSize()const override;
		const ITexture* getTexture()const;
		void setTexture( const std::shared_ptr<ITexture>& texture );
	protected:
	private:
		std::shared_ptr<ITexture> texture;
		std::unique_ptr<Math::IPosition<double>> position;
		std::unique_ptr<Math::ISize<double>> size;
	};
}
