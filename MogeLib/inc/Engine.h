#pragma once

#include <thread>
#include <mutex>
#include <memory>

#include "Singleton.h"
#include "IKeyboardObservable.h"
#include "INodeFactory.h"
#include "IRenderer.h"
#include "Math/ISize.h"
#include "IRenderer2D.h"
#include "IRenderer3D.h"
#include "ITextureFactory.h"
#include "IFPSCounter.h"
#include "LckPrim.h"
#include "ILogUtil.h"

namespace Moge
{
	class IKey;
	class IKeyFactory;
	class ITextureFactory3D;
	class IEventLoop;
	class MogeLib_API Engine: public Singleton<Engine>
	{
	public:
		Engine( void );
		virtual ~Engine();

		void createScreen( Math::ISize<unsigned int>& size, Math::IPosition<int>& position, const std::string& label = "Window label." )const;
		void start();
		void close();
		ITextureFactory* get2DTextureFactory()const;
		ITextureFactory* get3DTextureFactory()const;
		INodeFactory* get2DNodeFactory()const;
		INodeFactory* get3DNodeFactory()const;
		IKeyboardObservable* getKeyboardObservable()const;

	protected:

	private:
		void eventPool();
		void renderingLoop2D();
		void QueueFrame();
		void infoLoop();

		std::mutex mRenderableObjectsMutex;
		std::mutex mListMutex;
		std::thread mainLoop;
		std::thread infoLoopThread;
		LckPrim<bool> mainLoopIsRuning;
		LckPrim<bool> eventLoopActive;

		std::unique_ptr<INodeFactory> nodeFactory;
		
		std::unique_ptr<IRenderer2D> renderer2D;
		std::unique_ptr<IRenderer3D> renderer3D;
		
		std::unique_ptr<ITextureFactory3D> textureFactory3D;

		std::unique_ptr<IFPSCounter> fpsCounter;
		std::unique_ptr<ILogUtil> logUtil;
		std::unique_ptr<IKeyboardObservable> keyboardObservable;
		IEventLoop* keyboardEventObservable = nullptr;
		LckPrim<int> frameSleepTimeMs;
		int framesDelta = 2;
		int fpsConst = 60;
		unsigned framesSampleSize = 8;
		LckPrim<unsigned> fpsCalcSampleTimeSpan;
	};
}