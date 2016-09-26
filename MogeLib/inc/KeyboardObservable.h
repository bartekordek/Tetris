#pragma once

#include <vector>

#include <SDL_keyboard.h>
#include <SDL_keycode.h>

#include "KeyboardListener.h"

namespace Moge
{
	class KeyboardObservable
	{
	public:
		KeyboardObservable();
		~KeyboardObservable();
		void Initialize();
		void Register( KeyboardObserver* observer );

	private:
		void PoolThreadMethod();
		void NotifyObservers();

		bool mPoolKeyboardEvents = true;
		std::thread mPoolKeyboardEventsThread;

		std::vector<KeyboardObserver*> mObservers;
	};
}