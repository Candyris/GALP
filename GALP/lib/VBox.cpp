#include "VBox.hpp"

void VBoxLayout::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
    for (Widget* ptr : m_WidgetCollection)
    {
        ptr->updateAction(event, win);
    }
}

void VBoxLayout::draw(sf::RenderWindow& win)
{
    for (Widget* ptr : m_WidgetCollection)
    {
        ptr->draw(win);
    }
}

void VBoxLayout::setLayout()
{
    sf::Vector2f space = {};
    for (Widget* ptr : m_WidgetCollection)
    {
        //std::cout <<"Is ORgin" << ptr->IsOriginPosition << std::endl;

        sf::Vector2f temp = {};
        if (ptr->IsOriginPosition)
        {
            temp = ptr->getSize()/2.0f;
        }

            space += sf::Vector2f(0.0f, ptr->getSize().y) + sf::Vector2f(0.0f, m_Space.y);
            ptr->setPosition(m_Margin + space + temp);
    }
}

