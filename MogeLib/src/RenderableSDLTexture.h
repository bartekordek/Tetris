#pragma once
#include "IRenderable.h"
namespace Moge
{
	class RenderableSDLTexture: public IRenderable
	{
	public:
		RenderableSDLTexture();
		virtual ~RenderableSDLTexture();
		const Math::IPosition<double>& getPosition()const;
		const Math::ISize<double>& getSize()const;
		const ITexture* getTexture()const;
	protected:
	private:
	};
}