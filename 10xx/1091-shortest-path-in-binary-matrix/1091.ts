/* 1091. Shortest Path in Binary Matrix */

class MyQueue<T> {
  /* Queue seems to be already defined in LeetCode? */
  front: T[]; /* Will be in reverse order to allow pop instead of shift. */
  back: T[];

  constructor() {
    this.front = [];
    this.back = [];
  }

  isEmpty(): boolean {
    return this.front.length == 0;
  }

  enqueue(value: T): void {
    this.back.push(value);
  }

  dequeue(): T | undefined {
    if (this.front.length == 0) {
      this.moveBackToFront();
    }
    return this.front.pop();
  }

  private moveBackToFront() {
    this.front = this.back.reverse();
    this.back = [];
  }
}

type Matrix<T> = T[][];
type Grid = Matrix<0 | 1>;
type Field = [row: number, column: number];

function shortestPathBinaryMatrix(grid: Grid): number {
  const n = grid.length;

  function newMatrix<T>(initial: T): Matrix<T> {
    return Array(n).fill(null).map(() => Array(n).fill(initial));
  }

  const toVisit = new MyQueue<Field>();
  const discovered: Matrix<boolean> = newMatrix(false);
  const distances: Matrix<number> = newMatrix(-1);

  function isAllowed([i, j]: Field) {
    return grid[i][j] == 0;
  }

  function undiscoveredNeighbors(field: Field): Field[] {
    const result: Field[] = [];
    const [i0, j0] = field;
    for (let di = -1; di <= 1; ++di) {
      for (let dj = -1; dj <= 1; ++dj) {
        const i = i0 + di;
        const j = j0 + dj;
        if (
          0 <= i && i < n && 0 <= j && j < n &&
          isAllowed([i, j]) && !discovered[i][j]
        ) {
          result.push([i, j]);
        }
      }
    }
    return result;
  }

  if (!isAllowed([0, 0])) {
    return -1;
  }
  distances[0][0] = 1;
  discovered[0][0] = true;

  for (
    let field: Field | undefined = [0, 0];
    field !== undefined;
    field = toVisit.dequeue()
  ) {
    const [i0, j0] = field;
    if (i0 == n - 1 && j0 == n - 1) {
      return distances[i0][j0];
    }
    const newDistance = distances[i0][j0] + 1;
    for (const [i, j] of undiscoveredNeighbors(field)) {
      distances[i][j] = newDistance;
      toVisit.enqueue([i, j]);
      discovered[i][j] = true;
    }
  }

  return -1;
}
