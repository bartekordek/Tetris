#pragma once

#include "GeneralUtilities.h"
#include "Slab.h"
#include "Orientation.h"
#include "Picture.h"
#include <vector>
#include <utility>

namespace Tetris
{
	enum class BrickTypes: char
	{
		L, I, O, S, T
	};

	class CBrick
	{
	public:
		CBrick( BrickTypes typeofBrick, const COrientation::Direction direction = COrientation::Direction::R );
		CBrick( const std::vector<CSlab>& blocks, const COrientation::Direction direction = COrientation::Direction::R );
		CBrick( const CBrick& brick );
		virtual ~CBrick();
		CoordinatestList GetBlockPositions()const;
		void Move( const COrientation::Direction direction = COrientation::Direction::D );
		void Rotate( const bool clockWise = true );
		BrickTypes GetBlockType()const;

	private:
		virtual void m_RotateClockWise() = 0;
		BrickTypes m_brickType = BrickTypes::T;

	protected:
		std::vector<CSlab> m_blocks;

		COrientation::Direction m_direction;
	};

	class CLBrick: public CBrick
	{
	public:
		explicit CLBrick( const COrientation::Direction direction = COrientation::Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CIBrick: public CBrick
	{
	public:
		explicit CIBrick( const COrientation::Direction direction = COrientation::Direction::R );
	private:
		void m_RotateClockWise();
	};

	class COBrick: public CBrick
	{
	public:
		explicit COBrick(
			const COrientation::Direction direction = COrientation::Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CSBrick: public CBrick
	{
	public:
		explicit CSBrick( const COrientation::Direction direction = COrientation::Direction::R );
	private:
		void m_RotateClockWise();
	};

	class CTBrick: public CBrick
	{
	public:
		explicit CTBrick(
			const COrientation::Direction direction = COrientation::Direction::R );
	private:
		void m_RotateClockWise();
	};
}