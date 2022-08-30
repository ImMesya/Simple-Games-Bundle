#include "RockPaperScissors.h"

RockPaperScissors::RockPaperScissors(float width, float height)
{
	if (!rock.loadFromFile("images/rock_paper_scissors.png", 
		IntRect(spriteWidth*2, 0, spriteWidth, spriteHeight)))
	{
		cout << "No texture for Rock Paper Scissors!";
	}
	paper.loadFromFile("images/rock_paper_scissors.png",     
		IntRect(0, 0, spriteWidth, spriteHeight));
	scissors.loadFromFile("images/rock_paper_scissors.png",  
		IntRect(spriteWidth, 0, spriteWidth, spriteHeight));
	
	rockSprite.setTexture(rock);
	botRock.setTexture(rock);
	scissorsSprite.setTexture(scissors);
	botScissors.setTexture(scissors);
	paperSprite.setTexture(paper);
	botPaper.setTexture(paper);

	botRock.setOrigin(spriteWidth / 2, spriteHeight / 2);
	botPaper.setOrigin(spriteWidth / 2, spriteHeight / 2);
	botScissors.setOrigin(spriteWidth / 2, spriteHeight / 2);

	rockSprite.setPosition(width / 2 - spriteWidth * 3, height / 2);
	paperSprite.setPosition(width / 2, height / 2);
	scissorsSprite.setPosition(width / 2 + spriteWidth * 3, height / 2);
	botPaper.setPosition(-spriteWidth, -spriteHeight);
	botRock.setPosition(-spriteWidth, -spriteHeight);
	botScissors.setPosition(-spriteWidth, -spriteHeight);

	botPaper.setRotation(180);
	botRock.setRotation(180);
	botScissors.setRotation(180);

	rockSprite.setScale(2, 2);
	botRock.setScale(2, 2);
	paperSprite.setScale(2, 2);
	botPaper.setScale(2, 2);
	scissorsSprite.setScale(2, 2);
	botScissors.setScale(2, 2);

	srand(time(NULL));

	if (!font.loadFromFile("fonts/JellyBomb.ttf"))
	{
		cout << "Font not found";
	}

	stringstream ssPlayer;
	stringstream ssBot;
	

	winner.setFont(font);
	urWins.setFont(font);
	botWins.setFont(font);
	winner.setFillColor(Color::White);
	urWins.setFillColor(Color::White);
	botWins.setFillColor(Color::White);
	winner.setCharacterSize(characterSize);
	urWins.setCharacterSize(characterSize);
	botWins.setCharacterSize(characterSize);
	winner.setString("Choose one of the following options");
	ssPlayer << "Your wins - " << urWinsCount;
	urWins.setString(ssPlayer.str());
	ssBot << "Computer wins - " << botWinsCount;
	botWins.setString(ssBot.str());
	winner.setPosition(width / 2.5, height / 2.5);
	urWins.setPosition(20, 10);
	botWins.setPosition(20, 90);

	for (int i = 0; i < 3; i++)
	{
		textRPS[i].setFont(font);
		textRPS[i].setFillColor(Color::White);
		textRPS[i].setCharacterSize(characterSize);
		if (i == 0)
		{
			textRPS[i].setString("Rock");
			textRPS[i].setPosition(rockSprite.getPosition().x + characterSize / 2, rockSprite.getPosition().y + spriteHeight * 2);
			textRPS[i].setFillColor(Color::Blue);
		}
		if (i == 1)
		{
			textRPS[i].setString("Paper");
			textRPS[i].setPosition(paperSprite.getPosition().x + characterSize / 2, paperSprite.getPosition().y + spriteHeight * 2);
		}
		if (i == 2)
		{
			textRPS[i].setString("Scissors");
			textRPS[i].setPosition(scissorsSprite.getPosition().x + characterSize / 2, scissorsSprite.getPosition().y + spriteHeight * 2);
		}
	}
}

void RockPaperScissors::draw(RenderWindow& window)
{
	window.draw(rockSprite);
	window.draw(scissorsSprite);
	window.draw(paperSprite);
	window.draw(winner);
	window.draw(botPaper);
	window.draw(botRock);
	window.draw(botScissors);
	window.draw(urWins);
	window.draw(botWins);
	
	for (int i = 0; i < 3; i++)
	{
		window.draw(textRPS[i]);
	}

}

void RockPaperScissors::moveLeft()
{
	textRPS[RPSSelected].setFillColor(Color::White);

	RPSSelected--;
	if (RPSSelected == -1)
	{
		RPSSelected = 2;
	}
	textRPS[RPSSelected].setFillColor(Color::Blue);
}

void RockPaperScissors::moveRight()
{
	textRPS[RPSSelected].setFillColor(Color::White);

	RPSSelected++;
	if (RPSSelected == 3)
	{
		RPSSelected = 0;
	}
	textRPS[RPSSelected].setFillColor(Color::Blue);
}

void RockPaperScissors::RPSPressed(Vector2f resolution)
{
	int bot = rand() % 3;

	stringstream ssPlayer;
	stringstream ssBot;

	botRock.setPosition(-spriteWidth, -spriteHeight);
	botPaper.setPosition(-spriteWidth, -spriteHeight);
	botScissors.setPosition(-spriteWidth, -spriteHeight);

	if (bot == 1 && RPSSelected == 0) 
	{
		botWinsCount++;
		botPaper.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
		winner.setString("Computer Wins! Paper wraps Rock.");
		ssBot << "Computer wins - " << botWinsCount;
		botWins.setString(ssBot.str());
	}
	else if (bot == 2 && RPSSelected == 1)
	{
		botWinsCount++;
		botScissors.setPosition(resolution.x / 2 + spriteWidth/2, resolution.y / 4);
		winner.setString("Computer Wins! Scissors cut Paper.");
		ssBot << "Computer wins - " << botWinsCount;
		botWins.setString(ssBot.str());
	}
	else if (bot == 0 && RPSSelected == 2)
	{
		botWinsCount++;
		botRock.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
		winner.setString("Computer Wins! Rock smashes Scissors.");
		ssBot << "Computer wins - " << botWinsCount;
		botWins.setString(ssBot.str());
	}
	else if (RPSSelected == 0 && bot == 2) 
	{
		urWinsCount++;
		botScissors.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
		winner.setString("You Win! Rock smashes Scissors.");
		ssPlayer << "Your wins - " << urWinsCount;
		urWins.setString(ssPlayer.str());
	}
	else if (RPSSelected == 1 && bot == 0) 
	{
		urWinsCount++;
		botRock.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
		winner.setString("You Win! Paper wraps Rock.");
		ssPlayer << "Your wins - " << urWinsCount;
		urWins.setString(ssPlayer.str());
	}
	else if (RPSSelected == 2 && bot == 1) 
	{
		urWinsCount++;
		botPaper.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
		winner.setString("You Win! Scissors cut Paper.");
		ssPlayer << "Your wins - " << urWinsCount;
		urWins.setString(ssPlayer.str());
	}
	else 
	{
		switch (bot)
		{
		case 0:
			botRock.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
			break;
		case 1:
			botPaper.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
			break;
		case 2:
			botScissors.setPosition(resolution.x / 2 + spriteWidth / 2, resolution.y / 4);
			break;
		default:
			break;
		}
		winner.setString("Tie. Play again win the Game.");
	}

}