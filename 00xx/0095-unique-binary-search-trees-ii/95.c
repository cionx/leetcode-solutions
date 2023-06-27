/* 95. Unique Binary Search Trees II */

/* Complexities.
 * Time: Ω(n C(n)), probably O(n C(n)) and thus Θ(n C(n))
 * Space:   O(n^2 + ∑_{i=1}^{n+1} ∑_{j=i-1}^n C(j-i+1))
 *        = O(∑_{i=1}^{n+1} ∑_{j=i-1}^n C(j-i+1))
 *        = O(∑_{i=0}^n ∑_{j=i}^n C(j-i))
 *        = O(∑_{k=0}^n ∑_{l=0}^k C(l))
 *        = O(∑_{p=0}^n (p+1) C(p))
 *        = O(∑_{p=0}^n binom(2p,p))
 *        (This is A006134 in OEIS. I don’t know what growth type this is.)
 * where C(k) is the k-th Catalan number, and n is the input number. */

#include <stdlib.h>
#include <string.h>

/* Do not copy the below struct Definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TN; /* For          */
typedef TN **TNList;        /* readability. */

TNList generateTrees(int n, int *returnSize);
void generateSubTrees(int lower, int upper, TNList **bstCache, int *catalans);
void crossCombineTreeLists(TNList leftList, int leftSize, int value,
                           TNList rightList, int rightSize, TNList whereToSave);
TN *combineTrees(TN *left, int value, TN *right);

TNList generateTrees(int n, int *returnSize)
{
	/* The number of BSTs consisting of k distinct numbers is the k-th Catalan
	 * number, which can be computed as binom(2k, k) / (k + 1). These binomials
	 * can be computed iteratively using a recursive relation: we have
	 *  binom(2k, k) = 2k (2k - 1) ⋯ (k + 1) / k!
	 * and therefore
	 *  binom(2(k+1), k+1)
	 *  = binom(2k, k) ⋅ 2(k+1) (2(k+1)-1) / (k+1)^2.
	 *  = binom(2k, k) ⋅ 2 (2(k+1)-1) / (k+1). */

	/* We use long long for intermediate results to ensure no overflows. */

	int *catalans = malloc(((size_t) n + 1) * sizeof(int));
	long long binomial = 1; /* The binomial binom(2k, k). */
	for (int k = 0; k <= n; ++k, binomial = binomial * 2 * (2 * k - 1) / k)
		catalans[k] = (int) (binomial / (k + 1));

	/* We compute for all integers i, j with 1 <= i <= j <= n all BSTs with
	 * values i, i+1, ..., j, and store this array in a double array as
	 *   bst[i][j] = { BSTs with values i, i+1, ..., j }.
	 * For more consistent and easier code, we actually allow 0 <= i, j <= n+1,
	 * and we start with the base cases
	 *   bst[i][i - 1] = { NULL }, bst[i + 1][i] = { NULL };
	 * Note that the 0-th Catalan number is 1, whence the lists bst[i][i - 1]
	 * and bst[i + 1][i] will have length 1. */

	TNList **bstCache = malloc(((size_t) n + 2) * sizeof(TNList *));

	for (int i = 1; i <= n + 1; ++i) {
		bstCache[i] = malloc(((size_t) n + 2) * sizeof(TNList));
		for (int j = i - 1; j <= n; ++j) {
			const int numberOfBST = catalans[j - i + 1];
			bstCache[i][j] = malloc((size_t) numberOfBST * sizeof(TN *));
		}
	}

	/* Generate all trees of size 0 that we will need in the following
	 * recursion. */
	for (int i = 1; i <= n + 1; ++i)
		bstCache[i][i - 1][0] = NULL;

	/* We go through the intervals [i, ..., j] in increasing width. This
	 * guarantees that we have already generated all subtrees that we need. */
	for (int width = 1; width <= n; ++width)
		for (int i = 1, j = width; j <= n; ++i, ++j)
			generateSubTrees(i, j, bstCache, catalans);

	/* Before we free all the allocated memory, we make a copy of the result
	 * list, which is bstCache[1][n]. */
	*returnSize = catalans[n];
	size_t returnByteSize = (size_t) catalans[n] * sizeof(TN *);
	TNList result = malloc(returnByteSize);
	memcpy(result, bstCache[1][n], returnByteSize);

	/* Now we free all lists. The trees are not freed, as they are part of the
	 * returned result. As we have saves the result to a save place, we do not
	 * need special considerations for it. */
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = i - 1; j <= n; ++j)
			free(bstCache[i][j]);
		free(bstCache[i]);
	}
	free(bstCache);
	free(catalans);

	return result;
}

/* generateSubTrees: generates all BSTs with values in [lower, ..., upper], and
 * adds the results to the bstCache. */
void generateSubTrees(int lower, int upper, TNList **bstCache, int *catalans)
{
	TNList whereToAdd = bstCache[lower][upper];
	for (int value = lower; value <= upper; ++value) {
		TN **leftBSTList = bstCache[lower][value - 1];
		const int leftSize = catalans[(value - 1) - lower + 1];
		TN **rightBSTList = bstCache[value + 1][upper];
		const int rightSize = catalans[upper - (value + 1) + 1];
		crossCombineTreeLists(leftBSTList, leftSize, value, rightBSTList,
		                      rightSize, whereToAdd);
		whereToAdd += leftSize * rightSize;
	}
}

void crossCombineTreeLists(TNList leftList, int leftSize, int value,
                           TNList rightList, int rightSize, TNList whereToSave)
{
	for (int i = 0; i < leftSize; ++i)
		for (int j = 0; j < rightSize; ++j, ++whereToSave)
			*whereToSave = combineTrees(leftList[i], value, rightList[j]);
}

TN *combineTrees(TN *left, int value, TN *right)
{
	TN *node = malloc(sizeof(TN));
	node->val = value;
	node->left = left;
	node->right = right;
	return node;
}

int main(void)
{
	const int n = 16;
	int returnSize;

	TNList result = generateTrees(n, &returnSize);

	return 0;
}
