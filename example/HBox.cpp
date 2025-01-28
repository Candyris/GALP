#include "../sources/lib/widget.hpp"

int main()
{
	Application app("Normal");
	Label label1("Hello", 100, false, sf::Color(255, 1, 234), sf::Text::Style::Italic);
	Label label2("sad", 100, false, sf::Color(255, 1, 234), sf::Text::Style::Bold);
	Button btn("Hello", sf::Vector2f(100.0f, 50.0f));
	Button btn1("What to ", sf::Vector2f(100.0f, 50.0f));
	Button btn2("go bro", sf::Vector2f(100.0f, 50.0f));

	Object::connect(btn, []() {std::cout<< "Hello" << std::endl;});
	Object::connect(btn1, []() {std::cout<< "What to" << std::endl;});
	Object::connect(btn2, []() {std::cout<< "go bro" << std::endl;});
	HBox box;
	box.addWidget<Label>(&label2);
	box.addWidget<Button>(&btn);
	box.addWidget<Button>(&btn1);
	box.addWidget<Button>(&btn2);
	box.addWidget<Label>(&label1);
	app.setMainWidget(&box);
	app.show();
	return 0;
}