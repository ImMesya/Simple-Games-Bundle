#include "MainMenu.h"
#include "games/RockPaperScissors.h"
#include "games/GuessTheNumber.h"

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
			else if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.moveUp();
				}

				else if (event.key.code == Keyboard::Down)
				{
					mainMenu.moveDown();
				}

				// select game
				else if (event.key.code == Keyboard::Return)
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
								else if (eventRPS.type == Event::KeyPressed)
									if (eventRPS.key.code == Keyboard::Left)
									{
										rockPaperScissors.moveLeft();
									}

									else if (eventRPS.key.code == Keyboard::Right)
									{
										rockPaperScissors.moveRight();
									}

									else if (eventRPS.key.code == Keyboard::Return)
									{
										rockPaperScissors.RPSPressed(resolution);
									}

									else if (eventRPS.key.code == Keyboard::Escape)
									{
										RPS.close();
									}
								RPS.clear();
								rockPaperScissors.draw(RPS);
								RPS.display();
							}
						}
					}

					else if (mainMenu.mainMenuPressed() == 1)
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

								else if (eventTTT.type == Event::KeyPressed)
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

					else if (mainMenu.mainMenuPressed() == 2)
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

								else if (eventGtN.type == Event::KeyPressed)
								{
									if (eventGtN.key.code == Keyboard::Escape)
									{
										GtN.close();
									}
									else if (eventGtN.key.code == Keyboard::Left)
									{
										guessTheNum.moveLeft();
									}
									else if (eventGtN.key.code == Keyboard::Right)
									{
										guessTheNum.moveRight();
									}
									else if (eventGtN.key.code == Keyboard::Return)
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

					else if (mainMenu.mainMenuPressed() == 3)
					{
						menuWindow.close();
					}
				}

				else if (event.key.code == Keyboard::Escape)
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