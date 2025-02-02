#include "Utility.hpp"

std::optional<char> Utility::getKeyReleased(const std::optional<sf::Event>& event)
{
	if (const sf::Event::KeyReleased* key = event->getIf<sf::Event::KeyReleased>())
	{
		int code = static_cast<int>(key->code);
		if (0 <= code && code <= 25)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
			{
				return static_cast<char>(code + 65);
			}
			else
			{
				return static_cast<char>(code + 97);
			}
		}
		else if (code == int(sf::Keyboard::Key::Space))
		{
			return ' ';
		}
	}
	return std::nullopt;
}

std::optional<char> Utility::getKeyPressed(const std::optional<sf::Event>& event)
{
	if (const sf::Event::KeyPressed* key = event->getIf<sf::Event::KeyPressed>())
	{
		int code = static_cast<int>(key->code);
		if (0 <= code && code <= 25)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) // No CapsLock || key->scancode ==  sf::Keyboard::Scancode::CapsLock
			{
				return static_cast<char>(code + 65);
			}
			else
			{
				return static_cast<char>(code + 97);
			}
		}
		else if (code == int(sf::Keyboard::Key::Space))
		{
			return ' ';
		}
	}
	return std::nullopt;
}
