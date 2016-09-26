#include "Scene.h"
#include "SceneImpl.h"

namespace Moge
{
	Scene::Scene()
	{
		this->impl = new SceneImpl();
	}

	Scene::Scene( const Scene& scene )
	{
		this->impl = new SceneImpl( *scene.impl );
	}

	Scene::~Scene()
	{
		delete this->impl;
	}
}