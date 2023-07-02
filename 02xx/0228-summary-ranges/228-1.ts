/* 228. Summary Ranges */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array.
 */
function summaryRanges(nums: number[]): string[] {
  const result: string[] = [];

  for (let i = 0; i < nums.length;) {
    const start = nums[i];
    while (++i < nums.length && nums[i] == nums[i - 1] + 1);
    const end = nums[i - 1];
    const range = (start == end) ? `${start}` : `${start}->${end}`;
    result.push(range);
  }

  return result;
}
