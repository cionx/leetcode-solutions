#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *largest;
	int size;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int numsSize);
int kthLargestAdd(KthLargest *stream, int value);
int kthLargestPosition(KthLargest *stream, int value);
void kthLargestInsert(KthLargest *stream, int position, int value);
void kthLargestFree(KthLargest *stream);

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
	int *largest = malloc((size_t) k * sizeof(int));
	for (int i = 0; i < k; ++i)
		largest[i] = -10001;

	KthLargest *stream = malloc(sizeof(KthLargest));
	stream->largest = largest;
	stream->size = k;

	for (int i = 0; i < numsSize; ++i)
		kthLargestAdd(stream, nums[i]);

	return stream;
}

int kthLargestAdd(KthLargest *stream, int value)
{
	int position = kthLargestPosition(stream, value);
	if (position >= 0)
		kthLargestInsert(stream, position, value);

	return stream->largest[0];
}

int kthLargestPosition(KthLargest *stream, int value)
{
	if (value < stream->largest[0])
		return -1;

	int lower = 0;
	int upper = stream->size - 1;
	while (lower < upper) {
		int middle = (lower + upper + 1) / 2; // the higher choice
		if (value > stream->largest[middle])
			lower = middle;
		else
			upper = middle - 1;
	}
	/* Observe that middle is always strictly larger than lower.
	 * This ensures that the loop terminates, as either lower strictly
	 * increases or upper stricly decreases.
	 */

	return lower;
}

void kthLargestInsert(KthLargest *stream, int position, int value)
{
	for (int i = 0; i < position; ++i)
		stream->largest[i] = stream->largest[i + 1];
	stream->largest[position] = value;
}

void kthLargestFree(KthLargest *stream)
{
	free(stream->largest);
	free(stream);
}

/* Don’t copy the below to LeetCode. */

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

int main(void)
{
	int k = 7;
	int nums[] = {-10,1,3,1,4,10,3,9,4,5,1};
	KthLargest *stream = kthLargestCreate(k, nums, 11);
	int adds[] = {3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6};
	for (int i = 0; i < 27; ++i) {
		printf("%d ", kthLargestAdd(stream, adds[i]));
	}
	putchar('\n');

	kthLargestFree(stream);

	return 0;
}
