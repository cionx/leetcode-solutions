/* 2178. Maximum Split of Positive Even Integers */

/* Complexities.
 * Time: Θ(sqrt(n))
 * Space: Θ(1)
 * where n is the input number. */

/* Idea.
 * We first disregard every odd number. We may therefore assume that the input
 * integer n is even. Next we divide n by 2 to study the following, equivalent
 * problem:
 *
 *   Given a positive integer n, how can we construct a partition of n into
 *   distinct summands, of maximal length?
 *
 * Suppose that we are given such a maximal length partition
 *
 *   n = n1 + n2 + n3 + ... + nl .
 *
 * We can then rearrange the summands so that
 *
 *   n1 < n2 < n3 < ... < nl .
 *
 * Next we decrease the summand n1 to 1, while increasing the summand nl by the
 * same amount:
 *
 *   1 < n2 < n3 < ... < n'l .
 *
 * Then we decrease the summand n2 to 2, while increasing the summand n'l by the
 * same amount:
 *
 *   1 < 2 < n3 < ... < n''l .
 *
 * By continuing this process, we eventually end up with a partition of the form
 *
 *   1 < 2 < 3 < ... < l-1 < m .
 *
 * The length of this partition is once again l, and all summands are once again
 * distinct.
 *
 * It follows that we can construct one partition of the desired form via a
 * greedy approach. */

function maximumEvenSplit(n: number): number[] {
  if (n % 2 == 1) {
    return [];
  }

  const result: number[] = [];

  let remaining = n;
  for (let summand = 2; summand < remaining - summand; summand += 2) {
    result.push(summand);
    remaining -= summand;
  }
  result.push(remaining);

  return result;
}
