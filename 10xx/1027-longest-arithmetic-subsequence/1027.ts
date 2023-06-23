/* 1027. Longest Arithmetic Subsequence */

/* Complexities:
 * Time: O(n^2)
 * Space: O(n^2)
 * where n is the length of the input list. */

function longestArithSeqLength(nums: number[]): number {
  if (nums.length <= 1) {
    return nums.length;
  }

  /* cache[i][slope] is the length of the arithmetic sequence ending in nums[i]
   * with the given slope. Only sequences of length >= 2 are saved. */
  const cache: number[][] = [];

  for (let i = 0; i < nums.length; ++i) {
    calcSequences(i);
  }

  function calcSequences(j: number): void {
    cache[j] = [];
    for (let i = 0; i < j; ++i) {
      const slope = nums[j] - nums[i];
      if (cache[i][slope] === undefined) {
        cache[j][slope] = 2;
      } else {
        cache[j][slope] = cache[i][slope] + 1;
      }
    }
  }

  const allSlopes = cache.map((arr) => Object.values(arr)).flat();
  return Math.max(...allSlopes);
}
