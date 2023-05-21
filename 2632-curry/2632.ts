type Fn<T, U> = (...params: T[]) => U;
type CurFn<T, U> = (...params: T[]) => U | CurFn<T, U>;

function partiallyApplied<T, U>(fn: Fn<T, U>, prevArgs: T[]): CurFn<T, U> {
  return function (...newArgs: T[]): U | CurFn<T, U> {
    const totalArgs = prevArgs.concat(newArgs);
    if (totalArgs.length >= fn.length) {
      return fn(...totalArgs);
    } else {
      return partiallyApplied(fn, totalArgs);
    }
  };
}

function curry<T, U>(fn: Fn<T, U>): CurFn<T, U> {
  return partiallyApplied(fn, []);
}
