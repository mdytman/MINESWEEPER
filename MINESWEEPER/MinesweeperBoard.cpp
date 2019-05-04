#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode m) : width(w), height(h), mode(m)
{
	resetBoard(width, height, mode);
}

void MinesweeperBoard::resetBoard(int W, int H, GameMode M)
{
	width = W;
	height = H;
	mode = M;
	this->state = RUNNING;

	for (int i1 = 0; i1 < height; i1++)
		for (int j1 = 0; j1 < width; j1++)
		{
			board[i1][j1].isRevealed = 0;
			board[i1][j1].hasMine = 0;
			board[i1][j1].hasFlag = 0;
		}

	if (mode != DEBUG)
	{

		switch (mode)
		{
		case EASY:

			setMines(0.1);

			break;

		case NORMAL:

			setMines(0.2);

			break;

		case HARD:

			setMines(0.3);

			break;

		default:
			break;
		}
	}
	if (mode == DEBUG)
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < height; i++)
		{
			for (int ij = 0; ij < width; ij++)
			{
				board[x][ij].hasMine = 1;
				if (i < height)
				{
					board[i][i].hasMine = 1;
				}
				if (i % 2 == 0)
				{
					board[i][x].hasMine = 1;
				}
			}

		}
		

	}
}

void MinesweeperBoard::setMines(double part)
{
	int minedFields = 0;
	minedFields = part * width*height;
	int x = 0;
	int y = 0;

	for (int m1 = 0; m1 < minedFields; m1++)
	{
		do
		{
			x = rand() % height;
			y = rand() % width;

		} while (board[x][y].hasMine == 1);

		board[x][y].hasMine = 1;
	}


}

void MinesweeperBoard::debug_display() const
{
	for (int k = 0; k < height; k++)
	{
		for (int n = 0; n < width; n++)
		{
			std::cout << "[";
			if (board[k][n].hasMine == 1)
			{
				std::cout << 'M';
			}
			else
			{
				std::cout << '.';
			}

			if (board[k][n].isRevealed == 1)
			{
				std::cout << 'o';
			}
			else
			{
				std::cout << '.';
			}

			if (board[k][n].hasFlag == 1)
			{
				std::cout << 'f';
			}
			else
			{
				std::cout << '.';
			}

			std::cout << "]";


		}
		std::cout << std::endl;

	}
}

int MinesweeperBoard::getBoardWidth() const
{
	return width;
}
int MinesweeperBoard::getBoardHeight() const
{
	return height;
}
int MinesweeperBoard::getMineCount() const
{
	int minesAmount = 0;
	for (int ax = 0; ax < height; ax++)
	{
		for (int ay = 0; ay < width; ay++)
		{
			if (board[ax][ay].hasMine == 1)
			{
				minesAmount++;
			}
		}
	}
	return minesAmount;
}

int MinesweeperBoard::countMines(int k, int w) const
{
	if (board[k][w].isRevealed == 0)
	{
		return -1;
	}

	if ((k < 0) || (k >= height) || (w < 0) || (w >= width))
	{
		return -1;
	}

	int minesAround = 0;

	if ((w != 0) && (k != 0) && (board[k - 1][w - 1].hasMine == true))
	{
		minesAround++;
	}
	if ((w != 0) && (board[k][w - 1].hasMine == true))
	{
		minesAround++;
	}
	if ((w != 0) && (k != height - 1) && (board[k + 1][w - 1].hasMine == true))
	{
		minesAround++;
	}
	if ((k != 0) && (board[k - 1][w].hasMine == true))
	{
		minesAround++;
	}
	if ((k != height - 1) && (board[k + 1][w].hasMine == true))
	{
		minesAround++;
	}
	if ((w != width - 1) && (k != 0) && (board[k - 1][w + 1].hasMine == true))
	{
		minesAround++;
	}
	if ((w != width - 1) && (board[k][w + 1].hasMine == true))
	{
		minesAround++;
	}
	if ((w != width - 1) && (k != height - 1) && (board[k + 1][w + 1].hasMine == true))
	{
		minesAround++;
	}
	return minesAround;
}




