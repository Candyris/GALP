#include "Application.hpp"


Application::Application(const char* title ,const unsigned int width ,const unsigned int height)
{
	m_Window.create(sf::VideoMode({ width,height }), title, sf::Style::Close );
	m_MainWidget = nullptr;
	m_Window.setVerticalSyncEnabled(true);
	m_BackgroundColor = sf::Color::Black;
}

void Application::checkShortcuts()
{
	for (const auto& [code, action] : m_Shortcuts)
	{
		if (sf::Keyboard::isKeyPressed(code))
			action();
	}
}

void Application::updateAction(const std::optional<sf::Event>& event)
{
	// Close the application event
	if (event->is < sf::Event::Closed>())
		m_Window.close();
	if (m_MainWidget)
		m_MainWidget->updateAction(event, m_Window);

	this->checkShortcuts();
}

void Application::show()
{
	while (m_Window.isOpen())
	{
		while (const std::optional<sf::Event>& event = m_Window.pollEvent())
		{
			this->updateAction(event);
		}
		m_Window.clear(m_BackgroundColor);
		if (m_MainWidget)
			m_MainWidget->draw(m_Window);
		m_Window.display();
	}
}

void Application::close()
{
	m_Window.close();
}

void Application::setBackgroundColor(const sf::Color& color)
{
	m_BackgroundColor = color;
}

