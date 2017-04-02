#pragma once

#include "MogeLib.h"
#include "Math/ISize.h"

struct SDL_Renderer;
namespace Moge
{
	class MogeLib_API ITexture
	{
	public:
		ITexture();
		virtual ~ITexture();
		virtual const char* getPath()const = 0;
		virtual Math::ISize<double>& getSize() = 0;
		virtual const Math::ISize<double>& getSize()const = 0;
	protected:
	private:
	};
}