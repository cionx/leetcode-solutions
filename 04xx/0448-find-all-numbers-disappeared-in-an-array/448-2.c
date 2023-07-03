/* 448. Find All Numbers Disappeared in an Array */

/* This solution changes the input array. */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input list. */

/* Idea.
 * The given array represents a function
 *   f:  {1, …, n}  ->  {1, …, n} .
 * Suppose we have
 *   f(i) = j   with   i ≠ j.
 * If we visualize the function f as a string diagram, then we have string i->j:
 *   •  •  •  •  i  •  •  •  •
 *    \_|_  \  \  \  \ | _|_/
 *      | \  \  \  \  \|/ |
 *   •  •  •  •  •  j  •  •  •
 * Because of the condition i ≠ j, the string i->j is not straight. But we can
 * straighten it by precomposing the function f with the transposation σ that
 * swaps i and j.
 *   •  •  •  •  i  j  •  •  •         •  •  •  •  i  j  •  •  •
 *   |  |  |  |   \/   |  |  |          \ |  |  |   \ |  |  | /
 *   |  |  |  |   /\   |  |  |           \|  \  \    \|  |  |/
 *   •  •  •  •  i  j  •  •  •     =      |   \  \    |  |  |
 *    \_|_  \  \  \  \ | _|_/             |\   \  \   |\ | /|
 *      | \  \  \  \  \|/ |               | \   |  |  | \|/ |
 *   •  •  •  •  i  j  •  •  •         •  •  •  •  i  j  •  •  •
 * By passing from f to f σ, we have made j a fixed point. We also note that
 * - i was not a fixed point of f because f(i) = j ≠ i, and
 * - each fixed point k with k ≠ i, j is unaffected by the passing from f to
 *   f ∘ σ. (In fact, every function value except at the positions i and j
 * remains unchanged.)
 * We can therefore repeat the above unstraightening process to ultimately
 * arrive at a map g = f σ₁ ⋯ σᵣ such that every element in the image of g is
 * also a fixed point of g. Therefore, the image of g is precisely the set of
 * fixed points of g. But f and g have the same image, since g arives from f by
 * precomposition with a permutation.
 *
 * This discussion leads to the following algorithm:
 * - Go through x = 1, …, n, and whenever f(x) is not a fixed point of f, swap
 *   the function values of x and f(x).
 * - Afterwards, go through the permuted array and record all non-fixed points.
 * At this point we need to consider the array indexing: the input array is
 * 0-indexed (since we work in C) so f(i) corresponds to nums[i - 1]. To swap
 * the function values of x and y, we thus need to swap the two array entries
 * at indices i - 1 and j - 1.
 *
 * Regarding the running time: each swap will increase the number of fixed
 * points by at least one, so there will at most be n swaps. This allows us to
 * get a running time of O(n). We also have Ω(n) since we iterate through the
 * entire input array, and therefore Θ(n). */

#include <stdlib.h>

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize);
int f(int x, int *nums);
int isFixedPoint(int x, int *nums);
void swapFunctionValues(int x, int y, int *nums);

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
	for (int x = 1; x <= numsSize; ++x)
		for (int y = f(x, nums); !isFixedPoint(y, nums); y = f(x, nums))
			swapFunctionValues(x, y, nums);

	*returnSize = 0;
	for (int x = 1; x <= numsSize; ++x)
		*returnSize += !isFixedPoint(x, nums);
	int *result = malloc((size_t) *returnSize * sizeof(int));
	for (int x = 1, to = 0; x <= numsSize; ++x)
		if (!isFixedPoint(x, nums))
			result[to++] = x;

	return result;
}

int f(int x, int *nums)
{
	return nums[x - 1];
}

int isFixedPoint(int x, int *nums)
{
	return f(x, nums) == x;
}

void swapFunctionValues(int x, int y, int *nums)
{
	const int fx = f(x, nums);
	nums[x - 1] = f(y, nums);
	nums[y - 1] = fx;
}
