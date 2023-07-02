/* 46. Permutations */

/* Complexities.
 * Time: O(n!)
 * Space: O(n!)
 * where n is the length of the input array. */

function permute(nums: number[]): number[][] {
  if (nums.length == 0) {
    return [[]];
  }

  return nums
    .map((x) => nums.filter((y) => y !== x))
    .map(permute)
    .map((perms, index) => perms.map((perm) => perm.concat([nums[index]])))
    .flat();
  /* We are using .concat([...]) instead of .push(...) to add an element to an
   * array, but not in place. */
}
