#pragma once
#include "ILogUtil.h"
#include <memory>
#include <mutex>

namespace Moge
{
	class ITimer;
	class LOgUtilConcrete: public ILogUtil
	{
	public:
		LOgUtilConcrete();
		virtual ~LOgUtilConcrete();

		void showMessage( const char* message, const LogType type = LogType::INFO ) override;
	protected:
	private:

		std::unique_ptr<ITimer> timer;
		std::mutex msgLock;
		unsigned int elapsedFieldWidth = 16;
	};
}
