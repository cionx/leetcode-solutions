/* 88. Merge Sorted Arrays */

/* Complexities.
 * Time: O(m + n)
 * Space: O(1)
 * where m and n are the lengths of the input arrays. */

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int from1 = 0, from2 = 0;
	while (from1 < m && from2 < n)
		if (nums1[from1] <= nums2[from2])
			++from1;
		else
			++from2;

	int fromBoth = from1 + from2;
	int fromOne = m + n - fromBoth;
	int to = m + n - 1;

	int *copyFrom = (from1 == m) ? nums2 : nums1;
	int from = (from1 == m) ? n - 1 : m - 1;
	while (fromOne-- > 0)
		nums1[to--] = copyFrom[from--];

	--from1, --from2;
	while (from1 >= 0 && from2 >= 0)
		if (nums1[from1] >= nums2[from2])
			nums1[to--] = nums1[from1--];
		else
			nums1[to--] = nums2[from2--];

	/* Only of the following two loops will run. */
	while (from1 >= 0)
		nums1[to--] = nums1[from1--];
	while (from2 >= 0)
		nums1[to--] = nums2[from2--];
}
