#pragma once 
#include "windef.hpp"
#include "resources.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>


//#include <iostream>

// Widget is a visual element in a user-interface
class Widget
{
public:
	virtual void draw(sf::RenderWindow& win) {}
	virtual void setPosition(const sf::Vector2f& position) {}
};

// Must the wchar_t support later 
class Label : public Widget
{
public:

	Label(const char* text = "", const int pixel = 24,const bool centerOrgin = false, const sf::Color color = sf::Color::Yellow, uint8_t style = sf::Style::None)
		: m_Text(ResourceManger::get()->getFont()), m_TextStr(text), m_CharPixelSize(pixel), m_Color(color), m_Style(style), m_Modifed(false)
	{
		m_Text.setString(text);
		m_Text.setCharacterSize(pixel);
		m_Text.setFillColor(color);
		m_Text.setStyle(style);

		if (centerOrgin)
		{
			sf::FloatRect size = m_Text.getLocalBounds();
			m_Text.setOrigin(size.getCenter());
		}

	}

	void setPosition(const sf::Vector2f& position);
	void setCharSize(const int pixel);

	void draw(sf::RenderWindow& win) override;
	

private:
	// Main Component 
	sf::Text m_Text;

	// Attributes
	bool m_Modifed;
	uint32_t m_CharPixelSize;
	std::string m_TextStr;
	sf::Color m_Color;
	uint8_t m_Style;

};

class Button
{
public:
	Button(const char* string, sf::Vector2f size);
private:
	sf::Vector2f m_Size;
	std::string m_String;
	std::unique_ptr<Label*> label;
	sf::RectangleShape m_Body;
};


class Application
{
public:
	Application(const char* title);
	
	void setMainWidget(Widget* widget)
	{
		this->m_MainWidget = widget;
	}

	void show()
	{
		while (m_Window.isOpen())
		{
			while (const std::optional<sf::Event> event = m_Window.pollEvent())
			{
				if (event->is < sf::Event::Closed>())
					m_Window.close();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					m_MainWidget->setPosition(sf::Vector2f(sf::Mouse::getPosition(m_Window)));
			}
			m_Window.clear();
			
			if (m_MainWidget)
				m_MainWidget->draw(m_Window);
			m_Window.display();
		}
	}

private:
	sf::RenderWindow m_Window;
	Widget* m_MainWidget;
};