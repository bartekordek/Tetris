#pragma once

#include <memory>

#include "Node.h"
#include "Visible.h"
#include "FileSystem.h"
#include "SurfaceWrapper.h"
#include "MultiPointFactory.h"

namespace Moge
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	class MogeLib_API ObjectNodeContent: public Node, public Visible
	{
	public:
		ObjectNodeContent();
		explicit ObjectNodeContent( const Path& filePath );
		ObjectNodeContent( const ObjectNodeContent& objectNodeContent );
		virtual ~ObjectNodeContent();

		const int getX()const override;
		const int getY()const override;
		const int getZ()const override;

		void setXyz( const int x, const int y, const int z )override;
		void setXyz( const IPosition& size )override;

		void setX( const int x )override;
		void setY( const int y )override;
		void setZ( const int z )override;

		void setSize( const unsigned int width, const unsigned int height, const unsigned int depth ) override;
		void setSize( const ISize& size )override;
		void setWidth( const unsigned int width ) override;
		void setHeight( const unsigned int height ) override;
		void setHepth( const unsigned int depth ) override;

		const unsigned int getWidth()const override;
		const unsigned int getHeight()const override;
		const unsigned int getDepth()const override;

		ObjectNodeContent& operator=( const ObjectNodeContent& right );

		const ImageSurface& GetSurface()const;
		void SetSurface( const ImageSurface& surface );

	protected:
		virtual void UpdateImplementation();

	private:
		void FreeContent() override;
		std::shared_ptr<SurfaceWrapper> surface;
		Path mFilePath;

		Math::MultiPoint<int> position = Math::MultiPointFactory::create3d<int>( 0, 0, 0 );
		Math::MultiPoint<unsigned int> size = Math::MultiPointFactory::create3d<unsigned int>( 0, 0, 0 );
	};
	
	using ObjectNode = std::shared_ptr<ObjectNodeContent>;
}