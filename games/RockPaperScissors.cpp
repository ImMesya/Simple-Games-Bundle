#include "RockPaperScissors.h"

#include <iostream>
#include <sstream>

rock_paper_scissors::rock_paper_scissors(float width, float height)
{
    if (!rock_.loadFromFile("images/rock_paper_scissors.png",
                            sf::IntRect(sprite_width_ * 2, 0, sprite_width_, sprite_height_)))
    {
        std::cout << "No texture for Rock Paper Scissors!";
    }
    paper_.loadFromFile("images/rock_paper_scissors.png",
                        sf::IntRect(0, 0, sprite_width_, sprite_height_));
    scissors_.loadFromFile("images/rock_paper_scissors.png",
                           sf::IntRect(sprite_width_, 0, sprite_width_, sprite_height_));

    rock_sprite_.setTexture(rock_);
    bot_rock_.setTexture(rock_);
    scissors_sprite_.setTexture(scissors_);
    bot_scissors_.setTexture(scissors_);
    paper_sprite_.setTexture(paper_);
    bot_paper_.setTexture(paper_);

    bot_rock_.setOrigin(sprite_width_ / 2, sprite_height_ / 2);
    bot_paper_.setOrigin(sprite_width_ / 2, sprite_height_ / 2);
    bot_scissors_.setOrigin(sprite_width_ / 2, sprite_height_ / 2);

    rock_sprite_.setPosition(width / 2 - sprite_width_ * 3, height / 2);
    paper_sprite_.setPosition(width / 2, height / 2);
    scissors_sprite_.setPosition(width / 2 + sprite_width_ * 3, height / 2);
    bot_paper_.setPosition(-sprite_width_, -sprite_height_);
    bot_rock_.setPosition(-sprite_width_, -sprite_height_);
    bot_scissors_.setPosition(-sprite_width_, -sprite_height_);

    bot_paper_.setRotation(180);
    bot_rock_.setRotation(180);
    bot_scissors_.setRotation(180);

    rock_sprite_.setScale(2, 2);
    bot_rock_.setScale(2, 2);
    paper_sprite_.setScale(2, 2);
    bot_paper_.setScale(2, 2);
    scissors_sprite_.setScale(2, 2);
    bot_scissors_.setScale(2, 2);

    srand(time(NULL));

    if (!font_.loadFromFile("fonts/JellyBomb.ttf"))
    {
        std::cout << "Font not found";
    }

    std::stringstream ss_player;
    std::stringstream ss_bot;


    winner_.setFont(font_);
    ur_wins_.setFont(font_);
    bot_wins_.setFont(font_);
    winner_.setFillColor(sf::Color::White);
    ur_wins_.setFillColor(sf::Color::White);
    bot_wins_.setFillColor(sf::Color::White);
    winner_.setCharacterSize(character_size_);
    ur_wins_.setCharacterSize(character_size_);
    bot_wins_.setCharacterSize(character_size_);
    winner_.setString("Choose one of the following options");
    ss_player << "Your wins - " << ur_wins_count_;
    ur_wins_.setString(ss_player.str());
    ss_bot << "Computer wins - " << bot_wins_count_;
    bot_wins_.setString(ss_bot.str());
    winner_.setPosition(width / 2.5, height / 2.5);
    ur_wins_.setPosition(20, 10);
    bot_wins_.setPosition(20, 90);

    for (int i = 0; i < 3; i++)
    {
        text_rps_[i].setFont(font_);
        text_rps_[i].setFillColor(sf::Color::White);
        text_rps_[i].setCharacterSize(character_size_);
        if (i == 0)
        {
            text_rps_[i].setString("Rock");
            text_rps_[i].setPosition(rock_sprite_.getPosition().x + character_size_ / 2,
                                     rock_sprite_.getPosition().y + sprite_height_ * 2);
            text_rps_[i].setFillColor(sf::Color::Blue);
        }
        if (i == 1)
        {
            text_rps_[i].setString("Paper");
            text_rps_[i].setPosition(paper_sprite_.getPosition().x + character_size_ / 2,
                                     paper_sprite_.getPosition().y + sprite_height_ * 2);
        }
        if (i == 2)
        {
            text_rps_[i].setString("Scissors");
            text_rps_[i].setPosition(scissors_sprite_.getPosition().x + character_size_ / 2,
                                     scissors_sprite_.getPosition().y + sprite_height_ * 2);
        }
    }
}

