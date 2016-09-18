#pragma once

#include "MogeLib.h"

namespace MogeLib
{
	class MogeLib_API ObjectNode;
	class RenderableObjectContainerImpl;
	class MogeLib_API RenderableObjectContainer
	{
	public:
		RenderableObjectContainer();
		virtual ~RenderableObjectContainer();

		void addObject( const std::shared_ptr<ObjectNode>& node );

	protected:
	private:
		RenderableObjectContainerImpl* impl = nullptr;
		
	};
}