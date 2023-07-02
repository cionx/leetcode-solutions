/* 922. Sort Array By Parity II */

/* In-place solution. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of input array. */

/* Idea:
 * The input array is the disjoint union of two channels:
 *  arr[0] -> arr[2] -> arr[4] -> arr[6] -> ...
 *  arr[1] -> arr[3] -> arr[5] -> arr[8] -> ...
 * We travel along both channels in search of misplaced numbers. If a pair of
 * misplaced numbers has been found, then we swap these two numbers. We finish
 * once we have gone through the channels. (Note that both channels have the
 * same number of misplaced numbers in them, since there are as many even
 * numbers as odd ones in the entire array.) */

int *sortArrayByParityII(int *nums, int numsSize, int *returnSize)
{
	for (int indexEven = 0, indexOdd = 1;
	     indexEven < numsSize && indexOdd < numsSize;
	     indexEven += 2, indexOdd += 2) {
		while (indexEven < numsSize && nums[indexEven] % 2 == 0)
			indexEven += 2;
		while (indexOdd < numsSize && nums[indexOdd] % 2 == 1)
			indexOdd += 2;
		if (indexEven < numsSize && indexOdd < numsSize) {
			const int tmp = nums[indexEven];
			nums[indexEven] = nums[indexOdd];
			nums[indexOdd] = tmp;
		}
	}

	*returnSize = numsSize;
	return nums;
}
