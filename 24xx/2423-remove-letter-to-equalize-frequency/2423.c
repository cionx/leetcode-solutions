#include <stdbool.h>
#include <stdio.h>

bool equalFrequency(const char *word);

bool equalFrequency(const char *word)
{
	/* We start by recording the frequencies of all lower-case English letters.
	 */
	int freq[26] = {0}; /* Initializes all entries as 0. */

	for (int i = 0; word[i] != '\0'; ++i)
		++freq[word[i] - 'a'];

	/* For this function to return true, one of the following cases must occur:
	 * 1. Only one letter appears.
	 * 2. All letters have the same frequency except one, whose frequency is
	 *    precisly one larger than the common frequency.
	 * 3. All letters have the same frequency except one, which has frequency 1.
	 * 4. All letters have frequency 1.
	 *
	 * Note that in the cases 2, 3 and 4, if any two letters share a frequency,
	 * then this shared frequency must be the common frequency.
	 */

	/* We search for the first non-zero frequency. We know from the constraints
	 * that such a frequency exists, since the word is nonempty. */
	int i = 0;
	while (freq[i] == 0)
		++i;
	int freq1 = freq[i];

	/* Now we search for a second non-zero frequency, which may not exist. */
	do
		i++;
	while (i < 26 && freq[i] == 0);
	/* We haven’t found another non-zero entry if and only if i = 26. In this
	 * case the word consists of only letter, and we could remove any one
	 * character. */
	if (i == 26)
		return true;
	/* Otherwise, we have found another ocurring letter. */
	int freq2 = freq[i];

	/* However, two letters are not enough to determine the common frequency.
	 * We therefore search for a possible third letter.
	 */
	do
		i++;
	while (i < 26 && freq[i] == 0);

	/* If we haven’t found a third letter, then we have altogether only two
	 * letters, with frequencies freq1 and freq2 respectively. We then return
	 * true if and only if one of the following conditions is satisfied:
	 * 1. Both frequencies differ by exactly one.
	 * 2. (At least) one of the two frequencies is 1.
	 */
	if (i == 26)
		return freq1 == freq2 + 1 || freq2 == freq1 + 1 || freq1 == 1 ||
		       freq2 == 1;

	/* Otherwise, we have found a third non-zero frequency. */
	int freq3 = freq[i];

	/* If two of the three frequencies are equal, then this is the common
	 * frequency. If otherwise all three frequencies are distinct, then we can
	 * give upc
	 */
	int common;

	if (freq1 == freq2 || freq1 == freq3)
		common = freq1;
	else if (freq2 == freq3)
		common = freq2;
	else
		return false;

	/* Now that we know the common frequency, we can check if we’ve already
	 * found the outliner. If we’ve found it, then we will have to check that it
	 * is either one larger than the common frequency, or 1. We keep track of
	 * the value of the outliner in an extra variable; we initialize it with the
	 * value -1, which cannot occur for actual frequencies.
	 */
	int outliner = -1;
	if (freq1 != common)
		outliner = freq1;
	else if (freq2 != common)
		outliner = freq2;
	else if (freq3 != common)
		outliner = freq3;

	if (outliner != -1 && outliner != common + 1 && outliner != 1)
		return false;
	/* Remark: The program would still work if we removed this check. */

	/* If we haven’t found an outliner yet, then we look for it in the remaining
	 * frequencies. If we end up finding two outliners, then we abort.
	 */
	for (++i; i < 26; ++i)
		if (freq[i] != 0 && freq[i] != common) { /* Found an outliner. */
			if (outliner == -1)
				outliner = freq[i];
			else {
				return false;
			}
		}

	/* We are left with two possible cases:
	 * 1. If we have found altogether exactly one outliner, then we check that
	 *    it has a suitable frequency: either one larger than the common
	 *    frequency, or 1.
	 * 2. If we have found no outliner, then at this point in the program, we
	 *    can only succeed if the common frequency is 1.
	 */

	if (outliner != -1)
		return outliner == common + 1 || outliner == 1;

	return (common == 1) ? true : false;
}

int main(void)
{
	char word[] = "abcc";

	printf("%d\n", equalFrequency(word));
}
