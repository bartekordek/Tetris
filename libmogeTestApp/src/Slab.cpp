#include "Slab.h"

using namespace Tetris;
Slab::Slab( 
    cunt row, cunt col, 
    const bool empty ):
    empty( empty )
{
}

Slab::Slab( const Slab& slab ):
    empty( slab.empty )
{
}

Slab::~Slab()
{
}

Slab& Slab::operator=( const Slab& slab )
{
    if( this != &slab )
    {
        this->m_cartPos = slab.m_cartPos;
        this->m_matrixPos = slab.m_matrixPos;
        this->empty = slab.empty;
        this->node = slab.node;
    }
    return *this;
}

cunt Slab::row()const
{
    return position.getRow();
}

void Slab::row( cunt row )
{
    position.setRow( row );
}

void Slab::col( cunt col )
{
    position.setCol( col );
}

cunt Slab::col()const
{
    return position.getCol();
}

const bool Slab::isEmpty()const
{
    return this->empty;
}

void Slab::setEmpty( const bool empty )
{
    this->empty = empty;
}

void Slab::setNode( Moge::ISprite* node )
{
    this->node = node;
}

Moge::ISprite* Slab::getNode()const
{
    return this->node;
}

void Slab::setViewData( ViewData* viewData )
{
    this->m_viewData = viewData;
}

void Slab::updateNodePos()
{
    this->node->setPosition(
        this->position.
    );
}