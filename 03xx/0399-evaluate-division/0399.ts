/* Consider a graph whose vertices are the variables ocurring in `equations`,
   and where every equation-value-pair gives a directed edge: the equation
   a/b = 2 is an edge from b to a with value 2 (since a = 2b).
 * We start off with no edges, and then keep track of the (undirected)
   connected component as we keep adding the edges. In every component,
   we choose one vertex as a root. For every other vertex in the same
   component we keep track of the factor  coeff  for which
     vertex = coeff * root.
 * To make the code easier, we associate to every variable a numerical id. */

type Variable = string;
type Id = number;
type Equation = [Variable, Variable];
type Component = {
  ids: Id[];
  root: Id;
};

function calcEquation(
  equations: Equation[],
  values: number[],
  queries: Equation[],
) {
  /* We represent every variable occurring in an equation by an id.
     Not every id has an associated variable; the variables that
     appear in the queries but not in the equations get no id. */
  const idOfVar: Map<Variable, Id> = new Map();
  for (let i = 0; i < equations.length; i++) {
    idOfVar.set(equations[i][0], 2 * i);
    idOfVar.set(equations[i][1], 2 * i + 1);
  }
  const maxVarNumber = 2 * equations.length;
  /* In the following, we will save intermediate information in arrays.
     For simplicity, we will have entries for non-assigned ids,
     even though it costs a few more bytes. */

  /* In the beginning, every vertex is its own component. */
  const componentOfId: Component[] = new Array(maxVarNumber);
  for (let i = 0; i < maxVarNumber; i++) {
    componentOfId[i] = { ids: [i], root: i };
  }
  /* Therefore, every vertex is the root of its component, giving
     a multiplicative coefficient of 1 between the vertex and the root. */
  const coefficients: number[] = new Array(maxVarNumber);
  coefficients.fill(1);

  function mergeComponents(id1: Id, id2: Id, value: number): void {
    const comp1 = componentOfId[id1];
    const comp2 = componentOfId[id2];
    /* Two components are equal if and only if they have the same root. */
    if (comp1.root == comp2.root) return;
    const newComp: Component = {
      ids: comp1.ids.concat(comp2.ids),
      root: comp1.root, // comp2.root would be equally good.
    };
    for (let i = 0; i < newComp.ids.length; i++) {
      componentOfId[newComp.ids[i]] = newComp;
    }
    /* v1 = coeff1 * root1,
       v2 = coeff2 * root2,
       v1 = value * v2,
       gives
       root2 = root1 * (coeff1 / value / coeff2). */
    const factor = coefficients[id1] / value / coefficients[id2];
    for (let j = 0; j < comp2.ids.length; j++) {
      coefficients[comp2.ids[j]] *= factor;
    }
  }

  /* Incorporate all the equations, but do not check for consistency. */
  for (let i = 0; i < equations.length; i++) {
    const eq = equations[i];
    const id1 = idOfVar.get(eq[0]) as Id;
    const id2 = idOfVar.get(eq[1]) as Id;
    const value = values[i];
    mergeComponents(id1, id2, value);
  }

  function queryValue(var1: Variable, var2: Variable): number {
    /* Variables not occurring in the equations always give -1.
       Mathematically, we should actually return 1 if var1 == var2,
       but the exercise is weird. */
    const id1 = idOfVar.get(var1);
    if (id1 === undefined) return -1;
    const id2 = idOfVar.get(var2);
    if (id2 === undefined) return -1;
    /* Otherwise, two variables are in the same component
       if and only if their components have the same root. */
    const comp1 = componentOfId[id1];
    const comp2 = componentOfId[id2];
    if (comp1.root != comp2.root) {
      return -1;
    }
    /* Finally,  v1 = c1 * r  and  v2 = c2 * r  results in
       v1 / v2  =  (c1 * r) / (c2 * r)  =  c1 / c2 .       */
    return coefficients[id1] / coefficients[id2];
  }

  return queries.map(([var1, var2]) => queryValue(var1, var2));
}
