#include "ObjectNode.h"
#include "Math/IPositionFactory.h"
#include "Math/SizeDouble3D.h"
#include "Math/Vector3DFactory.h"
namespace Moge
{
	using namespace Math;
	ObjectNodeContent::ObjectNodeContent():
		position( Math::IPositionFactory::createSimplePositionDouble3D() ),
		size( new Math::SizeDouble3D() ),
		scale( Math::Vector3DFactory::createVectorSimpleDouble( 1.0, 1.0, 1.0 ) )
	{
		
	}

	ObjectNodeContent::ObjectNodeContent( const ObjectNodeContent& objectNodeContent ):
		mFilePath( objectNodeContent.mFilePath )
	{
	}

	ObjectNodeContent& ObjectNodeContent::operator=( const ObjectNodeContent& right )
	{
		if( &right != this )
		{
			this->position->setXyz( *right.position );
			this->size->setSize( *right.size );
			this->scale->setXYZ( *right.scale );
		}
		return *this;
	}

	ObjectNodeContent::~ObjectNodeContent()
	{
	}

	IPosition< double >& ObjectNodeContent::getPosition() const
	{
		return *this->position;
	}

	ISize< double >& ObjectNodeContent::getSize() const
	{
		return *this->size;
	}

	IVector3D< double >& ObjectNodeContent::getScale() const
	{
		return *this->scale;
	}

	void ObjectNodeContent::setTexture(const std::shared_ptr<ITexture>& texture)
	{
		this->texture = texture;
	}

	std::shared_ptr< ITexture >& ObjectNodeContent::getTexture()
	{
		return this->texture;
	}
}