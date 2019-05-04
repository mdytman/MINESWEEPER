#include "pch.h"
#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

MSTextController::MSTextController(MinesweeperBoard & bX, MSBoardTextView & vX) : boardX(bX), viewX(vX)
{

}

void MSTextController::play()
{
	int row, column;

	char action;

	int tmp = 1;

	do
	{
		viewX.display();
		std::cout << "row: ";
		std::cin >> row;
		std::cout << "column: ";
		std::cin >> column;
		std::cout << "action: ";
		std::cin >> action;

		if (action == 'r')
		{
			boardX.revealField(column, row);
		}
		if (action == 'f')
		{
			boardX.toggleFlag(column, row);
		}
		tmp++;

	} while (boardX.getGameState() == RUNNING);

	if (boardX.getGameState() == FINISHED_LOSS)
	{
		std::cout << "Game over " << std::endl;
	}

	if (boardX.getGameState() == FINISHED_WIN)
	{
		std::cout << "Congrats " << std::endl;
	}

}