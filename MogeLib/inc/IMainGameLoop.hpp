#pragma once
#include "MogeLib.h"
namespace Moge
{
	class MogeLib_API IMainGameLoop
	{
	public:
		IMainGameLoop() = default;
		virtual ~IMainGameLoop() = default;

		virtual void runMainLoop() = 0;

		virtual void stopMainLoop() = 0;

	protected:
	private:
	};
}