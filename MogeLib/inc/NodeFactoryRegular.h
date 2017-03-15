#pragma once

#include "INodeFactory.h"
#include <set>

namespace Moge
{
	class MogeLib_API NodeFactoryRegular: public INodeFactory
	{
	public:
		NodeFactoryRegular( SurfaceFactory* surfaceFactory );
		virtual ~NodeFactoryRegular() = default;
		ObjectNode CreateFromImage( const Path& filePath, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ), const MyString& name = MyString( "" ) ) override;
		ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ), const MyString& name = MyString( "" ) ) override;
        ObjectNode createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 )) override;
		void removeNode( ObjectNode& node) override;
		const bool exist( ObjectNode& node ) override;
		const unsigned int Count() override;
	protected:
	private:
		std::set< ObjectNodeContent* > nodes;
	};
} 