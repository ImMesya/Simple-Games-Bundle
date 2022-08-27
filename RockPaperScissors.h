#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>

using namespace sf;
using namespace std;

class RockPaperScissors
{
public:
	RockPaperScissors(float width, float height);

	void draw(RenderWindow& window);

	void moveLeft();
	void moveRight();

	void RPSPressed(Vector2f resolution);

private:
	const int spriteWidth = 108;
	const int spriteHeight = 162;

	Texture rock;
	Texture paper;
	Texture scissors;

	Sprite rockSprite;
	Sprite paperSprite;
	Sprite scissorsSprite;

	Sprite botRock;
	Sprite botPaper;
	Sprite botScissors;

	int RPSSelected = 0;

	const int characterSize = 70;
	Font font;
	Text textRPS[3];
	Text winner;
};