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

#ifndef __ANAX_SYSTEM_HPP__
#define __ANAX_SYSTEM_HPP__

#include <cstddef>
#include <vector>

class World;
	
class BaseSystem
{
public:
		
	/// Default constructor
	BaseSystem();
		
	/// Destructor
	virtual ~BaseSystem() = 0;

	virtual void Update(float deltaTime);

	/// \return The World attached to the System
	World& getWorld() const;

private:
		
	/// Initializes the system, when a world is succesfully
	/// attached to it.
	virtual void initialize() {}
	
		
	/// Used to set the attached World
	/// \param world The World to attach to
	/// \note This is called by the attached World object
	void setWorld(World& world);
		
	/// The World attached to the system
	World* _world;
				
	friend class World;
};


#endif // __ANAX_SYSTEM_HPP__