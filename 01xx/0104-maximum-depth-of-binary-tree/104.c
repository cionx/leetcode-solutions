/* 104. Maximum Depth of Binary Tree */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the tree, and h is its height. */

#include <stdlib.h>

/* Do not copy this definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root);
int max(int a, int b);

int maxDepth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}
