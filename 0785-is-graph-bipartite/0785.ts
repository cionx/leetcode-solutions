type Vertex = number;
type Graph = Vertex[][];

function isBipartite(graph: Graph): boolean {
  enum Color {
    NoColor,
    Red,
    Blue,
  }

  const n = graph.length;
  if (n == 0) return true;

  const coloring: Color[] = new Array(n);
  coloring.fill(Color.NoColor);

  function oppositeColor(v: Vertex): Color {
    return coloring[v] == Color.Red ? Color.Blue : Color.Red;
  }

  function isColored(v: Vertex) {
    return coloring[v] != Color.NoColor;
  }

  function setColor(v: Vertex, c: Color = Color.Red) {
    coloring[v] = c;
  }

  function sameColor(v: Vertex, w: Vertex) {
    return coloring[v] == coloring[w];
  }

  function checkComponent(v: Vertex) {
    if (isColored(v)) return true;

    const vertices: Vertex[] = [];
    setColor(v);
    vertices.push(v);

    while (vertices.length > 0) {
      const v = vertices.pop() as Vertex; // We won’t get undefined.
      for (const w of graph[v]) {
        if (isColored(w)) {
          if (sameColor(v, w)) return false;
          // Everything is fine if v and w have different colors.
        } else {
          setColor(w, oppositeColor(v));
          vertices.push(w);
        }
      }
    }

    return true;
  }

  for (let v: Vertex = 0; v < n; v++) {
    if (!checkComponent(v)) return false;
  }

  return true;
}
