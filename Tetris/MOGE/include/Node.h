#pragma once

#include "GeneralUtilities.h"
#include "Size.h"
#include "Position.h"
#include "SDL/SDL.h"

namespace MOGE
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	using ImagePtr = SharedPtr<SDL_Surface>;

	class Node
	{
	public:
		Node();
		Node( const Path& path, const Size& size );
		Node( const Size& size, const Position& position = Position() );
		virtual ~Node();

		void SetImage( ImagePtr& image );
		const ImagePtr& GetImage()const;

		void SetSize( const Size& size );
		void SetPosition( const Position& position );
		void SetVisible( const bool visible = true );
		const bool IsVisible()const;
		const Position& GetPosition()const;
		const Size& GetSize()const;

		void SetPath( const Path& path );
		const Path& GetPath()const;

		SDL_Rect* GetGeometricsInfo();

	protected:
	private:
		Size mSize;
		Position mPosition;
		ImagePtr mImg;
		Path mFilePath;
		bool mVisible;
		SDL_Rect mGeometrics;
	};

	using NodePtr = SharedPtr<Node>;
}