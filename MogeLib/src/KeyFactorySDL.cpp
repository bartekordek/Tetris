#include "KeyFactorySDL.h"
#include "KeySDL.h"
#include <SDL_events.h>

namespace Moge
{
	KeyFactorySDL::KeyFactorySDL(): sdlKey( SDL_GetKeyboardState( nullptr ) )
	{
	}

	const std::map<unsigned int, std::shared_ptr<IKey>> KeyFactorySDL::createKeys() const
	{
		std::map<unsigned int, std::shared_ptr<IKey>> result;
		for(
			unsigned int i = static_cast<unsigned int>( SDL_SCANCODE_A );
			i < static_cast<unsigned int>( SDL_NUM_SCANCODES );
			++i )
		{
			const auto key = createKey( i );
			result[i] = std::unique_ptr<IKey>( key );
		}
		return result;
	}

	IKey* KeyFactorySDL::createKey( const int keySignature ) const
	{
		IKey* result = new KeySDL();
		SDL_Scancode scanCode = static_cast<SDL_Scancode>( keySignature );
		result->setKeyName( SDL_GetScancodeName( scanCode ) );
		result->setKeyState( ( 0 == this->sdlKey[scanCode] ) ? false : true );
		return result;
	}
}