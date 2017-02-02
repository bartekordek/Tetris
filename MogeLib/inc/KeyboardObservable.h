#pragma once

#include <memory>
#include <map>
#include <thread>
#include <mutex>

#include "IKeyboardObservable.h"

namespace Moge
{
	class IKey;
	class IKeyFactory;
	class KeyboardObservable: public IKeyboardObservable
	{
	public:
		KeyboardObservable();
		virtual ~KeyboardObservable();
		const bool keyIsDown( const std::string& keyName )const;
	protected:
	private:
		void poolLoop();
		bool runLoop = true;
		const uint8_t* sdlKey = nullptr;
		std::map<unsigned int, std::shared_ptr<IKey>> keys;
		std::unique_ptr<IKeyFactory> keyFactory;
		std::thread poolThread;
		std::mutex quitMutex;

	};
}
