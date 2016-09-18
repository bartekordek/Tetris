#pragma once

#include <MogeLib.h>
#include "Named.h"
#include "Position3d.h"
#include "Size.h"
#include <SDL.h>

namespace MogeLib
{
	class MogeLib_API Node:
		public Name,
		public Position,
		public Size
	{
	public:
		Node( const MyString& name = "" );
		virtual ~Node();
		
		SDL_Rect* GetGeometricsInfo();

	protected:
		void UpdateGeometrics();

	private:
		virtual void FreeContent() = 0;
		

		SDL_Rect mGeometrics;
	};
}