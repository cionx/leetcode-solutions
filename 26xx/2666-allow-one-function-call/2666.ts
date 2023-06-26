/* 2666. Allow One Function Call */

type Fn<T, U> = (...args: T[]) => U;

function once<T, U>(fn: Fn<T, U>): Fn<T, U | undefined> {
  let internalFn: Fn<T, U | undefined> = fn;

  const newFn = function(...args: T[]) {
    const value = internalFn(...args);
    internalFn = () => undefined;
    return  value;
  }

  return newFn;
}
