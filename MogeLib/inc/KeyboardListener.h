#pragma once

#include <thread>

#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_events.h>

namespace Moge
{
	class KeyboardObservable;

	class KeyboardObserver
	{
	public:
		KeyboardObserver();
		~KeyboardObserver();
		virtual void KeyEvent( SDL_Keycode keyCode, SDL_EventType eventType ) = 0;
	};
}