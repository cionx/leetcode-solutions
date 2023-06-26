/* 350. Intersection of Two Arrays II */

/* Complexity
 * Time: O(m log(m) + n log(n))
 * Space: O(m + n)
 * where m and n are the length of the two input arrays respectively. */

/* Note.
 * The following code is copied from Problem 349 (Intersection of Two Arrays),
 * with changes only in the loop in lines 38-41. */

#include <stdlib.h>
#include <string.h>

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize);
int *giveSorted(int *nums, int numsSize);
int cmpInt(const void *pa, const void *pb);

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
               int *returnSize)
{
	int *sorted1 = giveSorted(nums1, nums1Size);
	int *sorted2 = giveSorted(nums2, nums2Size);

	const int maxSize = (nums1Size > nums2Size) ? nums1Size : nums2Size;
	int *result = malloc((size_t) maxSize * sizeof(int));
	int i = 0, j = 0, k = 0;
	while (i < nums1Size && j < nums2Size) {
		while (i < nums1Size && sorted1[i] < sorted2[j])
			++i;
		if (i == nums1Size)
			break;
		while (j < nums2Size && sorted2[j] < sorted1[i])
			++j;
		if (j == nums2Size)
			break;
		while (i < nums1Size && j < nums2Size && sorted1[i] == sorted2[j]) {
			result[k++] = sorted1[i];
			++i, ++j;
		}
	}
	result = reallocarray(result, (size_t) k, sizeof(int));

	free(sorted1);
	free(sorted2);
	*returnSize = k;
	return result;
}

int *giveSorted(int *nums, int numsSize)
{
	const size_t size = (size_t) numsSize * sizeof(int);
	int *sorted = malloc(size);
	memcpy(sorted, nums, size);
	qsort(sorted, (size_t) numsSize, sizeof(int), cmpInt);
	return sorted;
}

int cmpInt(const void *pa, const void *pb)
{
	const int *a = (const int *) pa;
	const int *b = (const int *) pb;
	return (*a > *b) - (*a < *b);
}
