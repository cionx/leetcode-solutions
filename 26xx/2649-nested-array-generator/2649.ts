/* 2649. Nested Array Generator */

type NDArray = (NDArray | number)[];

function* inorderTraversal(arr: NDArray): Generator<number, void, void> {
  for (let i = 0; i < arr.length; ++i) {
    const entry = arr[i];
    if (Array.isArray(entry)) {
      yield* inorderTraversal(entry);
    }
    else {
      yield entry;
    }
  }
}
