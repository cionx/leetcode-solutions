/* 956. Tallest Billboard */

/* Complexities.
 * Time: ?
 * Space: ?
 * where n is the length of the input array. */

type Cache = Map<number, number>;

function tallestBillboard(rods: number[]): number {
  /* highest[diff] is the highest support we can build where both sides have
   * the specified difference. We will return the value highest[0] at the very
   * end. We use a map instead of an array, because iterating over a map is
   * easier than iterating over a sparse array. */
  let highestPerDiff: Cache = new Map();
  highestPerDiff.set(0, 0);

  function addRod(rod: number): void {
    const newHighestPerDiff: Cache = new Map();
    for (const [diff, height] of highestPerDiff) {
      /* Possibility 1: we don’t use the new rod. */
      updateEntry(newHighestPerDiff, diff, height);
      /* Possibility 2: we add the new rod to the higher side. */
      updateEntry(newHighestPerDiff, diff + rod, height + rod);
      /* Possibility 3: we add the new rod to the lower side. */
      if (rod <= diff) {
        /* Case 3.1: the lower side stays lower. */
        updateEntry(newHighestPerDiff, diff - rod, height);
      } else {
        /* Case 3.2: the lower side becomes the new higher side. */
        updateEntry(newHighestPerDiff, rod - diff, height + rod - diff);
      }
    }
    highestPerDiff = newHighestPerDiff;
  }

  function updateEntry(cache: Cache, key: number, value: number) {
    const prevValue = cache.get(key);
    if (prevValue === undefined) {
      cache.set(key, value);
    } else {
      cache.set(key, Math.max(value, prevValue));
    }
  }

  for (const rod of rods) {
    addRod(rod);
  }

  const result = highestPerDiff.get(0);
  if (result === undefined) {
    throw new Error("No result found. This should not have happened.");
  }
  return result;
}
