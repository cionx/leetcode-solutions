/* 970. Powerful Integers */

/* Complexities.
 * Time: O(log(bound)^2)
 * Space: O(bound)
 * where bound is as in the problem description.
 */

function powerfulIntegers(x: number, y: number, bound: number): number[] {
  if (x > y) {
    [y, x] = [x, y];
  }

  if (y == 1) {
    return (bound < 2) ? [] : [2];
  }

  if (x == 1) {
    const result = [];
    for (let power = 1; power < bound; power *= y) {
      result.push(1 + power);
    }
    return result;
  }

  const pInts = [];
  const found: boolean[] = Array(bound + 1).fill(false);

  for (let power1 = 1; power1 + 1 <= bound; power1 *= x) {
    for (let power2 = 1;; power2 *= y) {
      const pint = power1 + power2;
      if (pint > bound) {
        break;
      }
      if (!found[pint]) { // !undefined is true
        pInts.push(pint);
        found[pint] = true;
      }
    }
  }

  return pInts;
}

/* PS: In terms of space, it makes more sense to make `found` a sparse array:
 *    const found: boolean[] = Array(bound + 1);
 * But I don’t know the time complexity of sparse arrays, and therefore decided
 * to avoid them. With sparse arrays, the required space shrinks to
 * O(log(bound)^2).
 */
