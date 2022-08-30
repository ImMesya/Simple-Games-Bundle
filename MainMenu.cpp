#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) {
	if (!font.loadFromFile("fonts/JellyBomb.ttf"))
	{
		cout << "Font not found";
	}

	for (int i = 0; i < MAX_MAIN_MENU; i++)
	{
		mainMenu[i].setFont(font);
		mainMenu[i].setFillColor(Color::White);
		mainMenu[i].setCharacterSize(characterSize);
		if (i == 0)
		{
			mainMenu[i].setString("Rock Paper Scissors");
			mainMenu[i].setPosition(width / 2 - characterSize, height / 2 - (characterSize * 2 - 50));
			mainMenu[i].setFillColor(Color::Blue);
		}
		if (i == 1)
		{
			mainMenu[i].setString("Tic Tac Toe");
			mainMenu[i].setPosition(width / 2 - characterSize, height / 2 - (characterSize - 50));
		}
		if (i == 2)
		{
			mainMenu[i].setString("Guess The Number");
			mainMenu[i].setPosition(width / 2 - characterSize, height / 2 + (characterSize - 20));
		}
		if (i == 3)
		{
			mainMenu[i].setString("Exit");
			mainMenu[i].setPosition(width / 2 - characterSize, height / 2 + (characterSize * 2 - 20));
		}
	}
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < 4; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::moveUp() 
{
	mainMenu[MainMenuSelected].setFillColor(Color::White);

	--MainMenuSelected;
	if (MainMenuSelected == -1)
	{
		MainMenuSelected = 3;
	}
	mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}

void MainMenu::moveDown()
{
	mainMenu[MainMenuSelected].setFillColor(Color::White);

	++MainMenuSelected;
	if (MainMenuSelected == 4)
	{
		MainMenuSelected = 0;
	}
	mainMenu[MainMenuSelected].setFillColor(Color::Blue);
}

int MainMenu::mainMenuPressed()
{
	return MainMenuSelected;
}