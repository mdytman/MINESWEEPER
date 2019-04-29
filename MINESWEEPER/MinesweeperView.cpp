#include "pch.h"
#include "MinesweeperView.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>


MinesweeperView::MinesweeperView(MinesweeperBoard & b) : board(b) 
{

}

void MinesweeperView::draw(sf::RenderWindow & win)
{


	int h = board.getBoardHeight() + 1;
	int w = board.getBoardWidth() + 1;
	float x0 = 35;
	float y0 = 35;

	//horizontal lines 
	sf::VertexArray lines(sf::Lines);
	for (int i = 0; i < h; ++i)
	{
		lines.append(sf::Vector2f(x0, y0 + i * y0));
		lines.append(sf::Vector2f(x0*w, y0 + i * y0));
	}

	//vertical lines
	for (int j = 0; j < w; ++j)
	{
		lines.append(sf::Vector2f(x0 + x0 * j, y0));
		lines.append(sf::Vector2f(x0 + x0 * j, y0*h));
	}

	//unrevealed fields
	sf::RectangleShape squares(sf::Vector2f(35, 35));

	//mines
	sf::CircleShape mines(10);
	mines.setOrigin(mines.getRadius(), mines.getRadius());

	//flags
	sf::CircleShape flags(10, 3);
	float fX = 10;
	float fY = 17 / 2;
	flags.setOrigin(fX, fY);
	flags.setRotation(90);

	// Declare a new font
	sf::Font font;
	if (!font.loadFromFile("arial-black.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	// Create a text which uses our font
	sf::Text text1;
	text1.setFont(font);
	text1.setCharacterSize(30);
	text1.setStyle(sf::Text::Regular);
	text1.setOrigin(-6, 2);

	for (int k1 = 0; k1 < board.getBoardHeight(); ++k1)
	{
		for (int k2 = 0; k2 < board.getBoardWidth(); ++k2)
		{
			squares.setFillColor(sf::Color(98, 98, 98));
			squares.setPosition(x0 + k2 * x0, y0 + k1 * y0);
			win.draw(squares);
			if (board.getFieldInfo(k1, k2) == '_')
			{
				squares.setFillColor(sf::Color(161, 161, 161));
				squares.setPosition(x0 + k2 * x0, y0 + k1 * y0);
				win.draw(squares);
			}
			if (board.getFieldInfo(k1, k2) == 'x')
			{
				mines.setFillColor(sf::Color::Black);
				mines.setPosition(3 * x0 / 2 + k2 * x0, 3 * y0 / 2 + k1 * y0);
				win.draw(mines);
			}
			if (board.getFieldInfo(k1, k2) == 'F')
			{
				flags.setFillColor(sf::Color::Yellow);
				flags.setPosition(3 * x0 / 2 + k2 * x0, 3 * y0 / 2 + k1 * y0);
				win.draw(flags);
			}
			if (board.getFieldInfo(k1, k2) > '0' && board.getFieldInfo(k1, k2) <= '9')
			{
				text1.setString(board.getFieldInfo(k1, k2));
				text1.setFillColor(sf::Color::Red);
				text1.setPosition(x0 + k2 * x0, y0 + k1 * y0);
				win.draw(text1);
			}


		}
	}

	win.draw(lines);
}
