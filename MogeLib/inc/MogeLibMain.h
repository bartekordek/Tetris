#pragma once

#include <memory>
#include "IEngine.h"

namespace Moge
{
	class MogeLib_API EngineManager
	{
	public:
		static IEngine* initializeEngine();
		static IEngine* getEngine();
	protected:
	private:
		static std::shared_ptr<IEngine> engineInstance;
	};
	
}