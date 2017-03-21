#pragma once

#include <atomic>
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <memory>

#include "Math/MultiPoint.h"
#include "Singleton.h"
#include "Path.h"
#include "ObjectNode.h"
#include "IKeyboardObservable.h"
#include "INodeFactory.h"
#include "ITextureFactory.h"
#include "SurfaceFactory.h"
#include "IRenderer.h"
#include "Math/ISize.h"

namespace Moge
{
	class IKeyboardObserver;
    class IKeyboardData;
    class IKey;
    class IKeyFactory;
	class MogeLib_API Engine: public Singleton<Engine>, public IKeyboardObservable
	{
	public:
		Engine( void );
		virtual ~Engine();

		void AddObject( const Path& filePath, const Math::MultiPoint<double>& position, const MyString& name = MyString( "" ) );
		void AddObject( const ObjectNode node, const MyString& name = MyString( "" ) );
		INodeFactory* getNodeFactory();
		SurfaceFactory* getSurfaceFactory();
        IRenderer* getRenderer();
        void setScreenSize( Math::ISize<int>& size, Math::IPosition<int>& position );
		void startMainLoop();
		void stopEventLoop();
		ITextureFactory* get2DTextureFactory()const;
		ITextureFactory* get3DTextureFactory()const;

	protected:

	private:
		void eventPool();
		void renderingLoop();
		void QueueFrame();
		void Render( ObjectNodeContent& node );
		

		std::set<ObjectNode> mRenderableObjects;
		std::mutex mRenderableObjectsMutex;
		std::mutex mListMutex;
		std::thread mainLoop;
		std::atomic<bool> mainLoopIsRuning = {true};
		std::atomic<bool> eventLoopActive = { true };
		unsigned int mFrameCount = 0;

		const uint8_t* sdlKey = nullptr;
		std::map<unsigned int, std::shared_ptr<IKey>> keys;
		std::unique_ptr<IKeyFactory> keyFactory;
		std::unique_ptr<INodeFactory> nodeFactory;
		std::unique_ptr<SurfaceFactory> surfaceFactory;
		std::unique_ptr<ITextureFactory> textureFactory2D;
		std::unique_ptr<ITextureFactory> textureFactory3D;
	};
}
