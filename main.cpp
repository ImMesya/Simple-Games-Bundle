#include "MainMenu.h"
#include "games/RockPaperScissors.h"
#include "games/GuessTheNumber.h"
#include "games/TicTacToe.h"

int main()
{
    sf::Vector2f resolution;

    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow menu_window(sf::VideoMode(resolution.x, resolution.y), "Simple Games Bundle");

    main_menu main_menu(resolution.x, resolution.y);

    while (menu_window.isOpen())
    {
        sf::Event event;

        while (menu_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                menu_window.close();
            }

            else if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Up)
                {
                    main_menu.move_up();
                }

                else if (event.key.code == sf::Keyboard::Down)
                {
                    main_menu.move_down();
                }

                else if (event.key.code == sf::Keyboard::Return)
                {
                    // If player choose Rock Paper Scissors game
                    if (main_menu.main_menu_pressed() == 0)
                    {
                        rock_paper_scissors rock_paper_scissors(resolution.x, resolution.y);
                        sf::RenderWindow rps(sf::VideoMode(resolution.x, resolution.y), "Rock Paper Scissors");
                        while (rps.isOpen())
                        {
                            sf::Event event_rps;
                            while (rps.pollEvent(event_rps))
                            {
                                if (event_rps.type == sf::Event::Closed)
                                    rps.close();
                                else if (event_rps.type == sf::Event::KeyPressed)
                                    if (event_rps.key.code == sf::Keyboard::Left)
                                    {
                                        rock_paper_scissors.move_left();
                                    }

                                    else if (event_rps.key.code == sf::Keyboard::Right)
                                    {
                                        rock_paper_scissors.move_right();
                                    }

                                    else if (event_rps.key.code == sf::Keyboard::Return)
                                    {
                                        rock_paper_scissors.rps_pressed(resolution);
                                    }

                                    else if (event_rps.key.code == sf::Keyboard::Escape)
                                    {
                                        rps.close();
                                    }
                            }

                            rps.clear();
                            rock_paper_scissors.draw(rps);
                            rps.display();
                        }
                    }

                    // If player choose Tic Tac Toe game
                    else if (main_menu.main_menu_pressed() == 1)
                    {
                        tic_tac_toe tic_tac_toe(resolution);
                        sf::RenderWindow ttt(sf::VideoMode(resolution.x, resolution.y), "Tic Tac Toe");
                        while (ttt.isOpen())
                        {
                            sf::Event event_ttt;
                            while (ttt.pollEvent(event_ttt))
                            {
                                if (event_ttt.type == sf::Event::Closed)
                                {
                                    ttt.close();
                                }

                                else if (event_ttt.type == sf::Event::KeyPressed)
                                {
                                    if (event_ttt.key.code == sf::Keyboard::Escape)
                                    {
                                        ttt.close();
                                    }
                                    else if (event_ttt.key.code == sf::Keyboard::R)
                                    {
                                        tic_tac_toe.restart();
                                    }
                                }
                                else if (event_ttt.type == sf::Event::MouseButtonPressed)
                                {
                                    if (event_ttt.mouseButton.button == sf::Mouse::Left)
                                    {
                                        tic_tac_toe.turn(event_ttt.mouseButton.x, event_ttt.mouseButton.y);
                                    }
                                }
                            }
                            ttt.clear();
                            tic_tac_toe.draw(ttt);
                            ttt.display();
                        }
                    }

                    // If player choose Guess The Number game
                    else if (main_menu.main_menu_pressed() == 2)
                    {
                        guess_the_number guess_the_num(resolution);
                        sf::RenderWindow gtn(sf::VideoMode(resolution.x, resolution.y), "Guess the Number");
                        while (gtn.isOpen())
                        {
                            sf::Event event_gtn;
                            while (gtn.pollEvent(event_gtn))
                            {
                                if (event_gtn.type == sf::Event::Closed)
                                {
                                    gtn.close();
                                }

                                else if (event_gtn.type == sf::Event::KeyPressed)
                                {
                                    if (event_gtn.key.code == sf::Keyboard::Escape)
                                    {
                                        gtn.close();
                                    }
                                    else if (event_gtn.key.code == sf::Keyboard::Left)
                                    {
                                        guess_the_num.move_left();
                                    }
                                    else if (event_gtn.key.code == sf::Keyboard::Right)
                                    {
                                        guess_the_num.move_right();
                                    }
                                    else if (event_gtn.key.code == sf::Keyboard::Return)
                                    {
                                        guess_the_num.player_guess();
                                    }
                                }
                            }
                            gtn.clear();
                            guess_the_num.draw(gtn);
                            gtn.display();
                        }
                    }

                    // If player choose EXIT button
                    else if (main_menu.main_menu_pressed() == 3)
                    {
                        menu_window.close();
                    }
                }

                else if (event.key.code == sf::Keyboard::Escape)
                {
                    menu_window.close();
                }
        }
        menu_window.clear();
        main_menu.draw(menu_window);
        menu_window.display();
    }
    return 0;
}
