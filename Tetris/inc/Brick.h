#pragma once

#include "Slab.h"
#include "SquareMatrix2D.hpp"
#include <vector>

namespace Tetris
{
	//http://stackoverflow.com/questions/8399417/why-vectorboolreference-doesnt-return-reference-to-bool
	using myBool = unsigned char;
	static const myBool False = 0;
	static const myBool True = 1;
	enum class BrickTypes: char
	{
		L, I, O, S, T
	};

	class Brick
	{
	public:
		Brick( const BrickTypes typeofBrick, const Moge::Math::Directions direction = Moge::Math::Directions::R );
		Brick( const std::vector<CSlab>& blocks, const Moge::Math::Directions direction = Moge::Math::Directions::R );
		Brick( const Brick& brick );
		virtual ~Brick();
		CoordinatestList getBlockPositions()const;
		void move( const Moge::Math::Directions direction = Moge::Math::Directions::D );
		void rotate( const bool clockWise = true );
		BrickTypes getBlockType()const;

	protected:
		static Moge::Math::SquareMatrix2D<myBool> slab2Matrix( const std::vector<CSlab>& slabs );
		std::vector<CSlab> m_blocks;
		Moge::Math::SquareMatrix2D<myBool> blockMatrix = Moge::Math::SquareMatrix2D<myBool>( 4 );
		Moge::Math::Directions m_direction;

	private:
		virtual void m_RotateClockWise() = 0;
		BrickTypes m_brickType = BrickTypes::T;
	};

	class CLBrick: public Brick
	{
	public:
		explicit CLBrick( const Moge::Math::Directions direction = Moge::Math::Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CIBrick: public Brick
	{
	public:
		explicit CIBrick( const Moge::Math::Directions direction = Moge::Math::Directions::R );
	private:
		void m_RotateClockWise();
	};

	class COBrick: public Brick
	{
	public:
		explicit COBrick(
			const Moge::Math::Directions direction = Moge::Math::Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CSBrick: public Brick
	{
	public:
		explicit CSBrick( const Moge::Math::Directions direction = Moge::Math::Directions::R );
	private:
		void m_RotateClockWise();
	};

	class CTBrick: public Brick
	{
	public:
		explicit CTBrick(
			const Moge::Math::Directions direction = Moge::Math::Directions::R );
	private:
		void m_RotateClockWise();
	};
}