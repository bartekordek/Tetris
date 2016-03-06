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

	class Node;

	using ImagePtr = SharedPtr<SDL_Surface>;
	using NodePtr = SharedPtr<Node>;

	class Node
	{
	public:
		Node( const String& name = "", const Path& path = Path( "" ), const Size& size = Size( 0, 0 ), const Position& position = Position() );
		virtual ~Node();

		void SetImage( ImagePtr& image );
		const ImagePtr& GetImage()const;

		void SetSize( const Size& size );
		const Size& GetSize()const;

		void SetPosition( const Position& position );
		const Position& GetPosition()const;

		void SetVisible( const bool visible = true );
		const bool GetVisible()const;
		
		void SetPath( const Path& path );
		const Path& GetPath()const;

		void SetName( const String& name );
		const String& GetName()const;

		SDL_Rect* GetGeometricsInfo();

	protected:
	private:
		void UpdateGeometrics();

		String mName;
		Size mSize;
		Position mPosition;
		ImagePtr mImg;
		Path mFilePath;
		bool mVisible;
		SDL_Rect mGeometrics;
	};
}