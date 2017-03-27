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
		virtual Math::ISize<int>& getSize() = 0;
		virtual const Math::ISize<int>& getSize()const = 0;
	protected:
	private:
	};
}