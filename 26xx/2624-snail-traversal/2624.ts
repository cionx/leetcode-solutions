/* We mentally arrange the values of [a, b, c, d, e, ...] as follows:
 *
 *   a         j k         t u
 *    b       i   l       s   v       .
 *     c     h     m     r     w     .
 *      d   g       n   q       x   .
 *       e f         o p         y z
 *
 * The height of this pattern is `rowsCount`.
 * We have two “stepSizes” in each row, between which we alternate.
 * When going from one row to the next, the first step size decreases by 2,
 * whereas the second step size increases by 2.
 */

declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): T[][];
  }
}

Array.prototype.snail = function <T>(
  rowsCount: number,
  colsCount: number,
): T[][] {
  if (this.length != rowsCount * colsCount) {
    return [];
  }

  const result: T[][] = [];

  /* Step sizes for the first row. */
  let fstStepSize = 2 * rowsCount - 1;
  let sndStepSize = 1;

  for (let start = 0; start < rowsCount; ++start) {
    const row: T[] = [];

    for (
      let i = start, j = 0;
      j < colsCount;
      i += (j % 2) == 0 ? fstStepSize : sndStepSize, ++j
    ) {
      row.push(this[i]);
    }

    result.push(row);
    fstStepSize -= 2;
    sndStepSize += 2;
  }

  return result;
};
