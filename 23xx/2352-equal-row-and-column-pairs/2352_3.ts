/* 2352. Equal Row and Column Pairs */

/* Complexities.
 * Time: best case: O(n^2)
 *       worst case: O(n^3)
 * Space: O(n)
 * where n × n is the size of the input grid.
 */


type Grid<T> = T[][];

function equalPairs(grid: Grid<number>): number {
  const n = grid.length;
  const size = 100; /* Number of hash buckets. */

  function rowHash(row: number): number {
    let sum = 0;
    for (let j = 0; j < n; ++j) {
      sum += grid[row][j];
      sum %= size;
    }
    return sum;
  }

  function columnHash(column: number): number {
    let sum = 0;
    for (let i = 0; i < n; ++i) {
      sum += grid[i][column];
      sum %= size;
    }
    return sum;
  }

  /* We use the hashes as indices in an array. JavaScript’s remainder operator
   * is somewhat broken (e.g., 5 % 10 is unequal (-5) % 10). But all grid
   * entries are positive, so we don’t need to worry about this.
   */

  const rowsByHash: number[][] = Array(size).fill(null).map(() => []);
  for (let i = 0; i < n; ++i) {
    rowsByHash[rowHash(i)].push(i);
  }

  function areEqual(row: number, column: number): number {
    for (let k = 0; k < n; ++k) {
      if (grid[row][k] != grid[k][column]) {
        return 0;
      }
    }
    return 1;
  }

  let counter = 0;
  for (let j = 0; j < n; ++j) {
    for (const i of rowsByHash[columnHash(j)]) {
      counter += areEqual(i, j);
    }
  }

  return counter;
}
