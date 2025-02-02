#include "HBox.hpp"
#include "Utility.hpp"

void HBoxLayout::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
    for (Widget* ptr : m_WidgetCollection)
    {
        ptr->updateAction(event, win);
    }
}

void HBoxLayout::draw(sf::RenderWindow& win)
{
    for (Widget* ptr : m_WidgetCollection)
    {
        ptr->draw(win);
    }
}

void HBoxLayout::setLayout()
{
    sf::Vector2f space = m_Margin;
    for (Widget* ptr : m_WidgetCollection)
    {
        if (m_HBoxSize.y < ptr->getSize().y)
        {
            m_HBoxSize.y = ptr->getSize().y;
        }
        //std::cout <<"Is ORgin" << ptr->IsOriginPosition << std::endl;
        if (ptr->IsOriginPosition)
        {
            ptr->setPosition(space + (ptr->getSize() / 2.0f));
            space += sf::Vector2f(m_Space.x, 0.0f) + sf::Vector2f(ptr->getSize().x, 0.0f);
        }
        else
        {
            ptr->setPosition(space);
            space += sf::Vector2f(m_Space.x, 0.0f) + sf::Vector2f(ptr->getSize().x, 0.0f);
        }
    }
}
