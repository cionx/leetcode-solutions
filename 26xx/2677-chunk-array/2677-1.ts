function chunk<T>(arr: T[], size: number): T[][] {
  const result: T[][] = [];
  let current: T[] = [];

  for (let i = 0, currentSize = 0; i < arr.length; ++i, ++currentSize) {
    if (currentSize == size) {
      result.push(current);
      current = [];
      currentSize = 0;
    }
    current.push(arr[i]);
  }
  if (current.length > 0)
    result.push(current);

  return result;
}
