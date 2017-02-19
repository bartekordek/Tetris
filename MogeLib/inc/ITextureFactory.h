#pragma once

#include "MogeLib.h"
#include "ITexture.h"
#include "Path.h"

namespace  Moge 
{
	class Engine;
	class MogeLib_API ITextureFactory
	{
	public:
		ITextureFactory( Engine* engine );
		virtual ~ITextureFactory();
		virtual ITexture* createTexture( const Path& path ) = 0;
		virtual ITexture* findTexture( const Path& path ) = 0;
		virtual void removeTexture( ITexture* texture ) = 0;
	protected:
		Engine* getEngine();
	private:
		Engine* engine = nullptr;
	};
}