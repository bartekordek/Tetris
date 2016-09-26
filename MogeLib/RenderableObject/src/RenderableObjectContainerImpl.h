#pragma once

#include <set>
#include <memory>
#include <mutex>

namespace Moge
{
	class ObjectNode;
	class RenderableObjectContainerImpl
	{
	public:
		RenderableObjectContainerImpl();
		explicit RenderableObjectContainerImpl( const RenderableObjectContainerImpl& renderableObject );
		virtual ~RenderableObjectContainerImpl();
		void addObject( const std::shared_ptr<ObjectNode>& node );

	protected:
	private:
		std::set<std::shared_ptr<ObjectNode>> nodes;
		std::mutex nodeMutex;
	};
}