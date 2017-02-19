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

		const int getX()const override;
		const int getY()const override;
		const int getZ()const override;

		void setXyz( const int x, const int y, const int z )override;
		void setXyz( const IPosition& size )override;

		void setX( const int x )override;
		void setY( const int y )override;
		void setZ( const int z )override;

		void setSize( const unsigned int width, const unsigned int height, const unsigned int depth ) override;
		void setWidth( const unsigned int width ) override;
		void setHeight( const unsigned int height ) override;
		void setDepth( const unsigned int depth ) override;
		void setSize( const ISize& size )override;

		const unsigned int getWidth()const override;
		const unsigned int getHeight()const override;
		const unsigned int getDepth()const override;

		void initialize();
		SDL_Window* GetScreen()const;
		SDL_Renderer* GetRenderer()const;
		SDL_Surface* GetSdlSurface()const;
		void DestroyScreen();
		void setResolution( const Math::MultiPoint<const unsigned int>& resolution );

	protected:
		virtual void UpdateImplementation();

	private:
		void FreeContent();

		SDL_Window* mainScreen = nullptr;
		SDL_Surface* mainScreenSurface = nullptr;
		SDL_Renderer* renderer = nullptr;
		Math::MultiPoint<int> position = Math::MultiPointFactory::create2d<int>( 100, 100 );
		Math::MultiPoint<unsigned int> size = Math::MultiPointFactory::create2d<unsigned int>( 640, 480 );

	};
}