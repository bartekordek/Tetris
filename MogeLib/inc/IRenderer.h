#pragma once
#include "MogeLib.h"
#include <cstdint>
#include "ITexture.h"
#include "Math/IPosition.h"

namespace Moge
{
	enum class ColorE: short
	{
		BLACK = 0,
		WHITE,
		RED,
		GREEN,
		BLUE
	};
	
	struct ColorS
	{
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t alpha = 255;
	};	
	
	ColorS convertE2S( const ColorE c );

	class IRenderable;
	class IPrimitive;
	class MogeLib_API IRenderer
	{
	public:
		IRenderer() = default;
		virtual ~IRenderer() = default;
		virtual void forceDestroy() = 0;
		virtual void render( const IRenderable& renderable ) = 0;
		virtual void render( const ITexture& texture, const Math::IPosition<double>& position ) = 0;
		virtual void render( const IPrimitive& primitive, const Math::IPosition<double>& position ) = 0;
		virtual void setBackgroundColor( const ColorE color ) = 0;
		virtual void setBackgroundColor( const ColorS& color ) = 0;
	protected:
	private:
	};
}
