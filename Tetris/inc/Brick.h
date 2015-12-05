#ifndef __CBRICK__
#define __CBRICK__

#include "Utils.h"
#include "Slab.h"
#include "Orientation.h"
#include "Picture.h"
#include <vector>
#include <utility>

enum BrickTypes { L, I, O, S, T };

class CBrick
{
public:
	CBrick( BrickTypes typeofBrick, const Direction direction = Direction::R );
	CBrick( const Vector<CSlab>& blocks, const Direction direction = Direction::R );
	CBrick( const CBrick& brick );
	virtual ~CBrick();
	CoordinatestList GetBlockPositions()const;
	void Move( const Direction direction = Direction::D );
	void Rotate( const bool clockWise = true );
	BrickTypes GetBlockType()const;

private:
	virtual void m_RotateClockWise() = 0;
	BrickTypes m_brickType;

protected:
	std::vector<CSlab> m_blocks;
	
	COrientation m_direction;
};

class CLBrick: public CBrick
{
public:
	CLBrick( const Direction direction = Direction::R );
private:
	void m_RotateClockWise();
};

class CIBrick: public CBrick
{
public:
	CIBrick( const Direction direction = Direction::R );
private:
	void m_RotateClockWise();
};

class COBrick: public CBrick
{
public:
	COBrick(
		const Direction direction = Direction::R );
private:
	void m_RotateClockWise();
};

class CSBrick: public CBrick
{
public:
	CSBrick( const Direction direction = Direction::R );
private:
	void m_RotateClockWise();
};

class CTBrick: public CBrick
{
public:
	CTBrick(
		const Direction direction = Direction::R );
private:
	void m_RotateClockWise();
};
#endif
