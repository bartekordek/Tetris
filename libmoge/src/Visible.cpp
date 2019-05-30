#include "Visible.h"

namespace Moge
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

    void Visible::SetVisible( const bool isVisible )
    {
        this->visible = isVisible;
    }
}