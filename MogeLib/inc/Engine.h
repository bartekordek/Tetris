#pragma once

#include <atomic>
#include <set>
#include <thread>
#include <mutex>
#include <memory>

#include "MultiPoint.h"
#include "Singleton.h"
#include "FileSystem.h"
#include "ObjectNode.h"
#include "ScreenNode.h"

namespace Moge
{
	class IKeyboardObservable;
	class IKeyboardObserver;
	class MogeLib_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name = MyString( "" ) );
		void AddObject( const ObjectNode node, const MyString& name = MyString( "" ) );
		void createScreen( const Math::MultiPoint<unsigned int>& resolution = Math::MultiPoint<unsigned int>( 2 ) );
		const std::shared_ptr<ScreenNode> getScreen()const;
		void initialize();
		void stop();
		void registerKeyboardListener( IKeyboardObserver* observer );

	protected:

	private:
		void eventPool();
		void MainLoop();
		void QueueFrame();
		void Render( ObjectNodeContent& node );

		std::shared_ptr<ScreenNode> mScreenBuffor;
		std::set<ObjectNode> mRenderableObjects;
		std::mutex mRenderableObjectsMutex;
		std::mutex mListMutex;
		std::thread mainLoop;
		std::atomic<bool> mainLoopIsRuning = true;
		std::atomic<bool> eventLoopActive = true;
		unsigned int mFrameCount = 0;
		std::unique_ptr<IKeyboardObservable> keyboardObservable;
	};
}