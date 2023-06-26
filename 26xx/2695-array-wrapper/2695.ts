/* 2695. Array Wrapper */

class ArrayWrapper {
  numbers: number[];

  constructor(nums: number[]) {
    this.numbers = nums;
  }

  /* valueOf allows class members to be used for arithmetic operations, like
   * addition, by coercing them. However, writing code in TypeScript that
   * actually uses this “feature” seems to be a bit of a problem (see
   * https://github.com/microsoft/TypeScript/issues/2361 for more details).
   */
  valueOf(): number {
    return this.numbers.reduce((acc, summand) => acc + summand, 0);
  }

  toString(): string {
    return `[${this.numbers.join(",")}]`;
  }
}
