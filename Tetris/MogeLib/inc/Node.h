#pragma once

#include <MOGE.h>
#include "Named.h"
#include "Position3d.h"
#include "Size.h"
#include <SDL.h>

namespace MOGE
{
	class MOGE_API Node:
		public Name,
		public Position,
		public Size
	{
	public:
		Node( const String& name = "" );
		virtual ~Node();
		
		SDL_Rect* GetGeometricsInfo();

	protected:
		void UpdateGeometrics();

	private:
		virtual void FreeContent() = 0;
		

		SDL_Rect mGeometrics;
	};
}