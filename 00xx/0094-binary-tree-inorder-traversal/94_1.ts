/* 94. Binary Tree Inorder Traversal */

/* Recursive solution */

/* Complexities
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree
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
  function aux(left: number[], root: NodeOrLeaf): number[] {
    if (root === null) {
      return left;
    }
    const newLeft = aux(left, root.left);
    newLeft.push(root.val);
    return aux(newLeft, root.right);
  }

  return aux([], root);
}
