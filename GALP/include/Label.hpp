#pragma once
#include "widget.hpp"
#include <string>
#include <functional>

// Must the wchar_t support later 
class Label : public Widget
{
public:

	Label(const char* text = "", const int pixel = 24, const bool centerOrigin = false, const sf::Color color = sf::Color::Yellow, uint8_t style = sf::Style::None)
		: m_Text(ResourceManger::get()->getFont()), m_TextStr(text)
	{
		this->IsOriginPosition = false;
		m_Text.setString(text);
		m_Text.setCharacterSize(pixel);
		m_Text.setFillColor(color);
		m_Text.setStyle(style);

		if (centerOrigin)
		{
			sf::FloatRect size = m_Text.getLocalBounds();
			m_Text.setOrigin(size.getCenter());
		}

	}

	void setString(const std::string& str) { m_TextStr = str; m_Text.setString(str); };
	void setPosition(const sf::Vector2f& position);
	void setCharSize(const int pixel);
	void setStyle(uint8_t style);
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
	{
		if (!m_Component) return;
		
			m_Component();
		
	}
	void setColor(const sf::Color& color);
	void attachEvent(const std::function<void()>& foo);

	void draw(sf::RenderWindow& win) override;
	sf::Vector2f getPosition() const override { return m_Text.getPosition(); }
	sf::Vector2f getSize() const override;


private:
	// Main Component 
	sf::Text m_Text;

	// Attributes
	std::string m_TextStr;
	std::function<void()> m_Component;
};

