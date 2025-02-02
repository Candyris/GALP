#pragma once
#include "widget.hpp"
#include "LineEdit.hpp"
#include <memory>
#include "Utility.hpp"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <functional>

class ArrowButton
{
public:
    ArrowButton(Utility::Range<int>* range = nullptr,const sf::Vector2f& position = {}, const sf::Vector2f& size = { 50.0f, 50.0f }, bool _rotate = false)
        : m_TriangleSize(size / 2.0f), m_IsRotate(_rotate ^ 1), m_IsClicked(false)
    {
        m_Body.setSize(size);
        m_Body.setFillColor(sf::Color(150, 150, 150));
        m_Body.setOutlineColor(sf::Color::Green);
        m_Body.setPosition(position);

        m_Triangle.setPointCount(3);

        this->rotate(m_IsRotate ^ 1);
        m_Triangle.setFillColor(sf::Color::Black);
    }
    void rotate(bool r)
    {
        if (m_IsRotate != r)
        {
            m_IsRotate = r;
            if (r == false)
            {
                m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, m_TriangleSize.y + (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, m_TriangleSize.y + (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y / 2));
            }
            else
            {
                m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y + m_TriangleSize.y / 2));
                m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, (m_TriangleSize.y / 2)));
            }
        }
    }
    void attachEvent(const std::function<void()>& foo)
    {
        m_OnClick =  foo;
    }
    void setSize(const sf::Vector2f& size)
    {
        m_Body.setSize(size);
        m_TriangleSize = size / 2.0f;
        if (m_IsRotate == false)
        {
            m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, m_TriangleSize.y + (m_TriangleSize.y / 2)));
            m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, m_TriangleSize.y + (m_TriangleSize.y / 2)));
            m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y / 2));
        }
        else
        {
            m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y + m_TriangleSize.y / 2));
            m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, (m_TriangleSize.y / 2)));
            m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, (m_TriangleSize.y / 2)));
        }
    }
    void setPosition(const sf::Vector2f& position)
    {
        m_Body.setPosition(position);
        {
            if (m_IsRotate == false)
            {
                m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, m_TriangleSize.y + (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, m_TriangleSize.y + (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y / 2));
            }
            else
            {
                m_Triangle.setPoint(2, m_Body.getPosition() + sf::Vector2f((m_TriangleSize.x / 2) + (m_TriangleSize.x / 2), m_TriangleSize.y + m_TriangleSize.y / 2));
                m_Triangle.setPoint(0, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2 + m_TriangleSize.x, (m_TriangleSize.y / 2)));
                m_Triangle.setPoint(1, m_Body.getPosition() + sf::Vector2f(m_TriangleSize.x / 2, (m_TriangleSize.y / 2)));
            }
        }
    }
    void draw(sf::RenderWindow& win)
    {
        win.draw(m_Body);
        win.draw(m_Triangle);
    }
    void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (!m_OnClick) return;
            if (Utility::checkCollision<float>(static_cast<sf::Vector2f>(sf::Mouse::getPosition(win)), {m_Body.getSize().x,m_Body.getSize().y/2.0f}, m_Body.getPosition()))
            {
                if (!m_IsClicked)
                {
                    //Utility::printVec2<float>(m_Body.getSize() / 2.0f);
                    m_IsClicked = true;
                    m_Body.setFillColor(sf::Color(70, 70, 70));
                    m_OnClick();
                }
            }
        }
        else if (m_IsClicked)
        {
            m_IsClicked = false;
            m_Body.setFillColor(sf::Color(150,150,150));
        }
    }

private:
    bool m_IsRotate;
    bool m_IsClicked;
    std::function<void()> m_OnClick;
    sf::Vector2f m_TriangleSize;
    sf::RectangleShape m_Body;
    sf::ConvexShape m_Triangle;
};

class SpinBox : public Widget
{
public:
    SpinBox(Utility::Range<int> range = Utility::Range<int>(0, 100), int interval = 5, const sf::Vector2f& size = {100.0f,32.0f});
	void draw(sf::RenderWindow& win) override;
	void setPosition(const sf::Vector2f& position) override;
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win) override;

	// virtual void setColor(const sf::Color& color) {}
	 sf::Vector2f getPosition() const { return m_Body.getPosition(); }
	 sf::Vector2f getSize() const { return m_Body.getSize(); }
private:
	Utility::Range<int> m_Range;
	sf::RectangleShape m_Body;
	std::unique_ptr<LineEdit> m_TextInput;
    ArrowButton m_UpBtn;
    ArrowButton m_DownBtn;
	int m_Interval;
};
