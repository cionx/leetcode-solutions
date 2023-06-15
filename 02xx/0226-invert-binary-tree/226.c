/* Recursive solution
 *
 * Time: O(n)
 * Space: O(h)
 *
 * where n is the number of nodes in the tree,
 * and h is the height of the tree.
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/* Do not copy the above struct definition to LeetCode. */

struct TreeNode *invertTree(struct TreeNode *root)
{
	if (root == NULL)
		return NULL;

	struct TreeNode *invertedNode = malloc(sizeof(struct TreeNode));
	invertedNode->val = root->val;
	invertedNode->left = invertTree(root->right);
	invertedNode->right = invertTree(root->left);

	return invertedNode;
}
