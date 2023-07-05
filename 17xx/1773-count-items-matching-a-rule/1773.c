/* 1773. Count Items Matching a Rule */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

#include <string.h>

int countMatches(char ***items, int itemsSize, int *itemsColSize, char *ruleKey,
                 char *ruleValue)
{
	int index;
	if (strcmp(ruleKey, "type") == 0)
		index = 0;
	else if (strcmp(ruleKey, "color") == 0)
		index = 1;
	else if (strcmp(ruleKey, "name") == 0)
		index = 2;

	int counter = 0;
	for (int i = 0; i < itemsSize; ++i)
		counter += (strcmp(items[i][index], ruleValue) == 0);

	return counter;
}
