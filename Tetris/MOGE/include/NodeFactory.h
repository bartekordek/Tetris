#pragma once

#include "Node.h"

namespace MOGE
{
	class NodeFactory
	{
	public:

		static NodePtr& CreateScreen( const Size& size );
		static NodePtr& CreateFromImage( Path filePath, Position position = Position(), const String& name = "" );
		static NodePtr& CreateEmpty( const Position& position = Position(), const Size& size = Size() );
	//	static NodePtr& CopyNode( const NodePtr& node );
		static NodePtr GetNode( const Path& path );

	private:
		static NodePtr& CreateEmpty( Node* nodeRawPtr );
		static const bool NodeExist( const String& nodeName );
		static const bool NodeExist( const NodePtr& node );

	private:
		//static Vector<NodePtr> nodes;

	};
} 