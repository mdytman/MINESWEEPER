#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "MinesweeperBoard.h"

class IntroController {
	bool finished = false;
	IntroView & view;
	MinesweeperBoard & board;
	int bx;
	int by; 
	GameMode bMode;
	
public:
	explicit IntroController(IntroView & iv, MinesweeperBoard & b);
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	int getBx() const;
	int getBy() const;
	GameMode getBMode() const;
	bool isFinished() const { return finished; }
};
