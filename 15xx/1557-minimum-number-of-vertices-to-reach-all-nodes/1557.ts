/* 1557. Minimum Number of Vertices to Reach All Nodes */

/** The result are precisely those vertices that don’t have an incoming edge. **/

function findSmallestSetOfVertices(n: number, edges: number[][]): number[] {
  const source = new Array<boolean>(n);
  source.fill(true);
  for (let i = 0; i < edges.length; i++) {
    source[edges[i][1]] = false;
  }

  const result: number[] = [];
  for (let i = 0; i < n; i++) {
    if (source[i]) {
      result.push(i);
    }
  }

  return result;
}
