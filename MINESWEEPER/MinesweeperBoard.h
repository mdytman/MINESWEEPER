#include <iostream>

#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
	Field board[100][100];
	int width;
	int height;
	GameMode mode;
	GameState state;

	void setMines(double part);

public:
	MinesweeperBoard(int W, int H, GameMode M);
	void resetBoard(int width, int height, GameMode mode);
	void debug_display() const;
	int getBoardWidth() const;
	int getBoardHeight() const;
	int getMineCount() const;
	int countMines(int k, int w) const;
	bool hasFlag(int x, int y) const;
	bool hasMine(int x, int y) const;
	void revealField(int x, int y);
	void toggleFlag(int x, int y);
	bool isRevealed(int x, int y) const;
	GameState getGameState() const;
	char getFieldInfo(int x, int y) const;
};

#endif