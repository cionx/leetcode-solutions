/* Time: O(m + n)
 * Space: O(m + n)
 */

#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int *merged = malloc((size_t) (m + n) * sizeof(int));

	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j])
			merged[k++] = nums1[i++];
		else
			merged[k++] = nums2[j++];
	}
	while (i < m)
		merged[k++] = nums1[i++];
	memcpy(nums1, merged, (size_t) k * sizeof(int));
	while (j < n)
		nums1[k++] = nums2[j++];

	free(merged);
}
