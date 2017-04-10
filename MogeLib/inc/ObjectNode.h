#pragma once

#include <memory>

#include "INode.h"
#include "Visible.h"
#include "Path.h"
#include "Scale.h"
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

		Math::IPosition<double>& getPosition()const override;
		Math::ISize<double>& getSize()const override;
		Math::IVector3D<double>& getScale()const override;
		void setTexture(const std::shared_ptr<ITexture>& texture);
		std::shared_ptr<ITexture>& getTexture();

	protected:
	private:
		Path mFilePath;
		std::unique_ptr<Math::IPosition<double>> position;
		std::unique_ptr<Math::IVector3D<double>> scale;
		std::shared_ptr<ITexture> texture;
	};
}
