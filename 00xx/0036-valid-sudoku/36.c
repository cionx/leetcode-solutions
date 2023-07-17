/* 36. Valid Sudoku */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1)
 * because Sudoku boards have a fixed size. */

#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize);
bool isValidRow(char **board, int row);
bool isValidColumn(char **board, int column);
bool isValidBlock(char **board, int row, int column);
bool isEmpty(char c);
int value(char c);

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
	for (int i = 0; i < 9; ++i)
		if (!isValidRow(board, i))
			return false;
	for (int j = 0; j < 9; ++j)
		if (!isValidColumn(board, j))
			return false;
	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 9; j += 3)
			if (!isValidBlock(board, i, j))
				return false;
	return true;
}

bool isValidRow(char **board, int row)
{
	bool found[10] = {false};
	for (int j = 0; j < 9; ++j) {
		if (isEmpty(board[row][j]))
			continue;
		int digit = value(board[row][j]);
		if (found[digit])
			return false;
		found[digit] = true;
	}
	return true;
}

bool isValidColumn(char **board, int column)
{
	bool found[10] = {false};
	for (int i = 0; i < 9; ++i) {
		if (isEmpty(board[i][column]))
			continue;
		int digit = value(board[i][column]);
		if (found[digit])
			return false;
		found[digit] = true;
	}
	return true;
}

bool isValidBlock(char **board, int row, int column)
{
	bool found[10] = {false};
	for (int i = row; i < row + 3; ++i) {
		for (int j = column; j < column + 3; ++j) {
			if (isEmpty(board[i][j]))
				continue;
			int digit = value(board[i][j]);
			if (found[digit])
				return false;
			found[digit] = true;
		}
	}
	return true;
}

bool isEmpty(char c)
{
	return c == '.';
}

int value(char c)
{
	return c - '0';
}
