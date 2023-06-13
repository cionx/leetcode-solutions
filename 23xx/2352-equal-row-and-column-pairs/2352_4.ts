/* Time: Best case:  O(n^2)
 *       Worst case: O(n^2 log(n))
 * Space: O(n^2)
 */
type Grid<T> = T[][];

function equalPairs(grid: Grid<number>): number {
  const n = grid.length;

  /* Time: O(n^2) */

  const transpose: Grid<number> = [];
  for (let j = 0; j < n; ++j) {
    transpose.push(grid.map((row) => row[j]));
  }

  /* Comparison takes O(1) to O(n) */
  function cmpRows(row1: number[], row2: number[]): number {
    for (let i = 0; i < n; ++i) {
      if (row1[i] > row2[i]) {
        return 1;
      } else if (row1[i] < row2[i]) {
        return -1;
      }
    }
    return 0;
  }

  /* Time: O(n log(n)) to O(n^2 log(n)) */

  /* We should use .toSorted() instead, but LeetCode is too outdated. */
  grid.sort(cmpRows);
  transpose.sort(cmpRows);

  /* Time: O(n) to O(n^2) */

  let counter = 0;
  for (let i = 0, j = 0; i < n && j < n;) {
    const row1 = grid[i];
    const row2 = transpose[j];
    const cmp = cmpRows(row1, row2);
    if (cmp > 0) {
      ++j;
      continue;
    }
    else if (cmp < 0) {
      ++i;
      continue;
    }
    let k = i + 1;
    let l = j + 1;
    while (k < n && cmpRows(grid[k], row1) == 0) {
      ++k;
    }
    while (l < n && cmpRows(transpose[l], row2) == 0) {
      ++l;
    }
    counter += (k - i) * (l - j);
    i = k;
    j = l;
  }

  return counter;
}
