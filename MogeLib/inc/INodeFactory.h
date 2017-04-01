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
		virtual std::shared_ptr<ObjectNodeContent>
			CreateFromImage(
            const Path& filePath, 
            const Math::IPosition<double>& position, 
            const MyString& name = MyString( "" ) ) = 0;
        virtual std::shared_ptr<ObjectNodeContent> createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ) ) = 0;
		virtual void removeNode(const std::shared_ptr<ObjectNodeContent>& node) = 0;
		virtual const bool exist(const std::shared_ptr<ObjectNodeContent>& node ) = 0;
		virtual const unsigned int Count() = 0;
	protected:
	private:
	};
}
