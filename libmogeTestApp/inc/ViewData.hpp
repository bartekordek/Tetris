#pragma once

#include "BasicTypedefs.hpp"

class ViewData
{
public:
    ViewData();
    virtual ~ViewData();

    void setTargetSlabSize( const Vector3dd& slabSize );
    const Vector3dd& getTargetSlabSize()const;

    void setDisplayOffset( const Vector3dd& displayOffset );
    const Vector3dd& getDisplayOffset()const;

protected:
private:

    Vector3dd m_targetSlabSize;
    Vector3dd m_displayOffset;

};