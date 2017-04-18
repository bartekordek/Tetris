#pragma once

#include "MogeLib.h"
#include "RenderableTypes.h"
#include "ITexture.h"
#include "Math/IPosition.h"
#include "Math/ISize.h"
#include "Math/IVector3D.h"

#include <memory>

namespace Moge
{
	class MogeLib_API IRenderable
	{
	public:
		IRenderable();
		virtual ~IRenderable();
		
		virtual const Math::IPosition<double>& getPosition()const = 0;
		virtual void setX( const double x ) = 0;
		virtual void setY( const double y ) = 0;
		virtual void setZ( const double z ) = 0;
		virtual void setPosition( const Math::IPosition<double>& pos ) = 0;
		virtual const Math::ISize<double>& getSize()const = 0;
		virtual const Math::IVector3D<double>& getScale()const = 0;
		virtual const RenderableType getRenderableType()const = 0;
		virtual const std::shared_ptr<ITexture>& getTexture()const  = 0;
	protected:
	private://TODO Write texture render method.	
	};
}
