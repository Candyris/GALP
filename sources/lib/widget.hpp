#pragma once 
#include "windef.hpp"
#include "resources.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <functional>
#include <optional>
#include <iostream>
#include <unordered_map>
#include <algorithm>

// Widget is a visual element in a user-interface
class Widget
{
public:
	virtual void draw(sf::RenderWindow& win) {}
	virtual void setPosition(const sf::Vector2f& position) {}
	virtual void setColor(const sf::Color& color) {}
	std::optional<sf::Vector2f> getPosition() const { return std::nullopt; }

	virtual void updateAction(const std::optional<sf::Event> &event, sf::RenderWindow& win) {}

};

// Must the wchar_t support later 
class Label : public Widget
{
public:

	Label(const char* text = "", const int pixel = 24,const bool centerOrgin = false, const sf::Color color = sf::Color::Yellow, uint8_t style = sf::Style::None)
		: m_Text(ResourceManger::get()->getFont()), m_TextStr(text)
	{
		m_Text.setString(text);
		m_Text.setCharacterSize(pixel);
		m_Text.setFillColor(color);
		m_Text.setStyle(style);

		if (centerOrgin)
		{
			sf::FloatRect size = m_Text.getLocalBounds();
			m_Text.setOrigin(size.getCenter());
		}

	}
	void setPosition(const sf::Vector2f& position);
	void setCharSize(const int pixel);
	void setStyle(uint8_t style);
	void updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
	{
		m_Component();
	}
	void setColor(const sf::Color& color);
	void attachEvent(const std::function<void()>& foo);

	void draw(sf::RenderWindow& win) override;
	

private:
	// Main Component 
	sf::Text m_Text;

	// Attributes
	std::string m_TextStr;
	std::function<void()> m_Component;
};


class Button : public Widget
{
public:
	Button(const char* string, sf::Vector2f size);
	void attachEvent(const std::function<void()>& foo);
	void updateAction(const std::optional<sf::Event> &event, sf::RenderWindow& win);
	void draw(sf::RenderWindow& win);
	void setPosition(const sf::Vector2f& position);
	std::optional<sf::Vector2f> getPosition() const ;
private:
	std::function<void()> m_OnClick;
	sf::Vector2f m_Size;
	std::string m_String;
	std::unique_ptr<Label> m_Label;
	sf::RectangleShape m_Body;
};

class Application
{
public:
	using ShortcutPair = std::pair<sf::Keyboard::Key, std::function<void()>>;
	using ShortcutMap = std::unordered_map<sf::Keyboard::Key, std::function<void()>>;
	Application(const char* title);
	
	void setMainWidget(Widget* widget)
	{
		this->m_MainWidget = widget;
	}

	// Later fix it to a Map structure
	void checkShortcuts()
	{
		for (const auto& [code, action] : m_Shortcuts)
		{
			if (sf::Keyboard::isKeyPressed(code))
				action();
		}
	}

	void updateAction(const std::optional<sf::Event>& event)
	{
		// Close the application event
		if (event->is < sf::Event::Closed>())
			m_Window.close();

		m_MainWidget->updateAction(event, m_Window);

		this->checkShortcuts();
	}

	void show()
	{
		while (m_Window.isOpen())
		{
			while (const std::optional<sf::Event> &event = m_Window.pollEvent())
			{
				this->updateAction(event);
			}
			m_Window.clear();
			if (m_MainWidget)
				m_MainWidget->draw(m_Window);
			m_Window.display();
		}
	}
	void close()
	{
		m_Window.close();
	}
	void addKeyShortcut(sf::Keyboard::Key key,std::function<void()> foo)
	{
		m_Shortcuts[key] = foo;
	}
private:
	sf::RenderWindow m_Window;
	Widget* m_MainWidget;
	ShortcutMap m_Shortcuts;
};

class Object
{
public:
	template <typename T>
	static void connect(T& subWidget, std::function<void()> callback)
	{
		subWidget.attachEvent(callback);
	}
	static void connectShortcut(Application& app, sf::Keyboard::Key key, std::function<void()> foo)
	{
		app.addKeyShortcut(key, foo);
	}
};