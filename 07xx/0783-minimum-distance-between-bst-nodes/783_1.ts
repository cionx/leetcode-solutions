/* Time: O(n)
 * Space: O(n)
 *
 * where n is the number of nodes in the tree.
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

function treeToArray(root: TreeNode | null): number[] {
  function aux(left: number[], root: TreeNode | null): number[] {
    if (root == null) {
      return left;
    }
    const newLeft = aux(left, root.left);
    newLeft.push(root.val);
    return aux(newLeft, root.right);
  }
  return aux([], root);
}

function minDiffInBST(root: TreeNode | null): number {
  const arr = treeToArray(root);
  console.log(arr);

  let minDiff = arr[1] - arr[0];
  for (let i = 2; i < arr.length; ++i) {
    const newDiff = arr[i] - arr[i - 1];
    if (newDiff < minDiff) {
      minDiff = newDiff;
    }
  }

  return minDiff;
}
