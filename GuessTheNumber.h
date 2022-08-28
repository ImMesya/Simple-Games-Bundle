#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

using namespace sf;
using namespace std;

class GuessTheNumber
{
public:
	GuessTheNumber(Vector2f resolution);

	void moveLeft();
	void moveRight();

	void playerGuess();

	void draw(RenderWindow& window);

private:
	Font font;
	const int characterSize = 70;
	Text numbers[10];
	int numberSelected = 0;
	Text guess;
	int rndmNum;
};