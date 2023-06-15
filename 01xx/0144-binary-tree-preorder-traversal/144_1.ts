/* Recursive solution
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

function preorderTraversal(root: NodeOrLeaf): number[] {
  function addValues(tmpResult: number[], root: NodeOrLeaf): void {
    if (root === null) {
      return;
    }
    tmpResult.push(root.val);
    addValues(tmpResult, root.left);
    addValues(tmpResult, root.right);
  }

  const result: number[] = [];
  addValues(result, root);

  return result;
}
