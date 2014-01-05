
#ifndef __BASEGAME_HPP__
#define __BASEGAME_HPP__

#include <cassert>
#include "World.h"

class BaseGame
{
public:
	
	/// Default constructor
	BaseGame()
		: _isRunning(true)
	{
	}
	
	/// Updates the game
	/// \param deltaTime The change in time
	/// \note You must define your own update method
	virtual void update(float deltaTime)
	{

		std::cout << "Implement your own update() function!";
	}
	
	/// Renders the game
	/// \note You must define your own render method
	virtual void render()
	{

				std::cout << "Implement your own update() function!";
	}
	
	/// Handles SFML events
	/// \note You must define your own handleEvents method
	virtual void handleEvents(sf::Event events)
	{

				std::cout << "Implement your own update() function!";
	}
	
	/// \return true if this Game is running
	bool isRunning() const { return _isRunning; }
	
	/// Quits the game
	void quit() { _isRunning = false; }
	
private:
	
	bool _isRunning;
};

#endif // __BASEGAME_HPP__