void rock_paper_scissors::draw(sf::RenderWindow& window)
{
    window.draw(rock_sprite_);
    window.draw(scissors_sprite_);
    window.draw(paper_sprite_);
    window.draw(winner_);
    window.draw(bot_paper_);
    window.draw(bot_rock_);
    window.draw(bot_scissors_);
    window.draw(ur_wins_);
    window.draw(bot_wins_);

    for (const auto& text_rp : text_rps_)
    {
        window.draw(text_rp);
    }
}

void rock_paper_scissors::move_left()
{
    text_rps_[rps_selected_].setFillColor(sf::Color::White);

    rps_selected_--;
    if (rps_selected_ == -1)
    {
        rps_selected_ = 2;
    }
    text_rps_[rps_selected_].setFillColor(sf::Color::Blue);
}

void rock_paper_scissors::move_right()
{
    text_rps_[rps_selected_].setFillColor(sf::Color::White);

    rps_selected_++;
    if (rps_selected_ == 3)
    {
        rps_selected_ = 0;
    }
    text_rps_[rps_selected_].setFillColor(sf::Color::Blue);
}


void rock_paper_scissors::rps_pressed(sf::Vector2f resolution)
{
    const int bot = rand() % 3;

    std::stringstream ss_player;
    std::stringstream ss_bot;

    bot_rock_.setPosition(-sprite_width_, -sprite_height_);
    bot_paper_.setPosition(-sprite_width_, -sprite_height_);
    bot_scissors_.setPosition(-sprite_width_, -sprite_height_);

    if (bot == 1 && rps_selected_ == 0)
    {
        bot_wins_count_++;
        bot_paper_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("Computer Wins! Paper wraps Rock.");
        ss_bot << "Computer wins - " << bot_wins_count_;
        bot_wins_.setString(ss_bot.str());
    }
    else if (bot == 2 && rps_selected_ == 1)
    {
        bot_wins_count_++;
        bot_scissors_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("Computer Wins! Scissors cut Paper.");
        ss_bot << "Computer wins - " << bot_wins_count_;
        bot_wins_.setString(ss_bot.str());
    }
    else if (bot == 0 && rps_selected_ == 2)
    {
        bot_wins_count_++;
        bot_rock_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("Computer Wins! Rock smashes Scissors.");
        ss_bot << "Computer wins - " << bot_wins_count_;
        bot_wins_.setString(ss_bot.str());
    }
    else if (rps_selected_ == 0 && bot == 2)
    {
        ur_wins_count_++;
        bot_scissors_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("You Win! Rock smashes Scissors.");
        ss_player << "Your wins - " << ur_wins_count_;
        ur_wins_.setString(ss_player.str());
    }
    else if (rps_selected_ == 1 && bot == 0)
    {
        ur_wins_count_++;
        bot_rock_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("You Win! Paper wraps Rock.");
        ss_player << "Your wins - " << ur_wins_count_;
        ur_wins_.setString(ss_player.str());
    }
    else if (rps_selected_ == 2 && bot == 1)
    {
        ur_wins_count_++;
        bot_paper_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
        winner_.setString("You Win! Scissors cut Paper.");
        ss_player << "Your wins - " << ur_wins_count_;
        ur_wins_.setString(ss_player.str());
    }
    else
    {
        switch (bot)
        {
        case 0:
            bot_rock_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
            break;
        case 1:
            bot_paper_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
            break;
        case 2:
            bot_scissors_.setPosition(resolution.x / 2 + sprite_width_ / 2, resolution.y / 4);
            break;
        default:
            break;
        }
        winner_.setString("Tie. Play again win the Game.");
    }
}
