/* 1137. N-th Tribonacci Number */

/* Iterative solution. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the input number. */

/* Note.
 * For larger recurrence relations, one should use a cyclic array together with
 * a sliding window approach for the sum. For three terms, the additional
 * computational costs of a cyclic array outweigh the benefits. */

int tribonacci(int n)
{
	int values[3] = {0, 1, 1};
	for (; n > 2; --n) {
		const int sum = values[0] + values[1] + values[2];
		values[0] = values[1];
		values[1] = values[2];
		values[2] = sum;
	}
	return values[n];
}
