#pragma once

#include "GeneralUtilities.h"
#include "SDL/SDL.h"
#include "Node.h"
#include <unordered_map>

namespace MOGE
{
	class Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		static void Initialize( const Size& size = Size( 800, 600 ) );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Position& position = Position(), const String name = "" );
		void AddObject( NodePtr& node, std::string name = "" );
		NodePtr& GetNode( const std::string& nodeName )const;
		NodePtr& GetNode( const unsigned int noodeIt )const;

	protected:


	private:
		void CreateScreen( const Size& size );
		void StartMainLoop();
		void StopMainLoop();
		void QueueFrame();
		void Render( Node& node );

		NodePtr mScreenBuffor;
		UnorderedMap< std::string, NodePtr> mRenderableObjects;
		Mutex mListMutex;
		Thread mainLoop;
	};
}