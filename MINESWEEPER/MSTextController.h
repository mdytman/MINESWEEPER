#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"


#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H


class MSTextController {
	MinesweeperBoard & boardX;
	MSBoardTextView & viewX;

public:
	MSTextController(MinesweeperBoard & bX, MSBoardTextView & vX);
	void play();
};


#endif 