#pragma once

#include <memory>
#include <set>

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
		ObjectNodeContent( const Path& filePath );
		ObjectNodeContent( const ObjectNodeContent& objectNodeContent );
		virtual ~ObjectNodeContent();

		virtual const int getX()const override;
		virtual const int getY()const override;
		virtual const int getZ()const override;

		virtual void setXyz( const int x, const int y, const int z )override;
		virtual void setXyz( const IPosition& size )override;

		virtual void setX( const int x )override;
		virtual void setY( const int y )override;
		virtual void setZ( const int z )override;

		virtual void setSize( const unsigned int width, const unsigned int height, const unsigned int depth ) override;
		virtual void setSize( const ISize& size )override;
		virtual void setWidth( const unsigned int width ) override;
		virtual void setHeight( const unsigned int height ) override;
		virtual void setHepth( const unsigned int depth ) override;

		virtual const unsigned int getWidth()const override;
		virtual const unsigned int getHeight()const override;
		virtual const unsigned int getDepth()const override;

		ObjectNodeContent& operator=( const ObjectNodeContent& right );

		const ImageSurface& GetSurface()const;
		const Path& GetPath()const;
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