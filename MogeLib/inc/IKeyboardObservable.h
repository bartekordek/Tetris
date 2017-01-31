#pragma once

#include "IObservable.h"

namespace Moge
{
	class IKeyboardObservable: public IObservable
	{
	public:
		IKeyboardObservable() = default;
		virtual ~IKeyboardObservable() = default;
		void notifyObservers( IObservableData* data = nullptr ) override;

	protected:
	private:
		
	};
}