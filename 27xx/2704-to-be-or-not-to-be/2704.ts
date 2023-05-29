type ToBeOrNotToBe<T> = {
  toBe: (val: T) => boolean;
  notToBe: (val: T) => boolean;
};

function expect<T>(val1: T): ToBeOrNotToBe<T> {
  return {
    toBe(val2: T): boolean {
      if (val1 === val2) {
        return true;
      }
      throw new Error("Not Equal");
    },
    notToBe(val2: T): boolean {
      if (val1 !== val2) {
        return true;
      }
      throw new Error("Equal");
    },
  };
}
