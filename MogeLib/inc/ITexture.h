#pragma once

#include "MogeLib.h"
#include "Math/IVector3D.h"

struct SDL_Renderer;
namespace Moge
{
	class MogeLib_API ITexture
	{
	public:
		ITexture();
		virtual ~ITexture();
		virtual const char* getPath()const = 0;

		virtual const Math::IVector3D<double>& getSize()const = 0;
		virtual void setSize( const Math::IVector3D<double>& size ) = 0;

		virtual const Math::IVector3D<double>& getScale()const  = 0;
		virtual void setScale( const Math::IVector3D<double>& scale ) = 0;
	protected:
	private:
	};
}