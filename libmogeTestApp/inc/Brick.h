#pragma once

#include "Slab.h"
#include "CUL/Math/SquareMatrix2D.hpp"
#include <vector>

namespace Tetris
{
    //http://stackoverflow.com/questions/8399417/why-vectorboolreference-doesnt-return-reference-to-bool
    using myBool = unsigned char;
    static const myBool False = 0;
    static const myBool True = 1;
    using Directions = CUL::Math::Directions;
    enum class BrickTypes: char
    {
        L, 
        I, 
        O, 
        S, 
        T, 
        Z,
        ITEMS_COUNT
    };

    class Brick
    {
    public:
        explicit Brick( const BrickTypes typeofBrick );
        Brick( const Brick& brick );
        virtual ~Brick();
        const CoordinatestList getBlockPositions()const;
        void move( const Directions direction = Directions::D );
        void rotate( const bool clockWise = true );
        const BrickTypes getBlockType()const;
        Brick& operator=( const Brick& right );

    protected:
    private:
        static CUL::Math::SquareMatrix2Di slab2Matrix( const std::vector<Slab>& slabs );

        CUL::Math::SquareMatrix2Di blockMatrix = CUL::Math::SquareMatrix2Di( 4 );
        BrickTypes brickType = BrickTypes::T;
        MatrixPos position;
    };
}