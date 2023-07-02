/* 94. Binary Tree Inorder Traversal */

/* Iterative solution, as explained in the editorial. */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
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

/* Don’t copy the above class definition to LeetCode. */

type NodeOrLeaf = TreeNode | null;

function inorderTraversal(root: NodeOrLeaf): number[] {
  const result: number[] = [];
  const yetToCheckOutRightChild: TreeNode[] = [];

  let current: NodeOrLeaf = root;
  while(current !== null || yetToCheckOutRightChild.length > 0) {
    while (current !== null) {
      yetToCheckOutRightChild.push(current);
      current = current.left;
    }
    current = yetToCheckOutRightChild.pop() as TreeNode;
    result.push(current.val);
    current = current.right;
  }

  return result;
}
