#pragma once

#include "MogeLib.h"

namespace MogeLib
{
	class MogeLib_API Visible
	{
	public:
		Visible();
		~Visible();
		const bool GetVisible()const;
		void SetVisible( const bool visible = true );

	protected:
	private:
		bool visible = false;
	};
}