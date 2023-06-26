/* 2623. Memoize */

type Fn<T, U> = (...params: T[]) => U;

/** JavaScript Maps cannot handle keys that are arrays.
    So we first need to convert these keys to an object. **/

function memoize<T, U>(fn: Fn<T, U>): Fn<T, U> {
  const valueMap: Map<string, U> = new Map();

  return function (...args: T[]) {
    const key = JSON.stringify(args);
    if (valueMap.has(key)) {
      // TypeScript is stupid here, see
      // https://github.com/Microsoft/TypeScript/issues/9619.
      return valueMap.get(key)!;
    } else {
      const newValue = fn(...args);
      valueMap.set(key, newValue);
      return newValue;
    }
  };
}
