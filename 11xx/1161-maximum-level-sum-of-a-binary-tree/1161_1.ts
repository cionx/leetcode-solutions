/* Time: O(n)
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

function maxLevelSum(root: TreeNode): number {
  const levelSums: number[] = Array(height(root) + 1).fill(0);

  function height(root: TreeNode | null): number {
    if (root === null) {
      return 0;
    }
    return 1 + Math.max(height(root.left), height(root.right));
  }

  function addNodes(root: TreeNode | null, rootLevel: number): void {
    if (root === null) {
      return;
    }
    levelSums[rootLevel] += root.val;
    addNodes(root.left, rootLevel + 1);
    addNodes(root.right, rootLevel + 1);
  }

  addNodes(root, 1);

  let richestLevel = 1;
  for (let level = 2; level < levelSums.length; ++level) {
    if (levelSums[level] > levelSums[richestLevel]) {
      richestLevel = level;
    }
  }
  return richestLevel;
}
