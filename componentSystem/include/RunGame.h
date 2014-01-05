///
/// anax
/// An open source C++ entity system.
///
/// Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///

#ifndef __RUNGAME_HPP__
#define __RUNGAME_HPP__

#include <iostream>


#include "BaseGame.h"

#include <SFML/Graphics.hpp>

/// A typedef that is used to represent a second
typedef double Seconds;

int RunGame(sf::RenderWindow& window, BaseGame& game)
{
	// Records amount of time it took to process one game loop(frame)
	sf::Clock prevFrameTime;

	// Used to calculate the amount of time it took for each function in main to complete
	sf::Clock funcCompTime;

	// Stores the amount of seconds it took to process the previous game loop
	double deltaTime = 0;

	sf::Event event;
	while(game.isRunning())
	{
		deltaTime = prevFrameTime.restart().asMicroseconds() / 1000000.f;

        funcCompTime.restart();

		while(window.pollEvent(event))
		{
			game.handleEvents(event);
		}

		game.update(deltaTime); // update the game (with the constant delta time)
		
		game.render();
		window.display();
	}
	
	return 0;
}


#endif // __RUNGAME_HPP__
