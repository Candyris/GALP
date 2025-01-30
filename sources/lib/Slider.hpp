#pragma once
#include "widget.hpp"
#include "Utlity.hpp"
#include <functional>

// later in the connect with pointer do single storing range

enum DISPLAY { Vertical, Horizontal };

class Slider : public Widget
{
public:
	Slider(Utlity::Range<int> range = Utlity::Range<int>(0,100), DISPLAY style = DISPLAY::Horizontal)
		:m_Style(style), m_Value(range)
	{
		this->IsOriginPosition = true;

		#pragma region settting_Body
		m_Body.setSize(sf::Vector2f(300.0f,100.0f));
		m_Body.setFillColor(sf::Color(70, 70, 70));
		m_Body.setOutlineThickness(3.0f);
		m_Body.setOutlineColor(sf::Color::White);
		m_Body.setOrigin(m_Body.getLocalBounds().getCenter());
		#pragma endregion 
		
		#pragma region settting_Bar
			m_Bar.setSize(sf::Vector2(Utlity::calSection<float>(75.0f,m_Body.getSize().x), Utlity::calSection<float>(25.0f, m_Body.getSize().y)));
			m_Bar.setFillColor(sf::Color(1, 22, 70));
			m_Bar.setOrigin(m_Bar.getSize()/2.0f);
		#pragma endregion 
		
		#pragma region settting_BarFill
			m_BarFill.setSize(sf::Vector2(Utlity::calSection<float>(10.0f,m_Bar.getSize().x),  m_Bar.getSize().y));
			m_BarFill.setFillColor(sf::Color(0, 0, 255));
			m_BarFill.setOrigin(m_Bar.getSize()/2.0f);
		#pragma endregion 
		this->setPosition(m_Body.getSize() / 2.0f);
	}
	void draw(sf::RenderWindow& win) override;
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win) override;

	void setPosition(const sf::Vector2f& position) 
	{
		//Utlity::printVec2<float>(m_Body.getPosition(),"Changed Slider");
		m_Body.setPosition(position);
		m_Bar.setPosition(position);
		m_BarFill.setPosition(position);
	}
	void attachEvent(const std::function<void()>& foo)
	{
		m_OnClick = foo;
	}

	void setColor(const sf::Color& color) {}
	sf::Vector2f getPosition() const override { return m_Body.getPosition(); }
	sf::Vector2f getSize() const override { return m_Body.getSize(); }
	bool IsOriginPosition = false;

private:
	std::function<void()> m_OnClick;

	sf::RectangleShape m_Body;
	sf::RectangleShape m_Bar; // later add two circle at the end
	sf::RectangleShape m_BarFill; // later add two circle at the end
	enum DISPLAY m_Style;
	Utlity::Range<int> m_Value;
};
