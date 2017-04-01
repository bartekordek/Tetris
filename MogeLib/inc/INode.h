#pragma once

#include <MogeLib.h>
#include "Named.h"
#include "Math/ISize.h"
#include "Math/IPosition.h"
#include "Math/IVector3D.h"

struct SDL_Rect;

namespace Moge
{
	class MogeLib_API INode: public Name
	{
	public:
		explicit INode( const MyString& name = MyString( "" ) );
		virtual ~INode() = default;
		
		virtual Math::IPosition<double>& getPosition()const = 0;
		virtual Math::ISize<double>& getSize()const = 0;
		virtual Math::IVector3D<double>& getScale()const = 0;

	protected:
	private:
	};
}