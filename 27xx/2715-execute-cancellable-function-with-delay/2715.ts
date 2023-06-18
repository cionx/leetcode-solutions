/* Time: O(1)
 * Space: O(1)
 */

type Fn<T, U> = (...param: T[]) => U;

function cancellable<T, U>(fn: Fn<T, U>, args: T[], delay: number): () => void {
  const timeoutId = setTimeout(() => fn(...args), delay);
  return () => clearTimeout(timeoutId);
}
