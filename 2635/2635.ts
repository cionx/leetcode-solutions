// Naive method
function map<T, U>(arr: T[], fn: (n: T, i :number) => U): U[] {
  const result: U[] = [];
  for (let i = 0; i < arr.length; i++) {
    result[i] = fn(arr[i], i);
  }
  return result;
}

// Slighly fancier
function map<T, U>(arr: T[], fn: (n: T, i :number) => U): U[] {
  const result: U[] = [];
  for (const kvPair of arr.entries()) {
    result.push( fn(kvPair[1], kvPair[0]) );
  }
  return result;
}
