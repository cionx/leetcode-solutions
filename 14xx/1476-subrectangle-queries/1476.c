/* 1476. Subrectangle Queries */

#include <stdlib.h>

typedef struct {
	int **entries;
} SubrectangleQueries;

SubrectangleQueries *subrectangleQueriesCreate(int **rectangle,
                                               int rectangleSize,
                                               int *rectangleColSize)
{
	SubrectangleQueries *result = malloc(sizeof(SubrectangleQueries));
	result->entries = rectangle;
	return result;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries *rect, int row1,
                                           int col1, int row2, int col2,
                                           int newValue)
{
	for (int i = row1; i <= row2; ++i)
		for (int j = col1; j <= col2; ++j)
			rect->entries[i][j] = newValue;
}

int subrectangleQueriesGetValue(SubrectangleQueries *rect, int row, int col)
{
	return rect->entries[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries *rect)
{
	free(rect);
}
