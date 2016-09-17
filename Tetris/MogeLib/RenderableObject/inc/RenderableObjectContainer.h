#pragma once

#include "MOGE.h"

namespace MOGE
{
	class MOGE_API ObjectNode;
	class MOGE_API RenderableObjectContainerImpl;
	class MOGE_API RenderableObjectContainer
	{
	public:
		RenderableObjectContainer();
		virtual ~RenderableObjectContainer();
	protected:
	private:
		RenderableObjectContainerImpl* impl = nullptr;
		
	};
}