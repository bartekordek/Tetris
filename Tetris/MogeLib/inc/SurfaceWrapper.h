#pragma once

#include <memory>

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

		SDL_Surface* GetSdlSurface()const;

	private:
		void ReleseSurface();
		void SetNewSurface( SDL_Surface* surface );

		SDL_Surface* surface = nullptr;
	};
	using ImageSurface = std::shared_ptr<SurfaceWrapper>;
}