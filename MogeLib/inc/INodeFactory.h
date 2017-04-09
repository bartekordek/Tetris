#pragma once

#include "ObjectNode.h"
#include "Math/IPositionAdapter.h"
#include "IIterator.h"

namespace Moge
{
	class MogeLib_API INodeFactory
	{
	public:
		INodeFactory() = default;
		virtual ~INodeFactory() = default;
		virtual std::shared_ptr<Node> CreateFromImage(
			const Path& filePath, 
			const Math::IPosition<double>& position, 
			const MyString& name = MyString( "" ) ) = 0;
		virtual std::shared_ptr<Node> createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ) ) = 0;
		virtual void removeNode(const std::shared_ptr<Node>& node) = 0;
		virtual const bool exist(const std::shared_ptr<Node>& node ) = 0;
		virtual const unsigned int count() = 0;
	protected:
	private:
	};
}
