#pragma once

#include <MOGE.h>
#include "GeneralUtilities.h"
#include <SDL.h>
#include "Node.h"
#include <unordered_map>

namespace MOGE
{
	class MOGE_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		static void Initialize( const Size& size = Size( 800, 600 ) );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Position& position = Position(), const String name = "" );
		void AddObject( NodePtr& node, std::string name = "" );

		void RenderFrame();

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