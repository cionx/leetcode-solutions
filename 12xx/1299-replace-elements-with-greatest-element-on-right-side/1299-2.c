/* 1299. Replace Elements with Greatest Element on Right Side */

/* In-place. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

int *replaceElements(int *arr, int arrSize, int *returnSize)
{
	int max = -1;
	for (int i = arrSize - 1; i >= 0; --i) {
		const int tmp = arr[i];
		arr[i] = max;
		if (tmp > max)
			max = tmp;
	}

	*returnSize = arrSize;
	return arr;
}
