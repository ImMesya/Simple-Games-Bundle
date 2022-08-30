#include "GuessTheNumber.h"

GuessTheNumber::GuessTheNumber(Vector2f resolution)
{
	srand(time(NULL));

	if (!font.loadFromFile("fonts/JellyBomb.ttf"))
	{
		cout << "Font not found";
	}

	guess.setFont(font);
	guess.setCharacterSize(characterSize);
	guess.setString("Guess the random number from 0 to 9");
	guess.setScale(2,2);
	guess.setOrigin(guess.getLocalBounds().width / 2, guess.getLocalBounds().height / 2);
	guess.setPosition(resolution.x / 2, resolution.y / 3);

	for (int i = 0; i < 10; i++)
	{
		numbers[i].setFont(font);
		numbers[i].setCharacterSize(characterSize);
		numbers[i].setString(to_string(i));
		numbers[i].setScale(3, 3);
		numbers[i].setPosition(300 + i * characterSize * 3, resolution.y / 1.5);
		i == 0 ? numbers[0].setFillColor(Color::Blue) : numbers[i].setFillColor(Color::White);
	}
	rndmNum = rand() % 10;
}

void GuessTheNumber::moveLeft()
{
	numbers[numberSelected].setFillColor(Color::White);

	numberSelected--;
	if (numberSelected == -1)
	{
		numberSelected = 9;
	}
	numbers[numberSelected].setFillColor(Color::Blue);
}

void GuessTheNumber::moveRight()
{
	numbers[numberSelected].setFillColor(Color::White);

	numberSelected++;
	if (numberSelected == 10)
	{
		numberSelected = 0;
	}
	numbers[numberSelected].setFillColor(Color::Blue);
}
void GuessTheNumber::playerGuess()
{
	if (rndmNum > numberSelected)
	{
		guess.setString("The guessed number is greater than yours.");
	}
	else if (rndmNum < numberSelected)
	{
		guess.setString("The guessed number is less than yours.");
	}
	else
	{
		guess.setString("You won! Try again.");
		rndmNum = rand() % 10;
	}
}

void GuessTheNumber::draw(RenderWindow& window)
{
	window.draw(guess);

	for (int i = 0; i < 10; i++)
	{
		window.draw(numbers[i]);
	}
}