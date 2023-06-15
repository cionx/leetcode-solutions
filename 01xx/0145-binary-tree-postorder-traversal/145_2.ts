/* Iterative solution
 *
 * Time: O(n)
 * Space: O(h)
 *
 * where n is the number of nodes in the tree,
 * and h is the height of the tree.
 */

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

/* Do not copy the above class definition to LeetCode. */

type NodeOrLeaf = TreeNode | null;

/* Instead of left -> right -> value, we are using value -> right -> left,
 * and afterwards reverse the resulting list.
 */
function postorderTraversal(root: NodeOrLeaf): number[] {
  const result: number[] = [];

  const yetToVisitLeftBranch = [];
  let current: NodeOrLeaf = root;
  while (current !== null || yetToVisitLeftBranch.length > 0) {
    while (current !== null) {
      result.push(current.val);
      yetToVisitLeftBranch.push(current);
      current = current.right;
    }
    current = yetToVisitLeftBranch.pop()?.left || null;
  }

  result.reverse();
  return result;
}
