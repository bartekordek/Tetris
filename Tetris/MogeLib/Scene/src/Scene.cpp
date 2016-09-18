#include "Scene.h"
#include "SceneImpl.h"

namespace MogeLib
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