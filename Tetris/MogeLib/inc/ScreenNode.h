#pragma once

#include "Node.h"
#include "MultiPointFactory.h"
#include "Size.h"

struct SDL_Window;
struct SDL_Surface;
struct SDL_Renderer;

namespace Moge
{
	class MogeLib_API ScreenNode: public Node
	{
	public:
		ScreenNode();
		ScreenNode( const ScreenNode& screenNode );
		virtual ~ScreenNode();

		virtual const int getX()const override;
		virtual const int getY()const override;
		virtual const int getZ()const override;

		virtual void setXyz( const int x, const int y, const int z )override;
		virtual void setXyz( const IPosition& size )override;

		virtual void setX( const int x )override;
		virtual void setY( const int y )override;
		virtual void setZ( const int z )override;

		virtual void setSize( const unsigned int width, const unsigned int height, const unsigned int depth ) override;
		virtual void setWidth( const unsigned int width ) override;
		virtual void setHeight( const unsigned int height ) override;
		virtual void setHepth( const unsigned int depth ) override;
		virtual void setSize( const ISize& size )override;

		virtual const unsigned int getWidth()const override;
		virtual const unsigned int getHeight()const override;
		virtual const unsigned int getDepth()const override;

		void initialize();
		SDL_Window* GetScreen()const;
		SDL_Renderer* GetRenderer()const;
		SDL_Surface* GetSdlSurface()const;
		void DestroyScreen();
		void setResolution( const Math::MultiPoint<CUInt>& resolution );

	protected:
		virtual void UpdateImplementation();

	private:
		void FreeContent() override;

		SDL_Window* mainScreen = nullptr;
		SDL_Renderer* mainRenderer = nullptr;
		SDL_Surface* mainScreenSurface = nullptr;
		Math::MultiPoint<int> position = Math::MultiPointFactory::create2d<int>( 100, 100 );
		Math::MultiPoint<unsigned int> size = Math::MultiPointFactory::create2d<unsigned int>( 640, 480 );

	};
}