#pragma once

#include "GeneralUtilities.h"
#include "Size.h"
#include "Position.h"

namespace MOGE
{
	class Node
	{
	public:
		Node();
		explicit Node( const Size& size, const Position& position );
		virtual ~Node();

		void SetSize( const Size& size );
		void SetPosition( const Position& position );
		const Position& GetPosition()const;
		const Size& GetSize()const;

	protected:
	private:
		Size mSize;
		Position mPosition;
	};
}