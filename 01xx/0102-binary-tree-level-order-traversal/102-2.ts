/* 102. Binary Tree Level Order Traversal */

/* Iterative solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: O(n)
 * where n is the number of nodes in the tree. */

/* An auxiliary class for queues. */
class MyQueue<T> {
  private front: T[];
  private back: T[];

  constructor() {
    this.front = [];
    this.back = [];
  }

  enqueue(value: T): void {
    this.back.push(value);
  }

  dequeue(): T | undefined {
    if (this.front.length == 0) {
      this.front = this.back.reverse();
      this.back = [];
    }
    return this.front.pop();
  }

  isEmpty(): boolean {
    return this.front.length == 0 && this.back.length == 0;
  }
}

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

type levelNode = [height: number, node: TreeNode | null];

function levelOrder(root: TreeNode | null): number[][] {
  function height(root: TreeNode | null): number {
    if (root == null) {
      return 0;
    }
    return 1 + Math.max(height(root.left), height(root.right));
  }

  const result: number[][] = [];
  const h = height(root);
  for (let i = 0; i < h; ++i) {
    result[i] = [];
  }

  const toVisit: MyQueue<levelNode> = new MyQueue();
  toVisit.enqueue([0, root]);
  while (!toVisit.isEmpty()) {
    const [level, node] = toVisit.dequeue() as levelNode;
    if (node == null) {
      continue;
    }
    result[level].push(node.val);
    toVisit.enqueue([level + 1, node.left]);
    toVisit.enqueue([level + 1, node.right]);
  }

  return result;
}
