#include "ObjectNode.h"
#include "Math/IPositionFactory.h"
#include "Math/SizeDouble3D.h"
#include "Math/Vector3DFactory.h"
namespace Moge
{
	using namespace Math;
	Node::Node():
		position( Math::IPositionFactory::createSimplePositionDouble3D() ),
		size( new Math::SizeDouble3D() ),
		scale( Math::Vector3DFactory::createVectorSimpleDouble( 1.0, 1.0, 1.0 ) )
	{
		
	}

	Node::Node( const Node& objectNodeContent ):
		mFilePath( objectNodeContent.mFilePath )
	{
	}

	Node& Node::operator=( const Node& right )
	{
		if( &right != this )
		{
			this->position->setXyz( *right.position );
			this->size->setSize( *right.size );
			this->scale->setXYZ( *right.scale );
		}
		return *this;
	}

	Node::~Node()
	{
	}

	IPosition< double >& Node::getPosition() const
	{
		return *this->position;
	}

	ISize< double >& Node::getSize() const
	{
		return *this->size;
	}

	IVector3D< double >& Node::getScale() const
	{
		return *this->scale;
	}

	void Node::setTexture(const std::shared_ptr<ITexture>& texture)
	{
		this->texture = texture;
	}

	std::shared_ptr< ITexture >& Node::getTexture()
	{
		return this->texture;
	}
}