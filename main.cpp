#include <SFML/Graphics.hpp>
#include "games/RockPaperScissors.h"
#include "games/GuessTheNumber.h"
#include "games/TicTacToe.h"
#include "MainMenu.h"

enum GameChoice
{
    ROCK_PAPER_SCISSORS = 0,
    TIC_TAC_TOE = 1,
    GUESS_THE_NUMBER = 2,
    EXIT = 3
};

void handleMainMenuKeyPress(const sf::Event& event, MainMenu& mainMenu, sf::RenderWindow& window,
                            const sf::Vector2f& resolution);

void playRockPaperScissors(const sf::Vector2f& resolution);
void handleRPSKeyPress(const sf::Event& event, RockPaperScissors& game, const sf::Vector2f& resolution,
                       sf::RenderWindow& window);

void playTicTacToe(const sf::Vector2f& resolution);
void handleTTTKeyPress(const sf::Event& event, TicTacToe& game, sf::RenderWindow& window);

void playGuessTheNumber(const sf::Vector2f& resolution);
void handleGTNKeyPress(const sf::Event& event, GuessTheNumber& game, sf::RenderWindow& window);

int main()
{
    sf::Vector2f resolution;

    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow menuWindow(
        sf::VideoMode(resolution.x, resolution.y), "Simple Games Bundle");

    MainMenu mainMenu(resolution.x, resolution.y);

    while (menuWindow.isOpen())
    {
        sf::Event event;
        while (menuWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                menuWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                handleMainMenuKeyPress(event, mainMenu, menuWindow, resolution);
            }
        }

        menuWindow.clear();
        mainMenu.draw(menuWindow);
        menuWindow.display();
    }

    return 0;
}

void handleMainMenuKeyPress(const sf::Event& event, MainMenu& mainMenu, sf::RenderWindow& window,
                            const sf::Vector2f& resolution)
{
    if (event.key.code == sf::Keyboard::Up)
    {
        mainMenu.moveUp();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        mainMenu.moveDown();
    }
    else if (event.key.code == sf::Keyboard::Return)
    {
        const int choice = mainMenu.getChoice();
        switch (choice)
        {
        case ROCK_PAPER_SCISSORS:
            playRockPaperScissors(resolution);
            break;
        case TIC_TAC_TOE:
            playTicTacToe(resolution);
            break;
        case GUESS_THE_NUMBER:
            playGuessTheNumber(resolution);
            break;
        case EXIT:
            window.close();
            break;
        default:
            break;
        }
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
}

void playRockPaperScissors(const sf::Vector2f& resolution)
{
    RockPaperScissors game(resolution);

    sf::RenderWindow rpsWindow(
        sf::VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)),
        "Rock Paper Scissors");

    while (rpsWindow.isOpen())
    {
        sf::Event event;
        while (rpsWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                rpsWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                handleRPSKeyPress(event, game, resolution, rpsWindow);
            }
        }

        rpsWindow.clear();
        game.draw(rpsWindow);
        rpsWindow.display();
    }
}

void handleRPSKeyPress(const sf::Event& event, RockPaperScissors& game, const sf::Vector2f& resolution,
                       sf::RenderWindow& window)
{
    if (event.key.code == sf::Keyboard::Left)
    {
        game.moveLeft();
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
        game.moveRight();
    }
    else if (event.key.code == sf::Keyboard::Return)
    {
        game.rpsPressed(resolution);
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
}

void playTicTacToe(const sf::Vector2f& resolution)
{
    TicTacToe game(resolution);

    sf::RenderWindow tttWindow(
        sf::VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)), "Tic Tac Toe");

    while (tttWindow.isOpen())
    {
        sf::Event event;
        while (tttWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                tttWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                handleTTTKeyPress(event, game, tttWindow);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    game.turn(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        tttWindow.clear();
        game.draw(tttWindow);
        tttWindow.display();
    }
}

void handleTTTKeyPress(const sf::Event& event, TicTacToe& game, sf::RenderWindow& window)
{
    if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
    else if (event.key.code == sf::Keyboard::R)
    {
        game.restart();
    }
}

void playGuessTheNumber(const sf::Vector2f& resolution)
{
    GuessTheNumber game(resolution);

    sf::RenderWindow gtnWindow(
        sf::VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)),
        "Guess the Number");

    while (gtnWindow.isOpen())
    {
        sf::Event event;
        while (gtnWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gtnWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                handleGTNKeyPress(event, game, gtnWindow);
            }
        }

        gtnWindow.clear();
        game.draw(gtnWindow);
        gtnWindow.display();
    }
}

void handleGTNKeyPress(const sf::Event& event, GuessTheNumber& game, sf::RenderWindow& window)
{
    if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }
    else if (event.key.code == sf::Keyboard::Left)
    {
        game.moveLeft();
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
        game.moveRight();
    }
    else if (event.key.code == sf::Keyboard::Return)
    {
        game.playerGuess();
    }
}
