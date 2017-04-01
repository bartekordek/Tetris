#pragma once
#include "INodeFactory.h"
#include <set>
namespace Moge
{
	class NodeFactory2D: public INodeFactory
	{
	public:
		NodeFactory2D( ITextureFactory2D* factory2D );
		virtual ~NodeFactory2D() = default;
		std::shared_ptr<ObjectNodeContent> CreateFromImage(
				const Path& filePath,
				const Math::IPosition<double>& position, 
				const MyString& name = MyString( "" ) ) override;
		std::shared_ptr<ObjectNodeContent> createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position = Math::IPositionAdapter<double>( 0.0, 0.0, 0.0 )) override;
		void removeNode(const std::shared_ptr<ObjectNodeContent>& node) override;
		const bool exist(const std::shared_ptr<ObjectNodeContent>& node ) override;
		const unsigned int Count() override;
	protected:
	private:
		ITextureFactory2D* factory2D = nullptr;
		std::set< ObjectNodeContent* > nodes;
	};
}