#pragma once
#include <SFML/Graphics.hpp>

class tic_tac_toe
{
public:
    explicit tic_tac_toe(sf::Vector2f resolution);

    void draw(sf::RenderWindow& window);

    void turn(int mouse_x, int mouse_y);
    void restart();
    bool check_winner(sf::Texture& mark);

private:
    sf::Texture grid_;
    sf::Texture mark_x_;
    sf::Texture mark_o_;
    sf::Texture blank_;

    sf::Sprite grid_sprite_;
    sf::Sprite blank_sprite_[10];

    bool is_x_turn_ = true;
    bool is_draw_ = false;
    bool is_winner_ = false;

    sf::Text instructions_;
    sf::Font font_;
};
