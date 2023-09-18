#include "MainMenu.h"

#include <iostream>

MainMenu::MainMenu(const float width, const float height)
{
    if (!font_.loadFromFile("fonts/JellyBomb.ttf"))
    {
        std::cout << "Font not found";
    }

    for (int i = 0; i < MAX_MAIN_MENU; i++)
    {
        main_menu_[i].setFont(font_);
        main_menu_[i].setFillColor(sf::Color::White);
        main_menu_[i].setCharacterSize(character_size_);
        if (i == 0)
        {
            main_menu_[i].setString("Rock Paper Scissors");
            main_menu_[i].setPosition(width / 2 - character_size_, height / 2 - (character_size_ * 2 - 50));
            main_menu_[i].setFillColor(sf::Color::Blue);
        }
        if (i == 1)
        {
            main_menu_[i].setString("Tic Tac Toe");
            main_menu_[i].setPosition(width / 2 - character_size_, height / 2 - (character_size_ - 50));
        }
        if (i == 2)
        {
            main_menu_[i].setString("Guess The Number");
            main_menu_[i].setPosition(width / 2 - character_size_, height / 2 + (character_size_ - 20));
        }
        if (i == 3)
        {
            main_menu_[i].setString("Exit");
            main_menu_[i].setPosition(width / 2 - character_size_, height / 2 + (character_size_ * 2 - 20));
        }
    }
}

void MainMenu::draw(sf::RenderWindow& window)
{
    for (const auto& i : main_menu_)
    {
        window.draw(i);
    }
}

void MainMenu::moveUp()
{
    main_menu_[main_menu_selected_].setFillColor(sf::Color::White);

    --main_menu_selected_;
    if (main_menu_selected_ == -1)
    {
        main_menu_selected_ = 3;
    }
    main_menu_[main_menu_selected_].setFillColor(sf::Color::Blue);
}

void MainMenu::moveDown()
{
    main_menu_[main_menu_selected_].setFillColor(sf::Color::White);

    ++main_menu_selected_;
    if (main_menu_selected_ == 4)
    {
        main_menu_selected_ = 0;
    }
    main_menu_[main_menu_selected_].setFillColor(sf::Color::Blue);
}

int MainMenu::getChoice() const
{
    return main_menu_selected_;
}
