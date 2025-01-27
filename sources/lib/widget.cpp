#include "widget.hpp"
#include <SFML/Graphics.hpp>
#include "resources.hpp"

Application::Application(const char* title)
{
	m_Window.create(sf::VideoMode({WITDTH,HEIGHT}), title, sf::Style::Close);
	m_MainWidget = nullptr;
	m_Window.setVerticalSyncEnabled(true);
}

// ----------------------- LABELS -----------------------------------//

void Label::setPosition(const sf::Vector2f& position)
{
	m_Text.setPosition(position);   
}

void Label::setCharSize(const int pixel)
{
	m_CharPixelSize = pixel;
}


void Label::draw(sf::RenderWindow& win)
{
	win.draw(m_Text);
}


// ---------------------------- END ---------------------------------//

// ----------------------- Button -----------------------------------//
Button::Button(const char* string, sf::Vector2f size)
	: m_Size(size), m_String(string)
{
	m_Body.setSize(size);
	
}
