/* 111. Minimum Depth of Binary Tree */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(h)
 * where n is the number of nodes in the tree, and h is its height. */

#include <stdlib.h>

/* Do not copy this struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root);
int nonzeroMin(int a, int b);

int minDepth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	return 1 + nonzeroMin(minDepth(root->left), minDepth(root->right));
}

/* The following function maps
 *   (0, 0) -> 0
 *   (a, 0) -> a
 *   (0, b) -> b
 *   (a, b) -> min(a, b)
 */
int nonzeroMin(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return (a < b) ? a : b;
}
