#include "TicTacToe.h"

TicTacToe::TicTacToe(Vector2f resolution)
{
	if (!font.loadFromFile("fonts/JellyBomb.ttf"))
	{
		cout << "Font not found";
	}

	if (!grid.loadFromFile("images/ttt_grid.png"))
	{
		cout << "No texture grid";
	}
	if (!markX.loadFromFile("images/ttt_x.png"))
	{
		cout << "No texture mark_x";
	}
	if (!markO.loadFromFile("images/ttt_o.png"))
	{
		cout << "No texture mark_o";
	}
	if (!blank.loadFromFile("images/ttt_blank.png"))
	{
		cout << "No texture blank";
	}

	instructions.setFont(font);
	instructions.setCharacterSize(70);
	instructions.setString("X - Your first turn.");
	instructions.setOrigin(instructions.getLocalBounds().width / 2, instructions.getLocalBounds().height / 2);
	instructions.setPosition(resolution.x / 2, resolution.y / 8);
	
	gridSprite.setTexture(grid);
	gridSprite.setPosition(resolution.x / 2, resolution.y / 2);
	gridSprite.setOrigin(gridSprite.getLocalBounds().width / 2, gridSprite.getLocalBounds().height / 2);
	gridSprite.setScale(2, 2);

	for (int i = 1; i < 10; i++)
	{
		blankSprite[i].setTexture(blank);
		blankSprite[i].setOrigin
		(
			blankSprite[i].getLocalBounds().width / 2, 
			blankSprite[i].getLocalBounds().height / 2
		);
		blankSprite[i].setScale(2, 2);
	}
	blankSprite[1].setPosition(resolution.x / 2 - 300, resolution.y / 2 - 300);
	blankSprite[2].setPosition(resolution.x / 2, resolution.y / 2 - 300);
	blankSprite[3].setPosition(resolution.x / 2 + 300, resolution.y / 2 - 300);
	blankSprite[4].setPosition(resolution.x / 2 - 300, resolution.y / 2);
	blankSprite[5].setPosition(resolution.x / 2, resolution.y / 2);
	blankSprite[6].setPosition(resolution.x / 2 + 300, resolution.y / 2);
	blankSprite[7].setPosition(resolution.x / 2 - 300, resolution.y / 2 + 300);
	blankSprite[8].setPosition(resolution.x / 2, resolution.y / 2 + 300);
	blankSprite[9].setPosition(resolution.x / 2 + 300, resolution.y / 2 + 300);

}

void TicTacToe::draw(RenderWindow& window)
{
	window.draw(gridSprite);
	window.draw(instructions);

	for (int i = 1; i < 10; i++)
	{
		window.draw(blankSprite[i]);
	}
}

void TicTacToe::turn(int mouseX, int mouseY)
{
	Vector2f mouseCoord(mouseX, mouseY);
	for (int i = 1; i < 10; i++)
	{
		if (blankSprite[i].getGlobalBounds().contains(mouseCoord) && blankSprite[i].getTexture() == &blank)
		{
			if (isXTurn)
			{
				if (!isWinner)
				{
					blankSprite[i].setTexture(markX);
				}
				
				if (checkWinner(markX))
				{
					instructions.setString("X - is Winner! Press R to Restart");
					isWinner = true;
					break;
				}
				else if (isDraw)
				{
					instructions.setString("It's Draw! Press R to Restart");
					isWinner = true;
					break;
				}
				isXTurn = false;
				instructions.setString("O - your turn.");
			}
			else
			{
				if (!isWinner)
				{
					blankSprite[i].setTexture(markO);
				}
				if (checkWinner(markO))
				{
					instructions.setString("O - is Winner! Press R to Restart");
					isWinner = true;
					break;
				}
				else if (isDraw)
				{
					instructions.setString("It's Draw! Press R to Restart");
					isWinner = true;
					break;
				}
				isXTurn = true;
				instructions.setString("X - your turn.");
			}
			
		}
		
	}
	
}

bool TicTacToe::checkWinner(Texture& mark)
{
	if (blankSprite[1].getTexture() == &mark && blankSprite[2].getTexture() == &mark && blankSprite[3].getTexture() == &mark)
		return true;
	else if (blankSprite[4].getTexture() == &mark && blankSprite[5].getTexture() == &mark && blankSprite[6].getTexture() == &mark)
		return true;
	else if (blankSprite[7].getTexture() == &mark && blankSprite[8].getTexture() == &mark && blankSprite[9].getTexture() == &mark)
		return true;
	else if (blankSprite[1].getTexture() == &mark && blankSprite[4].getTexture() == &mark && blankSprite[7].getTexture() == &mark)
		return true;
	else if (blankSprite[2].getTexture() == &mark && blankSprite[5].getTexture() == &mark && blankSprite[8].getTexture() == &mark)
		return true;
	else if (blankSprite[3].getTexture() == &mark && blankSprite[6].getTexture() == &mark && blankSprite[9].getTexture() == &mark)
		return true;
	else if (blankSprite[1].getTexture() == &mark && blankSprite[5].getTexture() == &mark && blankSprite[9].getTexture() == &mark)
		return true;
	else if (blankSprite[3].getTexture() == &mark && blankSprite[5].getTexture() == &mark && blankSprite[7].getTexture() == &mark)
		return true;
	else
	{
		for (int i = 1; i < 10; i++)
		{
			if (blankSprite[i].getTexture() == &blank)
				return false;
		}
			
		isDraw = true;
		return false;
	}
}

void TicTacToe::restart()
{
	isDraw = false;
	isXTurn = true;
	isWinner = false;
	instructions.setString("X - Your first turn.");

	for (int i = 1; i < 10; i++)
	{
		blankSprite[i].setTexture(blank);
	}
}