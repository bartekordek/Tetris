#pragma once

#include "IObservableData.h"

union SDL_Event;

namespace Moge
{
	class KeyboardData: public IObservableData
	{
	public:
		KeyboardData();
		KeyboardData( SDL_Event* sdlEvent );
		virtual ~KeyboardData();

		KeyboardData& operator=( const KeyboardData& keyboardData );

		void setEvent( SDL_Event* sdlEvent );
		SDL_Event* getSdlEvent()const;
	protected:
	private:
		SDL_Event* sdlEvent = nullptr;
	};
}