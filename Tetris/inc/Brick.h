#ifndef __CBRICK__
#define __CBRICK__

#include "Utils.h"
#include "Slab.h"
#include "Orientation.h"
#include "Picture.h"
#include <vector>
#include <utility>

enum BrickTypes { L, I, O, S, T };

/*
 * @brief This class contains information about part of main grid - brick, such as: brick orientation, brick type.
 * @details
 */
class CBrick
{
public:
	CBrick( BrickTypes typeofBrick, const Direction direction = Direction::R );
	CBrick( const Vector<CSlab>& blocks, const Direction direction = Direction::R );
	CBrick( const CBrick& brick );
	virtual ~CBrick();
	/*
	 * @brief Stores positions of all slabs from bricks in vector. 
	 * @param[out] vector of positions. 
	 */
	CoordinatestList GetBlockPositions()const;
	/*
	 * @brief Moves brick in selected direction. 
	 * @param[in] Direction direction which block is going to be moved.. 
	 */
	void Move( const Direction direction = Direction::D );
	/*
	 * @brief Rotates brick. 
	 * @param[in] bool direction which block is going to be rotated. 
	 */
	void Rotate( const bool clockWise = true );
	/*
	 * @brief Sets background image as string path. 
	 * @param[in] boost::filesystem::path path to file. 
	 */
	static void SetBackgroundImage( const Path& path );
	/*
	 * @brief Return image location as string.
	 * @param[out] std::string - location of image file.
	 */
	static const String GetImage();
	/*
	 * @brief Returns brick type. 
	 */
	BrickTypes GetBlockType()const;

private:
	virtual void m_RotateClockWise() = 0;
	static Path m_backgroundImage;
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
