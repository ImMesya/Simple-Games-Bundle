#pragma once
#include <SFML/Graphics.hpp>


#define MAX_MAIN_MENU 4

class MainMenu
{
public:
    MainMenu(float width, float height);

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int getChoice() const;

private:
    int main_menu_selected_ = 0;
    const float character_size_ = 70.0f;
    sf::Font font_;
    sf::Text main_menu_[MAX_MAIN_MENU];
};
