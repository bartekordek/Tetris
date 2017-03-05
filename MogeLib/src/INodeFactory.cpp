#include "INodeFactory.h"
#include <boost/assert.hpp>

namespace Moge
{
	INodeFactory::INodeFactory( SurfaceFactory* surfaceFactory ): surfaceFactory( surfaceFactory )
	{
		BOOST_ASSERT_MSG( nullptr != this->surfaceFactory, "INITIALIZATION FAILED: surface factory is nullptr." );
	}

	SurfaceFactory* INodeFactory::getSurfacefactory()
	{
		return this->surfaceFactory;
	}

}