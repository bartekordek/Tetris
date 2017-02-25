#include "ITextureFactory.h"
#include <boost/assert.hpp>

namespace Moge
{
	ITextureFactory::ITextureFactory( Engine* engine ): engine( engine )
	{
		BOOST_ASSERT( nullptr != engine );
	}

	ITextureFactory::~ITextureFactory()
	{
	}

	Engine* ITextureFactory::getEngine()
	{
		return this->engine;
	}


}