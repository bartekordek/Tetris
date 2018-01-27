#include "Brick.h"
#include "BrickFactory.h"

using Directions = CUL::Math::Directions;
namespace Tetris
{
    Brick::Brick( const BrickTypes typeofBrick ):
        blockMatrix( CBrickFactory::createBrick( typeofBrick ) ), 
        brickType( typeofBrick )
    {
    }

    Brick::Brick( const Brick& brick ):
        blockMatrix( brick.blockMatrix ),
        brickType( brick.brickType ), 
        position( brick.position )
    {
    }

    const BrickTypes Brick::getBlockType()const
    {
        return brickType;
    }

    Brick& Brick::operator=( const Brick& right )
    {
        if( &right != this )
        {
            this->blockMatrix = right.blockMatrix;
            this->brickType = right.brickType;
            this->position = right.position;
        }
        return *this;
    }

    CUL::Math::SquareMatrix2Di Brick::slab2Matrix( const std::vector<Slab>& slabs )
    {
        CUL::Math::SquareMatrix2Di result( 4 );
        for( const auto& slab: slabs )
        {
            const unsigned int row = slab.row();
            const unsigned int col = slab.col();
            result( row, col ) = true;
        }
        return result;
    }


    void Brick::rotate( const bool clockWise )
    {
        blockMatrix.rotate( clockWise );
        blockMatrix.moveElementsUntillNoEmptyLine( Directions::U );
        blockMatrix.moveElementsUntillNoEmptyLine( Directions::L );
    }

    const CoordinatestList Brick::getBlockPositions()const
    {
        CoordinatestList positions;

        for( unsigned int rowIndex = 0; rowIndex < this->blockMatrix.getRowsCount(); ++rowIndex )
        {
            for( unsigned int colIndex = 0; colIndex < this->blockMatrix.getColumnCount(); ++colIndex )
            {
                if( True == this->blockMatrix( rowIndex, colIndex ) )
                {
                    positions.push_back( MatrixPos( rowIndex, colIndex ) + this->position );
                }
            }
        }
        return positions;
    }

    Brick::~Brick()
     {
    }

    void Brick::move( const Directions direction )
    {
        int rowDiff = 0;
        int colDiff = 0;
        if( Directions::D == direction )
        {
            rowDiff = 1;
        }
        else if( Directions::L == direction )
        {
            colDiff = -1;
        }
        else if( Directions::R == direction )
        {
            colDiff = 1;
        }
        else if( Directions::U == direction )
        {
            rowDiff = -1;
        }

        position.setRow( position.getRow() + rowDiff );
        position.setCol( position.getCol() + colDiff );
    }
}