/* 2676 Throttle */

type F<T, U> = (...args: T[]) => U;
type Time = number;
type Timer = ReturnType<typeof setTimeout>;
interface Action {
  timer: Timer;
  rejector: () => void;
}

/* Doesn’t support infinite wait time. */
function throttle<T, U>(
  fn: F<T, U>,
  waitTime: number,
): F<T, Promise<U | void>> {
  let lastReturnTime: Time = -Infinity; // For the first call.
  let scheduledAction: Action | null = null;

  return function (...args: T[]): Promise<U | void> {
    clearSchedule();
    const now = Date.now();
    const waiting = new Promise<U>(function (resolve, reject) {
      const timeUntilNext = waitTime - (now - lastReturnTime);
      scheduledAction = {
        timer: setTimeout(function () {
          resolve(fn(...args));
          lastReturnTime = Date.now();
          clearSchedule();
        }, timeUntilNext),
        rejector: reject,
      };
    });
    return waiting.catch(() => {});
  };

  function clearSchedule() {
    if (scheduledAction !== null) {
      clearTimeout(scheduledAction.timer);
      scheduledAction.rejector();
      scheduledAction = null;
    }
  }
}

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
