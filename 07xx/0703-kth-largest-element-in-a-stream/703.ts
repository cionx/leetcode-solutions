/* 703. Kth Largest Element in a Stream */

class KthLargest {
  largest: number[]; // The k largest numbers in ascending order.

  constructor(k: number, nums: number[]) {
    this.largest = Array(k).fill(-Infinity);
    for (let i = 0; i < nums.length; ++i) {
      this.add(nums[i]);
    }
  }

  add(value: number): number {
    const position = this.findPosition(value);
    if (position >= 0) {
      this.insert(value, position);
    }
    return this.largest[0];
  }

  /* return -1 if not added */
  private findPosition(value: number): number {
    if (value <= this.largest[0]) {
      return -1;
    }
    let lower = 0;
    let upper = this.largest.length - 1;
    while (lower < upper) { // With lower < upper, the loop may not terminate
      const middle = Math.ceil((lower + upper) / 2); // fuck JS for not having integers
      if (value > this.largest[middle]) {
        lower = middle;
      } else {
        upper = middle - 1;
      }
    }

    return lower;
  }

  private insert(value: number, position: number) {
    for (let i = 0; i < position; ++i) {
      this.largest[i] = this.largest[i + 1];
    }
    this.largest[position] = value;
  }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * var obj = new KthLargest(k, nums)
 * var param_1 = obj.add(val)
 */
