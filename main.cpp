#include "MainMenu.h"

int main() {
	enum class State {MENU, ROCK_PAPER_SCISSORS, TIC_TAC_TOE, GUESS_NUM};
	State state = State::MENU;

	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Simple Games Bundle");
	RenderWindow RPS(VideoMode(resolution.x, resolution.y), "Rock Paper Scissors");
	RPS.setActive(false);

	MainMenu mainMenu(resolution.x, resolution.y);

	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			// Menu control
			if (state == State::MENU)
			{
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Up)
					{
						mainMenu.moveUp();
						break;
					}

					if (event.key.code == Keyboard::Down)
					{
						mainMenu.moveDown();
						break;
					}

					if (event.key.code == Keyboard::Return)
					{
						int x = mainMenu.mainMenuPressed();
						if (x == 0)
						{
							state = State::ROCK_PAPER_SCISSORS;
							
						}
						
						if (x == 1)
						{
							//state = State::TIC_TAC_TOE;
							RenderWindow TTT(VideoMode(resolution.x, resolution.y), "Tic Tac Toe");
						}
						
						if (x == 2)
						{
							//state = State::GUESS_NUM;
							RenderWindow RPS(VideoMode(resolution.x, resolution.y), "Guess the Number");
						}

						if (x == 3)
						{
							window.close();
						}
					}
				}

			}

			if (state == State::ROCK_PAPER_SCISSORS)
			{
				RPS.setActive(true);
				
			}

			if (state == State::TIC_TAC_TOE)
			{

			}

			if (state == State::GUESS_NUM)
			{

			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		window.clear();
		mainMenu.draw(window);
		window.display();
	}
}