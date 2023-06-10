#include "1802.h"
#include <stdio.h>

int main(void)
{
	int n = 6;
	int index = 1;
	int maxSum = 10;

	int result = maxValue(n, index, maxSum);
	printf("n = %d, index = %d, maxSum = %d | %d\n", n, index, maxSum, result);

	return 0;
}
