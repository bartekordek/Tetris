#include "SceneImpl.h"

namespace Moge
{
	SceneImpl::SceneImpl()
	{
	}

	SceneImpl::SceneImpl( const SceneImpl& sceneImpl ): nodes( sceneImpl.nodes )
	{
	}

	SceneImpl::~SceneImpl()
	{
	}
}