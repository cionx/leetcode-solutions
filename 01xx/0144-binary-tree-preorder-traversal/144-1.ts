/* 144. Binary Tree Preorder Traversal */

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

function preorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];

  function addValues(root: TreeNode | null): void {
    if (root === null) {
      return;
    }
    result.push(root.val);
    addValues(root.left);
    addValues(root.right);
  }

  addValues(root);

  return result;
}
