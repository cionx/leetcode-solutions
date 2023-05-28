declare global {
  interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, T[]>;
  }
}

Array.prototype.groupBy = function <T>(
  fn: (item: T) => string,
): Record<string, T[]> {
  const result: Record<string, T[]> = {};

  for (let i = 0; i < this.length; ++i) {
    const value: T = this[i];
    const key: string = fn(value);
    const group: T[] | undefined = result[key];
    if (group === undefined) {
      result[key] = [value];
    }
    else {
      group.push(value);
    }
  }

  return result;
};
