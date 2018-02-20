#pragma once

#include <MogeLib.h>
#include "CUL/Named.hpp"
#include "IRenderable.h"
#include "Visible.h"

namespace Moge
{
    using Vector3Dd = CUL::Math::Vector3Dd;
    using MyString = CUL::MyString;
    class MogeLib_API INode:
        public CUL::Name,
        public Visible
    {
    public:
        explicit INode( const CUL::MyString& name = MyString( "" ) );
        virtual ~INode();

        virtual const Vector3Dd& getPosition()const = 0;
        virtual void setX( const double x ) = 0;
        virtual void setY( const double y ) = 0;
        virtual void setZ( const double z ) = 0;
        virtual void setPosition( const CUL::Math::Vector3Dd& pos ) = 0;
        virtual const Vector3Dd& getSizeReal()const = 0;
        virtual const Vector3Dd& getSizeAbs()const = 0;
        virtual const Vector3Dd& getScale()const = 0;
        virtual void setScale( const Vector3Dd& scale ) = 0;

        virtual void attach( INode* node ); //TODO

        virtual IRenderable* getRenderable() = 0;

        const std::string& getName()const;
        void setName( const std::string& name );

    protected:
    private:
        std::string m_name;

    };
}