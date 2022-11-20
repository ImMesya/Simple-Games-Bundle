#pragma once
#include <SFML/Graphics.hpp>

class guess_the_number
{
public:
    explicit guess_the_number(sf::Vector2f resolution);

    void move_left();
    void move_right();

    void player_guess();

    void draw(sf::RenderWindow& window);

private:
    sf::Font font_;
    const int character_size_ = 70;
    sf::Text numbers_[10];
    int number_selected_ = 0;
    sf::Text guess_;
    int random_num_;
};
