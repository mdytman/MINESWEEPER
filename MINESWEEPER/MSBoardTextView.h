#include "MinesweeperBoard.h"

#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H


class MSBoardTextView 
{
	MinesweeperBoard &boardx;
public:
	explicit MSBoardTextView(MinesweeperBoard &b);
	void display() const;

};


#endif
