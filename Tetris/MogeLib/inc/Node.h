#pragma once

#include "Named.h"
#include "Size.h"
#include "Position.h"
#include <SDL.h>

namespace MOGE
{
	class Node;

	using ImagePtr = SharedPtr<SDL_Surface>;
	using NodePtr = SharedPtr<Node>;

	class Node: 
		public Named,
		public Position,
		public Size
	{
	public:
		Node();
		virtual ~Node();

		void SetVisible( const bool visible = true );
		const bool GetVisible()const;
		
		SDL_Rect* GetGeometricsInfo();

	protected:
	private:
		void FreeCurrentImage();
		void UpdateGeometrics();

		Size mSize;
		Position mPosition;
		ImagePtr mImg;
		Path mFilePath;
		bool mVisible;
		SDL_Rect mGeometrics;
	};
}