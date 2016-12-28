#pragma once

#include "MogeLib.h"

namespace Moge
{
	class MogeLib_API ObjectNode;
	class SceneImpl;
	class MogeLib_API Scene
	{
	public:
		Scene();
		Scene( const Scene& scene );
		virtual ~Scene();
	protected:
	private:
		SceneImpl* impl = nullptr;
	};
}