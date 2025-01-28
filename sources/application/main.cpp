#include <iostream>
#include <optional>
#include "../lib/widget.hpp"

int main()
{
	Application app("Normal");
	Label label("Hello",200,true,sf::Color(255,1,234),sf::Text::Style::Italic);
	Object::connect<Label>(label, []() {std::cout << "Co0l/n";});
	app.setMainWidget(&label);
	app.show();
	return 0;
}