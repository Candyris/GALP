#include "../sources/lib/GALP.hpp"
#include <string>
//#include <Windows.h>
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)  // for window application only

int main()
{
	Application app("Slider");
	app.setBackgroundColor({30,30,30});
	Slider slider;
	Label lab("Hello", 100);
	Label lab1("Hello", 20);
	Button button("Touch me");
	SpinBox sp;
	HBoxLayout b;
	LineEdit line({100.0f,32.0f});
	b.addWidget(&lab1);
	b.addWidget(&slider);
	b.addWidget(&button);
	b.addWidget(&sp);
	b.addWidget(&line);

	Object::connect(button, []() {std::cout << "Clicked\n";});
	Object::connectShortcut(app, sf::Keyboard::Key::Right, [&slider, &lab1]() {
		std::cout << std::to_string(slider.getBarValue())<<std::endl;
		slider.setBarValue(slider.getBarValue() + 1);
		lab1.setString(std::to_string(slider.getBarValue()));
		});
	Object::connectShortcut(app, sf::Keyboard::Key::Left, [&slider, &lab1]() {
		std::cout << std::to_string(slider.getBarValue())<<std::endl;
		slider.setBarValue(slider.getBarValue() - 1);
		lab1.setString(std::to_string(slider.getBarValue()));
		});
	Object::connect(slider, [&slider, &lab1]() {lab1.setString(std::to_string(slider.getBarValue()));});

	app.setMainWidget(&b);
	app.show();

	return 0;
}