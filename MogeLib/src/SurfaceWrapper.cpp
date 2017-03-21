#include "SurfaceWrapper.h"
#include <SDL_surface.h>

namespace Moge
{
	SurfaceWrapper::SurfaceWrapper()
	{
	}

	SurfaceWrapper::SurfaceWrapper( const SurfaceWrapper& surfaceWrapper )
	{
		setNewSurface( surfaceWrapper.surface );
		setPath( path );
	}

	SurfaceWrapper::SurfaceWrapper( SDL_Surface* sdlSurface )
	{
		setNewSurface( sdlSurface );
	}

	SurfaceWrapper::SurfaceWrapper( const Path& path ): path(path)
	{
	}

	SurfaceWrapper::~SurfaceWrapper()
	{
		ReleseSurface();
	}

	SurfaceWrapper& SurfaceWrapper::operator=( SDL_Surface* sdlSurface )
	{
		ReleseSurface();
		setNewSurface( sdlSurface );
		return *this;
	}

	SurfaceWrapper& SurfaceWrapper::operator=( const SurfaceWrapper& surfaceWrapper )
	{
		if( &surfaceWrapper != this )
		{
			setNewSurface( surfaceWrapper.surface );
			setPath( path );
		}
		return *this;
	}

	SDL_Surface* SurfaceWrapper::GetSdlSurface()const
	{
		return surface;
	}

	void SurfaceWrapper::setPath( const Path& path )
	{
		this->path = path;
	}
	
	const char* SurfaceWrapper::getPath()const
	{
		return this->path.c_str();
	}

	void SurfaceWrapper::ReleseSurface()
	{
		if( this->surface )
		{
			SDL_FreeSurface( this->surface );
			this->surface = nullptr;
		}
	}

	void SurfaceWrapper::setNewSurface( SDL_Surface* surface )
	{
		this->surface = surface;
	}
}