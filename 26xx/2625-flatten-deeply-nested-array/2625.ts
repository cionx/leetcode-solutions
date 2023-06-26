/* 2625. Flatten Deeply Nested Array */

/* The generic type T must not be an Array type. That is, T must not be of the
 * form U[] for any other type U.
 */
type NDArray<T> = (T | NDArray<T>)[];

function flat<T>(arr: NDArray<T>, n: number): NDArray<T> {
  const result: NDArray<T> = [];

  for (let i = 0; i < arr.length; ++i) {
    const entry = arr[i];
    if (!Array.isArray(entry) || n == 0) {
      result.push(entry);
      continue;
    }
    const recFlattened = flat(entry, n - 1);
    for (let j = 0; j < recFlattened.length; ++j) {
      result.push(recFlattened[j]);
    }
  }

  return result;
}
