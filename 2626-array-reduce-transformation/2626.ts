type Fn<T, U> = (accum: U, curr: T) => U

function reduce<T, U>(nums: T[], fn: Fn<T, U>, init: U): U {
  for (let i = 0; i < nums.length; i++) {
    init = fn(init, nums[i]);
  }
  return init;
}


// the following should be safer, but needs Node.js 17
function reduce<T, U>(nums: T[], fn: Fn<T, U>, init: U): U {
  let result = structuredClone(init);

  for (let i = 0; i < nums.length; i++) {
    result = fn(result, nums[i]);
  }
  return init;
}
