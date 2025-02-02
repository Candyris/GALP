#pragma once
#include "widget.hpp"
#include "Label.hpp"
#include <memory>
#include <functional>

class Button : public Widget
{
public:
	Button(const char* string, const sf::Vector2f& size = {100.0f, 32.0f});
	void attachEvent(const std::function<void()>& foo);
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win);
	void draw(sf::RenderWindow& win);
	void setPosition(const sf::Vector2f& position);
	void setColor(const sf::Color& color) { m_Label->setColor(color); }
	sf::Vector2f getPosition() const { return m_Body.getPosition(); }
	sf::Vector2f getSize() const { return m_Body.getSize(); }

private:
	std::function<void()> m_OnClick;
	sf::Vector2f m_Size;
	std::string m_String;
	std::unique_ptr<Label> m_Label;
	sf::RectangleShape m_Body;
};
