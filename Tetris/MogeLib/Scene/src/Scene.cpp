#include "Scene.h"
#include "SceneImpl.h"

namespace Moge
{
	Scene::Scene()
	{
		this->impl = new SceneImpl();
	}

	Scene::~Scene()
	{
		delete this->impl;
	}
}