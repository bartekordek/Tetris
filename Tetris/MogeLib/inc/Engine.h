#pragma once

#include <map>
#include <thread>
#include <mutex>


#include "Singleton.h"
#include "FileSystem.h"
#include "ObjectNode.h"
#include "ScreenNode.h"

#include <SDL.h>


namespace MOGE
{
	class MOGE_API std::thread;
	class MOGE_API std::mutex;
	template class MOGE_API std::map< std::string, ObjectNode>;

	class MOGE_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		static void Initialize( const Size& size = Size( 800, 600 ) );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Position& position = Position(), const String name = "" );
		void AddObject( ObjectNode& node, std::string name = "" );

		void RenderFrame();

	protected:

	private:
		void CreateScreen( const Size& size );
		void StartMainLoop();
		void StopMainLoop();
		void QueueFrame();
		void Render( Node& node );

		ScreenNode mScreenBuffor;
		std::map< std::string, ObjectNode> mRenderableObjects;
		std::mutex mListMutex;
		std::thread mainLoop;
	};
}