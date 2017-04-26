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

		const Math::IPosition<double>& getPosition()const override;
		void setX( const double x ) override;
		void setY( const double y ) override;
		void setZ( const double z ) override;
		const Math::Vector3D<double>& getSize()const override;
		const Math::Vector3D<double>& getAbsSize()const override;
		const Math::Vector3D<double>& getScale()const override;
		void setScale( const Math::Vector3D<double>& scale )override;
		void setPosition( const Math::IPosition<double>& pos ) override;
		const RenderableType getRenderableType()const override;

		void setTexture( const std::shared_ptr<ITexture>& texture );
		const std::shared_ptr<ITexture>& getTexture()const override;

	protected:
	private:
		std::unique_ptr<Math::IPosition<double>> position;
		Math::Vector3D<double> scale{ 1.0, 1.0, 1.0 };
		Math::Vector3D<double> absSize;
		std::shared_ptr<ITexture> texture;
	};
}
