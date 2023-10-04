/* 437. Path Sum III */

/* Idea.
 * We determine for every node x recursively the valid paths in the subtree
 * below x. There are five kinds of such paths:
 * - Paths of length 1 at x.
 * - Paths starting at x and extending into the left branch.
 * - Paths starting at x and extending into the right branch.
 * - Paths that lie entirely in the left branch.
 * - Paths that lie entirely in the right branch.
 * We refer to paths of the first three kinds as “direct paths”, and to paths of
 * the other two kinds as “inherited paths”. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int pathSum(struct TreeNode *root, int targetSum);
int64_t direct(struct TreeNode *root, int64_t targetSum);
int64_t inherited(struct TreeNode *root, int64_t targetSum);

int pathSum(struct TreeNode *root, int targetSum)
{
	return direct(root, targetSum) + inherited(root, targetSum);
}

int64_t direct(struct TreeNode *root, int64_t targetSum)
{
	if (root == NULL)
		return 0;

	return ((root->val == targetSum) ? 1 : 0) +
	       direct(root->left, targetSum - root->val) +
	       direct(root->right, targetSum - root->val);
}

int64_t inherited(struct TreeNode *root, int64_t targetSum)
{
	if (root == NULL)
		return 0;

	return pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}
