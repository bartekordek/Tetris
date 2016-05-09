#pragma once



namespace MOGE
{
	class NodeCreator
	{
	public:
		static ScreenNode CreateScreen( const Size& size );
	protected:
	private:
		
	};
	//class NodeFactory
	//{
	//public:

	//	
	//	static NodePtr& CreateFromImage( const Path filePath, const Position position = Position(), const String& name = "" );
	//	static NodePtr& CreateEmpty( const Position& position = Position(), const Size& size = Size() );
	//	static NodePtr GetNode( const Path& path );
	//	static NodePtr GetNodeByName( const String& name );

	//private:
	//	static NodePtr& Create( Node* nodeRawPtr );
	//	static const bool NodeExist( const String& nodeName );
	//	static const bool NodeExist( const NodePtr& node );

	//private:
	//	static Vector<NodePtr> nodes;

	//};
} 