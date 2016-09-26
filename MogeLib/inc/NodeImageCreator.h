#pragma once

#include "FileSystem.h"
#include "Node.h"
#include "SurfaceWrapper.h"

namespace Moge
{
	class MogeLib_API ImageCreator
	{
	public:
		static ImageSurface CreateSurfaceFromImage( const Path& imagePath );

	private:
		enum class ImageTypes: signed char
		{
			UNKOWN = -1,
			BMP = 1,
			PNG,
			JPG
		};

		static ImageTypes GetImageType( const Path& imagePath );
	};
}