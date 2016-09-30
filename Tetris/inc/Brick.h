#pragma once

#include "Slab.h"
#include <vector>

namespace Tetris
{
	enum class BrickTypes: char
	{
		L, I, O, S, T
	};

	enum class Directions: char
	{
		L,
		R,
		U,
		D
	};

	class CBrick
	{
	public:
		CBrick( BrickTypes typeofBrick, const Directions direction = Directions::R );
		CBrick( const std::vector<CSlab>& blocks, const Directions direction = Directions::R );
		CBrick( const CBrick& brick );
		virtual ~CBrick();
		CoordinatestList GetBlockPositions()const;
		void Move( const Directions direction = Directions::D );
		void Rotate( const bool clockWise = true );
		BrickTypes GetBlockType()const;

	private:
		virtual void m_RotateClockWise() = 0;
		BrickTypes m_brickType = BrickTypes::T;

	protected:
		std::vector<CSlab> m_blocks;

		Directions m_direction;
	};

	class CLBrick: public CBrick
	{
	public:
		explicit CLBrick( const Directions direction = Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CIBrick: public CBrick
	{
	public:
		explicit CIBrick( const Directions direction = Directions::R );
	private:
		void m_RotateClockWise();
	};

	class COBrick: public CBrick
	{
	public:
		explicit COBrick(
			const Directions direction = Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CSBrick: public CBrick
	{
	public:
		explicit CSBrick( const Directions direction = Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CTBrick: public CBrick
	{
	public:
		explicit CTBrick(
			const Directions direction = Directions::R );
	private:
		void m_RotateClockWise();
	};
}