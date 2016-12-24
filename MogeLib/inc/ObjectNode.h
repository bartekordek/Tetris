#pragma once

#include <memory>

#include "Node.h"
#include "Visible.h"
#include "FileSystem.h"
#include "SurfaceWrapper.h"
#include "MultiPointFactory.h"
#include "Scale.h"

namespace Moge
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	class MogeLib_API ObjectNodeContent: public Node, public Visible, public Scale
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
		void setDepth( const unsigned int depth ) override;

		const unsigned int getWidth()const override;
		const unsigned int getHeight()const override;
		const unsigned int getDepth()const override;

		ObjectNodeContent& operator=( const ObjectNodeContent& right );

		const ImageSurface& GetSurface()const;
		void SetSurface( const ImageSurface& surface );

		void setScale( const double scale );
		void setXscale( const double scale );
		void setYscale( const double scale );
		void setZscale( const double scale );

		const double getScale();
		const double getXscale();
		const double getYscale();
		const double getZscale();

	protected:
		double scaleX = 1.0;
		double scaleY = 1.0;
		double scaleZ = 1.0;

	private:
		void updateScale();
		std::shared_ptr<SurfaceWrapper> surface;
		Path mFilePath;

		Math::MultiPoint<int> position = Math::MultiPointFactory::create3d<int>( 0, 0, 0 );
		Math::MultiPoint<unsigned int> size = Math::MultiPointFactory::create3d<unsigned int>( 0, 0, 0 );
	};
	
	using ObjectNode = std::shared_ptr<ObjectNodeContent>;
}