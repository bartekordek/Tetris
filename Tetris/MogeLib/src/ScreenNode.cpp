#include "ScreenNode.h"

namespace MOGE
{
	ScreeNode::ScreeNode()
	{
	}


	ScreeNode::~ScreeNode()
	{
	}

	void ScreeNode::CreateScreen()
	{
		mainScreen = SDL_CreateWindow( Named::GetName().c_str(), Position::GetX(), Position::GetY(), Size::GetWidth(), Size::GetHeight(), SDL_WINDOW_SHOWN );
	}

	SDL_Window* ScreeNode::GetScreen()const
	{
		return mainScreen;
	}
}