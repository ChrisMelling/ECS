///
/// Example1
/// Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#include "Game.h"

#include <iostream>



Game::Game(sf::RenderWindow& renderTarget)
	: _renderTarget(&renderTarget),
	RenderSys(renderTarget)
{
}

void Game::init()
{
	std::srand(std::time(0));

    RenderSys.debug = false;

	PlayerFact.createPlayer(sf::Vector2f( 400, 400));

	for(int	i = 0; i < 10000; i++)
	{
		PlayerFact.createEnemy(sf::Vector2f( i * 1, 10));
	}

	this->_world.addSystem(this->ControlSys);
	this->_world.addSystem(this->MoveSys);
}

void Game::update(float deltaTime)
{
	this->_world.Update(deltaTime);
	this->ControlSys.Update(deltaTime);
	this->MoveSys.Update(deltaTime);

	std::cout << std::floor(1.f / deltaTime) << " FPS\n\n";
}

void Game::render()
{
	_renderTarget->clear(sf::Color(60,60,60,60));
	RenderSys.run();
}

void Game::handleEvents(sf::Event event)
{
	switch(event.type)
	{
		case sf::Event::Closed:
			quit();
			break;
		case sf::Event::KeyPressed:
			switch(event.key.code)
			{
				case sf::Keyboard::Key::Escape:
					quit();
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void Game::loadResources()
{

}