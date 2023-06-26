/* 429. N-ary Tree Level Order Traversal */

/* Recursive solution. */

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

function levelOrder(root: Node | null): number[][] {
  if (root === null) {
    return [];
  }

  function height(root: Node): number {
    return 1 + Math.max(0, ...root.children.map(height));
  }

  const result: number[][] = Array(height(root)).fill(null).map(() => []);

  function addNodes(node: Node, level: number) {
    result[level].push(node.val);
    /* We are using a for-loop to enforce the required order. */
    for (let i = 0; i < node.children.length; ++i) {
      addNodes(node.children[i], level + 1);
    }
  }

  addNodes(root, 0);

  return result;
}
