#pragma once
#include "INodeFactory.h"
namespace Moge
{
	class NodeFactory2D: public INodeFactory
	{
	public:
		NodeFactory2D( ITextureFactory2D* factory2D );
		virtual ~NodeFactory2D() = default;
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
		ITextureFactory2D* factory2D = nullptr;
		std::set< ObjectNodeContent* > nodes;
	};
}