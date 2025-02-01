#include "SpinBox.hpp"
#include "utility.hpp"
#include <string>

SpinBox::SpinBox(Utility::Range<int> range, int interval,const sf::Vector2f& size)
	:m_Range(range), m_Interval(interval)
{
	IsOriginPosition = false;
	m_Body.setSize(size);
	m_TextInput = std::make_unique<LineEdit>( sf::Vector2f(Utility::calSection<float>(80.0f, size.x), Utility::calSection<float>(90.0f, size.y)));
	m_TextInput->setString(std::to_string(m_Range.getValue()));
	m_UpBtn.setPosition(sf::Vector2f(Utility::calSection<float>(80.0f, size.x), 0.0f));
	m_UpBtn.setSize(sf::Vector2f(Utility::calSection<float>(20.0f, size.x), Utility::calSection<float>(50.0f, size.y)));

	m_DownBtn.setPosition(sf::Vector2f(Utility::calSection<float>(80.0f, size.x), Utility::calSection<float>(50.0f, size.y)));
	m_DownBtn.setSize(sf::Vector2f(Utility::calSection<float>(20.0f, size.x), Utility::calSection<float>(50.0f, size.y)));
	m_DownBtn.rotate(true);

	m_UpBtn.attachEvent([this]() {
		m_Range = m_Range.getValue() + m_Interval;
		m_TextInput->setString(std::to_string(m_Range.getValue()));
		});

	m_DownBtn.attachEvent([this]() {
		m_Range = m_Range.getValue() - m_Interval;
		m_TextInput->setString(std::to_string(m_Range.getValue()));
		});
}

void SpinBox::draw(sf::RenderWindow& win)
{
	win.draw(m_Body);
	m_TextInput->draw(win);
	m_UpBtn.draw(win);
	m_DownBtn.draw(win);
}

void SpinBox::setPosition(const sf::Vector2f& position)
{
	m_TextInput->setPosition(position);
	m_Body.setPosition(position);
	m_UpBtn.setPosition(sf::Vector2f(m_Body.getPosition().x + Utility::calSection<float>(80.0f, m_Body.getSize().x), m_Body.getPosition().y));
	m_DownBtn.setPosition(sf::Vector2f(m_Body.getPosition().x + Utility::calSection<float>(80.0f, m_Body.getSize().x),m_Body.getPosition().y + Utility::calSection<float>(50.0f, m_Body.getSize().y)));

}

void SpinBox::updateAction(const std::optional<sf::Event>& event, sf::RenderWindow& win)
{
	//m_TextInput->updateAction(event, win);
	m_UpBtn.updateAction(event,win);
	m_DownBtn.updateAction(event,win);
}
