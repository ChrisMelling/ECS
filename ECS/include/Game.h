#ifndef __GAME_HPP__
#define __GAME_HPP__

//STD
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "Constants.hpp"

#include "ResourceManager.hpp"

#include "EntityManager.hpp"
#include "Entity.hpp"

#include "Systems/RenderSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/ControlSystem.hpp"
#include "Systems/CollisionSystem.hpp"

#include "Components/Component.hpp"
#include "Components/Health.hpp"
#include "Components/Movement.hpp"
#include "Components/Display.hpp"
#include "Components/Flags.hpp"
#include "Components\Animated.h"

#include "Factories/PlayerFactory.hpp"

#include <map>

#include <SFML/Graphics.hpp>

#include "BaseGame.h"
#include "World.h"

class Game
	: public BaseGame
{
public:
	
	/// Constructs the Game with a sf::RenderTarget
	/// \param renderTarget The sf::RenderTarget you wish to set the game up with
	Game(sf::RenderWindow&);
	
	/// Initializes the game
	void init();
	
	/// Updates the game
	/// \param deltaTime The change in time
	void update(float deltaTime);
	
	/// Renders the game
	void render();
	
	/// Handles events
	/// \param event The event that will be handled
	void handleEvents(sf::Event event);
	
	/// Loads game resources
	void loadResources();
	
private:
	
	/// The target the game will render to
	sf::RenderWindow* _renderTarget;
	
	/// A texture cache
	std::map<std::string, sf::Texture> _textureCache;
	
	/// An anax entity world
	World _world;

	EntityManager EntMan;
	ResourceManager ResMan;

	RenderSystem RenderSys;
	CameraSystem CameraSys;
	MovementSystem MoveSys;
	ControlSystem ControlSys;
	CollisionSystem ColSys;

	PlayerFactory PlayerFact;
	
};



#endif // __GAME_HPP__