/* 461. Hamming Distance */

/* Complexities.
 * Time: Θ(d)
 * Space: Θ(1)
 * where d is the Hamming distance of the two input numbers. */

int hammingDistance(int x, int y);
int countBits(int x);

int hammingDistance(int x, int y)
{
	return countBits(x ^ y);
}

int countBits(int x)
{
	int counter = 0;
	while (x != 0) {
		++counter;
		x &= x - 1;
	}
	return counter;
}
