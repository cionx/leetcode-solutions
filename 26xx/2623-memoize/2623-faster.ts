/* 2623. Memoize */

/* This solution ought to be faster than the first one
   For some reason, it also seems to consume more memory; I have no idea why.
   I may have to revisit this one in the future… */

type Fn1 = (x: number) => number;
type Fn2 = (x: number, y: number) => number;
type Fn = Fn1 | Fn2;

function memoize1(fn: Fn1): Fn1 {
  const valueMap: Map<number, number> = new Map();

  return function (arg: number) {
    let value = valueMap.get(arg);
    if (value == undefined) {
      value = fn(arg);
      valueMap.set(arg, value);
      return value;
    }
    return value;
  };
}

/** JavaScript Maps cannot handle keys that are arrays.
    So we first need to convert these keys to something else **/

function memoize2(fn: Fn2): Fn2 {
  const valueMap: Map<string, number> = new Map();

  return function (x: number, y : number) {
    const key = [x,y].join(); // the string "%x,%y"
      let value = valueMap.get(key);
      if (value == undefined) {
        value = fn(x, y);
        valueMap.set(key, value);
        return value;
      }
      return value;
  };
}

function memoize(fn: Fn): Fn {
  if (isSingleParam(fn))
    return memoize1(fn);
  else
    return memoize2(fn);
}

// Type guard for TypeScript: if this function returns true, then TypeScript
// knows that fn is of actually of type Fn1 (and not just Fn).
function isSingleParam(fn: Fn): fn is Fn1 {
  return fn.length == 1;
}
