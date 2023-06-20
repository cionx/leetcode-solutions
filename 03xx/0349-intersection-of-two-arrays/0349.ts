/* 349. Intersection of Two Arrays */

/* Complexity
 * Time: O(m + n) on average
 * Space: O(m + n)
 * where m and n are the length of the two input arrays. */

function intersection(nums1: number[], nums2: number[]): number[] {
  const set1 = new Set(nums1)
  const set2 = new Set(nums2)

  const result = [];
  for (const x of set1) {
    if (set2.has(x)) {
      result.push(x)
    }
  }

  return result;
};
