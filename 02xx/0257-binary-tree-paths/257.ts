/* 257. Binary Tree Paths */

/* Complexities.
 * Time: ?
 * Space: ? */

/* Recursive solution, bottom to top */

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

function binaryTreePaths(root: TreeNode | null): string[] {
  if (root === null) {
    return [];
  }
  if (root.left === null && root.right === null) {
    return [`${root.val}`];
  }
  const prefix = `${root.val}->`;
  return binaryTreePaths(root.left)
    .concat(binaryTreePaths(root.right))
    .map((path) => prefix + path);
}
