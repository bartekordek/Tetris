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
    return this->m_matrixPos.getY();
}

void Slab::row( cunt row )
{
    this->m_matrixPos.setY( row );
    matrix2Cartesian();
}

void Slab::col( cunt col )
{
    this->m_matrixPos.setX( col );
    matrix2Cartesian();
}

cunt Slab::col()const
{
    return this->m_matrixPos.getX();
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
    this->node->setPosition( this->m_cartPos );
}

void Slab::cartesian2Matrix()
{

}

void Slab::matrix2Cartesian()
{
    this->m_cartPos.setX( 
        this->m_viewData->getDisplayOffset().getX() +
        this->m_viewData->getTargetSlabSize().getX() * this->m_matrixPos.getX() );

    this->m_cartPos.setY(
        this->m_viewData->getDisplayOffset().getY() +
        this->m_viewData->getTargetSlabSize().getY() * this->m_matrixPos.getY() );
}