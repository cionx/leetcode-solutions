/* 88. Merge Sorted Arrays */

/* Complexities.
 * Time: O((m + n) log(m + n))
 * Space: O(m + n)
 * where m and n are the lengths of the input arrays. */

#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);
int cmpInt(const void *va, const void *vb);

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int *tmp = malloc(((size_t) m + n) * sizeof(int));
	memcpy(tmp, nums1, (size_t) m * sizeof(int));
	memcpy(tmp + m, nums2, (size_t) n * sizeof(int));
	qsort(tmp, (size_t) m + n, sizeof(int), cmpInt);
	memcpy(nums1, tmp, ((size_t) m + n) * sizeof(int));
	free(tmp);
}

int cmpInt(const void *va, const void *vb)
{
	const int *pa = (const int *) va;
	const int *pb = (const int *) vb;
	return (*pa > *pb) - (*pa < *pb);
}
