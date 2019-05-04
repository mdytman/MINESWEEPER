#include "pch.h"
#include "IntroView.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>


IntroView::IntroView()
{
	//font1
	if (!font1.loadFromFile("diediedie.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text1.setFont(font1);

	//font2
	if (!font2.loadFromFile("courier-new.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text2.setFont(font2);

	//fields
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			rect[i][j].setSize(sf::Vector2f(150, 40));
			rect[i][j].setFillColor(sf::Color(143, 138, 129));
		}
	}

	//start
	start.setRadius(170);
	start.setFillColor(sf::Color(143, 138, 129));
	start.setPosition(700, 400);

}

void IntroView::startOutline()
{
	start.setOutlineThickness(10);
	start.setOutlineColor(sf::Color(129, 17, 17));
}


void IntroView::rectOutline(int posX, int posY, bool tmp)
{
	{
		if (tmp == true)
		{
			rect[posX][posY].setOutlineThickness(10);
			rect[posX][posY].setOutlineColor(sf::Color(129, 17, 17));
		}
		if (tmp == false)
		{
			rect[posX][posY].setOutlineThickness(10);
			rect[posX][posY].setOutlineColor(sf::Color::Black);
		}
	}
}



void IntroView::draw(sf::RenderWindow &win)
{
	//"SAPER"
	text1.setCharacterSize(100);
	text1.setStyle(sf::Text::Regular);

	text1.setString("SAPER");
	text1.setPosition(400, 10);
	text1.setFillColor(sf::Color::Red);

	win.draw(text1);

	//name
	text2.setCharacterSize(15);
	text2.setStyle(sf::Text::Regular);
	text2.setFillColor(sf::Color::White);

	text2.setString("Dytman Marta, 249046");
	text2.setPosition(550, 125);

	win.draw(text2);

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			rect[i][j].setPosition(40 + j * 200, 400 + i * 100);
			win.draw(rect[i][j]);
		}
	}

	//text on fields
	text2.setFillColor(sf::Color::Black);
	text2.setCharacterSize(30);

	text2.setString("10x10");
	text2.setPosition(65, 400);
	win.draw(text2);

	text2.setString("20x15");
	text2.setPosition(265, 400);
	win.draw(text2);

	text2.setString("30x20");
	text2.setPosition(465, 400);
	win.draw(text2);

	text2.setString("EASY");
	text2.setPosition(70, 500);
	win.draw(text2);

	text2.setString("NORMAL");
	text2.setPosition(255, 500);
	win.draw(text2);

	text2.setString("HARD");
	text2.setPosition(475, 500);
	win.draw(text2);

	//start
	win.draw(start);

	text1.setString("START");
	text1.setPosition(705, 500);

	win.draw(text1);
}
