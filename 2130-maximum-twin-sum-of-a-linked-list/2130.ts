class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function pairSum(head: ListNode | null): number {
  // Convert the linged list to an array.
  const entries: number[] = [];
  while (head != null) {
    entries.push(head.val);
    head = head.next;
  }

  // Now compute all twin sums and remember the maximal one.
  let sum = 0;
  const limit = entries.length / 2;
  for (let i = 0; i < limit; i++) {
    const new_sum = entries[i] + entries[entries.length - 1 - i];
    if (new_sum > sum)
      sum = new_sum;
  }

  return sum;
}
