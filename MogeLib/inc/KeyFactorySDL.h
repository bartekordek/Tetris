#pragma once

#include <map>
#include <memory>

#include "IKeyFactory.h"

namespace Moge
{
	class KeyFactorySDL: public IKeyFactory
	{
	public:
		KeyFactorySDL();
		virtual ~KeyFactorySDL() = default;
		const std::map< unsigned int, std::shared_ptr<IKey >> createKeys()const override;

	protected:
	private:
		IKey* createKey( const int keySignature )const;
		const unsigned char* sdlKey = nullptr;
	};
}