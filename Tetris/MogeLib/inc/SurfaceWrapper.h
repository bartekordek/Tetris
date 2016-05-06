#pragma once

#include <MOGE.h>

struct SDL_Surface;

namespace MOGE
{
	class MOGE_API SurfaceWrapper
	{
	public:
		SurfaceWrapper();
		SurfaceWrapper( const SurfaceWrapper& surfaceWrapper );
		SurfaceWrapper( SDL_Surface* sdlSurface );
		~SurfaceWrapper();

		SurfaceWrapper& operator=( SDL_Surface* sdlSurface );



	private:
		void ReleseSurface();
		void SetNewSurface( SDL_Surface* surface );

		SDL_Surface* surface = nullptr;
	};
}