#ifndef CONTROLSYSTEM_HPP
#define CONTROLSYSTEM_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Components/Flags.hpp"

#include "Utility/Vector.hpp"
#include "Systems\BaseSystem.h"

class ControlSystem
		: public BaseSystem
{
public:
    ControlSystem();
	void Update(float deltaTime);
private:
    std::vector<std::shared_ptr<Entity>> m_Ents;
    EntityManager m_EntMan;
};

#endif
