#pragma once

#include "FileSystem.h"
#include "Node.h"
#include "SurfaceWrapper.h"

namespace MogeLib
{
	class MOGE_API ImageCreator
	{
	public:
		static ImageSurface CreateSurfaceFromImage( const Path& imagePath );

	private:
		enum ImageTypes
		{
			UNKOWN = -1,
			BMP = 1,
			PNG,
			JPG
		};

		static ImageTypes GetImageType( const Path& imagePath );
	};
}