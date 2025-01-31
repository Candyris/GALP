#pragma once
#include "widget.hpp"
#include "Label.hpp"
#include <memory>
#include <string>

class LineEdit :public Widget
{
public:
	LineEdit(const sf::Vector2<float>& size = { 400.0f, 100.0f }, const int maxSize = -1);
	void setString(const std::string& str) { m_String = str; m_InputField->setString(str); }
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win) override;
	void draw(sf::RenderWindow& win) override;
	sf::Vector2f getSize() const override { return m_Body.getSize(); }
	void setPosition(const sf::Vector2f& position) override ;

	/*
	void setColor(const sf::Color& color) {}
	sf::Vector2f getPosition() const { return sf::Vector2f(100.0f, 100.0f); }
	bool IsOriginPosition;
	*/

private:
	std::string m_String;
	int m_MaxSize;
	sf::RectangleShape m_Body;
	std::unique_ptr<Label> m_InputField;
	std::unique_ptr<Label> m_PreField;
};