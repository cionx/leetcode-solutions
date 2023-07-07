/* 200. Number of Islands */

/* Complexities.
 * Time: Θ(m n)
 * Space: Θ(m n)
 * where m × n is the size of the input grid. */

type Field = [row: number, column: number];

enum Type {
  Water = "0",
  Land = "1",
}

function numIslands(grid: Type[][]): number {
  const m = grid.length;
  const n = grid[0].length;

  const discovered: boolean[][] = grid.map((row) => row.map(() => false));

  function exploreIsland([i0, j0]: Field) {
    const toVisit: Field[] = [];
    discovered[i0][j0] = true;

    for (
      let field: Field | undefined = [i0, j0];
      field !== undefined;
      field = toVisit.pop()
    ) {
      const [i, j] = field;
      if (grid[i][j] == Type.Water) {
        continue;
      }
      if (i > 0 && !discovered[i - 1][j]) {
        discovered[i - 1][j] = true;
        toVisit.push([i - 1, j]);
      }
      if (i + 1 < m && !discovered[i + 1][j]) {
        discovered[i + 1][j] = true;
        toVisit.push([i + 1, j]);
      }
      if (j > 0 && !discovered[i][j - 1]) {
        discovered[i][j - 1] = true;
        toVisit.push([i, j - 1]);
      }
      if (j + 1 < n && !discovered[i][j + 1]) {
        discovered[i][j + 1] = true;
        toVisit.push([i, j + 1]);
      }
    }
  }

  let counter = 0;
  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      if (!discovered[i][j] && grid[i][j] == Type.Land) {
        ++counter;
        exploreIsland([i, j]);
      }
    }
  }

  return counter;
}
