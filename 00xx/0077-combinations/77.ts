/* The following solution uses the approach that is usually used to prove the
 * combinatorical formula
 *   binom(n, k) = binom(n - 1, k) + binom(n - 1, k - 1).
 */
function combine(n: number, k: number): number[][] {
  if (k == 0) {
    return [[]];
  } else if (n < k) {
    return [];
  }

  /* All that do not contain n, plus all that contain n. */
  const noContain = combine(n - 1, k);
  const yesContain = combine(n - 1, k - 1);
  yesContain.forEach((combination) => combination.push(n));
  return noContain.concat(yesContain);
}
