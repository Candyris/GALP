#pragma once
#include "widget.hpp"
#include "Utility.hpp"
#include <functional>

// later in the connect with pointer do single storing range

enum DISPLAY { Vertical, Horizontal };

class Slider : public Widget
{
public:
	Slider(Utility::Range<int> range = Utility::Range<int>(0,100), DISPLAY style = DISPLAY::Horizontal)
		:m_Style(style), m_Value(range)
	{
		this->IsOriginPosition = true;

		#pragma region settting_Body
		m_Body.setSize(sf::Vector2f(200.0f,30.0f));
		m_Body.setFillColor(sf::Color(70, 70, 70,10));
		m_Body.setOutlineThickness(3.0f);
		m_Body.setOutlineColor(sf::Color::White);
		m_Body.setOrigin(m_Body.getLocalBounds().getCenter());
		#pragma endregion 
		
		#pragma region settting_Bar
			m_Bar.setSize(sf::Vector2(Utility::calSection<float>(80.0f,m_Body.getSize().x), Utility::calSection<float>(50.0f, m_Body.getSize().y)));
			m_Bar.setFillColor(sf::Color(1, 22, 70));
			m_Bar.setOrigin(m_Bar.getSize()/2.0f);
		#pragma endregion 
		
		#pragma region settting_BarFill
			m_BarFill.setSize(sf::Vector2(Utility::calSection<float>(20.0f,m_Bar.getSize().x),  m_Bar.getSize().y));
			m_BarFill.setFillColor(sf::Color(0, 0, 255));
			m_BarFill.setOrigin(m_Bar.getSize()/2.0f);
		#pragma endregion 
		this->setPosition(m_Body.getSize() / 2.0f);
	}
	void draw(sf::RenderWindow& win) override;
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win) override;
	void setBarValue(const int val);
	int getBarValue() const { return m_Value.getValue(); };
	void setPosition(const sf::Vector2f& position) 
	{
		//Utility::printVec2<float>(m_Body.getPosition(),"Changed Slider");
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
	Utility::Range<int> m_Value;
};
