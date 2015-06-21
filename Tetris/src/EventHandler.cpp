#include "EventHandler.h"
#include "SDL/SDL.h"
#include <iostream>

void CEventHandler::AddQuitActionHandler( std::function<void()> callback )
{
	quitCallback = callback;
}

void CEventHandler::MainEventLoop()
{
	SDL_Event event;
	bool quit = false;
	while( quit == false )
	{
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
			else if( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_q:
						quitCallback();
						break;
					case SDLK_h:
						std::cout << " wat " << std::endl;
						break;
				}
			}
		}
	}
	quitCallback();
}