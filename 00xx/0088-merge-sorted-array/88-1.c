/* 88. Merge Sorted Arrays */

/* Complexities.
 * Time: O(m + n)
 * Space: O(m + n)
 * where m and n are the lengths of the input arrays. */

#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int *merged = malloc((size_t) (m + n) * sizeof(int));

	int from1 = 0, from2 = 0, to = 0;
	while (from1 < m && from2 < n) {
		if (nums1[from1] < nums2[from2])
			merged[to++] = nums1[from1++];
		else
			merged[to++] = nums2[from2++];
	}
	while (from1 < m)
		merged[to++] = nums1[from1++];
	memcpy(nums1, merged, (size_t) to * sizeof(int));
	while (from2 < n)
		nums1[to++] = nums2[from2++];

	free(merged);
}
