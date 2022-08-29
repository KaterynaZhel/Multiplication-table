#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int start_game();
int menu_graph(RenderWindow&, int*, Event);
int game(RenderWindow&, int*, Event);
int gameover(RenderWindow&, int*, Event);
bool checkAnswer(std::string answer, int result);

static Time cursor_effect_time;
static Time result_effect_time;
static bool show_cursor;
static int example_count = 0;
static int example_right = 0;
static int example_fail = 0;

const int MAX_EXAMPLES = 4;


int main()
{
	setlocale(0, "");
	srand(unsigned(time(0)));

	start_game();

	return EXIT_SUCCESS;
}

int start_game() {
	RenderWindow window(VideoMode(800, 600), "Multiplication table");
	window.setVerticalSyncEnabled(true);

	Clock clock;

	// create background image
	Texture textureFon;
	Sprite spritefon;
	if (!textureFon.loadFromFile("resources\\fon.png"))
		return EXIT_FAILURE;
	spritefon.setTexture(textureFon);
	spritefon.setPosition(0, 0);

	window.draw(spritefon);

	int type_game = 0;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// create cursor blinking
		result_effect_time += clock.getElapsedTime();
		cursor_effect_time += clock.restart();

		// dispay first menu
		if (type_game == 0)
			menu_graph(window, &type_game, event);

		// run selected game 
		if (type_game >= 2 && type_game <= 10)
			game(window, &type_game, event);

		// game over
		if (type_game == 100)
			gameover(window, &type_game, event);

		window.display();
		window.clear();
		window.draw(spritefon);
	}
}

