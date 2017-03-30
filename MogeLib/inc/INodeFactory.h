#pragma once

#include "ObjectNode.h"
#include "Math/MultiPoint.h"
#include "Math/IPositionAdapter.h"
#include "ITextureFactory2D.h"
#include "ITextureFactory3D.h"

namespace Moge
{
	class MogeLib_API INodeFactory
	{
	public:
		INodeFactory() = default;
		virtual ~INodeFactory() = default;
		virtual ObjectNode CreateFromImage( 
            const Path& filePath, 
            const Math::IPosition<double>& position, 
            const MyString& name = MyString( "" ) ) = 0;
        virtual ObjectNode createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ) ) = 0;
		virtual void removeNode(const ObjectNode& node) = 0;
		virtual const bool exist(const ObjectNode& node ) = 0;
		virtual const unsigned int Count() = 0;
	protected:
	private:
	};
}
