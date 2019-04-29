//#include "pch.h"
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
	text1.setPosition(150, 200);
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
	
	//end or play again button
	if (!font3.loadFromFile("courier-new.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}


	text3.setFont(font3);
	text3.setCharacterSize(20);
	text3.setStyle(sf::Text::Regular);
	text3.setString("press space to close the window");
	text3.setFillColor(sf::Color::White);
	text3.setPosition(360, 550);

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
	
	win.draw(text3);
	
}
