/* 113. Path Sum II */

/* Idea.
 * We use the same logic as in Problem 112. */

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

type Path = number[];

function pathSum(root: TreeNode | null, targetSum: number): Path[] {
  if (root === null) {
    return [];
  }

  /* Case: leaf */
  if (root.left === null && root.right === null) {
    return (root.val == targetSum) ? [[root.val]] : [];
  }

  /* Case: at least one child. */
  const leftPaths = pathSum(root.left, targetSum - root.val);
  const rightPaths = pathSum(root.right, targetSum - root.val);
  const result = leftPaths.concat(rightPaths);
  result.forEach((path) => path.unshift(root.val));

  return result;
}
