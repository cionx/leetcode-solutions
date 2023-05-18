function partiallyApplied(fn, prevArgs) {
  return function (...newArgs) {
    const totalArgs = prevArgs.concat(newArgs);
    if (totalArgs.length >= fn.length) {
      return fn(...totalArgs);
    } else {
      return partiallyApplied(fn, totalArgs);
    }
  };
}

function curry(fn) {
  return partiallyApplied(fn, []);
}
