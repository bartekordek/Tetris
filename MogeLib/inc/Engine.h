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
#include "IRenderer.h"
#include "Math/ISize.h"
#include "IRenderer2D.h"
#include "IRenderer3D.h"

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
		void AddObject( const std::shared_ptr<Node> node, const MyString& name = MyString( "" ) );
		INodeFactory* getNodeFactory();
		IRenderer* getRenderer();
		void createScreen( Math::ISize<unsigned int>& size, Math::IPosition<int>& position, const std::string& label = "Window label." );
		void startMainLoop();
		void stopEventLoop();
		ITextureFactory2D* get2DTextureFactory()const;
		ITextureFactory3D* get3DTextureFactory()const;

	protected:

	private:
		void eventPool();
		void renderingLoop();
		void QueueFrame();
		void Render( Node& node );

		std::set<std::shared_ptr<Node>> mRenderableObjects;
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
		
		std::unique_ptr<IRenderer2D> renderer2D;
		std::unique_ptr<IRenderer3D> renderer3D;
		
		std::unique_ptr<ITextureFactory3D> textureFactory3D;
	};
}
