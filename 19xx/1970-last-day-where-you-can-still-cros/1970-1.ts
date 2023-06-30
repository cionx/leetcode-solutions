/* 1970. Last Day Where You Can Still Cross. */

/* Complexities.
 * Time: Ω(m n) and O(m n log(m n))
 * Space: Θ(m n)
 * where m × n is the size of the input grid.
 * (Regarding the time complexity: The factor log(m n) stems from the height of
 * the binary tree in the union-find part of the algorithm. I’m not sure if this
 * height estimate is correct.) */

/* Idea:
 * We start at the end of the process, when the map has been splintered into
 * separate islands. We then turn back time, slowly adding back the missing
 * land step by step. We use union-find to keep track of the merging islands.
 * We add fictional rows of land at the top and bottom of the field. Then
 * exists a path from the top to the bottom if and only if both fictional rows
 * belong to the same island. This is a condition that we can easily check
 * thanks to union-find. */

type Coord = [number, number];

function latestDayToCross(m: number, n: number, cells: Coord[]): number {
  enum Field {
    Land = 0,
    Water = 1,
  }

  type Grid<T> = T[][];
  function createGrid<T>(height: number, width: number, init: T): Grid<T> {
    return Array(height).fill(null).map(() => Array(width).fill(init));
  }

  /* We add a fictional row of land at the top and bottom of the map. The
   * 1-indexing works in our favour here. We also add a fictional column of
   * water the the left because of the 1-indexing. */
  const state: Grid<Field> = createGrid(m + 2, n + 1, Field.Land);
  for (let i = 0; i <= m + 1; ++i) {
    state[i][0] = Field.Water;
  }
  for (const [i, j] of cells) {
    state[i][j] = Field.Water;
  }

  /* We run through the map and number the islands, starting with 0. */

  let islandCounter = 0;
  const origIslandId = createGrid(m + 2, n + 1, -1);
  const islandSizes: number[] = [];

  const discovered = createGrid(m + 2, n + 1, false);
  for (let i = 0; i <= m + 1; ++i) {
    for (let j = 0; j <= n; ++j) {
      checkForIsland(i, j);
    }
  }

  type Stack<T> = T[];
  function checkForIsland(i: number, j: number): void {
    if (state[i][j] == Field.Water || discovered[i][j]) {
      return;
    }
    /* We crawl through the new island with DFS. */
    let islandSize = 0;
    const toVisit: Stack<Coord> = [];
    toVisit.push([i, j]);
    discovered[i][j] = true;
    let current: Coord | undefined;
    while ((current = toVisit.pop()) !== undefined) {
      const [i, j] = current;
      origIslandId[i][j] = islandCounter;
      ++islandSize;
      for (const [k, l] of getLandNbs(i, j)) {
        if (!discovered[k][l]) {
          toVisit.push([k, l]);
          discovered[k][l] = true;
        }
      }
    }
    islandSizes.push(islandSize);
    ++islandCounter;
  }

  function getLandNbs(i: number, j: number) {
    const allNbs: Coord[] = [];
    if (i > 0) {
      allNbs.push([i - 1, j]);
    }
    if (i <= m) {
      allNbs.push([i + 1, j]);
    }
    if (j > 0) {
      allNbs.push([i, j - 1]);
    }
    if (j < n) {
      allNbs.push([i, j + 1]);
    }
    return allNbs.filter(([i, j]) => (state[i][j] == Field.Land));
  }

  /* Initially, every island id is its own pivot. */
  const pivots: number[] = Array(islandCounter).fill(null).map((_, i) => i);

  function getId([i, j]: Coord): number {
    let id = origIslandId[i][j];
    while (pivots[id] != id) {
      id = pivots[id];
    }
    return id;
  }

  /* We now works backwards, removing water fields and union-merge islands.
   * We always merge the smaller island onto the larger one to keep the
   * averaged running time of getId small. This should hopefull keep the time
   * complexity of getId below O(log(m n)).*/

  if (havePath()) {
    return cells.length;
  }
  for (let day = cells.length - 1; day >= 0; --day) {
    addLand(cells[day][0], cells[day][1]);
    if (havePath()) {
      return day;
    }
  }

  function addLand(i: number, j: number): void {
    state[i][j] = Field.Land;
    const nbs: Coord[] = getLandNbs(i, j);
    if (nbs.length == 0) {
      const id = islandCounter;
      origIslandId[i][j] = id;
      pivots.push(id);
      islandSizes.push(1);
      ++islandCounter;
      return;
    }
    for (let k = 0; k < nbs.length; ++k) {
      for (let l = k + 1; l < nbs.length; ++l) {
        mergeIslandsByCoords(nbs[k], nbs[l]);
      }
    }
    origIslandId[i][j] = getId(nbs[0]);
  }

  function mergeIslandsByCoords(c1: Coord, c2: Coord) {
    const id1 = getId(c1);
    const id2 = getId(c2);
    mergeIslandsByIds(id1, id2);
  }

  /* We attach the smaller island to the larger one. */
  function mergeIslandsByIds(id1: number, id2: number) {
    if (id1 == id2) {
      return;
    }
    const size1 = islandSizes[id1];
    const size2 = islandSizes[id2];
    if (size1 > size2) {
      pivots[id2] = id1;
      islandSizes[id1] += size2;
    } else {
      pivots[id1] = id2;
      islandSizes[id2] += size1;
    }
  }

  /* To check if a path from the top to the bottom exists, we only need to
   * check if the fields (0, 1) and (m + 1, 1) (belonging to the fictional
   * rows) are on the same island. */
  function havePath(): boolean {
    return getId([0, 1]) == getId([m + 1, 1]);
  }

  /* We should never get here. */
  return -1;
}
