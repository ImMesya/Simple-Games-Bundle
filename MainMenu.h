#pragma once
#include <SFML/Graphics.hpp>


#define MAX_MAIN_MENU 4

class main_menu
{
public:
    main_menu(float width, float height);

    void draw(sf::RenderWindow& window);
    void move_up();
    void move_down();

    int main_menu_pressed() const;

private:
    int main_menu_selected_ = 0;
    const float character_size_ = 70.0f;
    sf::Font font_;
    sf::Text main_menu_[MAX_MAIN_MENU];
};
