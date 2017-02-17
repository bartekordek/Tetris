#pragma once

#include "MogeLib.h"
#include <memory>

namespace Moge
{
	class MogeLib_API ObjectNode;
	class RenderableObjectContainerImpl;
	class MogeLib_API RenderableObjectContainer
	{
	public:
		RenderableObjectContainer();
		explicit RenderableObjectContainer( const RenderableObjectContainer& renderableObjectContainer );
		virtual ~RenderableObjectContainer();

		void addObject( const std::shared_ptr<ObjectNode>& node );

	protected:
	private:
		RenderableObjectContainerImpl* impl = nullptr;
		
	};
}