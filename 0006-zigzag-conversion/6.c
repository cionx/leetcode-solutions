#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* We reorganize the problem as follows:
   A         K         U
    B       J L       T V
     C     I   M     S   W
      D   H     N   R     X
       E G       O Q       Y
        F         P         Z
*/

char *convert(char *s, int numRows);

char *convert(char *s, int numRows) {
	int len = (int) strlen(s);
	char *result = malloc(((size_t)len + 1) * sizeof(char));
	int i, j;
	int single_step, two_step_1, two_step_2;

	if (numRows == 1)
		return s;

	/* the top row */
	single_step = 2 * numRows - 2;
	j = 0;
	for (i = 0; i < len; i += single_step) {
		result[j] = s[i];
		j++;
	}
	if (numRows > 1) {
		/* the middle rows */
		for (int row = 1; row < numRows - 1; row++) {
			i = row;
			two_step_1 = single_step - 2 * i;
			two_step_2 = 2 * i;
			while (i < len) {
				result[j] = s[i];
				i += two_step_1;
				j++;
				if (i < len) {
					result[j] = s[i];
					i += two_step_2;
					j++;
				}
			}
		}
		/* the bottom row */
		for (i = numRows - 1; i < len; i += single_step) {
			result[j] = s[i];
			j++;
		}
	}
	result[len] = '\0';
	return result;
}

int main(void) {
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *result = convert(s, 6);
	printf("%s\n", result);
	free (result);
	return 0;
}
