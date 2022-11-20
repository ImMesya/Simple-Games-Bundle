#include "TicTacToe.h"

#include <iostream>

tic_tac_toe::tic_tac_toe(sf::Vector2f resolution)
{
    if (!font_.loadFromFile("fonts/JellyBomb.ttf"))
    {
        std::cout << "Font not found";
    }

    if (!grid_.loadFromFile("images/ttt_grid.png"))
    {
        std::cout << "No texture grid";
    }
    if (!mark_x_.loadFromFile("images/ttt_x.png"))
    {
        std::cout << "No texture mark_x";
    }
    if (!mark_o_.loadFromFile("images/ttt_o.png"))
    {
        std::cout << "No texture mark_o";
    }
    if (!blank_.loadFromFile("images/ttt_blank.png"))
    {
        std::cout << "No texture blank";
    }

    instructions_.setFont(font_);
    instructions_.setCharacterSize(70);
    instructions_.setString("X - Your first turn.");
    instructions_.setOrigin(instructions_.getLocalBounds().width / 2, instructions_.getLocalBounds().height / 2);
    instructions_.setPosition(resolution.x / 2, resolution.y / 8);

    grid_sprite_.setTexture(grid_);
    grid_sprite_.setPosition(resolution.x / 2, resolution.y / 2);
    grid_sprite_.setOrigin(grid_sprite_.getLocalBounds().width / 2, grid_sprite_.getLocalBounds().height / 2);
    grid_sprite_.setScale(2, 2);

    for (int i = 1; i < 10; i++)
    {
        blank_sprite_[i].setTexture(blank_);
        blank_sprite_[i].setOrigin
        (
            blank_sprite_[i].getLocalBounds().width / 2,
            blank_sprite_[i].getLocalBounds().height / 2
        );
        blank_sprite_[i].setScale(2, 2);
    }
    blank_sprite_[1].setPosition(resolution.x / 2 - 300, resolution.y / 2 - 300);
    blank_sprite_[2].setPosition(resolution.x / 2, resolution.y / 2 - 300);
    blank_sprite_[3].setPosition(resolution.x / 2 + 300, resolution.y / 2 - 300);
    blank_sprite_[4].setPosition(resolution.x / 2 - 300, resolution.y / 2);
    blank_sprite_[5].setPosition(resolution.x / 2, resolution.y / 2);
    blank_sprite_[6].setPosition(resolution.x / 2 + 300, resolution.y / 2);
    blank_sprite_[7].setPosition(resolution.x / 2 - 300, resolution.y / 2 + 300);
    blank_sprite_[8].setPosition(resolution.x / 2, resolution.y / 2 + 300);
    blank_sprite_[9].setPosition(resolution.x / 2 + 300, resolution.y / 2 + 300);
}

void tic_tac_toe::draw(sf::RenderWindow& window)
{
    window.draw(grid_sprite_);
    window.draw(instructions_);

    for (int i = 1; i < 10; i++)
    {
        window.draw(blank_sprite_[i]);
    }
}

void tic_tac_toe::turn(int mouse_x, int mouse_y)
{
    const sf::Vector2f mouseCoord(mouse_x, mouse_y);
    for (int i = 1; i < 10; i++)
    {
        if (blank_sprite_[i].getGlobalBounds().contains(mouseCoord) && blank_sprite_[i].getTexture() == &blank_)
        {
            if (is_x_turn_)
            {
                if (!is_winner_)
                {
                    blank_sprite_[i].setTexture(mark_x_);
                }

                if (check_winner(mark_x_))
                {
                    instructions_.setString("X - is Winner! Press R to Restart");
                    is_winner_ = true;
                    break;
                }
                if (is_draw_)
                {
                    instructions_.setString("It's Draw! Press R to Restart");
                    is_winner_ = true;
                    break;
                }
                is_x_turn_ = false;
                instructions_.setString("O - your turn.");
            }
            else
            {
                if (!is_winner_)
                {
                    blank_sprite_[i].setTexture(mark_o_);
                }
                if (check_winner(mark_o_))
                {
                    instructions_.setString("O - is Winner! Press R to Restart");
                    is_winner_ = true;
                    break;
                }
                else if (is_draw_)
                {
                    instructions_.setString("It's Draw! Press R to Restart");
                    is_winner_ = true;
                    break;
                }
                is_x_turn_ = true;
                instructions_.setString("X - your turn.");
            }
        }
    }
}

bool tic_tac_toe::check_winner(sf::Texture& mark)
{
    if (blank_sprite_[1].getTexture() == &mark && blank_sprite_[2].getTexture() == &mark && blank_sprite_[3].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[4].getTexture() == &mark && blank_sprite_[5].getTexture() == &mark && blank_sprite_[6].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[7].getTexture() == &mark && blank_sprite_[8].getTexture() == &mark && blank_sprite_[9].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[1].getTexture() == &mark && blank_sprite_[4].getTexture() == &mark && blank_sprite_[7].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[2].getTexture() == &mark && blank_sprite_[5].getTexture() == &mark && blank_sprite_[8].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[3].getTexture() == &mark && blank_sprite_[6].getTexture() == &mark && blank_sprite_[9].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[1].getTexture() == &mark && blank_sprite_[5].getTexture() == &mark && blank_sprite_[9].
        getTexture() == &mark)
        return true;
    else if (blank_sprite_[3].getTexture() == &mark && blank_sprite_[5].getTexture() == &mark && blank_sprite_[7].
        getTexture() == &mark)
        return true;
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (blank_sprite_[i].getTexture() == &blank_)
                return false;
        }

        is_draw_ = true;
        return false;
    }
}

void tic_tac_toe::restart()
{
    is_draw_ = false;
    is_x_turn_ = true;
    is_winner_ = false;
    instructions_.setString("X - Your first turn.");

    for (int i = 1; i < 10; i++)
    {
        blank_sprite_[i].setTexture(blank_);
    }
}
