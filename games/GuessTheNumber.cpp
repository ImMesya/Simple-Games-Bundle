#include "GuessTheNumber.h"

#include <iostream>

GuessTheNumber::GuessTheNumber(sf::Vector2f resolution)
{
    srand(time(NULL));

    if (!font_.loadFromFile("fonts/JellyBomb.ttf"))
    {
        std::cout << "Font not found";
    }

    guess_.setFont(font_);
    guess_.setCharacterSize(character_size_);
    guess_.setString("Guess the random number from 0 to 9");
    guess_.setScale(2, 2);
    guess_.setOrigin(guess_.getLocalBounds().width / 2, guess_.getLocalBounds().height / 2);
    guess_.setPosition(resolution.x / 2, resolution.y / 3);

    for (int i = 0; i < 10; i++)
    {
        numbers_[i].setFont(font_);
        numbers_[i].setCharacterSize(character_size_);
        numbers_[i].setString(std::to_string(i));
        numbers_[i].setScale(3, 3);
        numbers_[i].setPosition(300 + i * character_size_ * 3, resolution.y / 1.5);
        i == 0 ? numbers_[0].setFillColor(sf::Color::Blue) : numbers_[i].setFillColor(sf::Color::White);
    }
    random_num_ = rand() % 10;
}

void GuessTheNumber::moveLeft()
{
    numbers_[number_selected_].setFillColor(sf::Color::White);

    number_selected_--;
    if (number_selected_ == -1)
    {
        number_selected_ = 9;
    }
    numbers_[number_selected_].setFillColor(sf::Color::Blue);
}

void GuessTheNumber::moveRight()
{
    numbers_[number_selected_].setFillColor(sf::Color::White);

    number_selected_++;
    if (number_selected_ == 10)
    {
        number_selected_ = 0;
    }
    numbers_[number_selected_].setFillColor(sf::Color::Blue);
}

void GuessTheNumber::playerGuess()
{
    if (random_num_ > number_selected_)
    {
        guess_.setString("The guessed number is greater than yours.");
    }
    else if (random_num_ < number_selected_)
    {
        guess_.setString("The guessed number is less than yours.");
    }
    else
    {
        guess_.setString("You won! Try again.");
        random_num_ = rand() % 10;
    }
}

void GuessTheNumber::draw(sf::RenderWindow& window)
{
    window.draw(guess_);

    for (const auto& number : numbers_)
    {
        window.draw(number);
    }
}
