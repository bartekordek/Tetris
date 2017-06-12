#pragma once
#include "MogeLib.h"

namespace Moge
{
	enum class LogType: short
	{
		INFO = 0,
		DEBUG,
		WARNING,
		ERROR
	};

	class MogeLib_API ILogUtil
	{
	public:
		ILogUtil() = default;
		virtual ~ILogUtil() = default;
		virtual void showMessage( const char* message, const LogType type = LogType::INFO ) = 0;
	protected:
	private:
	};

	class MogeLib_API LogFactory
	{
	public:
		static ILogUtil* getConcrete();
	protected:
	private:
		LogFactory() = delete;
		virtual ~LogFactory() = delete;
	};
}
