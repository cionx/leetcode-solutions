type Fn<T, U> = (accum: U, curr: T) => U

function reduce<T, U>(nums: T[], fn: Fn<T, U>, init: U): U {
  while (nums.length > 0) {
    init = fn(init, <T>nums.shift());
  }
  return init;
}
