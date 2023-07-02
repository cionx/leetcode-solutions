/* 1262. Greatest Sum Divisible by Three. */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input list. */

int maxSumDivThree(int *nums, int numsSize);
void sortInto(int x, int mins[3][2]);
long min(long a, long b);

int maxSumDivThree(int *nums, int numsSize)
{
	/* mod[i] contains the two smallest numbers that are congruent i mod 3,
	 * arranged as mod[i][0] < mod[i][1]. We don’t need mod[0], only mod[1]
	 * and mod[2].
	 */
	int mins[3][2] = {{-1, -1}, {-1, -1}, {-1, -1}};
	long sum = 0; /* Needs values up to 4e8. */

	for (int i = 0; i < numsSize; ++i) {
		sum += (long) nums[i];
		sortInto(nums[i], mins);
	}

	long result;
	if (sum % 3 == 0)
		result = sum;
	else {
		const int modSum = sum % 3;
		const int modOther = 3 - modSum;
		/* Either subtract one same-mod, or two other-mod. */
		if (mins[modSum][0] != -1 && mins[modOther][1] != -1) {
			const long sub1 = mins[modSum][0];
			const long sub2 = mins[modOther][0] + mins[modOther][1];
			result = sum - min(sub1, sub2);
		}
		else if (mins[modSum][0] != -1)
			result = sum - mins[modSum][0];
		else if (mins[modOther][1] != -1)
			result = sum - mins[modOther][0] - mins[modOther][1];
		else
			/* We should never get here. */
			result = -1;
	}

	return (int) result;
}

void sortInto(int x, int mins[3][2])
{
	if (x % 3 != 0) {
		int *modMins = mins[x % 3]; /* An array of length 2. */
		/* modMins[0] < modMins[1] */
		if (x < modMins[0] || modMins[0] == -1)
			modMins[1] = modMins[0], modMins[0] = x;
		else if (x < modMins[1] || modMins[1] == -1)
			modMins[1] = x;
	}
}

inline long min(long a, long b)
{
	return (a < b) ? a : b;
}
