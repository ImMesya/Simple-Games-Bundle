#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#define MAX_MAIN_MENU 4

class MainMenu
{
public:
	MainMenu(float width, float height);

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed();

	~MainMenu();
private:
	int MainMenuSelected = 0;
	const int characterSize = 70;
	Font font;
	Text mainMenu[MAX_MAIN_MENU];
};