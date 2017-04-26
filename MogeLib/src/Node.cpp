#include "Node.h"
#include "Math/IPositionFactory.h"
#include "Math/SizeDouble3D.h"
#include "Math/Vector3DFactory.h"
namespace Moge
{
	using namespace Math;
	Node::Node():
		position(IPositionFactory::createSimplePositionDouble3D() )
	{
	}

	Node::Node( const Node& objectNodeContent ):
		position( IPositionFactory::createSimplePositionDouble3D() )
	{
		*this->position.get() = *objectNodeContent.position.get();
		this->texture = objectNodeContent.texture;
	}

	Node& Node::operator=( const Node& right )
	{
		if( &right != this )
		{
			this->position->setXyz( *right.position );
			this->scale = right.scale;
			this->texture = right.texture;
		}
		return *this;
	}

	const bool Node::operator==( const Node& right )const
	{
		if( this != &right )
		{
			if( *this->position == *right.position && this->scale == right.scale )
			{
				if( this->texture.get() == right.texture.get() )
				{
					return true;
				}
			}
		}
		else
		{
			return true;
		}
		return false;
	}

	Node::~Node()
	{
	}

	const IPosition< double >& Node::getPosition() const
	{
		return *this->position;
	}

	void Node::setX( const double x )
	{
		this->position->setX( x );
	}

	void Node::setY( const double y )
	{
		this->position->setY( y );
	}

	void Node::setZ( const double z )
	{
		this->position->setZ( z );
	}

	const Vector3D< double >& Node::getSize()const
	{
		return this->texture->getSize();
	}

	const Math::Vector3D< double >& Node::getAbsSize() const
	{
		return this->absSize;
	}

	const Vector3D< double >& Node::getScale() const
	{
		return this->scale;
	}

	void Node::setScale( const Vector3D< double >& scale )
	{
		this->scale = scale;
		this->absSize = scale * this->texture->getSize();
	}


	void Node::setTexture( const std::shared_ptr<ITexture>& texture )
	{
		this->texture = texture;
	}

	const std::shared_ptr< ITexture >& Node::getTexture()const
	{
		return this->texture;
	}

	void Node::setPosition( const IPosition< double >& pos )
	{
		*this->position = pos;
	}

	const RenderableType Node::getRenderableType() const
	{
		return RenderableType::TEXTURED;
	}
}