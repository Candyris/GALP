#include "Button.hpp"
#include "Utlity.hpp"

Button::Button(const char* string, sf::Vector2f size)
	: m_Size(size), m_String(string)
{
	m_Label = std::make_unique<Label>(Label(string, 24, true));
	m_Label->setColor(sf::Color(81, 255, 13));

	m_Body.setSize(m_Size);
	m_Body.setFillColor(sf::Color(70, 70, 70));
	m_Body.setOutlineThickness(3.0f);
	m_Body.setOutlineColor(sf::Color::White);

	m_Body.setOrigin(m_Body.getLocalBounds().getCenter());
	IsOriginPosition = true;

	this->setPosition(m_Body.getSize() / 2.0f);
}

void Button::attachEvent(const std::function<void()>& foo)
{
	m_OnClick = foo;
}

void Button::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
	if (!m_OnClick) return;
	static bool isClicked = false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		/*sf::Vector2i current = sf::Mouse::getPosition(win);
		sf::Vector2i BoxSize = sf::Vector2i(m_Body.getSize())/2;
		sf::Vector2i Position = sf::Vector2i(m_Body.getPosition());
		*/
		if (Utlity::checkCollision<int>(sf::Mouse::getPosition(win), sf::Vector2i(m_Body.getSize()) / 2, sf::Vector2i(m_Body.getPosition())))
		{ 
			if (!isClicked)
			{
				isClicked = true;
				m_Body.setFillColor(sf::Color(70, 70, 70));
				m_Label->setStyle(sf::Text::Style::Underlined);

				m_OnClick();
			}
		}
	}
	else if (isClicked)
	{
		isClicked = false;
		m_Label->setStyle(sf::Text::Style::Regular);
		m_Body.setFillColor(sf::Color(100, 100, 100));
	}
}

void Button::draw(sf::RenderWindow& win)
{
	win.draw(m_Body);
	m_Label->draw(win);
}

void Button::setPosition(const sf::Vector2f& position)
{
	m_Body.setPosition(position);
	m_Label->setPosition(position);
}
