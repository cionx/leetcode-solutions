/* Time: O(n)
 * Space: O(h)
 *
 * where n is the number of nodes in the tree,
 * and h is the height of the tree.
 *
 * Same code as for Problem 530.
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

function minDiffInBST(root: TreeNode): number {
  function helper(node: TreeNode): [minDiff: number, min: number, max: number] {
    let min = node.val;
    let max = node.val;
    let minDiff = Infinity;

    if (node.left !== null) {
      const [minDiffLeft, minLeft, maxLeft] = helper(node.left);
      min = Math.min(min, minLeft);
      max = Math.max(max, maxLeft);
      minDiff = Math.min(minDiff, minDiffLeft, node.val - maxLeft);
    }
    if (node.right !== null) {
      const [minDiffRight, minRight, maxRight] = helper(node.right);
      min = Math.min(min, minRight);
      max = Math.max(max, maxRight);
      minDiff = Math.min(minDiff, minDiffRight, minRight - node.val);
    }

    return [minDiff, min, max];
  }

  const [minDiff, _min, _max] = helper(root);
  return minDiff;
}
