#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *stoneGameIII(int *stoneValue, int stoneValueSize);
int calcValue(int *stoneValue, int stoneValueSize, int *cache, int i);
int min(int a, int b);
int max(int a, int b);
void printCache(int *cache, int start, int stoneValueSize);

char *stoneGameIII(int *stoneValue, int stoneValueSize)
{
	/* cache[i] is the score that Alice is guaranteed when starting from the
	 * i-th pile. We include the case i = stoneValueSize, which means that no
	 * piles will be left. The computation of cache[i] depends on the values of
	 * cache[j] for j > i. */
	int *cache = calloc(sizeof(int), (size_t) (stoneValueSize + 1));
	// printf("\n--------------------------------------------\n\n");
	for (int i = stoneValueSize - 1; i >= 0; --i) {
		cache[i] = calcValue(stoneValue, stoneValueSize, cache, i);
		// printCache(cache, i, stoneValueSize);
		// printf("\n--------------------------------------------\n\n");
	}

	int totalPoints = 0;
	for (int i = 0; i < stoneValueSize; ++i)
		totalPoints += stoneValue[i];

	int alicePoints = cache[0];
	int bobPoints = totalPoints - alicePoints;

	free(cache);

	// printf("Alice: %d of %d\n", alicePoints, totalPoints);
	if (alicePoints > bobPoints)
		return "Alice";
	else if (alicePoints < bobPoints)
		return "Bob";
	else
		return "Tie";
}

int calcValue(int *stoneValue, int stoneValueSize, int *cache, int i)
{
	// printf("Calculating i = %d...\n", i);
	int guaranteedResult = 0;
	bool haveGuaranteedResult = false;
	int thisTurn = 0;

	for (int aStep = 1; aStep <= 3 && i + aStep <= stoneValueSize; ++aStep) {
		// printf("\taStep = %d\n", aStep);
		thisTurn += stoneValue[i + aStep - 1];
		// printf("\t\tThis turn: %d\n", thisTurn);

		int futureTurn = 0;
		bool haveFutureTurn = false;
		/* In the following list, the case i + aStep + bStep = stoneValueSize
		 * ensures that Bob is allowed to take all remaining stones. The cache
		 * contains trailing spaces to ensure that the lookup
		 * cache[stoneValueSize] is not only possible, but also return the
		 * correct result. */
		for (int bStep = 1; bStep <= 3 && i + aStep + bStep <= stoneValueSize;
		     ++bStep) {
			int possibleFutureTurn = cache[i + aStep + bStep];
			if (!haveFutureTurn) {
				futureTurn = possibleFutureTurn;
				haveFutureTurn = true;
			}
			else
				futureTurn = min(futureTurn, possibleFutureTurn);
		}
		// printf("\t\tFuture turns: %d\n", futureTurn);

		int possibleResult = thisTurn + futureTurn;
		// printf("\t\tPossible result: %d\n", possibleResult);
		if (!haveGuaranteedResult) {
			guaranteedResult = possibleResult;
			haveGuaranteedResult = true;
		}
		else
			guaranteedResult = max(guaranteedResult, possibleResult);
		// printf("\t\tGuaranteed result: %d\n", guaranteedResult);
	}

	// printf("\tBest = %2d\n\n", guaranteedResult);
	return guaranteedResult;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a < b) ? b : a;
}

void printCache(int *cache, int start, int stoneValueSize)
{
	for (int i = start; i < stoneValueSize; ++i)
	printf("i = %2d  |  %3d\n", i, cache[i]);
}

/* Don’t copy the below to LeetCode. */

int main(void)
{
	int values[] = {17, -16, 1,   13, -17, 4,   -7, 13, -3,
	                3,  -11, -17, 10, 0,   -12, 6,  8};

	printf("Winner: %s\n", stoneGameIII(values, 17));

	return 0;
}
