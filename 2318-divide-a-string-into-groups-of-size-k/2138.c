#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **divideString(char *s, int k, char fill, int *returnSize);

char **divideString(char *s, int k, char fill, int *returnSize) {
	int len = (int)strlen(s);
	int number = (len / k) + (len % k == 0 ? 0 : 1);
	char **result = malloc((size_t)number * sizeof(char *));

	for (int i = 0; i < number - 1; ++i) {
		char *group = malloc((size_t)(k + 1) * sizeof(char));
		int offset = i * k;
		for (int j = 0; j < k; ++j) {
			group[j] = s[offset + j];
		}
		group[k] = '\0';
		result[i] = group;
	}

	char *last = malloc((size_t)(k + 1) * sizeof(char));
	int offset = (number - 1) * k;
	int j = 0;
	for (; offset + j < len; ++j) {
		last[j] = s[offset + j];
	}
	for (; j < k; ++j) {
		last[j] = fill;
	}
	last[k] = '\0';
	result[number - 1] = last;

	*returnSize = number;
	return result;
}

/* Don’t copy the below to LeetCode. */

int main(void) {
	char s[] = "abcdefghij";
	int k = 3;
	int *size = malloc(sizeof(int));
	char fill = 'x';

	char **result = divideString(s, k, fill, size);
	printf("%d\n", *size);
	for (int i = 0; i < *size; ++i)
		printf("%s\n", result[i]);

	for (int i = 0; i < *size; ++i)
		free(result[i]);
	free(result);
	free(size);
	return 0;
}
