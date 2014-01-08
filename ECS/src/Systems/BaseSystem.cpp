
#include "Systems\BaseSystem.h"

#include <algorithm>


BaseSystem::BaseSystem()
	: _world(nullptr)
{
}
	
	
BaseSystem::~BaseSystem()
{
}

void BaseSystem::Update(float deltaTime)
{

}

	
World& BaseSystem::getWorld() const
{
	return *_world;
}
	
void BaseSystem::setWorld(World &world)
{
	_world = &world;
	initialize();
}
