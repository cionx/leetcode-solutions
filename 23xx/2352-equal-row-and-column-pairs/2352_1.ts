/* Time:  O(n^2)
 * Space: O(n^2)
 */

/* We regard the columns of the grid as paths in a tree. For example, the given
 * example [[3,2,1],[1,7,6],[2,7,7]] corresponds to the following tree:
 *
 *       *
 *      /|\
 *     / | \
 *    1  2  3
 *    |  |  |
 *    7  7  2
 *    |  |  |
 *    6  7  1
 *
 *    #  #  #
 *    1  1  1
 *
 * To each leaf in the tree, we have an associated number that tells us how
 * often this specified path appeared as a row. We encode such a tree as nested
 * spares arrays:
 *
 *    [1: [7: [6: 1]], 2: [7: [7: 1]], 3: [2: [1: 1]]
 *
 * We first convert the rows into a tree. We then go through the columns, and
 * look up for each column if it appears in the tree, and if so, with which
 * associated number.
 */

type Tree<T> = Tree<T>[] | T[];
type Grid<T> = T[][];

function equalPairs(grid: Grid<number>): number {
  const n = grid.length;
  const rowTree: Tree<number> = [];

  /* First part: create the tree. */

  function addRow(row: number) {
    addRowAux(rowTree, row, 0);
  }

  function addRowAux(subTree: Tree<number>, row: number, column: number): void {
    const sparseIndex = grid[row][column];
    if (lowestLevel(subTree, n, column)) {
      const value = subTree[sparseIndex];
      subTree[sparseIndex] = (value === undefined) ? 1 : (value + 1);
    } else {
      const subSubTree = subTree[sparseIndex];
      if (subSubTree === undefined) {
        subTree[sparseIndex] = [];
      }
      addRowAux(subTree[sparseIndex], row, column + 1);
    }
  }

  function lowestLevel<T>(
    _tree: Tree<T>,
    height: number,
    level: number,
  ): _tree is T[] {
    return level == height - 1;
  }

  for (let i = 0; i < n; ++i) {
    addRow(i);
  }

  /* Second part: add up the numbers associated to the columns in the tree. */

  let counter = 0;

  function equalRows(column: number): number {
    return equalRowsAux(rowTree, column, 0);
  }

  function equalRowsAux(
    subTree: Tree<number>,
    columnIndex: number,
    i: number,
  ): number {
    if (lowestLevel(subTree, n, i)) {
      const value = subTree[grid[i][columnIndex]];
      return (value !== undefined) ? value : 0;
    }
    const subSubTree = subTree[grid[i][columnIndex]];
    return (subSubTree !== undefined)
      ? equalRowsAux(subSubTree, columnIndex, i + 1)
      : 0;
  }

  for (let j = 0; j < n; ++j) {
    counter += equalRows(j);
  }

  return counter;
}
