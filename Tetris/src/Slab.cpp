#include "Slab.h"

CSlab::CSlab( const CSlab& slab ): 
	m_position( CTableCoor( slab.Row(), slab.Col() ) ),
	m_partOfSlab( slab.m_partOfSlab ),
	m_empty( slab.m_empty )
{
}

CSlab::CSlab( CUInt row, CUInt col, const bool partOfSlab, const bool empty):
	m_position( CTableCoor( row, col ) ),
	m_partOfSlab(partOfSlab),
	m_empty(empty)
{
}

CSlab::~CSlab()
{

}

CSlab& CSlab::operator=( const CSlab& slab )
{
	if( this != &slab )
	{
		m_position = slab.m_position;
		m_partOfSlab = slab.m_partOfSlab;
		m_empty = slab.m_empty;
	}
	return *this;
}

CUInt CSlab::Row()const
{
	return m_position.Row();
}

void CSlab::Row( CUInt row )
{
	m_position.Row( row );
}

void CSlab::Col( CUInt col )
{
	m_position.Col( col );
}

CUInt CSlab::Col()const
{
	return m_position.Col();
}

void CSlab::SetPosition( CUInt row, CUInt col )
{
	m_position.ChangePosition( row, col ); 
}

const bool CSlab::PartOfSlab()const
{
	return m_partOfSlab;
}

const bool CSlab::Empty()const
{
	return m_empty;
}

void CSlab::Empty( const bool empty )
{
	m_empty = empty;
}

void CSlab::PartOfSlab( const bool partOfSlab )
{
	m_partOfSlab = partOfSlab;
}