#pragma once

#include "MogeLib.h"

namespace Moge
{
	class MogeLib_API Visible
	{
	public:
		Visible();
		virtual ~Visible();
		const bool GetVisible()const;
		void SetVisible( const bool visible = true );

	protected:
	private:
		bool visible = false;
	};
}