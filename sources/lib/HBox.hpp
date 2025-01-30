#include "widget.hpp"
#include <vector>

// Horizontal layout box
class HBoxLayout : public Widget
{
public:
	// later add caption here
	HBoxLayout(const sf::Vector2f& margin = { 10.0f,10.0f }, const sf::Vector2f& spacing = { 10.0f,10.0f })
		: m_Margin(margin), m_Space(spacing) {}

	// Adding the box model margin of the div
	// void setMargin(int pixel);

	// Item element space between
	// void setSpacing(int pixel); 


	// Append Widget to the container
	template<typename T>
	void addWidget(T* widget)
	{
		m_WidgetCollection.push_back(widget);
		this->setLayout();
	}

	// Organize the widget 
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win) override;

	void draw(sf::RenderWindow& win) override;

private:
	void setLayout();
	//void setPosition(const sf::Vector2f& position) override;

private:
	std::vector<Widget*> m_WidgetCollection;
	sf::Vector2f m_Margin;
	sf::Vector2f m_Space;
};
