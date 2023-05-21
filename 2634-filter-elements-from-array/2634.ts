// Naive
function filter<T, U>(arr: T[], fn: (n: T, i: number) => U): T[] {
  const result: T[] = [];
  for (let i = 0; i < arr.length; i++)
    if ( fn(arr[i], i) )
      result.push(arr[i]);
  return result;
}

// Fancier
function filter<T, U>(arr: T[], fn: (n: T, i: number) => U): T[] {
  const result: T[] = [];
  for (const [index, value] of arr.entries())
    if ( fn(value, index) )
      result.push(value);
  return result;
}