int menu_graph(RenderWindow& window, int* type_game, Event event)
{
	Texture logo;
	Sprite spritelogo;
	if (!logo.loadFromFile("resources\\logo.png"))
		return EXIT_FAILURE;
	spritelogo.setTexture(logo);
	spritelogo.setPosition(50, 400);
	
	
	Texture logo2;
	Sprite spritelogo2;
	if (!logo2.loadFromFile("resources\\logo2.png"))
		return EXIT_FAILURE;
	spritelogo2.setTexture(logo2);
	spritelogo2.setPosition(50, 100);
	

	Text menu_2, menu_3, menu_4, menu_5, menu_6, menu_7, menu_8, menu_9, menu_10, menu_11;
	Font font;
	if (!font.loadFromFile("resources\\comic.ttf"))
		return EXIT_FAILURE;

	for (auto it : { &menu_2, &menu_3, &menu_4, &menu_5, &menu_6, &menu_7, &menu_8, &menu_9, &menu_10, &menu_11 })
	{
		it->setFont(font);
		it->setCharacterSize(30);
		it->setFillColor(Color(255, 140, 0));
	}

	menu_2.setPosition(550, 20);
	menu_3.setPosition(550, 70);
	menu_4.setPosition(550, 120);
	menu_5.setPosition(550, 170);
	menu_6.setPosition(550, 220);
	menu_7.setPosition(550, 270);
	menu_8.setPosition(550, 320);
	menu_9.setPosition(550, 370);
	menu_10.setPosition(550, 420);
	menu_11.setPosition(550, 470);

	menu_2.setString("x2");
	menu_3.setString("x3");
	menu_4.setString("x4");
	menu_5.setString("x5");
	menu_6.setString("x6");
	menu_7.setString("x7");
	menu_8.setString("x8");
	menu_9.setString("x9");
	menu_10.setString("all numbers");

	menu_11.setString("Exit");
	menu_11.setFillColor(Color(255, 20, 147));



	if (IntRect(550, 20, 320, 30).contains(Mouse::getPosition(window)))
	{
		menu_2.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 2;
	}

	if (IntRect(550, 70, 320, 30).contains(Mouse::getPosition(window)))
	{
		menu_3.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 3;
	}
	if (IntRect(550, 120, 320, 30).contains(Mouse::getPosition(window)))
	{
		menu_4.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 4;
	}
	if (IntRect(550, 170, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_5.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 5;
	}
	if (IntRect(550, 220, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_6.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 6;
	}

	if (IntRect(550, 270, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_7.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 7;
	}
	if (IntRect(550, 320, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_8.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 8;
	}
	if (IntRect(550, 370, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_9.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 9;
	}
	if (IntRect(550, 420, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_10.setFillColor(Color::Blue);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) *type_game = 10;
	}
	if (IntRect(550, 470, 100, 30).contains(Mouse::getPosition(window)))
	{
		menu_11.setFillColor(Color::Black);
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) window.close();
	}

	window.draw(menu_2);
	window.draw(menu_3);
	window.draw(menu_4);
	window.draw(menu_5); 
	window.draw(menu_6);
	window.draw(menu_7); 
	window.draw(menu_8);
	window.draw(menu_9);
	window.draw(menu_10);
	window.draw(menu_11);

	window.draw(spritelogo);
	window.draw(spritelogo2);
}

int game(RenderWindow& window, int* type_game, Event event) {
	// game over
	if (example_count >= MAX_EXAMPLES) {
		*type_game = 100;
		return EXIT_SUCCESS;
	}
	
	Font font;
	if (!font.loadFromFile("resources\\comic.ttf"))
		return EXIT_FAILURE;

	// create questition text
	static std::string questition_text;
	static int result;
	if (questition_text.empty()) {
		int num1 = rand() % 8 + 2;
		int num2 = (* type_game == 10) ? rand() % 8 + 2 : *type_game;
		result = num1 * num2;
		questition_text = std::to_string(num1) + " x " + std::to_string(num2) + " = ";
	}
	Text questition(questition_text, font, 50);
	questition.setPosition(50, 10);
	questition.setFillColor(Color::Black);

	// create rectangle for input
	RectangleShape input(Vector2f(120, 50));
	input.setFillColor(Color::White);
	input.setPosition(300, 15);
	input.setOutlineThickness(2);
	input.setOutlineColor(Color::Black);

	// create input text
	static std::string answer;
	Text input_text("", font, 50);
	input_text.setPosition(310, 7);
	input_text.setFillColor(Color::Black);

	// create check result
	static Text check_result("", font, 50);
	check_result.setPosition(300, 400);

	// process entering text
	if (event.type == Event::TextEntered) {
		if (isdigit(event.text.unicode))
			answer += event.text.unicode;

		if (event.text.unicode == '\b')
			if (!answer.empty())
				answer.pop_back();

		sleep(milliseconds(80));
	}

	// reset timer after 0.5s
	if (cursor_effect_time >= seconds(0.5f))
	{
		show_cursor = !show_cursor;
		cursor_effect_time = Time::Zero;
	}

	// add cursor blinking to answer
	input_text.setString(answer + (show_cursor ? '_' : ' '));

	// auto verify answer
	if (checkAnswer(answer, result)) {
		example_count++;
		example_right++;
		questition_text = "";
		answer = "";

		std::string check_result_text = "Right (" + std::to_string(example_right) + " of " + std::to_string(MAX_EXAMPLES) + ")";
		check_result.setString(check_result_text);
		check_result.setFillColor(Color::Green);
		
		result_effect_time = Time::Zero;
	} else if (Keyboard::isKeyPressed(Keyboard::Enter) && !answer.empty()) {
		example_count++;
		example_fail++;
		questition_text = "";
		answer = "";

		std::string check_result_text = "Fail (" + std::to_string(example_fail) + " of " + std::to_string(MAX_EXAMPLES) + ")";
		check_result.setString(check_result_text);
		check_result.setFillColor(Color::Red);

		result_effect_time = Time::Zero;
	}

	if (result_effect_time < seconds(4)) {
		window.draw(check_result);
	}
	else {
		check_result.setString("");
	}

	window.draw(questition);
	window.draw(input);
	window.draw(input_text);
}

int gameover(RenderWindow& window, int* type_game, Event event) {
	Font font;
	if (!font.loadFromFile("resources\\comic.ttf"))
		return EXIT_FAILURE;

	// create background image
	Texture textureFon;
	Sprite spritefon;
	if (!textureFon.loadFromFile("resources\\fon.png"))
		return EXIT_FAILURE;
	spritefon.setTexture(textureFon);
	spritefon.setPosition(0, 0);

	// create statistic text
	std::string statistic_text = "Correct answers: " + std::to_string(example_right) + "\n";
	statistic_text += "Wrong answer: " + std::to_string(example_fail);
	Text statistic(statistic_text, font, 50);
	statistic.setPosition(300, 400);
	statistic.setFillColor(Color::Black);

	// create menu button
	Text main_menu("<Menu>", font, 50);
	main_menu.setPosition(550, 30);
	main_menu.setFillColor(Color::Blue);

	if (IntRect(550, 30, 600, 60).contains(Mouse::getPosition(window)))
	{
		main_menu.setFillColor(Color(255, 20, 147));
		if (event.type == Event::MouseButtonReleased)
			if (event.mouseButton.button == Mouse::Left) {
				// reset variables
				example_count = 0;
				example_right = 0;
				example_fail = 0;

				*type_game = 0;
			}
	}

	window.clear();
	window.draw(spritefon);
	window.draw(main_menu);
	window.draw(statistic);
}

bool checkAnswer(std::string answer, int result) {
	return answer == std::to_string(result);
}