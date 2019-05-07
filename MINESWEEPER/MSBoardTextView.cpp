//#include "pch.h"
#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b) : boardx(b) {}

void MSBoardTextView::display() const
{
	std::cout << "X ";
	for (int k = 0; k < boardx.getBoardWidth(); k++)
	{
		std::cout << " " << k << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < boardx.getBoardHeight(); i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < boardx.getBoardWidth(); j++)
		{
			std::cout << "[" << boardx.getFieldInfo(i, j) << "]";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
