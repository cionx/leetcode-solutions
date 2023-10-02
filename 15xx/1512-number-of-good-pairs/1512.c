/* 1512. Number of Good Pairs */

/* Complexities.
 * Time: Θ(n + MAXNUM)
 * Space: Θ(MAXNUM)
 * where n is the length of the input array, and MAXNUM equals 100. */

#define MAXNUM 100

int numIdenticalPairs(int *nums, int numsSize)
{
	int counter[MAXNUM + 1] = {0}; /* Initialize all entries as 0. */
	for (int i = 0; i < numsSize; ++i)
		++counter[nums[i]];

	int result = 0;
	for (int n = 1; n <= MAXNUM; ++n) {
		int c = counter[n];
		result += c * (c - 1) / 2;
	}

	return result;
}
