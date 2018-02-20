#include "Slab.h"

using namespace Tetris;
Slab::Slab( 
    cunt row, cunt col, 
    const bool empty ):
    m_matrixPos( col, row, 0 ),
    empty( empty )
{
    matrix2Cartesian();
}

Slab::Slab( const Slab& slab ):
    m_cartPos( slab.m_cartPos ),
    m_matrixPos( slab.m_matrixPos ),
    empty( slab.empty ),
    node( slab.node ),
    m_viewData( slab.m_viewData )
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
    matrix2Cartesian();
    rescaleSprite();
}

Moge::ISprite* Slab::getNode()const
{
    return this->node;
}

void Slab::setViewData( ViewData* viewData )
{
    this->m_viewData = viewData;
    matrix2Cartesian();
    rescaleSprite();
}

void Slab::cartesian2Matrix()
{
}

void Slab::matrix2Cartesian()
{
    if( this->m_viewData )
    {
        this->m_cartPos.setX(
            this->m_viewData->getDisplayOffset().getX() +
            this->m_viewData->getTargetSlabSize().getX() * this->m_matrixPos.getX() );

        this->m_cartPos.setY(
            this->m_viewData->getDisplayOffset().getY() +
            this->m_viewData->getTargetSlabSize().getY() * this->m_matrixPos.getY() );

        updateNodePos();
    }
}

void Slab::updateNodePos()
{
    if( this->node )
    {
        this->node->setPosition( this->m_cartPos );
    }
}

void Slab::rescaleSprite()
{
    if( this->node )
    {
        auto actualSize = this->node->getSizeReal();
        auto targetSize = this->m_viewData->getTargetSlabSize();
        if( actualSize.getZ() == 0 )
        {
            actualSize.setZ( 1.0 );
        }
        auto scale = targetSize / actualSize;
        this->node->setScale( scale );
    }
}