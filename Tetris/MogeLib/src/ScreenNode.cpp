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

	void ScreenNode::Initialize()
	{
		mainScreen = SDL_CreateWindow( Name::GetName().c_str(), Position::GetX(), Position::GetY(), Size::GetWidth(), Size::GetHeight(), SDL_WINDOW_SHOWN );
		mainRenderer = SDL_CreateRenderer( mainScreen, -1, SDL_RENDERER_ACCELERATED );
	}

	SDL_Window* ScreenNode::GetScreen()const
	{
		return mainScreen;
	}

	SDL_Renderer* ScreenNode::GetRenderer()const
	{
		return mainRenderer;
	}

	void ScreenNode::DestroyScreen()
	{
		FreeContent();
	}

	void ScreenNode::FreeContent()
	{
		SDL_DestroyRenderer( mainRenderer );
		SDL_DestroyWindow( mainScreen );
	}

}