#include "ViewData.hpp"

ViewData::ViewData()
{

}

ViewData::~ViewData()
{

}

void ViewData::setTargetSlabSize( const Vector3dd& slabSize )
{
    this->m_targetSlabSize = slabSize;
}

const Vector3dd& ViewData::getTargetSlabSize()const
{
    return this->m_targetSlabSize;
}

void ViewData::setDisplayOffset( const Vector3dd& displayOffset )
{
    this->m_displayOffset = displayOffset;
}

const Vector3dd& ViewData::getDisplayOffset()const
{
    return this->m_displayOffset;
}