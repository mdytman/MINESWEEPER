#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"


class MinesweeperView
{
	MinesweeperBoard & board;
public:
	MinesweeperView(MinesweeperBoard & b);
	void draw(sf::RenderWindow & win);

};

