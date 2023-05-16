type ReturnObj = {
  increment: () => number;
  decrement: () => number;
  reset: () => number;
};

function createCounter(init: number): ReturnObj {
  let n: number = init;

  return {
    increment: (() => ++n),
    decrement: (() => --n),
    reset: (() => n = init),
  };
}
