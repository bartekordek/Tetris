#pragma once

#include <set>
#include <thread>
#include <mutex>


#include "Position3d.h"
#include "Singleton.h"
#include "FileSystem.h"
#include "ObjectNode.h"
#include "ScreenNode.h"

#include <SDL.h>

namespace MOGE
{
	class MOGE_API std::thread;
	class MOGE_API std::mutex;
	template class MOGE_API std::set<ObjectNode>;

	class MOGE_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Position3d& position = Position3d(), const String& name = "" );
		void AddObject( const ObjectNode node, const String& name = "" );
		void CreateScreen( const Size& size );
		void StartMainLoop();
		void StopMainLoop();

	protected:

	private:
		void MainLoop();
		void QueueFrame();
		void Render( ObjectNodeContent& node );

		ScreenNode mScreenBuffor;
		std::set<ObjectNode> mRenderableObjects;
		std::mutex mRenderableObjectsMutex;
		std::mutex mListMutex;
		std::thread mainLoop;
		bool mainLoopIsRuning = false;
		std::mutex mMainLoopMutex;
		unsigned int mFrameCount = 0;
	};
}