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
  for (const kvPair of arr.entries())
    if ( fn(kvPair[1], kvPair[0]) )
      result.push(kvPair[1]);
  return result;
}
