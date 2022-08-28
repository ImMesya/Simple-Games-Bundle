#include "TicTacToe.h"

TicTacToe::TicTacToe(Vector2f resolution)
{
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
				blankSprite[i].setTexture(markX);
				if (checkWinner(markX))
				{
					cout << "MARK_X is Winner!" << endl;
				}
				else if (isDraw)
				{
					cout << "It's Draw! Press R to Restart" << endl;
				}
				isXTurn = false;
			}
			else
			{
				blankSprite[i].setTexture(markO);
				if (checkWinner(markO))
				{
					cout << "MARK_O is Winner!" << endl;
				}
				else if (isDraw)
				{
					cout << "It's Draw! Press R to Restart" << endl;
				}
				isXTurn = true;
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

	for (int i = 1; i < 10; i++)
	{
		blankSprite[i].setTexture(blank);
	}
}