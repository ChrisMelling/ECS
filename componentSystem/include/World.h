
#ifndef __ANAX_WORLD_HPP__
#define __ANAX_WORLD_HPP__

#include <vector>
#include <unordered_map>
#include <type_traits>
#include <iostream>

#include "Systems\BaseSystem.h"


class World
{
public:
		
	/// Default Constructor
	World();

	void Update(float deltaTime);

	void addSystem(BaseSystem& system);

private:
		
	typedef std::unordered_map<int, BaseSystem*> SystemArray;
		
		
	/// Systems attached with the world.
	SystemArray _systems;
		
};


#endif // __ANAX_WORLD_HPP__
