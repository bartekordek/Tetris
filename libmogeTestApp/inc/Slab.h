#pragma once

#include "ViewData.hpp"
#include "ISprite.hpp"

namespace Tetris
{
    class Slab
    {
    public:
        Slab( const Slab& slab );
        Slab( cunt row = 0, cunt col = 0, const bool empty = true );
        virtual ~Slab();
        Slab& operator=( const Slab& slab );
        cunt row()const;
        cunt col()const;
        void row( cunt row );
        void col( cunt col );
        const bool isEmpty()const;
        void setEmpty( const bool empty );
        void setNode( Moge::ISprite* node );
        Moge::ISprite* getNode()const;

        void setViewData( ViewData* viewData );

    private:
        void cartesian2Matrix();
        void matrix2Cartesian();
        void updateNodePos();
        void rescaleSprite();

        Vector3dd m_cartPos;
        Vector3du m_matrixPos;
        bool empty = true;
        Moge::ISprite* node = nullptr;
        ViewData* m_viewData = nullptr;
    };
}