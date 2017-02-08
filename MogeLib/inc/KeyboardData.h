#pragma once

#include "IObservableData.h"
#include <string>

namespace Moge
{

	class KeyboardData: public IObservableData
	{
	public:
		KeyboardData() = default;
		KeyboardData( const std::string& keyName, const bool keyIsDown );
		KeyboardData( const KeyboardData& keyboardData );
		virtual ~KeyboardData() = default;
		KeyboardData& operator=( const KeyboardData& keyboardData );
		MogeLib_API void setKeyName( const std::string& keyName );
		MogeLib_API const std::string& getKeyName()const;
		MogeLib_API void setKeyIsDown( const bool keyIsDown );
		MogeLib_API const bool getKeyIsDown()const;
	protected:
	private:
		std::string keyName;
		bool keyIsDown = false;
	};
}