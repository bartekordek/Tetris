#pragma once

#include "IObservableData.h"
#include "IKey.h"
#include <string>

union SDL_Event;
namespace Moge
{
	class KeyboardData: public IObservableData, public IKey
	{
	public:
		KeyboardData() = default;
		KeyboardData( const std::string& keyName, const bool keyIsDown );
		KeyboardData( const KeyboardData& keyboardData );
		virtual ~KeyboardData() = default;
		KeyboardData& operator=( const KeyboardData& keyboardData );
		MogeLib_API void setKeyName( const std::string& keyName ) override;
		MogeLib_API const std::string& getKeyName()const override;
		MogeLib_API void setKeyIsDown( const bool keyIsDown ) override;
		MogeLib_API const bool getKeyIsDown()const override;
	protected:
	private:
		std::string keyName;
		bool keyIsDown = false;
        int keyIndex = -1;
	};
}