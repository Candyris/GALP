//#include "../sources/lib/GALP.hpp"
//
//int main()
//{
//	Application app("Snap");
//
//	app.setBackgroundColor({ 12,34,86 });
//
//	Label label("Good Moring");
//	HBoxLayout hbox({ 20.0f,20.0f }, { 20.0f,20.0f });
//	LineEdit edit({ 300.0f,32.0f });
//	Button button("Ok!", { 200.0f,32.0f });
//	SpinBox sp;
//
//	hbox.addWidget<SpinBox>(&sp);
//	//hbox.addWidget<Label>(&label);
//	hbox.addWidget<LineEdit>(&edit);
//	hbox.addWidget<Button>(&button);
//
//	Object::connectShortcut(app, sf::Keyboard::Key::Escape, [&app]() {app.close();});
//	Object::connect(button, []() {std::cout << "Hello\n";});
//
//	app.setMainWidget(&hbox);
//	app.show();
//
//
//	return 0;
//}