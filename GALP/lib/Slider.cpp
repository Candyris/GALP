#include "Slider.hpp"
#include "Utility.hpp"
#include <cmath>

void Slider::draw(sf::RenderWindow& win)
{
	win.draw(m_Body);
	win.draw(m_Bar);
	win.draw(m_BarFill);
}

void Slider::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
	sf::Vector2f currentMouse= sf::Vector2f(sf::Mouse::getPosition(win));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (Utility::checkCollision(currentMouse, m_Bar.getSize()/2.0f, m_Bar.getPosition()))
		{
			m_BarFill.setSize(sf::Vector2f(currentMouse.x - (m_Bar.getPosition().x - (m_Bar.getSize().x / 2.0f)), m_Bar.getSize().y));
			m_Value = round(Utility::calPercentage<float>(m_BarFill.getSize().x, m_Bar.getSize().x));
			if (!m_OnClick) return;
			m_OnClick();
		}
	}
}

void Slider::setBarValue(const int val)
{
	m_Value = val;
	m_BarFill.setSize(sf::Vector2(Utility::calSection<float>((float)val, m_Bar.getSize().x), m_Bar.getSize().y));


}

		//Utility::printVec2<float>(this->getPosition(),"current Position");
		//this->setPosition(sf::Vector2f(sf::Mouse::getPosition(win)));