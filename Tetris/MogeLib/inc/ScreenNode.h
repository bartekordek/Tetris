#pragma once

#include "Node.h"

namespace MOGE
{
	class MOGE_API ScreenNode: public Node
	{
	public:
		ScreenNode();
		~ScreenNode();

		void Initialize();
		SDL_Window* GetScreen()const;
		SDL_Renderer* GetRenderer()const;
		void DestroyScreen();

	private:
		void FreeContent() override;
		SDL_Window* mainScreen = nullptr;
		SDL_Renderer* mainRenderer = nullptr;
	};
}