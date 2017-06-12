#pragma once
#include "IKeyboardObservable.h"
#include "LckPrim.h"
#include "IEventLoop.h"
#include <map>
#include <memory>
namespace Moge
{
	class IKeyFactory;
	class KeyboardObservableSDL: public IKeyboardObservable, public IEventLoop
	{
	public:
		KeyboardObservableSDL();
		virtual ~KeyboardObservableSDL();
		void runEventLoop() override;
		void stopEventLoop() override;
	protected:
	private:
		LckPrim<bool> m_runEventLoop;
		std::unique_ptr<IKeyFactory> keyFactory;
		const uint8_t* sdlKey = nullptr;
		std::map<unsigned int, std::shared_ptr<IKey>> keys;
	};
}