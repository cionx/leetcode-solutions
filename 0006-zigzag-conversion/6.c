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

char* convert(char* s, unsigned int numRows);

char* convert(char* s, unsigned int numRows) {
	unsigned long len = strlen(s);
	/* The following line makes Leetcode crash with
	   ==22==ERROR: AddressSanitizer: heap-buffer-overflow:
	     char* result = malloc( (len + 1) * sizeof(char) );
	   This makes absolutely no sense to me.
	   But it forces me to use a much slower alternative: */
	char* result = strdup(s);
	printf("%lu", sizeof(result));
	unsigned int i, j;
	unsigned int single_step, two_step_1, two_step_2;

	if (numRows == 1)
		return s;

	/* the top row */
	single_step = 2 * numRows - 2;
	j = 0;
	for(i = 0; i < len; i += single_step) {
		result[j] = s[i];
		j++;
	}
	if (numRows > 1) {
		/* the middle rows */
		for (unsigned int row = 1; row < numRows - 1; row++) {
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
		for(i = numRows - 1; i < len; i += single_step) {
			result[j] = s[i];
			j++;
		}
	}

	return result;
}

int main(void) {
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%s\n", convert(s, 6));
}
