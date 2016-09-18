#pragma once

#include "MogeLib.h"

namespace MogeLib
{
	class MogeLib_API ObjectNode;
	class SceneImpl;
	class MogeLib_API Scene
	{
	public:
		Scene();
		virtual ~Scene();
	protected:
	private:
		SceneImpl* impl = nullptr;
	};
}