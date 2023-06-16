const MODULO = 10 ** 9 + 7;
const MAXN = 1000;

/* For an explanation of the calculations, we refer to the attacked markdown
 * file.
 */

function numOfWays(nums: number[]): number {
  return numOfPermut(nums) - 1;
}

function numOfPermut(nums: number[]): number {
  if (nums.length <= 2) {
    return 1;
  }

  /* We use a loop instead of .filter() to only traverse the list once. We use
   * a for-let loop instead of a for-of loop to ensure the correct order of
   * elements in the created subarrays.
   */
  const first = nums[0];
  const smaller = [];
  const larger = [];
  for (let i = 1; i < nums.length; ++i) {
    if (nums[i] < first) {
      smaller.push(nums[i]);
    }
    else {
      larger.push(nums[i]);
    }
  }

  const n = nums.length - 1;
  const k = smaller.length;
  const binom = binomialMod(n, k);

  const smallerResult = numOfPermut(smaller);
  const largerResult = numOfPermut(larger);
  /* JavaScript shits itself with numbers larger than Number.MAX_SAFE_INTEGER,
   * which is 9007199254740991 ≈ 9e15. The following products can reach values
   * up to MODULO**2 ≈ 1e18, or eveny 1e27 if we multiply all three values at
   * once. We therefore need to resort to BitInts. */
  const result = Number(
    (BigInt(binom) * BigInt(smallerResult) * BigInt(largerResult)) %
      BigInt(MODULO),
  );

  return result;
}

/* To avoid repeated expensive calculations, we cache the binomial values. Note
 * that this cache persists among multiple calls to numOfPermut. I’d like to
 * use a static variable (in the sense of C), but don’t know how to do this in
 * JavaScript.
 * We need to safe values binom(n, k) with 0 <= k<= n. For simplicity we use 0
 * <= k, n <= MAXN. Most of the entries of the cache will therefore be empty,
 * and will stay empty.
 */
const binomCache: number[] = Array(MAXN * MAXN + 1);

/* To calculate the binomial values, we use the following recursive formula:
 *   binom(n, k) = binom(n - 1, k) + binom(n - 1, k - 1)
 * This recursion boils down to the following base cases:
 *   binom(n, 0) = 1   for every natural number n,
 *   binom(n, n) = 1   for every natural number n.
 * We will also include the following edge cases:
 *   binom(n, k) = 0   whenever k < 0,
 *   binom(n, k) = 0   whenever k > n.
 * We should actually never reach these edge cases, but it’s better to be safe
 * than sorry.
 * We will not safe the edge cases in the cache.
 */

function binomialMod(n: number, k: number): number {
  /* First the edge cases. */
  if (0 == k || k == n) {
    return 1;
  }
  if (k < 0 || n < k) {
    return 0;
  }

  /* Otherwise, looking for a cached value. */
  const cacheIndex = n * MAXN + k;
  const cacheValue = binomCache[cacheIndex];
  if (cacheValue !== undefined) {
    return cacheValue;
  }

  /* If no value has been cached before, calculating a new value, and save it
   * in the cache before returning it. */
  const result = (binomialMod(n - 1, k) + binomialMod(n - 1, k - 1)) % MODULO;
  binomCache[cacheIndex] = result;
  return result;
}
