#pragma once
#include "MogeLib.h"
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
	
	ColorS convertE2S( const ColorE c );
	
	struct ColorS
	{
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t alpha = 255;
	};
	
	class IRenderable;
	class MogeLib_API IRenderer
	{
	public:
		IRenderer();
		virtual ~IRenderer();
		virtual void forceDestroy() = 0;
		virtual void render( IRenderable* renderable ) = 0;
		virtual void setBackgroundColor( const ColorE color ) = 0;
		virtual void setBackgroundColor( const ColorS& color ) = 0;
	protected:
	private:
	};
}