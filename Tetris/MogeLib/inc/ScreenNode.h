#pragma once

#include "Node.h"

namespace MOGE
{
	class ScreeNode: public Node
	{
	public:
		ScreeNode();
		~ScreeNode();

		void CreateScreen();

		SDL_Window* GetScreen()const;

	private:
		SDL_Window* mainScreen = nullptr;
	};
}