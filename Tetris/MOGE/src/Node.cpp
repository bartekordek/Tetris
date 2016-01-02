#include "Node.h"
#include "Size.h"

namespace MOGE
{
	Node::Node()
	{
	}

	Node::Node(const Size& size, const Position& position): mSize(size), mPosition( position )
	{
	}

	Node::~Node()
	{
	}

	void Node::SetSize( const Size& size )
	{
		mSize = size;
	}

	void Node::SetPosition( const Position& position )
	{
		mPosition = position;
	}

	const Position& Node::GetPosition()const
	{
		return mPosition;
	}

	const Size& Node::GetSize()const
	{
		return mSize;
	}
}