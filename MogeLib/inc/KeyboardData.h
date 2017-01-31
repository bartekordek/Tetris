#pragma once

#include <string>
#include "IObservableData.h"

namespace Moge
{
	class KeyboardData: public IObservableData
	{
	public:
		KeyboardData( const std::string& data = "" );
		KeyboardData( const KeyboardData& keyboardData );
		virtual ~KeyboardData();
		KeyboardData& operator=( const KeyboardData& keyboardData );
		void setData( const std::string& data );
		const std::string& getData()const;
	protected:
	private:
		std::string data;
	};
}