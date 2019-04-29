#pragma once
#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "MinesweeperBoard.h"

class MinesweeperController {
	
	bool finished = false;
	MinesweeperView & view;
	MinesweeperBoard & board;

public:
	explicit MinesweeperController(MinesweeperView & v, MinesweeperBoard & b); 
public:
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};
