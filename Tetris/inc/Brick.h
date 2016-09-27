#pragma once

#include "GeneralUtilities.h"
#include "Slab.h"
#include "Picture.h"
#include <vector>
#include <utility>

namespace Tetris
{
	enum class BrickTypes: char
	{
		L, I, O, S, T
	};

	enum class Direction: char
	{
		L,
		R,
		U,
		D
	};

	class CBrick
	{
	public:
		CBrick( BrickTypes typeofBrick, const Direction direction = Direction::R );
		CBrick( const std::vector<CSlab>& blocks, const Direction direction = Direction::R );
		CBrick( const CBrick& brick );
		virtual ~CBrick();
		CoordinatestList GetBlockPositions()const;
		void Move( const Direction direction = Direction::D );
		void Rotate( const bool clockWise = true );
		BrickTypes GetBlockType()const;

	private:
		virtual void m_RotateClockWise() = 0;
		BrickTypes m_brickType = BrickTypes::T;

	protected:
		std::vector<CSlab> m_blocks;

		Direction m_direction;
	};

	class CLBrick: public CBrick
	{
	public:
		explicit CLBrick( const Direction direction = Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CIBrick: public CBrick
	{
	public:
		explicit CIBrick( const Direction direction = Direction::R );
	private:
		void m_RotateClockWise();
	};

	class COBrick: public CBrick
	{
	public:
		explicit COBrick(
			const Direction direction = Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CSBrick: public CBrick
	{
	public:
		explicit CSBrick( const Direction direction = Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CTBrick: public CBrick
	{
	public:
		explicit CTBrick(
			const Direction direction = Direction::R );
	private:
		void m_RotateClockWise();
	};
}