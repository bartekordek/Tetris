#include "KeyboardObservable.h"
#include <SDL_events.h>

namespace MogeLib
{
	KeyboardObservable::KeyboardObservable()
	{
	}


	KeyboardObservable::~KeyboardObservable()
	{
		mPoolKeyboardEventsThread.join();
	}

	void KeyboardObservable::Initialize()
	{
		mPoolKeyboardEventsThread = std::thread( &KeyboardObservable::PoolThreadMethod, this );
	}

	void KeyboardObservable::Register( KeyboardObserver* observer )
	{
		mObservers.push_back( observer );
	}

	void KeyboardObservable::PoolThreadMethod()
	{
		SDL_Event event;
		while( mPoolKeyboardEvents && SDL_PollEvent( &event ) )
		{
			if( SDL_KEYDOWN == event.type )
			{
				NotifyObservers();
			}
		}
	}

	void KeyboardObservable::NotifyObservers()
	{
		for( auto& observer: mObservers )
		{
		//	observer->KeyEvent();
		}
	}
}