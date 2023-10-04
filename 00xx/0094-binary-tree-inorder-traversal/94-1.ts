/* 94. Binary Tree Inorder Traversal */

/* Recursive solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the tree, and h is its height. */

/* Don’t copy this class definition to LeetCode. */
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

function inorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];

  function addValues(root: TreeNode | null): void {
    if (root === null) {
      return;
    }
    addValues(root.left);
    result.push(root.val);
    addValues(root.right);
  }

  addValues(root);

  return result;
}
