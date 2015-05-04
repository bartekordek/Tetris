#ifndef __CBRICK__
#define __CBRICK__

#include "Slab.h"
#include "Orientation.h"
#include <vector>

class CBrick
{
public:
	CBrick( const COrientation::Direction direction = COrientation::Direction::R );
	CBrick( 
		const std::vector<CSlab>& blocks, 
		const COrientation::Direction direction = COrientation::Direction::R );
	virtual ~CBrick();

	virtual void Draw();
	virtual void Move( const COrientation::Direction direction ) = 0;
	virtual void Rotate( const bool clockWise = true ) = 0;

private:

protected:
	std::vector<CSlab> m_blocks;
	COrientation m_direction;

};

class CLBrick: public CBrick
{
public:
	CLBrick( 
		const COrientation::Direction direction = COrientation::Direction::R );
private:
};

class CIBrick: public CBrick
{
public:
	CIBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
private:
};

class COBrick: public CBrick
{
public:
	COBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
private:
};

class CSBrick: public CBrick
{
public:
	CSBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
private:
};

class CTBrick: public CBrick
{
public:
	CTBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
private:
};

#endif