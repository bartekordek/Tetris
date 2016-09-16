#pragma once

#include "Node.h"

namespace MogeLib
{
	class MOGE_API ScreenNode: public Node
	{
	public:
		ScreenNode();
		~ScreenNode();

		void Initialize();
		SDL_Window* GetScreen()const;
		SDL_Renderer* GetRenderer()const;
		SDL_Surface* GetSdlSurface()const;
		void DestroyScreen();
	protected:
		virtual void UpdateImplementation();

	private:
		void FreeContent() override;
		SDL_Window* mainScreen = nullptr;
		SDL_Renderer* mainRenderer = nullptr;
		SDL_Surface* mainScreenSurface = nullptr;
	};
}