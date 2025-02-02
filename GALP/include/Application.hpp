#pragma once 
#include "windef.hpp"
#include "widget.hpp"
#include <unordered_map>
#include <functional> 

class Application
{
public:
	using ShortcutPair = std::pair<sf::Keyboard::Key, std::function<void()>>;
	using ShortcutMap = std::unordered_map<sf::Keyboard::Key, std::function<void()>>;
	Application(const char* title, const unsigned int width = WITDTH, const unsigned int height = HEIGHT);

	void setMainWidget(Widget* widget)
	{
		this->m_MainWidget = widget;
	}

	// Later fix it to a Map structure
	void checkShortcuts();

	void updateAction(const std::optional<sf::Event>& event);

	void show();
	
	void close();
	void addKeyShortcut(sf::Keyboard::Key key, std::function<void()> foo)
	{
		m_Shortcuts[key] = foo;
	}
	void setBackgroundColor(const sf::Color& color);

private:
	sf::RenderWindow m_Window;
	Widget* m_MainWidget;
	ShortcutMap m_Shortcuts;
	sf::Color m_BackgroundColor;
};
