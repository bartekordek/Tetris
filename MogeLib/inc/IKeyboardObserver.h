#pragma once 

#include "IObserver.h"

namespace Moge
{
	class IKeyboardObserver: public IObserver
	{
	public:
		IKeyboardObserver() = default;
		virtual ~IKeyboardObserver() = default;
		virtual void keyboardEvent( IObservableData* data = nullptr ) = 0;
	protected:
	private:
	};
}