function generateParenthesis(n: number): string[] {
  /* It could be useful to remember the cache outside the function, to prevent
   * repeated calculation among multiple calls to the function.
   */
  const cache: string[][] = Array(n + 1);
  cache[0] = [""]; /* Initial entry. */

  function generateCache(m: number): void {
    if (cache[m] !== undefined) {
      return;
    }
    cache[m] = Array(m)
      .fill(null)
      .map((_, i) => combineResults(cache[i], cache[m - 1 - i]))
      .flat();
  }

  function combineResults(arr1: string[], arr2: string[]) {
    return arr1
      .map((first) => arr2.map((rest) => `(${first})${rest}`))
      .flat();
  }

  for (let i = 0; i <= n; ++i) {
    generateCache(i);
  }

  return cache[n];
}
