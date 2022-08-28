#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class TicTacToe 
{
public:
	TicTacToe(Vector2f resolution);

	void draw(RenderWindow& window);

	void turn(int mouseX, int mouseY);
	void restart();
	bool checkWinner(Texture &mark);

private:
	Texture grid;
	Texture markX;
	Texture markO;
	Texture blank;

	Sprite gridSprite;
	Sprite blankSprite[10];

	bool isXTurn = true;
	bool isDraw = false;
	bool isWinner = false;

	Text instructions;
	Font font;
};