#include "Systems/MovementSystem.hpp"

MovementSystem::MovementSystem()
{
}

void MovementSystem::Update(float deltaTime)
{
  	if(this->m_Ents.capacity() <= 0)
	{
		m_Ents = m_EntMan.getEntsByComp<Display>();
	}

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {

		Display* display = m_Ents[i]->comp<Display>().get();
        Movement* mov = m_Ents[i]->comp<Movement>().get();

		display->sprite.move(mov->velocity.x * deltaTime, mov->velocity.y * deltaTime);
    }
}
