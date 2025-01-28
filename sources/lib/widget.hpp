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
#include <crtdbg.h>

#include <Windows.h>

// Widget is a visual element in a user-interface
class Widget
{
public:
	virtual void draw(sf::RenderWindow& win) {}
	virtual void setPosition(const sf::Vector2f& position) {}
	virtual void updateAction(const std::optional<sf::Event> &event, sf::RenderWindow& win) {}

	virtual void setColor(const sf::Color& color) {}
	virtual sf::Vector2f getPosition() const { return sf::Vector2f(100.0f, 100.0f); }
	virtual sf::Vector2f getSize() const { return sf::Vector2f(100.0f, 100.0f); }
	bool IsOriginPosition = false;

};

// Must the wchar_t support later 
class Label : public Widget
{
public:

	Label(const char* text = "", const int pixel = 24,const bool centerOrigin = false, const sf::Color color = sf::Color::Yellow, uint8_t style = sf::Style::None)
		: m_Text(ResourceManger::get()->getFont()), m_TextStr(text)
	{
		m_Text.setString(text);
		m_Text.setCharacterSize(pixel);
		m_Text.setFillColor(color);
		m_Text.setStyle(style);

		if (centerOrigin)
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
		//m_Component();
	}
	void setColor(const sf::Color& color);
	void attachEvent(const std::function<void()>& foo);

	void draw(sf::RenderWindow& win) override;
	sf::Vector2f getPosition() const override { return m_Text.getPosition(); }
	sf::Vector2f getSize() const override 
	{
		// returning two thing size and position
		auto[size,position]  = m_Text.getLocalBounds();
		//std::cout << "Size: x = " << size.x << ", y = " << size.y << std::endl;
		return sf::Vector2f( size.y * m_TextStr.size()  , size.x);
	}
    

private:
	// Main Component 
	sf::Text m_Text;

	// Attributes
	std::string m_TextStr;
	std::optional<std::function<void()>> m_Component;
};


class Button : public Widget
{
public:
	Button(const char* string, sf::Vector2f size);
	void attachEvent(const std::function<void()>& foo);
	void updateAction(const std::optional<sf::Event> &event, sf::RenderWindow& win);
	void draw(sf::RenderWindow& win);
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() const { return m_Body.getPosition(); }
	sf::Vector2f getSize() const { return m_Body.getSize(); }

private:
	std::function<void()> m_OnClick;
	sf::Vector2f m_Size;
	std::string m_String;
	std::unique_ptr<Label> m_Label;
	sf::RectangleShape m_Body;
};

// Horizontal layout box
class HBox : public Widget
{
public:
	// later add caption here
	HBox(const sf::Vector2f& margin = { 10.0f,10.0f }, const sf::Vector2f& spacing = { 10.0f,10.0f })
		: m_Margin(margin), m_Space(spacing) {}

	// Adding the box model margin of the div
	//void setMargin(int pixel);

	// Item element space between
	//void setSpacing(int pixel); 


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

class Slider
{

};

class SpinBox
{

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
		if (m_MainWidget)
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


