/* 108. Convert Sorted Array to Binary Search Tree */

/* Complexities:
 * Time: Θ(n)
 * Space: Θ(log(n))
 * where n is the length of the input array. */

#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TN;

TN *sortedArrayToBST(int *nums, int numsSize);
TN *makeNode(int val, TN *left, TN *right);

TN *sortedArrayToBST(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return NULL;

	int middle = numsSize / 2;
	TN *left = sortedArrayToBST(nums, middle);
	TN *right = sortedArrayToBST(nums + middle + 1, numsSize - middle - 1);
	return makeNode(nums[middle], left, right);
}

TN *makeNode(int val, TN *left, TN *right)
{
	TN *result = malloc(sizeof(TN));
	result->val = val;
	result->left = left;
	result->right = right;
	return result;
}
