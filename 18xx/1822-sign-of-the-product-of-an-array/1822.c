/* 1822. Sign of the Product of an Array */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

int arraySign(int* nums, int numsSize){
	int sign = 1;

	for (int i = 0; i < numsSize; ++i) {
		const int factor = nums[i];
		if (factor < 0)
			sign = -sign;
		else if (factor == 0)
			return 0;
	}

	return sign;
}
