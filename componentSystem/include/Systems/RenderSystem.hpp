#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

//STD
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <cmath>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Components/Component.hpp"
#include "Components/Display.hpp"
#include "Components/Movement.hpp"
#include "Components/Flags.hpp"

class RenderSystem
{
public:

	RenderSystem();

	RenderSystem(sf::RenderWindow& renderTarget);

	void setRenderTarget(sf::RenderWindow& renderTarget);
	
	sf::RenderWindow& getRenderTarget() const;
    void run();
    bool debug;

private:
    std::vector<std::shared_ptr<Entity>> m_Ents;
    EntityManager m_EntMan;
    ResourceManager m_ResMan;

	sf::RenderWindow* renderTarget;
};

#endif
