#pragma once

#include <MogeLib.h>
#include "Named.h"
#include "ISize.h"
#include "IPosition.h"

struct SDL_Rect;

namespace Moge
{
	class MogeLib_API Node: public Name, public Math::IPosition<int>, public Math::ISize<unsigned int>
	{
	public:
		explicit Node( const MyString& name = MyString( "" ) );
		virtual ~Node();
		
		SDL_Rect* GetGeometricsInfo()const;

	protected:
		virtual void UpdateGeometrics();

	private:
		virtual void FreeContent() = 0;
		
		SDL_Rect* mGeometrics = nullptr;
	};
}