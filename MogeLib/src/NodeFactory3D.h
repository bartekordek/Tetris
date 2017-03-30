#pragma once
#include "INodeFactory.h"
#include <set>
namespace Moge
{
	class NodeFactory3D: public INodeFactory
	{
	public:
		NodeFactory3D( ITextureFactory3D* factory3D );
		virtual ~NodeFactory3D() = default;
		ObjectNode CreateFromImage( 
				const Path& filePath,
				const Math::IPosition<double>& position, 
				const MyString& name = MyString( "" ) ) override;
        ObjectNode createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 )) override;
		void removeNode(const ObjectNode& node) override;
		const bool exist(const ObjectNode& node ) override;
		const unsigned int Count() override;
	protected:
	private:
		ITextureFactory3D* factory3D = nullptr;
		std::set< ObjectNodeContent* > nodes;
	};
}