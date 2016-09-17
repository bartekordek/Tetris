#pragma once

#include <set>
#include <memory>
#include <mutex>

namespace MOGE
{
	class ObjectNode;
	class RenderableObjectContainerImpl
	{
	public:
		RenderableObjectContainerImpl();
		virtual ~RenderableObjectContainerImpl();
		void addObject( const std::shared_ptr<ObjectNode>& node );

	protected:
	private:
		std::set<std::shared_ptr<ObjectNode>> nodes;
		std::mutex nodeMutex;
	};
}