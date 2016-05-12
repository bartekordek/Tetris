#pragma once

#include "MOGE.h"

namespace MOGE
{
	class MOGE_API Visible
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