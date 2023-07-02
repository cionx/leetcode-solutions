/* 1161. Maximum Level Sum of a Binary Tree */

/* Complexities.
 * Time: O(n)
 * Space: with tail recursion elimination: O(w)
 *        without tail recursion elimination: O(h + w)
 * where n is the number of nodes in the tree, and w is the “width” of the
 * tree (the largest number of nodes on the same level) and h is the height of
 * the tree. */

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
  function helper(
    levelNodes: TreeNode[],
    level: number,
    bestLevel: number,
    bestSum: number,
  ): number {
    if (levelNodes.length == 0) {
      return bestLevel;
    }

    const sum: number = levelNodes
      .map((node) => node.val)
      .reduce((a, b) => a + b, 0);
    if (sum > bestSum) {
      bestLevel = level;
      bestSum = sum;
    }

    const children = levelNodes
      .map((node) => [node.left, node.right])
      .flat()
      .filter((child): child is Exclude<typeof child, null> => child !== null);
    /* TS doesn’t automatically understand that we filtered out null. */
    return helper(children, level + 1, bestLevel, bestSum);
  }

  return helper([root], 1, 0, -Infinity);
}
