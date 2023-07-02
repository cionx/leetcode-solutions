/* 1089. Duplicate Zeros */

/* Complexities.
 * Time: O(n)
 * Space: O(1)
 * where n is the length of the input array. */

void duplicateZeros(int *arr, int arrSize)
{
	int from = 0, to = 0;
	while (to < arrSize)
		to += (arr[from++] == 0) ? 2 : 1;
	--from;

	/* The last one by hand. */
	const int step = (arr[from] == 0) ? 2 : 1;
	to -= step;
	if (step == 1 || to == arrSize - 1)
		arr[to] = arr[from];
	else
		arr[to] = arr[to + 1] = 0;
	--from;

	/* The rest automated. */
	for (; from >= 0; --from) {
		const int step = (arr[from] == 0) ? 2 : 1;
		to -= step;
		if (step == 1)
			arr[to] = arr[from];
		else
			arr[to] = arr[to + 1] = 0;
	}
}
