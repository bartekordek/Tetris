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
	CBrick( const Direction direction = Direction::R );
	CBrick( const std::vector<CSlab>& blocks, 
			const Direction direction = Direction::R );
	virtual ~CBrick();
	CoordinatestList GetBlockPositions()const;

	void Move( const Direction direction = Direction::D );

	virtual void Draw();
	virtual void Rotate( const bool clockWise = true ) = 0;

	static void SetBackgroundImage( const Path& path );
	static const String GetImage();

private:
	static Path m_backgroundImage;

protected:
	std::vector<CSlab> m_blocks;
	COrientation m_direction;

};

class CLBrick: public CBrick
{
public:
	CLBrick( const Direction direction = Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CIBrick: public CBrick
{
public:
	CIBrick( const Direction direction = Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class COBrick: public CBrick
{
public:
	COBrick(
		const Direction direction = Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CSBrick: public CBrick
{
public:
	CSBrick( const Direction direction = Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CTBrick: public CBrick
{
public:
	CTBrick(
		const Direction direction = Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

#endif