/* 144. Binary Tree Preorder Traversal */

/* Iterative solution. */

/* Complexities
 * Time: O(n)
 * Space: ?
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

function preorderTraversal(root: NodeOrLeaf): number[] {
  const result: number[] = [];

  const yetToVisitRightBranch = [];
  let current: NodeOrLeaf = root;
  while (current != null || yetToVisitRightBranch.length > 0) {
    while (current != null) {
      result.push(current.val);
      yetToVisitRightBranch.push(current);
      current = current.left;
    }
    /* The loop condition ensures that the array yetToVisitRightBranch is
     * nonempty at this point. */
    current = yetToVisitRightBranch.pop() as TreeNode;
    current = current.right;
  }

  return result;
}
