#include "Label.hpp"


void Label::setPosition(const sf::Vector2f& position)
{
	m_Text.setPosition(position);
}

void Label::setCharSize(const int pixel)
{
	m_Text.setCharacterSize(pixel);
}

void Label::setStyle(uint8_t style)
{
	m_Text.setStyle(style);
}


void Label::setColor(const sf::Color& color)
{
	m_Text.setFillColor(color);
}

void Label::attachEvent(const std::function<void()>& foo)
{
	m_Component = foo;
}

void Label::draw(sf::RenderWindow& win)
{
	win.draw(m_Text);
}

sf::Vector2f Label::getSize() const
{
	// returning two thing size and position
	auto [size, position] = m_Text.getLocalBounds();
	//std::cout << "Size: x = " << size.x << ", y = " << size.y << std::endl;
	return sf::Vector2f(size.y * m_TextStr.size() * 1.5, size.y  );
}


