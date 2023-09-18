#pragma once
#include <SFML/Graphics.hpp>

class GuessTheNumber
{
public:
    explicit GuessTheNumber(sf::Vector2f resolution);

    void moveLeft();
    void moveRight();

    void playerGuess();

    void draw(sf::RenderWindow& window);

private:
    sf::Font font_;
    const int character_size_ = 70;
    sf::Text numbers_[10];
    int number_selected_ = 0;
    sf::Text guess_;
    int random_num_;
};
