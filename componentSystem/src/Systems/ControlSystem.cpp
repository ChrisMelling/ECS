#include "Systems/ControlSystem.hpp"


ControlSystem::ControlSystem()
{
}

void ControlSystem::Update(float deltaTime)
{
	if(this->m_Ents.capacity() <= 0)
	{
		m_Ents = m_EntMan.getEntsByComp<Display>();
	}

    for (size_t i = 0; i < m_Ents.size(); ++i)
    {
		if (m_Ents[i]->hasComp<Flags>() && m_Ents[i]->comp<Flags>()->flags.test(constant::Flag::Player))
        {
			Display* disp = m_Ents[i]->comp<Display>().get();
			Movement* mov = m_Ents[i]->comp<Movement>().get();

			double rad = zge::degToRad(disp->sprite.getRotation());

			double sinRad = std::sin(rad);
			double cosRad = std::cos(rad);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                mov->velocity.x += sinRad * mov->acceleration * deltaTime;
                mov->velocity.y += -1 * cosRad * mov->acceleration * deltaTime;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                mov->velocity.x += -1 * sinRad * mov->acceleration * deltaTime;
                mov->velocity.y += cosRad * mov->acceleration * deltaTime;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                disp->sprite.rotate(-mov->acceleration * deltaTime);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                disp->sprite.rotate(mov->acceleration * deltaTime);
            }
        }
    }
}
