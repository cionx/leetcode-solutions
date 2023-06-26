/* 2469. Convert the Temperature */

/* Complexities.
 * Time: O(1)
 * Space: O(1) */

#include <stdlib.h>

double *convertTemperature(double celsius, int *returnSize)
{
	double *result = malloc(2 * sizeof(double));
	result[0] = celsius + 273.15;    /* Kelvin */
	result[1] = celsius * 1.8 + 32.; /* Fahrenheit */
	*returnSize = 2;
	return result;
}
