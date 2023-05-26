function findDifference(nums1: number[], nums2: number[]): number[][] {
  const result: number[][] = [[], []];

  /* We should really use toSorted instead of sort,
   * but LeetCode doesn’t support it yet.
   */
  nums1.sort((x, y) => x - y);
  nums2.sort((x, y) => x - y);

  let i = 0;
  let j = 0;

  while (i < nums1.length || j < nums2.length) {
    /* Case 1: only nums1 left. */
    if (j >= nums2.length) {
      while (i < nums1.length) {
        const c = nums1[i];
        result[0].push(c);
        while (nums1[i] == c) i++;
      }
    }
    /* Case 2: only nums2 left. */
    else if (i >= nums1.length) {
      while (j < nums2.length) {
        const c = nums2[j];
        result[1].push(c);
        while (nums2[j] == c) j++;
      }
    }
    /* Case 3: nums1 and nums2 left, same head. */
    else if (nums1[i] == nums2[j]) {
      const c = nums1[i];
      while (nums1[i] == c) i++;
      while (nums2[j] == c) j++;
    }
    /* Case 4: nums1 and nums2 left, nums1 < nums2. */
    else if (nums1[i] < nums2[j]) {
      const c = nums1[i];
      result[0].push(c);
      while (nums1[i] == c) i++;
    } /* Case 5: nums1 and nums2 left, nums1 > nums2. */
    else if (nums1[i] > nums2[j]) {
      const c = nums2[j];
      result[1].push(c);
      while (nums2[j] == c) j++;
    }
  }

  return result;
}
