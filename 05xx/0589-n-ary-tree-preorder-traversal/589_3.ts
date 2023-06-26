/* 589. N-ary Tree Preorder Traversal */

/* Iterative solution */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree,
 * and h is the height of the tree.
 */

class Node {
  val: number;
  children: Node[];
  constructor(val?: number) {
    this.val = val === undefined ? 0 : val;
    this.children = [];
  }
}

/* Do not copy the above class definition to LeetCode. */

type MaybeNode = Node | null;
type Direction = number; /* integers -1, 0, 1, 2, ... */

function preorder(root: MaybeNode): number[] {
  if (root === null) {
    return [];
  }

  let current: Node = root;
  const pathFromRoot: Node[] = [root];
  /* pathFromRoot:
   * The path from the root to the current node, as a sequence of nodes. Does
   * not include the current node!
   */
  const directionFromRoot: Direction[] = [0];
  let lastDirection: Direction = -1;
  /* directionFromRoot:
   * lastDirection:
   * - The directions that pathFromRoot took, and the direction where we last
   *   came from. -1 means we came from above. 0, 1, 2, ... means that we came
   *   from below, from the child with this specific index.
   * - The value of lastDirection is -1 if we came from above. Otherwise, it is
   *   the index of the child we just returned from. The entries of
   *   directionFromRoot are always 0, 1, 2, ..., never -1.
   * - At the beginning, we pretend that we came from a fictional node situated
   *   above the root. The upcoming main loop will stop once we return to this
   *   fictional node.
   */

  const result: number[] = [];

  while (pathFromRoot.length > 0) {
    if (lastDirection == -1) {
      result.push(current.val);
    }
    const next = lastDirection + 1;
    if (next < current.children.length) {
      pathFromRoot.push(current);
      directionFromRoot.push(next);
      lastDirection = -1;
      current = current.children[next];
    } else {
      current = pathFromRoot.pop() as Node;
      lastDirection = directionFromRoot.pop() as number;
    }
  }

  return result;
}
