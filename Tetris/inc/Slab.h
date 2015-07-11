#ifndef __CSLAB__
#define __CSLAB__

#include "Position.h"
#include "Utils.h"
#include "TableCoordinates.h"

/*
 * @brief This class contains information about smallest part of game grid, which is slab. Slabs are parts of bricks.
 * @details
 */
class CSlab
{
public:
	CSlab( const CSlab& slab );
	CSlab( CUInt row = 0, CUInt col = 0,  const bool partOfSlab = false, const bool empty = true );
	virtual ~CSlab();
	CSlab& operator=( const CSlab& slab );
	CUInt Row()const;
	CUInt Col()const;
/*
 * @brief Sets row number.
 * @param[in] typedef for const unsigned int as row number.
 */
	void Row( CUInt row );
/*
 * @brief Sets column number.
 * @param[in] typedef for const unsigned int as column number.
 */
	void Col( CUInt col );
/*
 * @brief Sets row number and column number.
 * @param[in] typedef for const unsigned int as row number.
 * @param[in] typedef for const unsigned int as column number.
 */
	void SetPosition( CUInt row, CUInt col );
/*
 * @brief Checks if slab is a part of slab.
 * @param[out] bool, true if is a part of slab, false otherwise.
 */
	const bool PartOfSlab()const;
/*
 * @brief Sets flag that tell if slab is a part of brick.
 * @param[in] bool condition - if is a part of slab.
 */
	void PartOfSlab( const bool partOfSlab );
/*
 * @brief Checks if slab is empty (if is not empty, it means that it should have differenc color).
 * @param[out] bool, true if is empty, false otherwise.
 */
	const bool Empty()const;
/*
 * @brief Sets emptiness condition (if is not empty, it means that it should have differenc color).
 * @param[in] bool condition - if is empty.
 */
	void Empty( const bool empty );
	
private:
	CTableCoor m_position;
	bool m_partOfSlab = false; // C++ 11 feature.
	bool m_empty;
};

#endif