/* 101. Symmetric Tree */

/* Complexities.
 * Time: O(n)
 * Space: O(h)
 * where n is the number of nodes in the tree, and h is its height. */

#include <stdbool.h>
#include <stdlib.h>

/* Do not copy the below struct definition to LeetCode. */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSymmetric(struct TreeNode *root);
bool areMirrored(struct TreeNode *root1, struct TreeNode *root2);

bool isSymmetric(struct TreeNode *root)
{
	return root == NULL || areMirrored(root->left, root->right);
}

bool areMirrored(struct TreeNode *root1, struct TreeNode *root2)
{
	return (root1 == NULL && root2 == NULL) ||
	       (root1 != NULL && root2 != NULL && root1->val == root2->val &&
	        areMirrored(root1->left, root2->right) &&
	        areMirrored(root1->right, root2->left));
}
