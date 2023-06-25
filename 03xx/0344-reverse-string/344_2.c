/* 344. Reverse String */

/* Recursive solution. */

/* Complexities.
 * Time: O(n)
 * Space: with tail recursion elimination: O(1)
 *        without tail recursion elimination: O(n)
 * where n is the length of the input list. */

void reverseString(char *s, int sSize);
void swapOuter(char *s, int left, int right);

void reverseString(char *s, int sSize)
{
	swapOuter(s, 0, sSize - 1);
}

void swapOuter(char *s, int left, int right)
{
	if (left >= right)
		return;
	const char tmp = s[left];
	s[left] = s[right];
	s[right] = tmp;
	swapOuter(s, left + 1, right - 1);
}
