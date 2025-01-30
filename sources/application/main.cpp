#include "../lib/GALP.hpp"

//#include <Windows.h>
//int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) for window application only

int main()
{
	Application app("Slider");

	Slider slider;
	Label lab("Hello",100);
	Label lab1("Hello",20);
	Button button("Touch me",sf::Vector2f(100.0f,100.0f));
	HBoxLayout b;
	b.addWidget(&lab1);
	b.addWidget(&slider);
	b.addWidget(&button);

	app.setMainWidget(&b);
	app.show();

	return 0;
}