//#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MinesweeperView.h"
#include "MSBoardTextView.h"
#include "IntroView.h"
#include "IntroController.h"
#include "MinesweeperController.h"
#include "ScoreView.h"
#include "MinesweeperBoard.h"
#include "ScoreController.h"
#include "GameManager.h"



int main()
{
	MinesweeperBoard b(30, 20, HARD);
	
	MSBoardTextView tView(b);
	tView.display();
	
	IntroView iv;
	IntroController ic(iv, b);
	
	MinesweeperView mv(b);
	MinesweeperController mc(mv, b);
	
	ScoreView sv(b);
	ScoreController sc(sv);

	GameManager gm(ic, mc, sc);

	sf::RenderWindow w{ sf::VideoMode{1100, 800}, "MINESWEEPER" };

	w.setFramerateLimit(60);
	sf::Event event;

	while (w.isOpen()) {
		
		sf::Event event;
		while (w.pollEvent(event)) {
		
			if (event.type == sf::Event::Closed)
				w.close();

			gm.handleEvent(event);

		}

		w.clear();

		gm.draw(w);
		
		w.display();
	}

	return 0;
}