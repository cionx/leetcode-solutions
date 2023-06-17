/* This solution is a clusterfuck, but I need to submit in a few minutes. */

/* Key observations:
 *
 * - We may assume that arr2 contains no duplicates and is ordered in strictly
 *   increasing order. It costs us O(m log(m)) to establish these properties.
 *
 * - Let say that we replace arr1[i] by arr2[j]. Every future replacement of
 *   arr1[i'] by arr2[j'] is then subject to the following condition:
 *   - If i' < i then we also need arr[j'] < arr[j], and thus j' < j.
 *   - If i < i' then we also need arr[j] < arr[j'], and thus j < j'.
 *   We will therefore consider the same problem for the two pairs of subarrays
 *   - arr1[1 : i - 1] and arr2[1 : j - 1] and
 *   - arr1[i + 1 : n] and arr2[j + 1 : m].
 *   However, we need to consider a slightly stronger problem for these two
 *   subarrays: For the left problem, we need to ensure that the last entry in
 *   the resulting sorted array is also strictly smaller than arr2[j].
 *   Similarly, for the right problem, we need to ensure that the first entry
 *   in the resulting sorted array is also strictly larger than arr2[j].
 *
 * - It never makes sense to replace the first entry of arr1 by a larger entry
 *   (unless forced to). Similarly, it never makes sense to replace the last
 *   entry of arr1 by a smaller entry (unless forced to).
 *
 * - If we were to replace an entry arr1[i] by a smaller value, then we might
 *   as well make the replaced value as small as possible (i.e., the smallest
 *   value of arr2 that is strictl larger than arr1[i - 1].
 *
 ******************************************************************************
 *
 * The resulting algorithm:
 *
 * Recursively speaking, we work our way from the left to the right. We start
 * with two possible choices:
 *   1. Leave the value arr1[0] unchanged.
 *   2. If arr2[0] < arr1[0], then replace arr1[0] by arr2[0].
 *
 * Suppose more generally that after some steps, we are left with the subarrays
 * arr1[i : n] and arr2[j : m], and such that arr2[j] > arr1[i - 1]. We have
 * once again two cases to consider:
 *
 *   1. If arr1[i - 1] ≥ arr1[i] then we need to raise arr1[i], but only as
 *      far as required.
 *        a. We hence replace arr1[i] by arr2[j], and then continue with the
 *           subarrays arr1[i + 1 : n], arr2[j + 1 : m].
 *        b. But if arr2[j : m] is already empty, then there is nothing we
 *           can do, and we cannot form a solution.
 *
 *   2. If arr1[i - 1] < arr1[i], then we have the following subcases:
 *        a. If arr2[j] > arr1[i], so that arr1[i - 1] < arr1[i] < arr2[j],
 *           then we do nothing, and continue with arr1[i + 1 : n] and
 *           arr2[j : m].
 *        b. If arr2[j] = arr1[i], then we continue with arr1[i + 1 : n]
 *           and arr2[j' : m] where j' is the smallest index with
 *           arr2[j'] > arr1[i].
 *        c. If arr2[j] < arr1[i], so that arr1[i - 1] < arr2[j] < arr1[i],
 *           then we have two subcases:
 *             i.  replace arr1[i] by arr2[j] and continue with arr1[i + 1 : n]
 *                 and arr2[j + 1 : m].
 *             ii. continue with arr1[i + 1 : n] and arr2[j' : m] where j' is
 *                 the smallest index for which arr1[i] < arr2[j'].
 *
 *  We have three pieces of information in each situation: the subarrays
 *  arr1[i : n] and arr2[j : m], and the previous value arr1[i - 1]. However,
 *  we note that the index j can be derived from the previous value arr1[i - 1]
 *  as being minimal with the property that arr2[j] > arr1[i - 1]. We could
 *  therefore express everything above purely in terms of arr1[i - 1] and
 *  arr1[i].
 *
 *  This allows us to work backwards, caching our results with the value
 *  arr1[i - 1] and index i as keys.
 */

type Value = number;
type Index = number;

function makeArrayIncreasing(arr1: number[], arr2: number[]): number {
  const cache: number[][] = [];

  /* We should use toSorted instead of sort, but LeetCode is too outdated. */
  arr2.sort((a, b) => a - b);
  arr2 = Array.from(new Set(arr2)); /* Remove duplicates. */

  function getValue(prev: Value, i: Index): number {
    if (i >= arr1.length) {
      return 0;
    }

    const cachedResult = cache.at(i)?.at(prev);
    if (cachedResult !== undefined) {
      return cachedResult;
    }

    const j = binarySearch(arr2, prev);
    let recValue: number;
    let oneIfOperation = 0;

    /* Case 1: previous value >= arr1[i]
     * In this case, we need to increate arr1[i] to arr2[j]. */
    if (prev >= arr1[i]) {
      if (j < arr2.length) {
        recValue = getValue(arr2[j], i + 1);
        oneIfOperation = 1;
      } else {
        recValue = -1;
      }
    }
    /* Case 2: previous value < arr1[i]
     * In this case, we can either leave arr1[i] unchanged,
     * or decrease it to arr2[j] if possible. */
    else {
      recValue = getValue(arr1[i], i + 1);
      /* If we can decrease arr1[i] to arr2[j]: */
      if (j < arr2.length && arr2[j] < arr1[i]) {
        const recValueAlt = getValue(arr2[j], i + 1);
        if (recValueAlt >= 0 && (recValueAlt < recValue || recValue == -1)) {
          recValue = recValueAlt;
          oneIfOperation = 1;
        }
      }
    }

    /* If no recursive solution was found, then there is no solution. Otherwise
     * we might need increment the best recursive solution by 1, depending on
     * whether we performed an operation to get this best result. */
    const newValue = (recValue == -1) ? -1 : (recValue + oneIfOperation);

    /* Save the new result in the cache. */
    if (cache[i] != undefined) {
      cache[i][prev] = newValue;
    } else {
      cache[i] = [];
      cache[i][prev] = newValue;
    }

    return newValue;
  }

  /* binarySearch searches for the first index whose value is strictly larger
   * than value. If no such index exists, then the first out-of-bound index is
   * returned, i.e., the length of the array.*/
  function binarySearch(array: number[], value: number): number {
    let lower = 0;
    let upper = array.length;

    while (lower < upper) {
      /* lower ≤ middle < upper */
      const middle = Math.floor((lower + upper) / 2);
      if (array[middle] <= value) {
        lower = middle + 1;
      } else {
        upper = middle;
      }
    }

    return upper;
  }

  if (arr1.length == 0) {
    throw new Error("arr1 needs to be nonempty");
  }
  if (arr2.length == 0) {
    throw new Error("arr2 needs to be nonempty");
  }

  return getValue(-Infinity, 0); // Slight hack.
}
