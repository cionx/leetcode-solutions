/* 747. Largest Number At Least Twice of Others */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

int dominantIndex(int *nums, int numsSize)
{
	int largest, sndLargest;
	int index;
	if (nums[0] < nums[1]) {
		sndLargest = nums[0];
		largest = nums[1];
		index = 1;
	}
	else {
		sndLargest = nums[1];
		largest = nums[0];
		index = 0;
	}

	for (int i = 2; i < numsSize; ++i) {
		if (nums[i] > largest) {
			sndLargest = largest;
			largest = nums[i];
			index = i;
		}
		else if (nums[i] > sndLargest)
			sndLargest = nums[i];
	}

	return (largest / 2 >= sndLargest) ? index : -1;
}
