/* 110. Balanced Binary Tree */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree
 * and h is the height of the tree. */

#include <stdbool.h>
#include <stdlib.h> /* For NULL. */

/* Don’t copy this struct to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode *root);
int balancedHeight(struct TreeNode *root);

bool isBalanced(struct TreeNode *root)
{
	return balancedHeight(root) != -1;
}

/* balancedHeight: returns -1 if the input tree is not height-balanced,
 * otherwise returns the height of the tree */
int balancedHeight(struct TreeNode *root)
{
	if (root == NULL)
		return 0;

	int leftHeight = balancedHeight(root->left);
	if (leftHeight == -1)
		return -1;

	int rightHeight = balancedHeight(root->right);
	if (rightHeight == -1)
		return -1;

	if (leftHeight == rightHeight || leftHeight == rightHeight + 1)
		return leftHeight + 1;
	if (rightHeight == leftHeight + 1)
		return rightHeight + 1;

	return -1;
}
