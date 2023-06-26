/* 17. Letter Combinations of a Phone Number */

function letterCombinations(digits: string): string[] {
  if (digits.length == 0) {
    return [];
  }

  const letters = [
    [],
    [],
    ["a", "b", "c"],
    ["d", "e", "f"],
    ["g", "h", "i"],
    ["j", "k", "l"],
    ["m", "n", "o"],
    ["p", "q", "r", "s"],
    ["t", "u", "v"],
    ["w", "x", "y", "z"],
  ];

  function crossCombine(arr1: string[], arr2: string[]): string[] {
    return arr1
      .map((first) => arr2.map((second) => first + second))
      .flat();
  }

  return Array
    .from(digits)
    .map((char) => parseInt(char)) /* JS is broken like that */
    .map((digit) => letters[digit])
    .reduce(crossCombine); /* This line would crash if digits were empty. */
}
