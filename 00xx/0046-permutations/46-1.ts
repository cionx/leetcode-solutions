/* 46. Permutations */

/* Complexities.
 * Time: O(n n!)
 * Space: O(n)
 * where n is the length of the input array. */

function permute(nums: number[]): number[][] {
  if (nums.length == 0) {
    return [[]];
  }

  let result: number[][] = [];

  for (const x of nums) {
    /* Filter is somewhat overkill, but LeetCode doesn’t support
     * structuredClone + splice, nor toSpliced. */
    const recResult = permute(nums.filter((y) => y !== x));
    recResult.forEach((result) => result.push(x));
    result = result.concat(recResult);
  }

  return result;
}
