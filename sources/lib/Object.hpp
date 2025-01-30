#pragma once 
#include "widget.hpp"
#include "Application.hpp"
#include <functional>
class Object
{
public:
	template <typename T>
	static void connect(T& subWidget, std::function<void()> callback)
	{
		subWidget.attachEvent(callback);
	}
	template <typename T>
	static void connect(T& subWidget, std::function<void()> callback, int* sharedStorage)
	{
		subWidget.attachEvent(callback);
	}
	static void connectShortcut(Application& app, sf::Keyboard::Key key, std::function<void()> foo)
	{
		app.addKeyShortcut(key, foo);
	}
};


