#pragma once
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>

class ScoreView
{
	MinesweeperBoard & board; 
	sf::Font font1;
	sf::Text text1;
	sf::Font font2;
	sf::Text text2;
public:
	ScoreView(MinesweeperBoard & b);
	void draw(sf::RenderWindow &win);
};

