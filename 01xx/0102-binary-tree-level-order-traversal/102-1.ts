/* 102. Binary Tree Level Order Traversal */

/* Recursive solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the tree, and h is its height. */

/* Do not copy this class definition to LeetCode. */
class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function levelOrder(root: TreeNode | null): number[][] {
  function height(root: TreeNode | null): number {
    if (root == null) {
      return 0;
    }
    return 1 + Math.max(height(root.left), height(root.right));
  }

  const result: number[][] = [];
  const h = height(root);
  for (let i = 0; i < h; ++i) {
    result[i] = [];
  }

  function addValue(root: TreeNode | null, level: number) {
    if (root == null) {
      return;
    }
    result[level].push(root.val);
    addValue(root.left, level + 1);
    addValue(root.right, level + 1);
  }

  addValue(root, 0);

  return result;
}
