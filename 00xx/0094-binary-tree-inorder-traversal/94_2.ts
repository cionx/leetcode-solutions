/* Iterative solution
 *
 * Time: O(n)
 * Space: O(h)
 *
 * where n denotes the number of nodes in the tree,
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
  enum Direction {
    Above,
    BelowRight,
    BelowLeft,
  }

  /* pathNodes and pathDirections:
   * The path from root to current node, and the directions we took along the
   * way. For each node in the path we have exactly one ingoing direction.
   */
  const pathNodes: NodeOrLeaf[] = [root];
  const pathDirections: Direction[] = [Direction.Above];
  /* whereFrom:
   * How we got to the current node. If we came from above, then this is the
   * same as the last entry in pathDirections. But if we came from below, then
   * it cannot be derived from the entries of pathDirections.
   */
  let whereFrom: Direction = Direction.Above;

  const result: number[] = [];
  while (pathNodes.length > 0) {
    const currentNode: NodeOrLeaf = pathNodes.at(-1) as NodeOrLeaf;
    /* We have the following steps:
     * - If the node is null, then there’s nothing to see here. We then return
     *   upwards.
     * - Otherwise, and if we just came from above, then we first descend into
     *   the left subtree.
     * - At some point in the future we will come back up from the left subtree.
     *   We then append the the current node onto the result so far, and then
     *   descend into the right subtree.
     * - Once we come back from the right subtree, we are finished with the node
     *   and all its children. We then return upwards.
     */
    if (currentNode === null || whereFrom == Direction.BelowRight) {
      pathNodes.pop();
      whereFrom = pathDirections.pop() as Direction;
    }
    else if (whereFrom == Direction.Above) {
      pathNodes.push(currentNode.left);
      pathDirections.push(Direction.BelowLeft);
      whereFrom = Direction.Above;
    }
    else if (whereFrom == Direction.BelowLeft) {
      result.push(currentNode.val);
      pathNodes.push(currentNode.right);
      pathDirections.push(Direction.BelowRight);
      whereFrom = Direction.Above;
    }
  }

  return result;
}
