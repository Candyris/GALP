#include "LineEdit.hpp"
#include "Utility.hpp"
#include <string>

LineEdit::LineEdit(const sf::Vector2<float>& size, const int maxSize)
	:m_MaxSize(0)
{
	this->IsOriginPosition = false;


	m_Body.setSize(size);
	m_Body.setFillColor(sf::Color::White);
	m_Body.setOutlineColor(sf::Color(150,150,150));
	m_Body.setOutlineThickness(3.0f);

	m_InputField = std::make_unique<Label>("Nothing");
	m_InputField->setColor(sf::Color::Black);
	m_InputField->setCharSize(Utility::calSection<float>(65,static_cast<int>(size.y)));
	if (maxSize == -1)
		m_MaxSize = static_cast<int>(m_Body.getSize().x / Utility::calSection<float>(37.3f, size.y)); // why is this half i don't know
}

void LineEdit::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
	static bool state = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (Utility::checkCollision<float>(sf::Vector2f(sf::Mouse::getPosition(win)), m_Body.getSize(), m_Body.getPosition()))
		{
			state = true;
		}
		else
		{
			state = false;
		}
	}
	if (state)
	{
		if (const std::optional<char> character = Utility::getKeyPressed(event))
		{
			if (m_MaxSize > m_String.size())
			m_String.push_back(*character);
			m_InputField->setString(m_String);
		}
		if (event->is<sf::Event::KeyPressed>())
		{
			if (sf::Keyboard::Scancode::Backspace == event->getIf<sf::Event::KeyPressed>()->scancode)
			{
				if (!m_String.empty()) m_String.pop_back();
				m_InputField->setString(m_String);
			}
		}
	}

}

void LineEdit::draw(sf::RenderWindow& win)
{
	win.draw(m_Body);
	m_InputField->draw(win);
}

void LineEdit::setPosition(const sf::Vector2f& position)
{
	m_Body.setPosition(position);
	m_InputField->setPosition(position);
	//m_PreField->setPosition(position);
}
