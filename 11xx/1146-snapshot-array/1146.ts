/* 1146. Snapshot Array */

type SnapId = number;
type Index = number;
type entry = [SnapId, number];
type EntryHistory = entry[];

class SnapshotArray {
  /* TS’s type system doesn’t auto-support sparse arrays. */
  histories: (EntryHistory | undefined)[];
  currentSnapId: SnapId;

  constructor(length: number) {
    this.histories = Array(length); /* sparse array */
    this.currentSnapId = 0;
  }

  set(index: Index, value: number): void {
    const history = this.histories[index];
    if (history == undefined) {
      this.histories[index] = [[this.currentSnapId, value]];
    } else {
      history.push([this.currentSnapId, value]);
    }
  }

  snap(): SnapId {
    return this.currentSnapId++;
  }

  get(index: Index, snapId: SnapId): number {
    const history = this.histories[index];
    /* No history means that we never ever set a value at the index. */
    if (history == undefined) {
      return 0;
    }
    /* It may happen that a value at the specified index was first set after the
     * specified snapshot.
     */
    const firstEntry = history[0]; /* history is ensured to be nonempty. */
    if (firstEntry[0] > snapId) {
      return 0;
    }
    /* At this point, we know that we have some value at the specified index in
     * the specified snapshot. We search for the right entry with binary search.
     */
    let lower = 0;
    let upper = history.length - 1;
    while (lower < upper) {
      const middle = Math.ceil((lower + upper) / 2); /* rounded up */
      if (history[middle][0] > snapId) {
        upper = middle - 1;
      } else {
        lower = middle;
      }
    }
    return history[upper][1];
  }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * var obj = new SnapshotArray(length)
 * obj.set(index,val)
 * var param_2 = obj.snap()
 * var param_3 = obj.get(index,snap_id)
 */
