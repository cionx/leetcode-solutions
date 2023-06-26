/* 1802. Maximum Value at a Given Index in a Bounded Array */

/* Complexities.
 * Time: O(log(n))
 * Space: O(1)
 * where n is as given in the problem statement. */

#include "1802.h"

/* See the LeetCode editorical for a detailed explanation. */

typedef long long myInt; /* so that no overflows occur */

int maxValue(int n, int index, int maxSum);
myInt binarySearch(int lower, int upper, int n, int index, int maxSum);
myInt calcSum(myInt height, int index, int length);
myInt calcOneSidedSum(myInt height, myInt width);

int maxValue(int n, int index, int maxSum)
{
	return (int) binarySearch(1, maxSum, n, index, maxSum);
}

myInt binarySearch(int lower, int upper, int n, int index, int maxSum)
{
	while (lower < upper) {
		const int middle = lower + (upper - lower + 1) / 2; /* rounded up */
		const myInt resultingSum = calcSum(middle, index, n);
		if (resultingSum < maxSum)
			lower = middle;
		else if (resultingSum > maxSum)
			upper = middle - 1;
		else
			return middle;
	}

	return lower;
}

myInt calcSum(myInt height, int index, int n)
{
	const myInt left = calcOneSidedSum(height, index + 1);
	const myInt right = calcOneSidedSum(height, n - index);
	return left + right - height;
}

myInt calcOneSidedSum(myInt height, myInt width)
{
	if (height <= width)
		return (height * (height + 1) / 2) + (width - height);
	else
		return (width * (width + 1) / 2) + (width * (height - width));
}
