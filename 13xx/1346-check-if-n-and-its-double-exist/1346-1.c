/* 1346. Check If N and Its Double Exist */

/* Complexities.
 * Time: O(n^2)
 * Space: O(1)
 * where n is the length of the input array. */

#include <stdbool.h>

bool checkIfExist(int *arr, int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
		for (int j = i + 1; j < arrSize; ++j)
			if (2 * arr[i] == arr[j] || 2 * arr[j] == arr[i])
				return true;
	return false;
}
