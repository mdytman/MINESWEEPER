//#include "pch.h"
#include "GameManager.h"

GameManager::GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc)
	: introController(ic), minesweeperController(mc), scoreController(sc)
{
	state = INTRO;
}

void GameManager::updateState() {
	
	switch (state) {
	case INTRO:
		if (introController.isFinished())
		{
			state = GAME;
		}
			
		break;
	case GAME:
		if (minesweeperController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		break;
	}
}

void GameManager::handleEvent(sf::Event &event)
{
	switch (state) {
	case INTRO:
		introController.handleEvent(event);
		break;
	case GAME:
		minesweeperController.handleEvent(event);
		//Sleep(3000);
		break;
	case SCORE:
		scoreController.handleEvent(event);
		break;
	}
	updateState();
}

void GameManager::draw(sf::RenderWindow &win) 
{
	switch (state) {
	case INTRO:
		introController.draw(win);
		break;
	case GAME:
		minesweeperController.draw(win);
		break;
	case SCORE:
		scoreController.draw(win);
		if (scoreController.isFinished())
			win.close();
		break;
	}
}