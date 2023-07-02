/* 2352. Equal Row and Column Pairs */

/* Complexities.
 * Time:  O(n^3)
 * Space: O(1)
 * where n × n is the size of the input array.
 */

type Grid<T> = T[][];

function equalPairs(grid: Grid<number>): number {
  const n = grid.length;

  let counter = 0;

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < n; ++j) {
      counter += areEqual(i, j);
    }
  }

  function areEqual(row: number, column: number) {
    for (let k = 0; k < n; ++k) {
      if (grid[row][k] != grid[k][column]) {
        return 0;
      }
    }
    return 1;
  }

  return counter;
}
