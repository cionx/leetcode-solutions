/* 700. Search in a Binary Search Tree */

/* Complexities.
 * Time: O(h)
 * Space: with tail recursion elimination: O(1)
 *        without tail recursion elimination: O(h)
 * where h is the height of the tree. */

#include <stdlib.h>

/* Do not copy the following struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int target)
{
	if (root == NULL)
		return NULL;
	if (target < root->val)
		return searchBST(root->left, target);
	if (root->val < target)
		return searchBST(root->right, target);
	return root;
}
