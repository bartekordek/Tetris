#pragma once

#include <memory>

#include "INode.h"
#include "Visible.h"
#include "Path.h"
#include "Scale.h"
#include "ITexture.h"

namespace Moge
{
	enum IMAGETYPE
	{
		UNKOWN = -1,
		BMP,
		PNG,
		MAIN_SCREEN
	};

	class MogeLib_API ObjectNodeContent: public INode, public Visible
	{
	public:
		ObjectNodeContent();
		ObjectNodeContent( const ObjectNodeContent& objectNodeContent );
		virtual ~ObjectNodeContent();

		ObjectNodeContent& operator=( const ObjectNodeContent& right );

		Math::IPosition<double>& getPosition()const override;
		Math::ISize<double>& getSize()const override;
		Math::IVector3D<double>& getScale()const override;
		void setTexture(const std::shared_ptr<ITexture>& texture);
		std::shared_ptr<ITexture>& getTexture();

	protected:
	private:
		Path mFilePath;
		std::unique_ptr<Math::IPosition<double>> position;
		std::unique_ptr<Math::ISize<double>> size;
		std::unique_ptr<Math::IVector3D<double>> scale;
		std::shared_ptr<ITexture> texture;
	};
}
