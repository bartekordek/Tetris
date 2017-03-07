#pragma once

#include "ObjectNode.h"
#include "Math/MultiPoint.h"
#include "Math/IPositionAdapter.h"
#include "SurfaceFactory.h"

namespace Moge
{
	class MogeLib_API INodeFactory
	{
	public:
		INodeFactory( SurfaceFactory* surfaceFactory );
		virtual ~INodeFactory() = default;
		virtual ObjectNode CreateFromImage( 
            const Path& filePath, 
            const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ), 
            const MyString& name = MyString( "" ) ) = 0;
		virtual ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ), const MyString& name = MyString( "" ) ) = 0;
		virtual void removeNode( ObjectNode& node ) = 0;
		virtual const bool exist( ObjectNode& node ) = 0;
		virtual const unsigned int Count() = 0;
	protected:
		SurfaceFactory* getSurfacefactory();
	private:
		SurfaceFactory* surfaceFactory = nullptr;
	};
}
