#pragma once 

#include "IObserver.h"
#include "KeyboardData.h"

namespace Moge
{
	class MogeLib_API IKeyboardObserver: public IObserver
	{
	public:
		IKeyboardObserver() = default;
		virtual ~IKeyboardObserver() = default;
		virtual void keyboardEvent( KeyboardData* data = nullptr ) = 0;
	protected:
	private:
	};
}