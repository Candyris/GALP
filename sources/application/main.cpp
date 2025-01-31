#include "../lib/GALP.hpp"

int main()
{
	Application app("Snap");

	app.setBackgroundColor({12,34,86 });

	Label label("Good Moring");
	HBoxLayout hbox({20.0f,20.0f},{20.0f,20.0f});
	LineEdit edit({300.0f,32.0f});
	Button button("Ok!", {200.0f,32.0f});

	hbox.addWidget<LineEdit>(&edit);
	hbox.addWidget<Label>(&label);
	hbox.addWidget<Button>(&button);

	Object::connect(button, []() {std::cout << "Hello\n";});

	app.setMainWidget(&hbox);
	app.show();


	return 0;
}