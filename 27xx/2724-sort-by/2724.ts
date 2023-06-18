function sortBy<T>(arr: T[], fn: (value: T) => number): T[] {
  /* We should use .toSorted() instead of .sort() so that the input array
   * remains unchanged, but LeetCode is too outdated. */
  arr.sort((a, b) => fn(a) - fn(b));
  return arr;
}
