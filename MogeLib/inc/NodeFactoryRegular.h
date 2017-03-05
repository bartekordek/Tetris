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
		ObjectNode CreateFromImage( const Path& filePath, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const MyString& name = MyString( "" ) ) override;
		ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const MyString& name = MyString( "" ) ) override;
		void removeNode( ObjectNode& node) override;
		const bool exist( ObjectNode& node ) override;
		const unsigned int Count() override;
	protected:
	private:
		std::set< ObjectNodeContent* > nodes;
	};
} 