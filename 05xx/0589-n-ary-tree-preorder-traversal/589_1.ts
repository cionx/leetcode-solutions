/* Recursive solution, mutable arrays
 * Time: O(n)
 * Space: O(h)
 *
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

function preorder(root: MaybeNode): number[] {
  function addNodes(toTheLeft: number[], root: MaybeNode): void {
    if (root === null) {
      return;
    }
    toTheLeft.push(root.val);
    for (let i = 0; i < root.children.length; ++i) {
      addNodes(toTheLeft, root.children[i]);
    }
  }

  const result: number[] = [];
  addNodes(result, root);

  return result;
}
