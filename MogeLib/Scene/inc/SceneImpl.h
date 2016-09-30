#pragma once

#include <set>
#include <memory>

namespace Moge
{
	class ObjectNode;
	class SceneImpl
	{
	public:
		SceneImpl();
		explicit SceneImpl( const SceneImpl& sceneImpl );
		virtual ~SceneImpl();
	protected:
	private:
		std::set<std::shared_ptr<ObjectNode>> nodes;
	};
}