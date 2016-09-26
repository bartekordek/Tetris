#pragma once

#include <set>
#include <thread>
#include <mutex>

#include "MultiPoint.h"
#include "Singleton.h"
#include "FileSystem.h"
#include "ObjectNode.h"
#include "ScreenNode.h"

namespace Moge
{
	class MogeLib_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name = MyString( "" ) );
		void AddObject( const ObjectNode node, const MyString& name = MyString( "" ) );
		void CreateScreen( const Math::MultiPoint<unsigned int>& resolution = Math::MultiPoint<unsigned int>( 2 ) );
		void StartMainLoop();
		void StopMainLoop();

	protected:

	private:
		void MainLoop();
		void QueueFrame();
		void Render( ObjectNodeContent& node );

		std::shared_ptr<ScreenNode> mScreenBuffor;
		std::set<ObjectNode> mRenderableObjects;
		std::mutex mRenderableObjectsMutex;
		std::mutex mListMutex;
		std::thread mainLoop;
		bool mainLoopIsRuning = false;
		std::mutex mMainLoopMutex;
		unsigned int mFrameCount = 0;
	};
}