#pragma once 
#include "windef.hpp"
#include "resources.hpp"
#include <SFML/Graphics.hpp>

// Widget is a visual element in a user-interface
class Widget
{
public:
	virtual void draw(sf::RenderWindow& win) {}
	virtual void setPosition(const sf::Vector2f& position) {}
	virtual void updateAction(const std::optional<sf::Event> &event, sf::RenderWindow& win) {}

	virtual void setColor(const sf::Color& color) {}
	virtual sf::Vector2f getPosition() const { return sf::Vector2f(100.0f, 100.0f); }
	virtual sf::Vector2f getSize() const { return sf::Vector2f(100.0f, 100.0f); }
	bool IsOriginPosition = true;

};
