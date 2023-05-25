#include <stdio.h>
#include <stdlib.h>

double new21Game(int n, int k, int maxPts);

double new21Game(int n, int k, int maxPts)
{
	/* We remove the trivial part of the problem space. */
	if (k + maxPts <= n || k == 0)
		return 1;

	/* pos[i] is the probability that we pass through i. */
	size_t size = (size_t) k;
	double *probs = malloc(size * sizeof(double));
	double q = 1.0 / maxPts;
	/* In the following we prefer multiplying with q instead of dividing
	 * by maxPts. The overall result is probably slightly less accurate,
	 * but this way better reflects the mathematical idea of “incorporating
	 * a previous case with weight q = 1 / maxPts”.
	 */

	/* We always start at 0, and so will always pass through 0. */
	probs[0] = 1.0;

	/* The recursion is generally given by
	 *   probs[i] = q * probs[i - 1] + ... + q * probs[i - maxPts]
	 *            = q * (probs[i - 1] + ... + probs[i - maxPts]) .
	 * Note that as i increases by one, this sum stays nearly unchanged:
	 * we only get a new first term, and the previous last term goes away.
	 * Instead of calculating this sum each time, we can therefore use
	 * a “shifting window” approach: we keep track of this sum in an
	 * auxiliary variable `currentProb`, and to pass from i to i + 1, we
	 * subtract q * probs[i - maxPts] and add q * probs[i] = q * currentProb.
	 */

	/* currentProb starts the i-iteration with the already-correct
	 * value for probs[i]. For the first index, i = 1, we hence
	 * need a starting value of q.
	 */
	double currentProb = q;
	for (int i = 1; i < k && i < maxPts; ++i) {
		probs[i] = currentProb;
		currentProb += q * currentProb;
	}
	for (int i = maxPts; i < k; i++) {
		probs[i] = currentProb;
		currentProb += q * currentProb;
		currentProb -= q * probs[i - maxPts];
	}

	/* At this point, currentProb is the probability of landing at k. */

	/* We finish by landing in [k, ..., k + maxPts - 1]. We hence need the
	 * probability of finishing on i with both k <= i < k + maxPts and i <= n.
	 * But we have removed the case k + maxPts <= n at the very beginning of
	 * this function, so at this point, we have n < k + maxPts. So we need
	 * to check for i from k to n.
	 *
	 * The code for this loop as basically the same as for the previous loop,
	 * except that we do not gain a new summand. (Because once we’ve reached k
	 * or above, we cannot go further up.)
	 */
	double result = 0.0;
	for (int i = k; i <= n; ++i) {
		result += currentProb;
		if (i >= maxPts)
			currentProb -= q * probs[i - maxPts];
	}

	free(probs);

	return result;
}

int main(void)
{
	int n = 21;
	int k = 17;
	int maxPts = 10;
	double result = new21Game(n, k, maxPts);

	printf("n = %d, k = %d, maxPts = %d  -->  %f\n", n, k, maxPts, result);
	return 0;
}
