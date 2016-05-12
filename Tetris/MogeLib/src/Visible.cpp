#include "Visible.h"

namespace MOGE
{
	Visible::Visible()
	{
	}


	Visible::~Visible()
	{
	}

	const bool Visible::GetVisible()const
	{
		return this->visible;
	}

	void Visible::SetVisible( const bool visible )
	{
		this->visible = visible;
	}
}