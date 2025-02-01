#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <iostream>
#include <optional>
#include <SFML/Window/Event.hpp>

namespace Utility {

	template<typename T>
	void printVec2(sf::Vector2<T> vec, const char* name)
	{
		std::cout << name << ": x-> " << vec.x << ", y-> " << vec.y << std::endl;
	}
	//void printVec3f(sf::Vector2f vec, const char* name);

	template <typename T>
	T calSection(T percentage, T total)
	{
		return (T)(total * percentage) / (100);
	}
	
	// change the name to be reasonable
	template <typename T>
	T calPercentage(T value, T total)
	{
		return (T)(value / total )* 100;
	}
	
	template <typename T>
	bool checkCollision(const sf::Vector2<T> currentPos, sf::Vector2<T> midToBound, sf::Vector2<T> collisionPos)
	{
		if (collisionPos.x - midToBound.x <= currentPos.x && currentPos.x <= collisionPos.x + midToBound.x)
			if (collisionPos.y - midToBound.y <= currentPos.y && currentPos.y <= collisionPos.y + midToBound.y)
			{
				return true;
			}
		return false;
	}
	
	template <typename T>
	class Range
	{
	public:
		Range() { m_Value = 0; }
		Range(T _min, T _max)
			: m_Min(_min), m_Max(_max) {
			m_Value = 0;
		}

		void setRange(T _min, T _max)
		{
			m_Min = _min;
			m_Max = _max;

			if (m_Value <= _min)
				m_Value = _min;
			if (m_Value >= _max)
				m_Value = _max;
		}
		void setValue(const T& val)
		{
			if (m_Min <= val && val <= m_Max)
				m_Value = val;
		}
		T getValue() const
		{
			return m_Value;
		}
		Range& operator= (const T val)
		{
			this->setValue(val);
			return *this;
		}

	private:
		T m_Value;
		T m_Max, m_Min;
	};

	std::optional<char> getKeyReleased(const std::optional<sf::Event>& event);
	std::optional<char> getKeyPressed(const std::optional<sf::Event>& event);
	
};