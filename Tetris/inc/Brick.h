#ifndef __CBRICK__
#define __CBRICK__

#include "Utils.h"

#include "Slab.h"
#include "Orientation.h"
#include "Picture.h"
#include <vector>
#include <utility>

class CBrick
{
public:
	CBrick( const COrientation::Direction direction = COrientation::Direction::R );
	CBrick( const std::vector<CSlab>& blocks, 
			const COrientation::Direction direction = COrientation::Direction::R );
	virtual ~CBrick();
	CoordinatestList GetBlockPositions()const;

	void Move( const COrientation::Direction direction = COrientation::Direction::D );

	virtual void Draw();
	virtual void Rotate( const bool clockWise = true ) = 0;

	static void SetBackgroundImage( const Path& path );
	static const std::string GetImage();

private:
	static Path m_backgroundImage;

protected:
	std::vector<CSlab> m_blocks;
	COrientation m_direction;

};

class CLBrick: public CBrick
{
public:
	CLBrick( const COrientation::Direction direction = COrientation::Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CIBrick: public CBrick
{
public:
	CIBrick( const COrientation::Direction direction = COrientation::Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class COBrick: public CBrick
{
public:
	COBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CSBrick: public CBrick
{
public:
	CSBrick( const COrientation::Direction direction = COrientation::Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

class CTBrick: public CBrick
{
public:
	CTBrick(
		const COrientation::Direction direction = COrientation::Direction::R );
	void Rotate( const bool clockWise = true ) {};
private:
};

#endif