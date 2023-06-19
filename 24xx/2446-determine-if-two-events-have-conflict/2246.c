/* Time: O(1)
 * Space: O(1)
 */

#include <stdbool.h>

bool haveConflict(char **event1, int event1Size, char **event2, int event2Size);
int timeStringToMinutes(const char timeString[]);
int dtoi(char c);

bool haveConflict(char **event1, int event1Size, char **event2, int event2Size)
{
	const int start1 = timeStringToMinutes(event1[0]);
	const int start2 = timeStringToMinutes(event2[0]);
	const int end1 = timeStringToMinutes(event1[1]);
	const int end2 = timeStringToMinutes(event2[1]);

	return !(end1 < start2 || end2 < start1);
}

int timeStringToMinutes(const char s[])
{
	return 60 * (10 * dtoi(s[0]) + dtoi(s[1])) + 10 * dtoi(s[3]) + dtoi(s[4]);
}

inline int dtoi(char c)
{
	return c - '0';
}
