# pragma once

#include "ObjectNode.h"
#include "Math/IPositionAdapter.h"

namespace Moge
{
	class MogeLib_API INodeCreator
	{
	public:
		INodeCreator();
		virtual ~INodeCreator();
		virtual void createScreen( const Math::MultiPoint<unsigned int>& size ) = 0;
		virtual ObjectNode createFromImage( const Path& filePath, const Math::IPosition<int>& position = Math::IPositionAdapter<int>( 0, 0, 0 ), const MyString& name = MyString( "" ) ) = 0;
		virtual void removeNode( ObjectNode& node ) = 0;
		virtual const bool exist( ObjectNode& node ) = 0;
		virtual const unsigned int count() = 0;
	protected:
	private:
	};
}