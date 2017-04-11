#pragma once
#include "INodeFactory.h"
#include "IList.h"
#include <memory>
namespace Moge
{
	class ITextureFactory3D;
	class NodeFactory3D: public INodeFactory
	{
	public:
		NodeFactory3D( ITextureFactory3D* factory3D );
		virtual ~NodeFactory3D() = default;
		std::shared_ptr<Node> CreateFromImage(
				const Path& filePath,
				const Math::IPosition<double>& position, 
				const MyString& name = MyString( "" ) ) override;
		std::shared_ptr<Node> createFromTexture(
				const std::shared_ptr<ITexture>& texture, 
				const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 ),
				const MyString& name = MyString( "" ) ) override;
		void remove(const std::shared_ptr<Node>& node) override;
		void remove( const Node* node ) override;
		const bool exist(const std::shared_ptr<Node>& node )const override;
		const unsigned int count()const override;
		IIterator<Node>& getNodes()override;
	protected:
	private:
		ITextureFactory3D* factory3D = nullptr;
		std::unique_ptr< IList<Node>> nodes;
	};
}
