/* 144. Binary Tree Preorder Traversal */

/* Iterative solution. */

/* Complexities
 * Time: Θ(n)
 * Space: O(n)
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

  const yetToVisitRightBranches = [];

  let current: TreeNode | null = root;
  while (current != null || yetToVisitRightBranches.length > 0) {
    while (current != null) {
      result.push(current.val);
      yetToVisitRightBranches.push(current.right);
      current = current.left;
    }
    /* The outer loop condition ensures that the array yetToVisitRightBranches
     * is nonempty at this point. */
    current = yetToVisitRightBranches.pop() as TreeNode;
  }

  return result;
}
