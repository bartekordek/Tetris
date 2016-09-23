#pragma once

#include <memory>

#include "FileSystem.h"

struct SDL_Surface;

namespace Moge
{
	class MogeLib_API SurfaceWrapper
	{
	public:
		explicit SurfaceWrapper();
		explicit SurfaceWrapper( const SurfaceWrapper& surfaceWrapper );
		explicit SurfaceWrapper( SDL_Surface* sdlSurface );
		explicit SurfaceWrapper( const Path& path );
		virtual ~SurfaceWrapper();

		SurfaceWrapper& operator=( SDL_Surface* sdlSurface );
		SurfaceWrapper& operator=( const SurfaceWrapper& surfaceWrapper );

		SDL_Surface* GetSdlSurface()const;
		void setNewSurface( SDL_Surface* surface );
		void setPath( const Path& path );

	private:
		void ReleseSurface();
		

		SDL_Surface* surface = nullptr;
		Path path;
	};
	using ImageSurface = std::shared_ptr<SurfaceWrapper>;
}