/* 2627. Debounce */

type Time = number;
type Call = {
  time: Time;
  timer: ReturnType<typeof setTimeout>;
  rejector: () => void;
};
type F<T, U> = (...paras: T[]) => U;

/** The result of a debounded function is a promise, which will resolve after
    the given waiting period to the function value. If another function call is
    made before the period is over, then the timer is cancelled and the promise
    is rejected, befor creating a new promise. **/
function debounce<T, U>(fn: F<T, U>, timeDiff: Time): F<T, Promise<U | void>> {
  let prevCall: Call | undefined = undefined;

  return function (...args: T[]): Promise<U | void> {
    const now: Time = Date.now();
    if (prevCall != undefined && now - prevCall.time < timeDiff) {
      clearTimeout(prevCall.timer);
      prevCall.rejector();
    }

    let newCall: Call;
    const preResult = new Promise<U>(function (resolve, reject) {
      newCall = {
        time: now,
        timer: setTimeout(() => resolve(fn(...args)), timeDiff),
        rejector: reject,
      };
    });
    prevCall = newCall!;
    return preResult.catch(() => {});
  };
}

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
