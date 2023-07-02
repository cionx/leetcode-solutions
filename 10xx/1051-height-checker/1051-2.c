/* 1051. Height Checker */

/* Complexities.
 * Time: O(n)
 * Space: Θ(MAXHEIGHT) = Θ(1)
 * where n is the length of the input array and MAXHEIGHT is the maximal allowed
 * height. */

#define MAXHEIGHT 100

int heightChecker(int *heights, int heightsSize);
int cmpInt(const void *vpa, const void *vpb);

int heightChecker(int *heights, int heightsSize)
{
	int frequencies[MAXHEIGHT + 1] = {0}; /* Initialize all as entries 0. */
	for (int i = 0; i < heightsSize; ++i)
		++frequencies[heights[i]];

	int counter = 0;
	for (int i = 0, expected = 0; i < heightsSize; ++i) {
		while (frequencies[expected] == 0)
			++expected;
		counter += (heights[i] != expected);
		--frequencies[expected];
	}

	return counter;
}
