#pragma once
#include <SFML/Graphics.hpp>

class RockPaperScissors
{
public:
    RockPaperScissors(const sf::Vector2f& resolution);

    void draw(sf::RenderWindow& window);

    void moveLeft();
    void moveRight();

    void rpsPressed(sf::Vector2f resolution);

private:
    const int sprite_width_ = 108;
    const int sprite_height_ = 162;

    sf::Texture rock_;
    sf::Texture paper_;
    sf::Texture scissors_;

    sf::Sprite rock_sprite_;
    sf::Sprite paper_sprite_;
    sf::Sprite scissors_sprite_;

    sf::Sprite bot_rock_;
    sf::Sprite bot_paper_;
    sf::Sprite bot_scissors_;

    int rps_selected_ = 0;

    const int character_size_ = 70;
    sf::Font font_;
    sf::Text text_rps_[3];
    sf::Text winner_;

    sf::Text ur_wins_;
    sf::Text bot_wins_;

    int ur_wins_count_ = 0;
    int bot_wins_count_ = 0;
};
