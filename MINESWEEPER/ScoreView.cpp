#include "pch.h"
#include "ScoreView.h"
#include "MinesweeperBoard.h"


ScoreView::ScoreView(MinesweeperBoard & b) : board(b)
{
	//FINISHED_LOSS
	if (!font1.loadFromFile("diediedie.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text1.setFont(font1);
	text1.setCharacterSize(170);
	text1.setStyle(sf::Text::Regular);
	text1.setString("GAME OVER");
	text1.setPosition(150, 300);
	text1.setFillColor(sf::Color::Red);

	//FINISHED_WIN
	if (!font2.loadFromFile("cleopatra.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text2.setFont(font2);
	text2.setCharacterSize(100);
	text2.setStyle(sf::Text::Regular);
	text2.setString("Congratulations!");
	text2.setPosition(180, 200);
	text2.setFillColor(sf::Color::Red);
	//you have the fastest time for this difficulty level, please enter your name

}
void ScoreView::draw(sf::RenderWindow &win)
{
	if (board.getGameState() == FINISHED_LOSS)
	{
		win.draw(text1);
	}
	if (board.getGameState() == FINISHED_WIN)
	{
		win.draw(text2);
	}
}
