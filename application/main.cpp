#include <GALP.hpp>
#include <string>
// #include <Windows.h>
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)  // for window application only

int main()
{
	Application app("Slider",250u,300u);
	app.setBackgroundColor({30,30,30});
	Slider slider;
	Label lab2("Percentage: ", 20);
	Label lab1("Hello", 20);
	Button button("Touch me", {200.0f,32.0f});
	SpinBox sp( {0,100},5,{200.0f,32.f} );
	VBoxLayout b({ 20.0f,20.0f }, {20.0f,20.0f});
	LineEdit line({200.0f,32.0f});

	HBoxLayout h({35.0f,0.0f}, {0.0f,0.0f});
	h.addWidget(&lab2);
	h.addWidget(&lab1);

	b.addWidget(&h);
	b.addWidget(&button);
	b.addWidget(&slider);
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