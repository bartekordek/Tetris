#pragma once

#include "Node.h"

namespace MOGE
{
	class MOGE_API ScreenNode: public Node
	{
	public:
		ScreenNode();
		~ScreenNode();

		void CreateScreen();
		SDL_Window* GetScreen()const;

	private:
		void FreeContent() override;
		SDL_Window* mainScreen = nullptr;
	};
}