bool MinesweeperBoard::hasFlag(int x, int y) const
{
	if ((x >= height || y >= width) || (board[x][y].hasFlag == 0) || (board[x][y].isRevealed == 1))
	{
		return false;
	}
	if (board[x][y].hasFlag == 1)
	{
		return true;
	}

}

bool MinesweeperBoard::hasMine(int x, int y) const
{
	if ((x >= height || y >= width) || (board[x][y].hasMine == false) || (board[x][y].isRevealed == true))
	{
		return false;
	}
	if (board[x][y].hasMine == true)
	{
		return true;
	}
}

void MinesweeperBoard::revealField(int x, int y)
{
	static unsigned int callCount = 0;

	if ((board[x][y].isRevealed == 1) || (x >= height || y >= width) || (state == FINISHED_WIN) || (board[x][y].hasFlag == 1))
	{
		return;
	}
	else
	{
		if (board[x][y].isRevealed == 0 && board[x][y].hasMine == 0)
		{
			board[x][y].isRevealed = true;
			
			if (countMines(x, y) == 0)
			{
				
					if ((y != 0) && (x != 0) )
					{
						revealField(x - 1, y - 1);
					}
					if ((y != 0))
					{
						revealField(x, y - 1);
					}
					if ((y != 0) && (x != height - 1))
					{
						revealField(x + 1, y - 1);
					}
					if ((x != 0))
					{
						revealField(x - 1, y);
					}
					if ((x != height - 1))
					{
						revealField(x + 1, y);
					}
					if ((y != width - 1) && (x != 0))
					{
						revealField(x - 1, y + 1);
					}
					if ((y != width - 1))
					{
						revealField(x, y + 1);
					}
					if ((y != width - 1) && (x != height - 1))
					{
						revealField(x + 1, y + 1);
					}
				
			}
						
		}
		if (board[x][y].isRevealed == 0 && board[x][y].hasMine == 1)
		{
			if (callCount == 0 && mode != DEBUG)
			{
				board[x][y].hasMine = 0;
				int px = 0;
				int py = 0;
				do {
					px = rand() % height;
					py = rand() % width;
				} while (px == x && py == y || board[px][py].hasMine == 1);
				board[px][py].hasMine = 1;
			}
			if (callCount > 1)
			{
				board[x][y].isRevealed = 1;
				state = FINISHED_LOSS;
			}
		}
	}
	callCount++;
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
	if (board[x][y].isRevealed == 0)
	{
		board[x][y].hasFlag = 1;
	}
	if ((board[x][y].isRevealed == 1) || (x >= height || y >= width) || (state == FINISHED_WIN || state == FINISHED_LOSS))
	{
		return;
	}
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
	if (board[x][y].isRevealed == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

GameState MinesweeperBoard::getGameState() const
{
	int flags = 0;
	int flagsOnMine = 0;
	int fieldsWithoutMine = 0;
	fieldsWithoutMine = width * height - getMineCount();
	int revealedFields = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j].isRevealed == 1 && board[i][j].hasMine == 1)
			{
				return FINISHED_LOSS;
			}
			if (board[i][j].hasFlag == 1)
			{
				flags++;
			}
			if (board[i][j].hasFlag == 1 && board[i][j].hasMine == 1)
			{
				flagsOnMine++;
				if (flagsOnMine == flags && flagsOnMine == getMineCount())
				{
					return FINISHED_WIN;
				}
			}
			if (board[i][j].isRevealed == 1 && board[i][j].hasMine == 0)
			{
				revealedFields++;
				if (revealedFields == fieldsWithoutMine)
				{
					return FINISHED_WIN;
				}
			}
		}
	}
	return state;

}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
	if (x >= height || y >= width)
	{
		return '#';
	}
	if (board[x][y].isRevealed == 0 && board[x][y].hasFlag == 1)
	{
		return 'F';
	}
	if (board[x][y].isRevealed == 0 && board[x][y].hasFlag == 0)
	{
		return '_';
	}
	if (board[x][y].isRevealed == 1 && board[x][y].hasMine == 1)
	{
		return 'x';
	}
	if (board[x][y].isRevealed == 1 && countMines(x, y) == 0)
	{
		return 'r';
	}
	if (board[x][y].isRevealed == 1 && countMines(x, y) != 0)
	{
		int tmpx = 0;
		tmpx = countMines(x, y);
		return '0' + tmpx;
	}
}


