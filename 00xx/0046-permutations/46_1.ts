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
