#pragma once

#include <memory>

#include "INode.h"
#include "Visible.h"
#include "ITexture.h"

namespace Moge
{
    class MogeLib_API Node: public INode, public Visible
    {
    public:
        Node();
        Node( const Node& objectNodeContent );
        virtual ~Node();

        Node& operator=( const Node& right );
        const bool operator==( const Node& right )const;

        const CUL::Math::Vector3Dd& getPosition()const override;
        void setX( const double x ) override;
        void setY( const double y ) override;
        void setZ( const double z ) override;
        const CUL::Math::Vector3Dd& getSize()const override;
        const CUL::Math::Vector3Dd& getAbsSize()const override;
        const CUL::Math::Vector3Dd& getScale()const override;
        void setScale( const CUL::Math::Vector3Dd& scale )override;
        void setPosition( const CUL::Math::Vector3Dd& pos ) override;
        const RenderableType getRenderableType()const override;

        void setTexture( const std::shared_ptr<ITexture>& texture );
        const std::shared_ptr<ITexture>& getTexture()const override;

    protected:
    private:
        CUL::Math::Vector3Dd position;
        CUL::Math::Vector3Dd scale{ 1.0, 1.0, 1.0 };
        CUL::Math::Vector3Dd absSize;
        std::shared_ptr<ITexture> texture;
    };
}
