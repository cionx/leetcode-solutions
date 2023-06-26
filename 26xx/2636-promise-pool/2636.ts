/* 2636. Promise Pool */

type F<T> = () => Promise<T>;

function promisePool<T>(functions: F<T>[], poolSize: number): Promise<void> {
  return new Promise<void>(function (resolve, _) {
    if (functions.length == 0) {
      resolve();
      return;
    }

    let i = 0;
    let resolvedCounter = 0;

    function reportFinished() {
      resolvedCounter++;
      if (resolvedCounter == functions.length) {
        resolve(); // Here we resolve the overall pool promise.
      }
      startNext();
    }

    function startNext() {
      if (i < functions.length) {
        functions[i]().finally(reportFinished);
        i++;
      }
    }

    // Initialize the first few promises.
    for (; poolSize > 0; poolSize--) {
      startNext();
    }
  });
}
