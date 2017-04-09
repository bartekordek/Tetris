#pragma once
#include "INodeFactory.h"
#include <set>
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
		std::shared_ptr<Node> createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 )) override;
		void removeNode(const std::shared_ptr<Node>& node) override;
		const bool exist(const std::shared_ptr<Node>& node ) override;
		const unsigned int count() override;
		IIterator<std::shared_ptr<Node>>& getNodes()override;
	protected:
	private:
		ITextureFactory3D* factory3D = nullptr;
		std::set< Node* > nodes;
	};
}