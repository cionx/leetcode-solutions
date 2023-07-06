/* 2418. Sort the People */

/* Complexities.
 * Time: O(n log(n))
 * Space: O(n)
 * where n is the length of the input array. */

#include <stdlib.h>

typedef struct {
	char *name;
	int height;
} person;

char **sortPeople(char **names, int namesSize, int *heights, int heightsSize,
                  int *returnSize);
int cmpPeople(const void *pva, const void *pvb);
int cmpInt(int a, int b);

char **sortPeople(char **names, int namesSize, int *heights, int heightsSize,
                  int *returnSize)
{
	/* Would (people **) be faster for sorting? */
	person *sortedPeople = malloc((size_t) namesSize * sizeof(person));
	for (int i = 0; i < namesSize; ++i)
		sortedPeople[i] = (person){.name = names[i], .height = heights[i]};
	qsort(sortedPeople, (size_t) namesSize, sizeof(person), cmpPeople);

	char **result = malloc((size_t) namesSize * sizeof(char *));
	for (int i = 0; i < namesSize; ++i)
		result[i] = sortedPeople[i].name;

	free(sortedPeople);
	*returnSize = namesSize;
	return result;
}

int cmpPeople(const void *pva, const void *pvb)
{
	const person *pa = (const person *) pva;
	const person *pb = (const person *) pvb;
	return cmpInt(pa->height, pb->height);
}

int cmpInt(int a, int b)
{
	return (a < b) - (a > b);
}
