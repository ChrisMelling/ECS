
#include <World.h>

#include <cassert>



World::World()
{
}


void World::Update(float deltaTime)
{
	//for (auto it = _systems.begin(); it != _systems.end(); ++it)
	//{
	//	it->second->Update(deltaTime);
	//}
}


	
void World::addSystem(BaseSystem& system)
{
	assert(!system._world && "System is already contained within a World");
		
	_systems[0] = &system;
		
	system._world = this;
	system.initialize();
}	
	
