#pragma once

#include "Engine.h"

namespace Moge
{
	class MogeLib_API EngineManager
	{
	public:
		static Engine* initializeEngine();
		static Engine* getEngine();
		static void destroyEngine();
	protected:
	private:
		static Engine* engineInstance;
	};
	
}