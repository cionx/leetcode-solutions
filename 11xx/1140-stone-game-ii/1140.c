#include <stdlib.h>

int stoneGameII(int *piles, int pSize);
int calculateValue(int *piles, int pSize, int maxM, int *cache, int i, int m);
void setValue(int *cache, int maxM, int i, int m, int value);
int getValue(int *cache, int maxM, int i, int m);
int max(int a, int b);
int min(int a, int b);
int newM(int oldM, int x, int maxM);

enum { none = 1000001 };
/* This is 100 * 10^4 + 1, a value larger than any possible game score. */

int stoneGameII(int *piles, int pSize)
{
	/* values(i, m) is the the maximal amount that one can win when starting
	 * from the i-th pile, for a given value of m.
	 *
	 * i goes from 0 (start pile) to pileSize (no pile left). The inclusion of
	 * the case `i = pileSize` will make the code easier.
	 *
	 * m goes from 1 to ceil(pSize / 2): once we reach this value for m, we
	 * can take all the remaining piles at once. We can therefore always
	 * truncate m by this maximal value without changing the overall result.
	 * This truncation halves both memory usage and run time.
	 */
	int maxM = (pSize + 1) / 2;
	int *cache = calloc((size_t) ((pSize + 1) * (1 + maxM)), sizeof(int));

	/* The general recursion relation is
	     values(i, m) = sum over values(i + x + y, m'')
	   for 1 <= x <= 2m,  m'  = max(m, x),
	       1 <= y <= 2m', m'' = max(m', y).
	*/
	/* The values for i = pileSize are already correctly set by calloc. */
	for (int i = pSize - 1; i >= 0; --i) {
		for (int m = 1; m <= maxM; ++m) {
			int newValue = calculateValue(piles, pSize, maxM, cache, i, m);
			setValue(cache, maxM, i, m, newValue);
		}
	}

	int result = getValue(cache, maxM, 0, 1);
	free(cache);
	return result;
}

int calculateValue(int *piles, int pSize, int maxM, int *cache, int i, int m0)
{
	int thisTurn = 0;
	int bestResult = 0;

	for (int x = 1; x <= 2 * m0 && i + x < pSize + 1; x++) {
		thisTurn += piles[i + x - 1];
		/* We will now simulate Bob’s possible moves, and what they mean
		 * for Alice’s score. If Alice has no turns left after Bob, then
		 * `futureTurns` will be 0. If turns are left, then Bob will choose
		 * his move to minimize Alice’s `futureTurns`.
		 */
		int m1 = newM(m0, x, maxM); // Bob can then choose from this.
		int futureTurns = none;
		int j = 0; // This is where Alice will be after Bob’s turn.
		for (int y = 1; y <= 2 * m1 && (j = i + x + y) < pSize + 1; ++y) {
			int m2 = newM(m1, y, maxM);
			int possibleFutureValue = getValue(cache, maxM, j, m2);
			/* Minimum because Bob will choose what is worst for Alice.
			 * `none` is implemented as a number larger than any possible game
			 * score, so `none` will be replaced by `possibleFutureValue` during
			 * the first iteration. */
			futureTurns = min(futureTurns, possibleFutureValue);
		}
		if (futureTurns == none)
			futureTurns = 0;
		bestResult = max(bestResult, thisTurn + futureTurns);
	}

	return bestResult;
}

void setValue(int *cache, int maxM, int i, int m, int value)
{
	cache[i * maxM + m] = value;
}

int getValue(int *cache, int maxM, int i, int m)
{
	return cache[i * maxM + m];
}

int max(int a, int b)
{
	return (a < b) ? b : a;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int newM(int oldM, int x, int maxM)
{
	return min(max(oldM, x), maxM);
}
