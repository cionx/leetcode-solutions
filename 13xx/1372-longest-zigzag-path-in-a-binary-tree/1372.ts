/* 1372. Longest ZigZag Path in a Binary Tree */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of vertices in the tree, and h is its height. */

/* Idea.
 * We determine for each node in the tree three numbers.
 * - The longest ZigZag path starting at the node in left direction.
 * - The longest ZigZag path starting at the node in right direction.
 * - The longest ZigZag path in the subtree below the node. */

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

type ReturnValue = [zagLeft: number, zagRight: number, zagMax: number];

function longestZigZag(root: TreeNode | null): number {
  return threeValues(root)[2];
}

function threeValues(root: TreeNode | null): ReturnValue {
  if (root === null) {
    return [-1, -1, -1];
  }

  const [_leftZagLeft, leftZagRight, leftZagMax] = threeValues(root.left);
  const [rightZagLeft, _rightZagRight, rightZagMax] = threeValues(root.right);

  const curZagLeft = leftZagRight + 1;
  const curZagRight = rightZagLeft + 1;
  const curZagMax = Math.max(curZagLeft, curZagRight, leftZagMax, rightZagMax);

  return [curZagLeft, curZagRight, curZagMax];
}
