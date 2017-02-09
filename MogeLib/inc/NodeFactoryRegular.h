#pragma once

#include "INodeFactory.h"

namespace Moge
{
	class MogeLib_API NodeFactoryRegular: public INodeFactory
	{
	public:
		std::shared_ptr<ScreenNode> CreateScreen( const Math::MultiPoint<unsigned int>& size ) override;
		ObjectNode CreateFromImage( const Path& filePath, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const MyString& name = MyString( "" ) ) override;
		ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const MyString& name = MyString( "" ) ) override;
		void RemoveNode( ObjectNode& node) override;
		const bool Exist( ObjectNode& node ) override;
		const unsigned int Count() override;
	protected:
	private:
		std::set< ObjectNodeContent* > nodes;
	};
} 