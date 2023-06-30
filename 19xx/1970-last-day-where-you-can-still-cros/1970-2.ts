/* 1970. Last Day Where You Can Still Cross. */

/* Coplexities.
 * Time: Θ(m n log(m n))
 * Space: Θ(m n)
 * where m × n is the size of the input grid. */

/* Idea.
 * We search for the correct day with binay search. We use BFS to check if we
 * can go from the top to the bottom on a specified day (and therefore also on
 * all previous days). More explicitly, we add a row of land to the top and
 * bottom of the map, and check if we can go from the top row to the bottom row
 * via BFS. The additional row on top also makes handeling the 1-indexed
 * coordinates easier. We add a column of water to the left of the map, so that
 * we can truly use the 1-indexed coordinates without change.  */

class MyQueue<T> {
  front: T[];
  back: T[];

  constructor() {
    this.front = [];
    this.back = [];
  }

  push(value: T): void {
    this.back.push(value);
  }

  pop(): T | undefined {
    if (this.front.length == 0) {
      this.front = this.back;
      this.front.reverse();
      this.back = [];
    }
    return this.front.pop();
  }
}

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

  const state: Grid<Field> = createGrid(m + 2, n + 1, Field.Land);
  for (let i = 0; i <= m + 1; ++i) {
    state[i][0] = Field.Water;
  }
  /* We use a cache to avoid recomputing the neighbours of a field. */
  const nhbCache: Grid<null | Coord[]> = createGrid(m + 2, n + 1, null);

  let lower = 0;
  let upper = cells.length;
  let current = 0;
  while (lower < upper) {
    const middle = Math.ceil(lower + (upper - lower) / 2);
    changeState(current, middle);
    current = middle;
    if (havePath()) {
      lower = middle;
    } else {
      upper = middle - 1;
    }
  }

  function changeState(from: number, to: number) {
    /* If we go forward in time, then we add water. */
    for (let day = from; day < to; ++day) {
      const [i, j] = cells[day];
      state[i][j] = Field.Water;
    }
    /* But if we go backward, then we add land. */
    for (let day = from - 1; day >= to; --day) {
      const [i, j] = cells[day];
      state[i][j] = Field.Land;
    }
  }

  function havePath(): boolean {
    /* We try to get from the top to the bottom via BFS. */
    const toVisit: MyQueue<Coord> = new MyQueue();
    const discovered = createGrid(m + 2, n + 1, false);
    toVisit.push([0, 1]);
    discovered[0][1] = true;
    let current: Coord | undefined;
    while ((current = toVisit.pop()) !== undefined) {
      const [i, j] = current;
      const landNeighbors = neighbors(i, j)
        .filter(([k, l]) => state[k][l] == Field.Land);
      for (const [k, l] of landNeighbors) {
        if (!discovered[k][l]) {
          if (k == m + 1) {
            return true;
          }
          toVisit.push([k, l]);
          discovered[k][l] = true;
        }
      }
    }
    return false;
  }

  function neighbors(i: number, j: number): Coord[] {
    let result = nhbCache[i][j];
    if (result !== null) {
      return result;
    }
    result = [];
    if (i > 0) {
      result.push([i - 1, j]);
    }
    if (i <= m) {
      result.push([i + 1, j]);
    }
    if (j > 0) {
      result.push([i, j - 1]);
    }
    if (j < n) {
      result.push([i, j + 1]);
    }
    nhbCache[i][j] = result;
    return result;
  }

  return upper;
}
