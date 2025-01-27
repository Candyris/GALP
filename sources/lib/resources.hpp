#pragma once
#include <SFML/Graphics/Font.hpp>


class ResourceManger
{
public:
	ResourceManger();

	static ResourceManger* get()
	{
		static ResourceManger r;
		return &r;
	}

	sf::Font& getFont()
	{
		return m_Font;
	}
private:
	sf::Font m_Font;
};