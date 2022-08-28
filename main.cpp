#include "MainMenu.h"
#include "RockPaperScissors.h"
#include "GuessTheNumber.h"

int main() {
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow menuWindow(VideoMode(resolution.x, resolution.y), "Simple Games Bundle");
	MainMenu mainMenu(resolution.x, resolution.y);
	RockPaperScissors rockPaperScissors(resolution.x, resolution.y);
	GuessTheNumber guessTheNum(resolution);

	View mainView(FloatRect(0, 0, resolution.x, resolution.y));

	while (menuWindow.isOpen())
	{
		Event event;
		
		while (menuWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				menuWindow.close();
			}
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.moveUp();
				}

				if (event.key.code == Keyboard::Down)
				{
					mainMenu.moveDown();
				}

				// select game
				if (event.key.code == Keyboard::Return)
				{
					if (mainMenu.mainMenuPressed() == 0)
					{
						RenderWindow RPS(VideoMode(resolution.x, resolution.y), "Rock Paper Scissors");
						while (RPS.isOpen())
						{
							Event eventRPS;
							while (RPS.pollEvent(eventRPS))
							{
								if (eventRPS.type == Event::Closed)
									RPS.close();
								if (eventRPS.type == Event::KeyPressed)
									if (eventRPS.key.code == Keyboard::Left)
									{
										rockPaperScissors.moveLeft();
									}

									if (eventRPS.key.code == Keyboard::Right)
									{
										rockPaperScissors.moveRight();
									}

									if (eventRPS.key.code == Keyboard::Return)
									{
										rockPaperScissors.RPSPressed(resolution);
									}

									if (eventRPS.key.code == Keyboard::Escape)
									{
										RPS.close();
									}
								RPS.clear();
								rockPaperScissors.draw(RPS);
								RPS.display();
							}
						}
					}

					if (mainMenu.mainMenuPressed() == 1)
					{
						RenderWindow TTT(VideoMode(resolution.x, resolution.y), "Tic Tac Toe");
						while (TTT.isOpen())
						{
							Event eventTTT;
							while (TTT.pollEvent(eventTTT))
							{
								if (eventTTT.type == Event::Closed)
								{
									TTT.close();
								}

								if (eventTTT.type == Event::KeyPressed)
								{
									if (eventTTT.key.code == Keyboard::Escape)
									{
										TTT.close();
									}
								}
							}
							TTT.clear();
							TTT.display();
						}
					}

					if (mainMenu.mainMenuPressed() == 2)
					{
						RenderWindow GtN(VideoMode(resolution.x, resolution.y), "Guess the Number");
						while (GtN.isOpen())
						{
							Event eventGtN;
							while (GtN.pollEvent(eventGtN))
							{
								if (eventGtN.type == Event::Closed)
								{
									GtN.close();
								}

								if (eventGtN.type == Event::KeyPressed)
								{
									if (eventGtN.key.code == Keyboard::Escape)
									{
										GtN.close();
									}
									if (eventGtN.key.code == Keyboard::Left)
									{
										guessTheNum.moveLeft();
									}
									if (eventGtN.key.code == Keyboard::Right)
									{
										guessTheNum.moveRight();
									}
									if (eventGtN.key.code == Keyboard::Return)
									{
										guessTheNum.playerGuess();
									}
								}
							}
							GtN.clear();
							guessTheNum.draw(GtN);
							GtN.display();
						}
					}

					if (mainMenu.mainMenuPressed() == 3)
					{
						menuWindow.close();
					}
				}

				if (event.key.code == Keyboard::Escape)
				{
					menuWindow.close();
				}
		}
		menuWindow.clear();
		mainMenu.draw(menuWindow);
		menuWindow.display();
	}
	return 0;
}