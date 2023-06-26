/* 430. Flatten Multilevel Doubly Linked List */

class Node {
  val: number;
  prev: Node | null;
  next: Node | null;
  child: Node | null;
  constructor(val?: number, prev?: Node, next?: Node, child?: Node) {
    this.val = val === undefined ? 0 : val;
    this.prev = prev === undefined ? null : prev;
    this.next = next === undefined ? null : next;
    this.child = child === undefined ? null : child;
  }
}

/* Do not copy the above to LeetCode. */

function flatten(head: Node | null): Node | null {
  if (head == null) {
    return null;
  }

  const flatRest = concat(flatten(head.child), flatten(head.next));

  const node = new Node(head.val);
  if (head.prev !== null) {
    link(head.prev, node);
  }
  if (flatRest !== null) {
    link(node, flatRest);
  }

  return node;
}

function concat(before: Node | null, after: Node | null): Node | null {
  /* Auxiliary function to concatenate `front` and `back` in that order */
  function iter(front: Node, back: Node): void {
    if (front.next === null) {
      link(front, back);
    }
    else {
      iter(front.next, back);
    }
  }
  if (before === null) { // Nested ifs to satisfy the type checker.
    if (after === null) {
      return null;
    }
    return after;
  }
  if (after !== null) {
    iter(before, after);
  }
  return before;
}

function link(node1: Node, node2: Node) {
  node1.next = node2;
  node2.prev = node1;
}
