/* 145. Binary Tree Postorder Traversal */

/* Iterative solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: ?
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

/* Instead of left -> right -> value, we are using value -> right -> left,
 * and afterwards reverse the resulting list.
 */
function postorderTraversal(root: TreeNode | null): number[] {
  const result: number[] = [];

  const yetToVisitLeftBranches = [];
  let current: TreeNode | null = root;
  while (current !== null || yetToVisitLeftBranches.length > 0) {
    while (current !== null) {
      result.push(current.val);
      yetToVisitLeftBranches.push(current.left);
      current = current.right;
    }
    current = yetToVisitLeftBranches.pop() || null;
  }

  result.reverse();
  return result;
}
