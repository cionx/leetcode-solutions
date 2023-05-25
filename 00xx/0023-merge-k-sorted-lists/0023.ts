class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

/* Don’t copy the above to LeetCode. */

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  const tmpHead: ListNode = new ListNode();
  let tail: ListNode = tmpHead;

  const pointers: ListNode[] = [];
  for (let i = 0; i < lists.length; i++) {
    const list = lists[i]; /* TypeScript struggles otherwise. */
    if (list !== null) {
      pointers.push(list);
    }
  }

  while (pointers.length > 0) {
    let minIndex = 0;
    for (let i = 1; i < pointers.length; i++) {
      if (pointers[i].val < pointers[minIndex].val) {
        minIndex = i;
      }
    }
    tail.next = new ListNode(pointers[minIndex].val);
    tail = tail.next;
    const shifted = pointers[minIndex].next;
    if (shifted !== null) {
      pointers[minIndex] = shifted;
    } else {
      pointers.splice(minIndex, 1); // Probably expensive; DLL would be better.
    }
  }

  return tmpHead.next;
}
