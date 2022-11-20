#include "MainMenu.h"
#include "games/RockPaperScissors.h"
#include "games/GuessTheNumber.h"
#include "games/TicTacToe.h"

int main()
{
    Vector2f resolution;

    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow menu_window(VideoMode(resolution.x, resolution.y), "Simple Games Bundle");

    main_menu main_menu(resolution.x, resolution.y);
    View main_view(FloatRect(0, 0, resolution.x, resolution.y));

    while (menu_window.isOpen())
    {
        Event event;

        while (menu_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                menu_window.close();
            }

            else if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Up)
                {
                    main_menu.move_up();
                }

                else if (event.key.code == Keyboard::Down)
                {
                    main_menu.move_down();
                }

                else if (event.key.code == Keyboard::Return)
                {
                    // If player choose Rock Paper Scissors game
                    if (main_menu.main_menu_pressed() == 0)
                    {
                        RockPaperScissors rockPaperScissors(resolution.x, resolution.y);
                        RenderWindow RPS(VideoMode(resolution.x, resolution.y), "Rock Paper Scissors");
                        while (RPS.isOpen())
                        {
                            Event eventRPS;
                            while (RPS.pollEvent(eventRPS))
                            {
                                if (eventRPS.type == Event::Closed)
                                    RPS.close();
                                else if (eventRPS.type == Event::KeyPressed)
                                    if (eventRPS.key.code == Keyboard::Left)
                                    {
                                        rockPaperScissors.moveLeft();
                                    }

                                    else if (eventRPS.key.code == Keyboard::Right)
                                    {
                                        rockPaperScissors.moveRight();
                                    }

                                    else if (eventRPS.key.code == Keyboard::Return)
                                    {
                                        rockPaperScissors.RPSPressed(resolution);
                                    }

                                    else if (eventRPS.key.code == Keyboard::Escape)
                                    {
                                        RPS.close();
                                    }
                            }

                            RPS.clear();
                            rockPaperScissors.draw(RPS);
                            RPS.display();
                        }
                    }

                    // If player choose Tic Tac Toe game
                    else if (main_menu.main_menu_pressed() == 1)
                    {
                        TicTacToe ticTacToe(resolution);
                        RenderWindow TTT(VideoMode(resolution.x, resolution.y), "Tic Tac Toe");
                        while (TTT.isOpen())
                        {
                            Event eventTTT;
                            while (TTT.pollEvent(eventTTT))
                            {
                                if (eventTTT.type == Event::Closed)
                                {
                                    TTT.close();
                                }

                                else if (eventTTT.type == Event::KeyPressed)
                                {
                                    if (eventTTT.key.code == Keyboard::Escape)
                                    {
                                        TTT.close();
                                    }
                                    else if (eventTTT.key.code == Keyboard::R)
                                    {
                                        ticTacToe.restart();
                                    }
                                }
                                else if (eventTTT.type == Event::MouseButtonPressed)
                                {
                                    if (eventTTT.mouseButton.button == Mouse::Left)
                                    {
                                        ticTacToe.turn(eventTTT.mouseButton.x, eventTTT.mouseButton.y);
                                    }
                                }
                            }
                            TTT.clear();
                            ticTacToe.draw(TTT);
                            TTT.display();
                        }
                    }

                    // If player choose Guess The Number game
                    else if (main_menu.main_menu_pressed() == 2)
                    {
                        guess_the_number guessTheNum(resolution);
                        RenderWindow GtN(VideoMode(resolution.x, resolution.y), "Guess the Number");
                        while (GtN.isOpen())
                        {
                            Event eventGtN;
                            while (GtN.pollEvent(eventGtN))
                            {
                                if (eventGtN.type == Event::Closed)
                                {
                                    GtN.close();
                                }

                                else if (eventGtN.type == Event::KeyPressed)
                                {
                                    if (eventGtN.key.code == Keyboard::Escape)
                                    {
                                        GtN.close();
                                    }
                                    else if (eventGtN.key.code == Keyboard::Left)
                                    {
                                        guessTheNum.move_left();
                                    }
                                    else if (eventGtN.key.code == Keyboard::Right)
                                    {
                                        guessTheNum.move_right();
                                    }
                                    else if (eventGtN.key.code == Keyboard::Return)
                                    {
                                        guessTheNum.player_guess();
                                    }
                                }
                            }
                            GtN.clear();
                            guessTheNum.draw(GtN);
                            GtN.display();
                        }
                    }

                    // If player choose EXIT button
                    else if (main_menu.main_menu_pressed() == 3)
                    {
                        menu_window.close();
                    }
                }

                else if (event.key.code == Keyboard::Escape)
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
