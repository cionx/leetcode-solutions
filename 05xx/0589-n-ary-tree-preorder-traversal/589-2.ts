/* 589. N-ary Tree Preorder Traversal */

/* Recursive solution, immutable arrays. */

/* Complexities.
 * Time: O(n)
 * Space: ?
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
  if (root === null) {
    return [];
  }
  return [root.val].concat(...root.children.map(preorder).flat());
}
