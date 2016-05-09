#include "SurfaceWrapper.h"
#include <SDL_surface.h>

namespace MOGE
{
	SurfaceWrapper::SurfaceWrapper()
	{
	}

	SurfaceWrapper::SurfaceWrapper( const SurfaceWrapper& surfaceWrapper )
	{
		SetNewSurface( surfaceWrapper.surface );
	}

	SurfaceWrapper::SurfaceWrapper( SDL_Surface* sdlSurface )
	{
		SetNewSurface( sdlSurface );
	}

	SurfaceWrapper::~SurfaceWrapper()
	{
		ReleseSurface();
	}

	SurfaceWrapper& SurfaceWrapper::operator=( SDL_Surface* sdlSurface )
	{
		ReleseSurface();
		SetNewSurface( sdlSurface );
		return *this;
	}

	SDL_Surface* SurfaceWrapper::GetSdlSurface()const
	{
		return surface;
	}

	void SurfaceWrapper::ReleseSurface()
	{
		if( this->surface )
		{
			SDL_FreeSurface( this->surface );
			this->surface = nullptr;
		}
	}

	void SurfaceWrapper::SetNewSurface( SDL_Surface* surface )
	{
		this->surface = surface;
	}
}