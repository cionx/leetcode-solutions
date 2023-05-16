// Naive method
function map(arr: number[], fn: (n: number, i :number) => number): number[] {
  const result: number[] = [];
  for (let i = 0; i < arr.length; i++) {
    result[i] = fn(arr[i], i);
  }
  return result;
}

// Slighly fancier
function map(arr: number[], fn: (n: number, i :number) => number): number[] {
  const result: number[] = [];
  for (const kvPair of arr.entries()) {
    result.push( fn(kvPair[1], kvPair[0]) );
  }
  return result;
}
