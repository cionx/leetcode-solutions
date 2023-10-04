/* 112. Path Sum */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree, and h is its height. */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum)
{
	if (root == NULL)
		return false;
	/* The case of a leaf. */
	if (root->left == NULL && root->right == NULL)
		return targetSum == root->val;
	/* The case of at least one child. */
	return hasPathSum(root->left, targetSum - root->val) ||
	       hasPathSum(root->right, targetSum - root->val);
}
