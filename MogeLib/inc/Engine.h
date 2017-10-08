#pragma once

#include <map>
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

namespace Moge
{
	class IKeyboardObserver;
	class IKeyboardData;
	class IKey;
	class IKeyFactory;
	class ITextureFactory3D;
	class MogeLib_API Engine: public Singleton<Engine>, public IKeyboardObservable
	{
	public:
		Engine( void );
		virtual ~Engine();

		void createScreen( Math::ISize<unsigned int>& size, Math::IPosition<int>& position, const std::string& label = "Window label." )const;
		void startMainLoop();
		void stopEventLoop();
		ITextureFactory* get2DTextureFactory()const;
		ITextureFactory* get3DTextureFactory()const;
		INodeFactory* get2DNodeFactory()const;
		INodeFactory* get3DNodeFactory()const;

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

		std::map<unsigned int, std::shared_ptr<IKey>> keys;
		std::unique_ptr<IKeyFactory> keyFactory;

		std::unique_ptr<INodeFactory> nodeFactory;
		
		std::unique_ptr<IRenderer2D> renderer2D;
		std::unique_ptr<IRenderer3D> renderer3D;
		
		std::unique_ptr<ITextureFactory3D> textureFactory3D;

		std::unique_ptr<IFPSCounter> fpsCounter;
		LckPrim<int> frameSleepTimeMs;
		int framesDelta = 2;
		int fpsConst = 60;
		unsigned framesSampleSize = 8;
		LckPrim<unsigned> fpsCalcSampleTimeSpan;
	};
}