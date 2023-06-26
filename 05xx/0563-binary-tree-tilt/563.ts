/* 563. Binary Tree Tilt */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree,
 * and h is the height of the tree. */

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

/* Don’t copy the above to LeetCode. */

function findTilt(root: TreeNode | null): number {
  const [_, tiltSum] = sumsValueTilt(root);
  return tiltSum;
}

function sumsValueTilt(
  root: TreeNode | null,
): [valueSum: number, tiltSum: number] {
  if (root === null) {
    return [0, 0];
  }

  const [leftValueSum, leftTiltSum] = sumsValueTilt(root.left);
  const [rightValSum, rightTiltSum] = sumsValueTilt(root.right);
  const rootValueSum = leftValueSum + root.val + rightValSum;
  const rootTilt = Math.abs(leftValueSum - rightValSum);
  const rootTiltSum = leftTiltSum + rootTilt + rightTiltSum;

  return [rootValueSum, rootTiltSum];
}
