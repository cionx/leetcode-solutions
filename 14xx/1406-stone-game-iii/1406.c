/* 1406. Stone Game III */

/* Complexities.
 * Time: O(n)
 * Space: O(n)
 * where n is the length of the input list. */

#include <stdbool.h>
#include <stdlib.h>

char *stoneGameIII(int *stoneValue, int stoneValueSize);
int calcValue(int *stoneValue, int stoneValueSize, int *cache, int i);
int min(int a, int b);
int max(int a, int b);

char *stoneGameIII(int *stoneValue, int stoneValueSize)
{
	/* cache[i] is the score that Alice is guaranteed when starting from the
	 * i-th pile. We include the case i = stoneValueSize, which means that no
	 * piles will be left. The computation of cache[i] depends on the values of
	 * cache[j] for j > i. */
	int *cache = calloc(sizeof(int), (size_t) (stoneValueSize + 1));
	for (int i = stoneValueSize - 1; i >= 0; --i) {
		cache[i] = calcValue(stoneValue, stoneValueSize, cache, i);
	}

	int totalPoints = 0;
	for (int i = 0; i < stoneValueSize; ++i)
		totalPoints += stoneValue[i];

	int alicePoints = cache[0];
	int bobPoints = totalPoints - alicePoints;

	free(cache);

	if (alicePoints > bobPoints)
		return "Alice";
	else if (alicePoints < bobPoints)
		return "Bob";
	else
		return "Tie";
}

int calcValue(int *stoneValue, int stoneValueSize, int *cache, int i)
{
	int guaranteedResult = 0;
	bool haveGuaranteedResult = false;
	int thisTurn = 0;

	for (int aStep = 1; aStep <= 3 && i + aStep <= stoneValueSize; ++aStep) {
		thisTurn += stoneValue[i + aStep - 1];

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

		int possibleResult = thisTurn + futureTurn;
		if (!haveGuaranteedResult) {
			guaranteedResult = possibleResult;
			haveGuaranteedResult = true;
		}
		else
			guaranteedResult = max(guaranteedResult, possibleResult);
	}

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
