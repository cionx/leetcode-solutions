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
  for (const [index, value] of arr.entries()) {
    result.push( fn(value, index) );
  }
  return result;
}

// Create the array already of the correct size for better speed.
// I don’t know if the use of generics makes this optimization useless.
function map<T, U>(arr: T[], fn: (n: T, i :number) => U): U[] {
  const result: U[] = new Array<U>(arr.length);
  for (let i = 0; i < arr.length; i++) {
    result[i] = fn(arr[i], i);
  }
  return result;
}
