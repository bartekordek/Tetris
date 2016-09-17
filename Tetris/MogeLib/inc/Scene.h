#pragma once

#include "MOGE.h"

#include <map>
#include <memory>

namespace MOGE
{
	class MOGE_API ObjectNode;
	class MOGE_API Scene
	{
	public:
		Scene();
		virtual ~Scene();
	protected:
	private:
		std::set<std::shared_ptr<ObjectNode>> nodes;
	};
}