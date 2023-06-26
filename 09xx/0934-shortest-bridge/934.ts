/* 934. Shortest Bridge */

/* Complexities.
 * Time: O(n^2)
 * Space: O(n^2)
 * where n × n is the size of the input matrix. */

enum Type {
  Water = 0,
  Land = 1,
}
type GridMap = Type[][];
type Field = [number, number];

function shortestBridge(map: GridMap): number {
  const n = map.length;

  /* First, we need to find a piece of land */
  let start: Field = [0, 0]; // Initialize with arbitrary value.
  let found = false;
  for (let i = 0; !found; i++) { // Needs some land to exist.
    for (let j = 0; j < n; j++) {
      if (map[i][j] == Type.Land) {
        start = [i, j];
        found = true;
        break;
      }
    }
  }

  /* Now we record all water (non-diagonally) adjacent to the found island:
   * we go through all land pieces and remember every adjacent water piece. */
  const shore: Field[] = [];
  const toVisit: Field[] = [start];
  const visited: boolean[][] = Array(n).fill(null).map(() => Array(n).fill(false));

  while (toVisit.length > 0) {
    const [i, j] = toVisit.pop() as Field;
    if (!visited[i][j]) {
      if (map[i][j] == Type.Land) {
        if (i > 0) toVisit.push([i - 1, j]);
        if (i + 1 < n) toVisit.push([i + 1, j]);
        if (j > 0) toVisit.push([i, j - 1]);
        if (j + 1 < n) toVisit.push([i, j + 1]);
      } else {
        shore.push([i, j]);
      }
      visited[i][j] = true;
    }
  }
  /* We now have a list of all shore fields, and all fields on the shore,
   * as well as all field on the island are marked as visited. */

  /* We now perform a breadth-first search around the island. */
  let visitNow = shore;
  for (let distance = 1;; distance++) {
    const visitLater: Field[] = [];
    for (let k = 0; k < visitNow.length; k++) {
      const [i, j] = visitNow[k];
      /* Above */
      if (i > 0 && !visited[i - 1][j]) {
        if (map[i - 1][j] == Type.Land) return distance;
        visitLater.push([i - 1, j]);
        visited[i - 1][j] = true;
      }
      /* Below */
      if (i + 1 < n && !visited[i + 1][j]) {
        if (map[i + 1][j] == Type.Land) return distance;
        visitLater.push([i + 1, j]);
        visited[i + 1][j] = true;
      }
      /* Left */
      if (j > 0 && !visited[i][j - 1]) {
        if (map[i][j - 1] == Type.Land) return distance;
        visitLater.push([i, j - 1]);
        visited[i][j - 1] = true;
      }
      /* Right */
      if (j + 1 < n && !visited[i][j + 1]) {
        if (map[i][j + 1] == Type.Land) return distance;
        visitLater.push([i, j + 1]);
        visited[i][j + 1] = true;
      }
    }
    visitNow = visitLater;
  }
}
