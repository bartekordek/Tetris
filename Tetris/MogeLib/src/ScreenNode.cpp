#include "ScreenNode.h"

namespace MOGE
{
	ScreenNode::ScreenNode()
	{
	}


	ScreenNode::~ScreenNode()
	{
		FreeContent();
	}

	void ScreenNode::CreateScreen()
	{
		mainScreen = SDL_CreateWindow( Named::GetName().c_str(), Position::GetX(), Position::GetY(), Size::GetWidth(), Size::GetHeight(), SDL_WINDOW_SHOWN );
	}

	void ScreenNode::FreeContent()
	{
		SDL_DestroyWindow( mainScreen );
	}

	SDL_Window* ScreenNode::GetScreen()const
	{
		return mainScreen;
	}
}