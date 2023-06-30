/* 894. Shortest Path to Get All Keys */

/* Complexities.
 * Time: O(m n 2^k)
 * Space: O(m n 2^k)
 * where m × n is the size of the input grid, and k is the number of keys. */

class MyQueue<T> {
  front: T[];
  back: T[];

  constructor() {
    this.front = [];
    this.back = [];
  }

  enqueue(value: T) {
    this.back.push(value);
  }

  dequeue() {
    if (this.front.length == 0) {
      this.front = this.back;
      this.front.reverse();
      this.back = [];
    }
    return this.front.pop();
  }

  get size() {
    return this.front.length + this.back.length;
  }
}

function shortestPathAllKeys(grid: string[]): number {
  const m = grid.length;
  const n = grid[0].length;

  let keyNumber = 0;
  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      if (isKey(grid[i][j])) {
        ++keyNumber;
      }
    }
  }

  type Mask = number;
  const maskNumber = 1 << keyNumber;
  const fullMask = maskNumber - 1;

  type Level = boolean[][];
  type State = [keys: Mask, steps: number, i: number, j: number];

  /* We first have to prepare the cache. (LeetCode’s version of Node.js is too
   * outdated to support structuredClone. We therefore have to fake it.) */

  const blueprint: Level = Array(m)
    .fill(null)
    .map((_, i) => grid[i].split("").map(isWall));

  function makeLevel(): Level {
    return Array(m)
      .fill(null)
      .map((_, i) => Array.from(blueprint[i])); /* Array.from shallow copies. */
  }

  const discovered: Level[] = Array(maskNumber)
    .fill(null)
    .map(() => makeLevel());


  /* Now we find the start field, and add it to the queue of fields-to-visit. */

  let start: [number, number] = [-1, -1];
  for (let i = 0; start[0] == -1 && i < m; ++i) {
    for (let j = 0; start[0] == -1 && j < n; ++j) {
      if (isStart(grid[i][j])) {
        start = [i, j];
      }
    }
  }

  const startMask = 0;
  const toVisit: MyQueue<State> = new MyQueue();
  toVisit.enqueue([startMask, 0, start[0], start[1]]);
  discovered[startMask][start[0]][start[1]] = true;

  let current: State | undefined;
  while ((current = toVisit.dequeue()) != undefined) {
    let [mask, steps, i, j] = current;
    const field = grid[i][j];
    if (isKey(field)) {
      mask |= maskOfKey(field);
      if (mask == fullMask) {
        return steps;
      }
      discovered[mask][i][j] = true;
    }
    visitLater(mask, steps + 1, i - 1, j);
    visitLater(mask, steps + 1, i + 1, j);
    visitLater(mask, steps + 1, i, j + 1);
    visitLater(mask, steps + 1, i, j - 1);
  }

  function visitLater(mask: Mask, steps: number, i: number, j: number) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return;
    }
    if (isWall(grid[i][j])) {
      return;
    }
    if (discovered[mask][i][j]) {
      return;
    }
    if (isLock(grid[i][j]) && (mask & maskOfLock(grid[i][j])) == 0) {
      return;
    }
    toVisit.enqueue([mask, steps, i, j]);
    discovered[mask][i][j] = true;
  }

  /* Auxiliary functions. */

  function isKey(c: string) {
    const ascii = c.charCodeAt(0);
    return 97 <= ascii && ascii <= 122;
  }

  function isLock(c: string) {
    const ascii = c.charCodeAt(0);
    return 65 <= ascii && ascii <= 90;
  }

  function isStart(c: string) {
    return c == "@";
  }

  function isWall(c: string) {
    return c === "#";
  }
  function maskOfKey(c: string) {
    return 1 << (c.charCodeAt(0) - 97);
  }

  function maskOfLock(c: string) {
    return 1 << (c.charCodeAt(0) - 65);
  }

  /* We only end up down here if we didn’t find a path. */

  return -1;
}
