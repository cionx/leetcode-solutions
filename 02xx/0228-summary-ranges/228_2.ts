/* Time: Best case:  O(log(n))
 *       Worst case: O(n log(n))
 * Space: O(1)
 */

/* Main observation:
 * Suppose that we have an index  i  for which  nums[i]  starts a new range. We
 * can then check in O(1) if for another index  j , with  i <= j,  the value
 * nums[j]  lies in this range: The difference  nums[j] - nums[i]  is always
 * larger or equal to the difference  j - i  because the entries in nums are
 * strictly increasing. The differences are equal if and only if  nums[j]  lies
 * in the range. Even more, the mapping  j -> nums[j] - nums[i]  is weakly
 * increasing. We can therefore determine the end of the given range by finding
 * the largest integer  j  for which  nums[j] - nums[i]  equals  j - i.  This
 * can be done with binary search.
 */
function summaryRanges(nums: number[]): string[] {
  /* We use an auxiliary function to find the end of a range via binary search,
   * as discussed above.
   */
  function findRangeEnd(start: number) {
    let lower = start;
    let upper = nums.length - 1;
    while (lower < upper) {
      const middle = Math.ceil((lower + upper) / 2); /* larger than lower */
      if (nums[middle] - nums[start] > middle - start) {
        upper = middle - 1;
      } else {
        lower = middle;
      }
    }
    return upper;
  }

  const result: string[] = [];

  for (let start = 0, end; start < nums.length; start = end + 1) {
    end = findRangeEnd(start);
    const range = (start == end)
      ? `${nums[start]}`
      : `${nums[start]}->${nums[end]}`;
    result.push(range);
  }

  return result;
}
