type Fn<T, U> = (...params: T[]) => Promise<U>;

function timeLimit<T, U>(fn: Fn<T, U>, t: number): Fn<T, U> {
  return function (...args: T[]) {
    return new Promise(function (resolve, reject) {
      const timer = setTimeout(() => reject("Time Limit Exceeded"), t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timer));
    });
  };
}
