#pragma once

#include <MOGE.h>
#include "Named.h"
#include "Position.h"
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

		void SetVisible( const bool visible = true );
		const bool GetVisible()const;
		
		SDL_Rect* GetGeometricsInfo();

	protected:
	private:
		virtual void FreeContent() = 0;
		void UpdateGeometrics();

		bool mVisible;
		SDL_Rect mGeometrics;
	};
}