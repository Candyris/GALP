#include "Slider.hpp"
#include "Utlity.hpp"
#include <cmath>

void Slider::draw(sf::RenderWindow& win)
{
	win.draw(m_Body);
	win.draw(m_Bar);
	win.draw(m_BarFill);
}

void Slider::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
	//m_OnClick();
	sf::Vector2f currentMouse= sf::Vector2f(sf::Mouse::getPosition(win));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (Utlity::checkCollision(currentMouse, m_Bar.getSize()/2.0f, m_Bar.getPosition()))
		{
			m_BarFill.setSize(sf::Vector2f(currentMouse.x - (m_Bar.getPosition().x - (m_Bar.getSize().x / 2.0f)), m_Bar.getSize().y));
			int percentage = round(Utlity::calPercentage<float>(m_BarFill.getSize().x, m_Bar.getSize().x));
			std::cout << "Percentage: " << percentage<<"%\n" ;
		}
	}
}

		//Utlity::printVec2<float>(this->getPosition(),"current Position");
		//this->setPosition(sf::Vector2f(sf::Mouse::getPosition(win)));